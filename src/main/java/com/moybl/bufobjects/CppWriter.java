package com.moybl.bufobjects;

import com.moybl.sidl.Schema;
import com.moybl.sidl.ast.*;

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
/*
      for (int j = 0; j < definitions.size(); j++) {
        Definition d = definitions.get(j);

        String templateName = null;
        model = JtwigModel.newModel()
          .with("definition", d)
          .with("utils", utils)
          .with("path", d.getName().getPath())
          .with("bufferObjectIdType", bufferObjectIdType)
          .with("schema", schema)
          .with("bufferObjectId", ids.get(d))
          .with("topNamespace", schema.getTopNamespace());

        if (d instanceof EnumDefinition) {
          templateName = "cpp/enum.twig";
          JtwigTemplate.classpathTemplate("cpp/enum.twig").render(model, header);
        } else if (d instanceof ClassDefinition) {
          templateName = "cpp/class_header.twig";
          JtwigTemplate.classpathTemplate("cpp/enum.twig").render(model, header);
          templateName = "cpp/class_source.twig";
          JtwigTemplate.classpathTemplate("cpp/enum.twig").render(model, source);
        } else if (d instanceof StructDefinition) {
          templateName = "cpp/struct_header.twig";
          JtwigTemplate.classpathTemplate("cpp/enum.twig").render(model, header);
          templateName = "cpp/struct_source.twig";
          JtwigTemplate.classpathTemplate("cpp/enum.twig").render(model, source);
        } else if (d instanceof InterfaceDefinition) {
          templateName = "cpp/interface_header.twig";
          JtwigTemplate.classpathTemplate("cpp/enum.twig").render(model, header);
          templateName = "cpp/interface_source.twig";
          JtwigTemplate.classpathTemplate("cpp/enum.twig").render(model, source);
        }
      }
      */

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
