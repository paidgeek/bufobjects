package com.moybl.bufobjects;

import com.moybl.sidl.Schema;
import com.moybl.sidl.ast.*;

import org.apache.commons.cli.*;
import org.jtwig.JtwigModel;
import org.jtwig.JtwigTemplate;

import java.io.*;
import java.util.*;

public class BufferObjects {

  private static final String[] SUPPORTED_LANGUAGES = {"java", "go"};

  public static void main(String[] args) {
    Option inputOption = new Option("i", "input", true, "input directory");
    inputOption.setRequired(true);
    Option outputOption = new Option("o", "output", true, "output directory");
    outputOption.setRequired(false);
    Option genOneFileOption = new Option(null, "gen-onefile", false, "Generate single output file");
    genOneFileOption.setRequired(false);
    Option langOption = new Option("l", "lang", true, "Target language");
    langOption.setRequired(true);

    Options options = new Options();
    options.addOption(inputOption);
    options.addOption(outputOption);
    options.addOption(genOneFileOption);
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
      .getOptionValue("output", inputDirectory + File.separator + "sidlgenerated"));

    try {
      //writeMultipleFiles(lang, schema, outputDirectory);
      writeBufferObjectsUtil(lang, schema, outputDirectory);
    } catch (Exception e) {
      e.printStackTrace();
      System.exit(1);
    }
  }

  private static void writeBufferObjectsUtil(String lang, Schema schema, File outputDirectory) throws Exception {
    Map<Definition, Integer> ids = Util.generateIds(schema);

    JtwigTemplate template = JtwigTemplate.classpathTemplate(lang + "/buffer_objects.twig");
    JtwigModel model = JtwigModel.newModel()
      .with("utils", new SchemaUtils())
      .with("schema", schema.getRawSchema())
      .with("ids", ids);

    ByteArrayOutputStream out = new ByteArrayOutputStream();
    template.render(model, out);

    System.out.println(out.toString());
  }

  private static void writeMultipleFiles(String lang, Schema schema, File outputDirectory) throws Exception {
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
          .with("path", d.getName().getPath());

        if (d instanceof EnumDefinition) {
          template = JtwigTemplate.classpathTemplate(lang + "/enum.twig");
        } else if (d instanceof InterfaceDefinition) {
          template = JtwigTemplate.classpathTemplate(lang + "/interface.twig");
        } else {
          template = JtwigTemplate.classpathTemplate(lang + "/type.twig");
        }

        ByteArrayOutputStream out = new ByteArrayOutputStream();
        template.render(model, out);
        //String source = Util.formatJava(out.toString().trim());
        String source = out.toString().trim();

        File path = new File(outputDirectory
          .getAbsolutePath() + File.separator + getFilePath(lang, d.getName().getPath()));
        if (!path.exists()) {
          path.mkdirs();
        }

        File file = new File(path, getFileName(lang, d));
        if (!file.exists()) {
          file.createNewFile();
        }

        try (FileOutputStream fos = new FileOutputStream(file)) {
          fos.write(source.getBytes("UTF-8"));
        } catch (FileNotFoundException e) {
          e.printStackTrace();
        }
      }
    }
  }

  private static String getFilePath(String lang, List<String> path) {
    JtwigTemplate template = JtwigTemplate.classpathTemplate(lang + "/filepath.twig");
    JtwigModel model = JtwigModel.newModel()
      .with("path", path);

    return template.render(model).trim();
  }

  private static String getFileName(String lang, Definition definition) {
    JtwigTemplate template = JtwigTemplate.classpathTemplate(lang + "/filename.twig");
    JtwigModel model = JtwigModel.newModel()
      .with("utils", new SchemaUtils())
      .with("definition", definition);

    return template.render(model).trim();
  }

}
