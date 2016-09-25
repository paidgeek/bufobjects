package com.moybl.bufobjects;

import com.moybl.sidl.*;
import com.moybl.sidl.ast.*;
import com.moybl.sidl.semantics.NameLinker;

import org.apache.commons.cli.*;
import org.apache.commons.io.FileUtils;
import org.jtwig.JtwigModel;
import org.jtwig.JtwigTemplate;

import java.io.*;
import java.util.*;

public class BufferObjects {

  private static String BUFFER_OBJECT_ID_TYPE = "u16";
  private static boolean changedOnly = false;
  private static SchemaUtils utils = new SchemaUtils();
  private static final String[] SUPPORTED_LANGUAGES = {"java", "cpp"};
  private static final String META_FILENAME = ".bufobjects.meta";
  private static long lastParseTime;
  private static Set<String> changedDefinitions;

  public static void main(String[] args) {
    Option inputOption = new Option("i", "input", true, "input directory");
    inputOption.setRequired(true);
    Option outputOption = new Option("o", "output", true, "output directory");
    outputOption.setRequired(false);
    Option langOption = new Option("l", "lang", true, "Target language");
    langOption.setRequired(true);
    Option useRawPointers = new Option("rawpointers", "rawpointers", false, "Use raw pointers");
    useRawPointers.setRequired(false);

    Options options = new Options();
    options.addOption(inputOption);
    options.addOption(outputOption);
    options.addOption(langOption);
    options.addOption(useRawPointers);

    CommandLineParser cmdParser = new DefaultParser();
    HelpFormatter helpFormatter = new HelpFormatter();
    CommandLine cmd = null;

    try {
      cmd = cmdParser.parse(options, args);
    } catch (ParseException e) {
      System.err.println(e.getMessage());
      System.exit(1);
    }

    String lang = cmd.getOptionValue("lang");
    boolean genOneFile = cmd.hasOption("gen-onefile");

    if (!Arrays.asList(SUPPORTED_LANGUAGES).contains(lang)) {
      System.err.println("Unsupported language: " + lang);
      System.exit(1);
    }

    readMetaFile();
    changedDefinitions = new HashSet<>();

    File inputDirectory = new File(cmd.getOptionValue("input"));
    Schema schema = parseSchema(inputDirectory);

    File outputDirectory = new File(cmd
      .getOptionValue("output", inputDirectory + File.separator + "bufobjects"));

    Map<Definition, Integer> ids = Util.generateIds(schema);

    try {
      switch (lang) {
        case "java":
          writeJavaFiles(schema, outputDirectory, ids);
          break;
        case "cpp":
          utils.setRawPointers(cmd.hasOption("rawpointers"));
          writeCppFiles(schema, outputDirectory, ids);
          break;
      }
    } catch (Exception e) {
      e.printStackTrace();
      System.exit(1);
    }

    writeMetaFile();
  }

  public static Schema parseSchema(File inputDirectory) {
    List<Definition> definitions = new ArrayList<Definition>();

    if (inputDirectory.isFile()) {
      FileInputStream fis = null;
      try {
        fis = new FileInputStream(inputDirectory);
        Lexer lexer = new Lexer(new BufferedInputStream(fis));
        com.moybl.sidl.Parser parser = new com.moybl.sidl.Parser(lexer);

        List<Definition> parsedDefinitions = parser.parse().getDefinitions();
        definitions.addAll(parsedDefinitions);

        if (inputDirectory.lastModified() > lastParseTime) {
          for (int i = 0; i < parsedDefinitions.size(); i++) {
            changedDefinitions.add(parsedDefinitions.get(i).getDefinedName());
          }
        }
      } catch (FileNotFoundException e) {
        e.printStackTrace();
      } finally {
        if (fis != null) {
          try {
            fis.close();
          } catch (IOException e) {
          }
        }
      }
    } else {
      Iterator<File> fileIterator = FileUtils.iterateFiles(inputDirectory, null, true);

      while (fileIterator.hasNext()) {
        File file = fileIterator.next();
        FileInputStream fis = null;

        try {
          fis = new FileInputStream(file);
          Lexer lexer = new Lexer(new BufferedInputStream(fis));
          com.moybl.sidl.Parser parser = new com.moybl.sidl.Parser(lexer);

          List<Definition> parsedDefinitions = parser.parse().getDefinitions();
          definitions.addAll(parsedDefinitions);

          if (file.lastModified() > lastParseTime) {
            for (int i = 0; i < parsedDefinitions.size(); i++) {
              changedDefinitions.add(parsedDefinitions.get(i).getDefinedName());
            }
          }
        } catch (FileNotFoundException e) {
          e.printStackTrace();
        } finally {
          if (fis != null) {
            try {
              fis.close();
            } catch (IOException e) {
            }
          }
        }
      }
    }

    Position p = null;

    if (definitions.size() != 0) {
      Position a = definitions.get(0).getPosition();
      Position b = definitions.get(definitions.size() - 1).getPosition();
      p = Position.expand(a, b);
    }

    Document document = new Document(p, definitions);
    document.accept(new NameLinker());

    Schema s = new Schema();
    String ns = "";

    for (int i = 0; i < definitions.size(); i++) {
      Definition d = definitions.get(i);

      if (d instanceof NamespaceDefinition) {
        ns = ((NamespaceDefinition) d).getDefinedName();
      } else {
        s.addDefinition(ns, d);
      }
    }

    return s;
  }

