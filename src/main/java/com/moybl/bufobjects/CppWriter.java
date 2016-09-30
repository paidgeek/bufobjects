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
    JtwigModel model = JtwigModel.newModel()
      .with("utils", utils)
      .with("schema", schema.getRawSchema())
      .with("topNamespace", schema.getTopNamespace())
      .with("bufferObjectIdType", bufferObjectIdType)
      .with("ids", ids);

    List<String> topNamespace = Arrays.asList(schema.getTopNamespace(), "");

    Util
      .writeTemplateFile("cpp/buffer_object_header.twig",
        model,
        outputDirectory,
        "buffer_object.h");
    Util
      .writeTemplateFile("cpp/buffer_object_source.twig",
        model,
        outputDirectory,
        "buffer_object.cc");
    Util
      .writeTemplateFile("cpp/buffer_builder.twig",
        model,
        outputDirectory,
        "buffer_builder.h");

    for (int i = 0; i < schema.getNamespaces().size(); i++) {
      String namespace = schema.getNamespaces().get(i);
      List<Definition> definitions = schema.getDefinitions(namespace);
      String namespaceName = namespace.replace(".", "_").toLowerCase();

      ByteArrayOutputStream source = new ByteArrayOutputStream();
      ByteArrayOutputStream header = new ByteArrayOutputStream();

      model = JtwigModel.newModel()
        .with("utils", utils)
        .with("schema", schema.getRawSchema())
        .with("namespace", namespace)
        .with("namespaceName", namespaceName)
        .with("topNamespace", schema.getTopNamespace())
        .with("bufferObjectIdType", bufferObjectIdType)
        .with("ids", ids);

      JtwigTemplate.classpathTemplate("cpp/namespace_header.twig").render(model, header);
      Util.writeFile(outputDirectory, namespaceName + ".h", header.toString());

      JtwigTemplate.classpathTemplate("cpp/namespace_source.twig").render(model, source);
      Util.writeFile(outputDirectory, namespaceName + ".cc", source.toString());
    }
  }

}
