package com.moybl.bufobjects;

import com.moybl.sidl.Schema;
import com.moybl.sidl.ast.*;

import org.apache.commons.cli.*;
import org.jtwig.JtwigModel;
import org.jtwig.JtwigTemplate;

import java.io.File;
import java.util.*;

import me.tongfei.progressbar.ProgressBar;

public class BufferObjects {

  private static String BUFFER_OBJECT_ID_TYPE = "u16";
  private static final String[] SUPPORTED_LANGUAGES = {"java", "cpp"};
  private static ProgressBar progressBar;

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
    boolean genOneFile = cmd.hasOption("gen-onefile");

    if (!Arrays.asList(SUPPORTED_LANGUAGES).contains(lang)) {
      System.err.println("Unsupported language: " + lang);
      System.exit(1);
    }

    File inputDirectory = new File(cmd.getOptionValue("input"));
    Schema schema = Util.parseSchema(inputDirectory);

    File outputDirectory = new File(cmd
      .getOptionValue("output", inputDirectory + File.separator + "bufobjects"));

    Map<Definition, Integer> ids = Util.generateIds(schema);

    try {
      switch (lang) {
        case "java":
          writeJavaFiles(schema, outputDirectory, ids);
          break;
        case "cpp":
          writeCppFiles(schema, outputDirectory, ids);
          break;
      }
    } catch (Exception e) {
      e.printStackTrace();
      System.exit(1);
    }

    progressBar.stop();
  }

  private static void writeJavaFiles(Schema schema, File outputDirectory, Map<Definition, Integer> ids) throws Exception {
    int totalJobs = 2;
    for (int i = 0; i < schema.getNamespaces().size(); i++) {
      totalJobs += schema.getDefinitions(schema.getNamespaces().get(i)).size();
    }
    progressBar = new ProgressBar("Buffer Objects", totalJobs);
    progressBar.start();

    JtwigModel model = JtwigModel.newModel()
      .with("utils", new SchemaUtils())
      .with("schema", schema.getRawSchema())
      .with("topNamespace", schema.getTopNamespace())
      .with("bufferObjectIdType", BUFFER_OBJECT_ID_TYPE)
      .with("ids", ids);

    List<String> topNamespace = Arrays.asList(schema.getTopNamespace(), "");
    writeTemplate("java/buffer_object.twig", model, outputDirectory, getFilePath("java", topNamespace), getFileName("java", "BufferObject"));
    writeTemplate("java/buffer_object_builder.twig", model, outputDirectory, getFilePath("java", topNamespace), getFileName("java", "BufferObjectBuilder"));

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
        } else {
          templateName = "java/type.twig";
        }

        writeTemplate(templateName, model, outputDirectory, getFilePath("java", d.getName()
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
        if (defs.get(j) instanceof TypeDefinition) {
          totalJobs++;
        }
      }
    }
    progressBar = new ProgressBar("Buffer Objects", totalJobs, 50);
    progressBar.start();

    JtwigModel model = JtwigModel.newModel()
      .with("utils", new SchemaUtils())
      .with("schema", schema.getRawSchema())
      .with("topNamespace", schema.getTopNamespace())
      .with("bufferObjectIdType", BUFFER_OBJECT_ID_TYPE)
      .with("ids", ids);

    List<String> topNamespace = Arrays.asList(schema.getTopNamespace(), "");
    writeTemplate("cpp/buffer_object.twig", model, outputDirectory, "", "buffer_object.h");
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
          .with("utils", new SchemaUtils())
          .with("path", name)
          .with("definitions", definitions);
        writeTemplate("cpp/namespace.twig", model, outputDirectory,
          getFilePath("cpp", filePath),
          name.get(name.size() - 1).toLowerCase() + ".h");
      }

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
          templateName = "cpp/enum.twig";
          writeTemplate(templateName, model, outputDirectory,
            getFilePath("cpp", d.getName().getPath()),
            d.getName().getSimpleName() + ".h");
        } else if (d instanceof TypeDefinition) {
          templateName = "cpp/type_header.twig";
          writeTemplate(templateName, model, outputDirectory,
            getFilePath("cpp", d.getName().getPath()),
            d.getName().getSimpleName() + ".h");
          templateName = "cpp/type_source.twig";
          writeTemplate(templateName, model, outputDirectory,
            getFilePath("cpp", d.getName().getPath()),
            d.getName().getSimpleName() + ".cc");
        }
      }
    }
  }

  private static void writeTemplate(String templateName, JtwigModel model, File outputDirectory, String filePath, String fileName) throws Exception {
    JtwigTemplate template = JtwigTemplate.classpathTemplate(templateName);
    String source = template.render(model).trim();

    Util.writeFile(outputDirectory, filePath, fileName, source);
    updateProgress();
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

  private static void updateProgress() {
    progressBar.step();
  }

}