  private static void writeJavaFiles(Schema schema, File outputDirectory, Map<Definition, Integer> ids) throws Exception {
    int totalJobs = 2;
    for (int i = 0; i < schema.getNamespaces().size(); i++) {
      totalJobs += schema.getDefinitions(schema.getNamespaces().get(i)).size();
    }

    JtwigModel model = JtwigModel.newModel()
      .with("utils", new SchemaUtils())
      .with("schema", schema.getRawSchema())
      .with("topNamespace", schema.getTopNamespace())
      .with("bufferObjectIdType", BUFFER_OBJECT_ID_TYPE)
      .with("ids", ids);

    List<String> topNamespace = Arrays.asList(schema.getTopNamespace(), "");
    writeTemplate("java/buffer_object.twig", model, outputDirectory, getFilePath("java", topNamespace), "BufferObject.java");
    writeTemplate("java/buffer_object_builder.twig", model, outputDirectory, getFilePath("java", topNamespace), "BufferObjectBuilder.java");

    for (int i = 0; i < schema.getNamespaces().size(); i++) {
      String namespace = schema.getNamespaces().get(i);
      List<Definition> definitions = schema.getDefinitions(namespace);

      for (int j = 0; j < definitions.size(); j++) {
        Definition d = definitions.get(j);
        String templateName = null;
        model = JtwigModel.newModel()
          .with("definition", d)
          .with("utils", new SchemaUtils())
          .with("path", d.getName().getPath())
          .with("bufferObjectIdType", BUFFER_OBJECT_ID_TYPE)
          .with("bufferObjectId", ids.get(d))
          .with("topNamespace", schema.getTopNamespace());

        if (d instanceof EnumDefinition) {
          templateName = "java/enum.twig";
        } else if (d instanceof InterfaceDefinition) {
          templateName = "java/interface.twig";
        } else if (d instanceof ServiceDefinition) {
          templateName = "java/service.twig";
        } else if (d instanceof StructDefinition) {
          templateName = "java/struct.twig";
        } else {
          templateName = "java/class.twig";
        }

        writeTemplate(d, templateName, model, outputDirectory, getFilePath("java", d.getName()
          .getPath()), getFileName("java", d.getName().getSimpleName()));
      }
    }
  }

