package com.moybl.bufobjects;

import com.moybl.sidl.Schema;
import com.moybl.sidl.ast.*;

import org.apache.commons.cli.*;
import org.jtwig.JtwigModel;
import org.jtwig.JtwigTemplate;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.util.*;

public class BufferObjects {

  private static final String[] SUPPORTED_LANGUAGES = {"java", "go"};

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
      writeTypes(lang, schema, outputDirectory, ids);
      writeBufferObjectsStd(lang, schema, outputDirectory, ids);
    } catch (Exception e) {
      e.printStackTrace();
      System.exit(1);
    }
  }

  private static void writeBufferObjectsStd(String lang, Schema schema, File outputDirectory, Map<Definition, Integer> ids) throws Exception {
    JtwigTemplate template = JtwigTemplate.classpathTemplate(lang + "/buffer_objects.twig");
    JtwigModel model = JtwigModel.newModel()
      .with("utils", new SchemaUtils())
      .with("schema", schema.getRawSchema())
      .with("topNamespace", schema.getTopNamespace())
      .with("ids", ids);

    ByteArrayOutputStream out = new ByteArrayOutputStream();
    template.render(model, out);
    String source = out.toString().trim();

    String bufferObject = JtwigTemplate.classpathTemplate(lang + "/buffer_object.twig")
      .render(model);
    List<String> topNamespace = Arrays.asList(schema.getTopNamespace(), "");

    Util
      .writeFile(outputDirectory, getFilePath(lang, topNamespace),
        getFileName(lang, "BufferObjects"), source);
    Util.writeFile(outputDirectory, getFilePath(lang, topNamespace),
      getFileName(lang, "BufferObject"), bufferObject);
  }

  private static void writeTypes(String lang, Schema schema, File outputDirectory, Map<Definition, Integer> ids) throws Exception {
    for (int i = 0; i < schema.getNamespaces().size(); i++) {
      String namespace = schema.getNamespaces().get(i);
      List<Definition> definitions = schema.getDefinitions(namespace);

      for (int j = 0; j < definitions.size(); j++) {
        Definition d = definitions.get(j);
        JtwigTemplate template = null;
        JtwigModel model = JtwigModel.newModel()
          .with("definition", d)
          .with("utils", new SchemaUtils())
          .with("isOneFile", false)
          .with("path", d.getName().getPath())
          .with("bufferObjectId", ids.get(d))
          .with("topNamespace", schema.getTopNamespace());

        if (d instanceof EnumDefinition) {
          template = JtwigTemplate.classpathTemplate(lang + "/enum.twig");
        } else if (d instanceof InterfaceDefinition) {
          template = JtwigTemplate.classpathTemplate(lang + "/interface.twig");
        } else {
          template = JtwigTemplate.classpathTemplate(lang + "/type.twig");
        }

        ByteArrayOutputStream out = new ByteArrayOutputStream();
        template.render(model, out);
        String source = out.toString().trim();

        Util
          .writeFile(outputDirectory, getFilePath(lang, d.getName().getPath()), getFileName(lang, d
            .getName().getSimpleName()), source);
      }
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
