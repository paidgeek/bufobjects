package com.moybl.bufobjects;

import com.moybl.sidl.Schema;
import com.moybl.sidl.ast.Definition;

import org.jtwig.JtwigModel;
import org.jtwig.JtwigTemplate;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.util.*;

public class CppWriter {

  public static void write(Schema schema,
                           String bufferObjectIdType,
                           File outputDirectory,
                           Map<Definition, Integer> ids,
                           CppSchemaUtils utils) throws Exception {
    List<String> includes = getIncludes(schema.getTopNamespace(), schema, utils);
    JtwigModel model = JtwigModel.newModel()
      .with("utils", utils)
      .with("schema", schema.getRawSchema())
      .with("topNamespace", schema.getTopNamespace())
      .with("bufferObjectIdType", bufferObjectIdType)
      .with("ids", ids)
      .with("includes", includes);

    File out = new File(outputDirectory, schema.getTopNamespace().toLowerCase());
    Util
      .writeTemplateFile("cpp/buffer_object_header.twig",
        model,
        out,
        "buffer_object.h");
    Util
      .writeTemplateFile("cpp/buffer_object_source.twig",
        model,
        out,
        "buffer_object.cc");
    Util
      .writeTemplateFile("cpp/buffer_builder.twig",
        model,
        out,
        "buffer_builder.h");

    for (int i = 0; i < schema.getNamespaces().size(); i++) {
      String namespace = schema.getNamespaces().get(i);
      List<Definition> definitions = schema.getDefinitions(namespace);
      String namespaceName = namespace.replace(".", "_").toLowerCase();
      includes = getIncludes(namespace, schema, utils);

      ByteArrayOutputStream source = new ByteArrayOutputStream();
      ByteArrayOutputStream header = new ByteArrayOutputStream();

      model = JtwigModel.newModel()
        .with("utils", utils)
        .with("schema", schema.getRawSchema())
        .with("namespace", namespace)
        .with("namespaceName", namespaceName)
        .with("topNamespace", schema.getTopNamespace())
        .with("bufferObjectIdType", bufferObjectIdType)
        .with("includes", includes)
        .with("ids", ids);

      String[] path = namespace.split("\\.");
      out = new File(outputDirectory, namespace.replace('.', '/').toLowerCase());
      String fileName = utils.toSnakeCase(path[path.length - 1]);

      JtwigTemplate.classpathTemplate("cpp/namespace_header.twig").render(model, header);
      Util.writeFile(out, fileName + ".h", header.toString());

      JtwigTemplate.classpathTemplate("cpp/namespace_source.twig").render(model, source);
      Util.writeFile(out, fileName + ".cc", source.toString());
    }
  }

  private static List<String> getIncludes(String namespace, Schema schema, CppSchemaUtils utils) {
    List<String> includes = new ArrayList<>();
    String[] path = namespace.split("\\.");

    String prefix = "./";
    for (int i = 0; i < path.length; i++) {
      prefix += "../";
    }

    for (String ns : schema.getNamespaces()) {
      String[] nsPath = ns.split("\\.");
      for (int i = 0; i < nsPath.length; i++) {
        if (i < nsPath.length - 1) {
          nsPath[i] = nsPath[i].toLowerCase();
        } else {
          nsPath[i] = utils.toSnakeCase(nsPath[i]);
        }
      }

      includes.add(prefix + String.join("/", nsPath) + "/" + nsPath[nsPath.length - 1] + ".h");
    }

    return includes;
  }

}