  private static void writeCppFiles(Schema schema, File outputDirectory, Map<Definition, Integer> ids) throws Exception {
    int totalJobs = 2 + schema.getNamespaces().size();
    for (int i = 0; i < schema.getNamespaces().size(); i++) {
      List<Definition> defs = schema.getDefinitions(schema.getNamespaces().get(i));
      totalJobs += defs.size();
      for (int j = 0; j < defs.size(); j++) {
        if (defs.get(j) instanceof ClassDefinition || defs
          .get(j) instanceof InterfaceDefinition || defs.get(j) instanceof StructDefinition) {
          totalJobs++;
        }
      }
    }

    JtwigModel model = JtwigModel.newModel()
      .with("utils", utils)
      .with("schema", schema.getRawSchema())
      .with("topNamespace", schema.getTopNamespace())
      .with("bufferObjectIdType", BUFFER_OBJECT_ID_TYPE)
      .with("ids", ids);

    List<String> topNamespace = Arrays.asList(schema.getTopNamespace(), "");
    writeTemplate("cpp/buffer_object_header.twig", model, outputDirectory, "", "buffer_object.h");
    writeTemplate("cpp/buffer_object_source.twig", model, outputDirectory, "", "buffer_object.cc");
    writeTemplate("cpp/buffer_object_builder.twig", model, outputDirectory, "", "buffer_object_builder.h");

    for (int i = 0; i < schema.getNamespaces().size(); i++) {
      String namespace = schema.getNamespaces().get(i);
      List<Definition> definitions = schema.getDefinitions(namespace);

      {
        List<String> name = Arrays.asList(namespace.split("\\."));
        List<String> filePath = new ArrayList<>(name);
        filePath.add("");
        for (int j = 0; j < filePath.size(); j++) {
          filePath.set(j, filePath.get(j).toLowerCase());
        }

        model = JtwigModel.newModel()
          .with("utils", utils)
          .with("path", name)
          .with("schema", schema)
          .with("definitions", definitions);
        writeTemplate("cpp/namespace.twig", model, outputDirectory,
          getFilePath("cpp", filePath), "_all.h");
      }

      for (int j = 0; j < definitions.size(); j++) {
        Definition d = definitions.get(j);

        String templateName = null;
        model = JtwigModel.newModel()
          .with("definition", d)
          .with("utils", utils)
          .with("path", d.getName().getPath())
          .with("bufferObjectIdType", BUFFER_OBJECT_ID_TYPE)
          .with("schema", schema)
          .with("bufferObjectId", ids.get(d))
          .with("topNamespace", schema.getTopNamespace());

        if (d instanceof EnumDefinition) {
          templateName = "cpp/enum.twig";
          writeTemplate(d, templateName, model, outputDirectory,
            getFilePath("cpp", d.getName().getPath()),
            utils.toSnakeCase(d.getName().getSimpleName()) + ".h");
        } else if (d instanceof ClassDefinition) {
          templateName = "cpp/class_header.twig";
          writeTemplate(d, templateName, model, outputDirectory,
            getFilePath("cpp", d.getName().getPath()),
            utils.toSnakeCase(d.getName().getSimpleName()) + ".h");
          templateName = "cpp/class_source.twig";
          writeTemplate(d, templateName, model, outputDirectory,
            getFilePath("cpp", d.getName().getPath()),
            utils.toSnakeCase(d.getName().getSimpleName()) + ".cc");
        } else if (d instanceof StructDefinition) {
          templateName = "cpp/struct_header.twig";
          writeTemplate(d, templateName, model, outputDirectory,
            getFilePath("cpp", d.getName().getPath()),
            utils.toSnakeCase(d.getName().getSimpleName()) + ".h");
          templateName = "cpp/struct_source.twig";
          writeTemplate(d, templateName, model, outputDirectory,
            getFilePath("cpp", d.getName().getPath()),
            utils.toSnakeCase(d.getName().getSimpleName()) + ".cc");
        } else if (d instanceof InterfaceDefinition) {
          templateName = "cpp/interface_header.twig";
          writeTemplate(d, templateName, model, outputDirectory,
            getFilePath("cpp", d.getName().getPath()),
            utils.toSnakeCase(d.getName().getSimpleName()) + ".h");
          templateName = "cpp/interface_source.twig";
          writeTemplate(d, templateName, model, outputDirectory,
            getFilePath("cpp", d.getName().getPath()),
            utils.toSnakeCase(d.getName().getSimpleName()) + ".cc");
        }
      }
    }
  }

  private static void readMetaFile() {
    try (FileInputStream fis = new FileInputStream(META_FILENAME)) {
      ObjectInputStream ois = new ObjectInputStream(fis);

      lastParseTime = ois.readLong();
    } catch (FileNotFoundException e) {
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  private static void writeMetaFile() {
    ObjectOutputStream oos = null;

    try {
      FileOutputStream fos = new FileOutputStream(META_FILENAME);
      oos = new ObjectOutputStream(fos);
    } catch (FileNotFoundException e) {
      try {
        File metaFile = new File(META_FILENAME);
        metaFile.createNewFile();
        oos = new ObjectOutputStream(new FileOutputStream(metaFile));
      } catch (Exception e1) {
        e1.printStackTrace();
        return;
      }
    } catch (Exception e) {
      e.printStackTrace();
    }

    if (oos != null) {
      lastParseTime = System.currentTimeMillis();

      try {
        oos.writeLong(lastParseTime);
        oos.flush();
      } catch (Exception e) {
        e.printStackTrace();
      }
    }
  }

  private static void writeTemplate(String templateName, JtwigModel model, File outputDirectory, String filePath, String fileName) throws Exception {
    writeTemplate(null, templateName, model, outputDirectory, filePath, fileName);
  }

  private static void writeTemplate(Definition definition, String templateName, JtwigModel model, File outputDirectory, String filePath, String fileName) throws Exception {
    JtwigTemplate template = JtwigTemplate.classpathTemplate(templateName);

    File path = new File(outputDirectory
      .getAbsolutePath() + File.separator + filePath);
    if (!path.exists()) {
      path.mkdirs();
    }

    File file = new File(path, fileName);

    if (!file.exists()) {
      file.createNewFile();
    } else {
      if (changedOnly && definition != null && !changedDefinitions
        .contains(definition.getDefinedName())) {
        return;
      }
    }

    System.out.println("Generating: " + file.getAbsolutePath());
    try (FileOutputStream fos = new FileOutputStream(file)) {
      template.render(model, fos);
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    }
  }

  private static String getFilePath(String lang, List<String> path) {
    JtwigTemplate template = JtwigTemplate.classpathTemplate(lang + "/filepath.twig");
    JtwigModel model = JtwigModel.newModel()
      .with("path", path);

    return template.render(model).trim();
  }

  private static String getFileName(String lang, String name) {
    JtwigTemplate template = JtwigTemplate.classpathTemplate(lang + "/filename.twig");
    JtwigModel model = JtwigModel.newModel()
      .with("utils", new SchemaUtils())
      .with("name", name);

    return template.render(model).trim();
  }

}
