package com.moybl.bufobjects;

import com.moybl.sidl.Schema;
import com.moybl.sidl.ast.*;

import org.apache.commons.cli.*;
import org.jtwig.JtwigModel;
import org.jtwig.JtwigTemplate;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.util.Arrays;
import java.util.List;

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

    write(lang, schema, genOneFile);
  }

  private static void write(String lang, Schema schema, boolean oneFile) {
    SchemaUtils utils = new SchemaUtils();
    ByteArrayOutputStream out = new ByteArrayOutputStream();

    for (int i = 0; i < schema.getNamespaces().size(); i++) {
      String namespace = schema.getNamespaces().get(i);
      List<Definition> definitions = schema.getDefinitions(namespace);

      for (int j = 0; j < definitions.size(); j++) {
        Definition d = definitions.get(j);
        JtwigTemplate template = null;
        JtwigModel model = JtwigModel.newModel()
            .with("definition", d)
            .with("utils", utils)
            .with("isOneFile", oneFile)
            .with("path", d.getName().getPath());

        if (d instanceof EnumDefinition) {
          template = JtwigTemplate.classpathTemplate(lang + "/enum.twig");
        } else if (d instanceof InterfaceDefinition) {
          template = JtwigTemplate.classpathTemplate(lang + "/interface.twig");
        } else {
          template = JtwigTemplate.classpathTemplate(lang + "/type.twig");
        }

        template.render(model, out);

				/*
        if (!oneFile) {
					Formatter javaFormatter = new Formatter();
					try {
						System.out.println(javaFormatter.formatSource(out.toString()));
					} catch (FormatterException e) {
						e.printStackTrace();
					}

					out = new ByteArrayOutputStream();
				}
				*/
      }

      //System.out.println(out.toString());
      System.out.println(Util.formatJava(out.toString()));
    }
  }

}
