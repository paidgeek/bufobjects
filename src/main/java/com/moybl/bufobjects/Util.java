package com.moybl.bufobjects;

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

  public static Map<Definition, Integer> generateIds(Schema schema) {
    Map<Definition, Integer> ids = new HashMap<>();
    int next = 1;

    // small ids
    for (String namespace : schema.getNamespaces()) {
      for (Definition definition : schema.getDefinitions(namespace)) {
        if (definition instanceof TypeDefinition && !definition.getAttributes()
          .containsKey("SmallId")) {
          ids.put(definition, next++);
        }
      }
    }

    // the rest
    for (String namespace : schema.getNamespaces()) {
      for (Definition definition : schema.getDefinitions(namespace)) {
        if (definition instanceof TypeDefinition && !ids.containsKey(definition)) {
          ids.put(definition, next++);
        }
      }
    }

    return ids;
  }

  public static void writeFile(File dir, String pathName, String fileName, String data) throws IOException {
    File path = new File(dir
      .getAbsolutePath() + File.separator + pathName);
    if (!path.exists()) {
      path.mkdirs();
    }

    File file = new File(path, fileName);
    if (!file.exists()) {
      file.createNewFile();
    }

    try (FileOutputStream fos = new FileOutputStream(file)) {
      fos.write(data.getBytes("UTF-8"));
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    }
  }

}
