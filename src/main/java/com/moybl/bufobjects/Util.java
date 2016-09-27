package com.moybl.bufobjects;

import com.moybl.sidl.Schema;
import com.moybl.sidl.ast.ClassDefinition;
import com.moybl.sidl.ast.Definition;

import org.jtwig.JtwigModel;
import org.jtwig.JtwigTemplate;

import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class Util {

  public static Map<Definition, Integer> generateIds(Schema schema) {
    Map<Definition, Integer> ids = new HashMap<>();
    int next = 1;

    // small ids
    for (String namespace : schema.getNamespaces()) {
      for (Definition definition : schema.getDefinitions(namespace)) {
        if (definition instanceof ClassDefinition && !definition.getAttributes()
          .containsKey("SmallId")) {
          ids.put(definition, next++);
        }
      }
    }

    // the rest
    for (String namespace : schema.getNamespaces()) {
      for (Definition definition : schema.getDefinitions(namespace)) {
        if (definition instanceof ClassDefinition && !ids.containsKey(definition)) {
          ids.put(definition, next++);
        }
      }
    }

    return ids;
  }

  public static void writeTemplateFile(String templateName, JtwigModel model, File outputDirectory, String fileName) throws Exception {
    JtwigTemplate template = JtwigTemplate.classpathTemplate(templateName);

    File path = new File(outputDirectory
      .getAbsolutePath());
    if (!path.exists()) {
      path.mkdirs();
    }

    File file = new File(path, fileName);

    if (!file.exists()) {
      file.createNewFile();
    }

    System.out.println("Generating: " + file.getAbsolutePath());
    try (FileOutputStream fos = new FileOutputStream(file)) {
      template.render(model, fos);
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    }
  }

  public static void writeFile(File outputDirectory, String fileName, String source) throws Exception {
    File path = new File(outputDirectory
      .getAbsolutePath() );
    if (!path.exists()) {
      path.mkdirs();
    }

    File file = new File(path, fileName);

    if (!file.exists()) {
      file.createNewFile();
    }

    System.out.println("Generating: " + file.getAbsolutePath());
    try (FileOutputStream fos = new FileOutputStream(file)) {
      fos.write(source.trim().getBytes());
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    }
  }

}
