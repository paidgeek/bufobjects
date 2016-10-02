package com.moybl.bufobjects;

import com.moybl.sidl.*;
import com.moybl.sidl.ast.*;
import com.moybl.sidl.semantics.NameLinker;

import org.apache.commons.cli.*;
import org.apache.commons.io.FileUtils;

import java.io.*;
import java.util.*;

public class BufferObjects {

  private static final String[] SUPPORTED_LANGUAGES = {"java", "cpp"};
  private static final String[] VALID_OBJECT_ID_TYPES = {"i8", "u8", "i16", "u16", "i32", "u32", "i64", "u64"};

  public static void main(String[] args) {
    Option inputOption = new Option("i", "input", true, "input directory");
    inputOption.setRequired(true);
    Option outputOption = new Option("o", "output", true, "output directory");
    outputOption.setRequired(false);
    Option langOption = new Option("l", "lang", true, "Target language");
    langOption.setRequired(true);
    Option idTypeOption = new Option("id", "id", true, "Object id type");
    idTypeOption.setRequired(false);

    Options options = new Options();
    options.addOption(inputOption);
    options.addOption(outputOption);
    options.addOption(langOption);
    options.addOption(idTypeOption);

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

    String idType = cmd.hasOption("id") ? cmd.getOptionValue("id") : "u16";
    if (!Arrays.asList(VALID_OBJECT_ID_TYPES).contains(idType)) {
      System.err
        .printf("Invalid object id type '%s'\nValid object id types are: %s.\n", idType, Arrays
          .asList(VALID_OBJECT_ID_TYPES));
      System.exit(1);
    }

    Map<Definition, Integer> ids = Util.generateIds(schema);

    try {
      if (lang.equals("java")) {
        JavaSchemaUtils javaUtils = new JavaSchemaUtils();
        JavaWriter.write(schema, idType, outputDirectory, ids, javaUtils);
      } else if (lang.equals("cpp")) {
        CppSchemaUtils cppUtils = new CppSchemaUtils();
        CppWriter.write(schema, idType, outputDirectory, ids, cppUtils);
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
    String ns = null;
    String tls = null;

    for (int i = 0; i < definitions.size(); i++) {
      Definition d = definitions.get(i);

      if (!(d instanceof NamespaceDefinition) && d.getName().getPath().size() < 2) {
        throw new RuntimeException("Top level namespace required");
      }

      if (d instanceof NamespaceDefinition) {
        ns = ((NamespaceDefinition) d).getDefinedName();
      } else {
        s.addDefinition(ns, d);

        if (tls == null) {
          tls = d.getName().getPath().get(0);
        } else if (!tls.equals(d.getName().getPath().get(0))) {
          throw new RuntimeException("Only one top level namespace allowed");
        }
      }
    }

    return s;
  }

}
