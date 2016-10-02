package com.moybl.bufobjects;

import com.moybl.sidl.Schema;
import com.moybl.sidl.ast.*;

import org.jtwig.JtwigModel;

import java.io.File;
import java.util.*;

public class JavaWriter {

  public static void write(Schema schema,
                           String bufferObjectIdType,
                           File outputDirectory,
                           Map<Definition, Integer> ids,
                           JavaSchemaUtils utils) throws Exception {
    JtwigModel model = JtwigModel.newModel()
      .with("utils", utils)
      .with("schema", schema.getRawSchema())
      .with("topNamespace", schema.getTopNamespace())
      .with("bufferObjectIdType", bufferObjectIdType)
      .with("ids", ids);

    File out = new File(outputDirectory, schema.getTopNamespace().toLowerCase());
    Util
      .writeTemplateFile("java/buffer_object.twig",
        model,
        out,
        "BufferObject.java");
    Util
      .writeTemplateFile("java/buffer_builder.twig",
        model,
        out,
        "BufferBuilder.java");

    for (int i = 0; i < schema.getNamespaces().size(); i++) {
      String namespace = schema.getNamespaces().get(i);
      List<Definition> definitions = schema.getDefinitions(namespace);
      for (int j = 0; j < definitions.size(); j++) {
        Definition d = definitions.get(j);
        String templateName = null;
        model = JtwigModel.newModel()
          .with("definition", d)
          .with("utils", utils)
          .with("path", d.getName().getPath())
          .with("bufferObjectIdType", bufferObjectIdType)
          .with("bufferObjectId", ids.get(d))
          .with("topNamespace", schema.getTopNamespace());
        if (d instanceof EnumDefinition) {
          templateName = "java/enum.twig";
        } else if (d instanceof InterfaceDefinition) {
          templateName = "java/interface.twig";
        } else if (d instanceof StructDefinition) {
          templateName = "java/struct.twig";
        } else {
          templateName = "java/class.twig";
        }

        String[] path = namespace.split("\\.");
        out = new File(outputDirectory, namespace.replace('.', '/').toLowerCase());

        Util.writeTemplateFile(templateName, model, out, d.getName().getSimpleName() + ".java");
      }
    }
  }

}
