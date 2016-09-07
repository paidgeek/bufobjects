package com.moybl.bufobjects;

import com.google.googlejavaformat.java.Formatter;
import com.google.googlejavaformat.java.*;

import com.moybl.sidl.*;
import com.moybl.sidl.ast.*;
import com.moybl.sidl.semantics.NameLinker;

import org.apache.commons.io.FileUtils;

import java.io.*;
import java.util.*;

public class Util {

  public static Schema parseSchema(File inputDirectory) {
    List<Definition> definitions = new ArrayList<Definition>();
    Iterator<File> fileIterator = FileUtils.iterateFiles(inputDirectory, null, true);

    while (fileIterator.hasNext()) {
      File file = fileIterator.next();
      FileInputStream fis = null;

      try {
        fis = new FileInputStream(file);
        Lexer lexer = new Lexer(new BufferedInputStream(fis));
        Parser parser = new Parser(lexer);
        definitions.addAll(parser.parse().getDefinitions());
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

  public static String formatJava(String source) {
    com.google.googlejavaformat.java.Formatter javaFormatter = new Formatter(new JavaFormatterOptions(JavaFormatterOptions.JavadocFormatter.ECLIPSE, JavaFormatterOptions.Style.GOOGLE, JavaFormatterOptions.SortImports.NO));

    try {
      return javaFormatter.formatSource(source);
    } catch (FormatterException e) {
      e.printStackTrace();
    }

    return null;
  }

}
