package com.moybl.bufobjects;

import com.moybl.sidl.*;
import com.moybl.sidl.ast.*;
import com.moybl.sidl.semantics.NameLinker;

import org.apache.commons.cli.*;
import org.apache.commons.io.FileUtils;

import java.io.*;
import java.util.*;

public class BufferObjects {

  private static String bufferObjectIdType = "u16";
  private static final String[] SUPPORTED_LANGUAGES = {"java", "cpp"};

  public static void main(String[] args) {
    Option inputOption = new Option("i", "input", true, "input directory");
    inputOption.setRequired(true);
    Option outputOption = new Option("o", "output", true, "output directory");
    outputOption.setRequired(false);
    Option langOption = new Option("l", "lang", true, "Target language");
    langOption.setRequired(true);

    Options options = new Options();
    options.addOption(inputOption);
    options.addOption(outputOption);
    options.addOption(langOption);

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

    if (!Arrays.asList(SUPPORTED_LANGUAGES).contains(lang)) {
      System.err.println("Unsupported language: " + lang);
      System.exit(1);
    }

    File inputDirectory = new File(cmd.getOptionValue("input"));
    Schema schema = parseSchema(inputDirectory);

    File outputDirectory = new File(cmd
      .getOptionValue("output", inputDirectory + File.separator + "bufobjects"));

    Map<Definition, Integer> ids = Util.generateIds(schema);

    try {
      if (lang.equals("java")) {
      } else if (lang.equals("cpp")) {
        CppSchemaUtils cppUtils = new CppSchemaUtils();

        CppWriter.write(schema, bufferObjectIdType, outputDirectory, ids, cppUtils);
      }
    } catch (Exception e) {
      e.printStackTrace();
      System.exit(1);
    }
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

  /*
  private static void writeJavaFiles(Schema schema, File outputDirectory, Map<Definition, Integer> ids) throws Exception {
    int totalJobs = 2;
    for (int i = 0; i < schema.getNamespaces().size(); i++) {
      totalJobs += schema.getDefinitions(schema.getNamespaces().get(i)).size();
    }

    JtwigModel model = JtwigModel.newModel()
      .with("utils", utils)
      .with("schema", schema.getRawSchema())
      .with("topNamespace", schema.getTopNamespace())
      .with("bufferObjectIdType", bufferObjectIdType)
      .with("ids", ids);

    List<String> topNamespace = Arrays.asList(schema.getTopNamespace(), "");
    writeTemplate("java/buffer_object.twig", model, outputDirectory, schema
      .getTopNamespace(), "BufferObject.java");
    writeTemplate("java/buffer_object_builder.twig", model, outputDirectory, schema
      .getTopNamespace(), "BufferObjectBuilder.java");

    for (int i = 0; i < schema.getNamespaces().size(); i++) {
      String namespace = schema.getNamespaces().get(i);
      List<Definition> definitions = schema.getDefinitions(namespace);

      for (int j = 0; j < definitions.size(); j++) {
        Definition d = definitions.get(j);
        String templateName = null;
        model = JtwigModel.newModel()
          .with("definition", d)
          .with("utils", utils)
          .with("path", d.getName().getPath())
          .with("bufferObjectIdType", bufferObjectIdType)
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

        writeTemplate(d, templateName, model, outputDirectory, utils.getFilePath(d), d.getName()
          .getSimpleName() + ".java");
      }
    }
  }
*/

}
