package com.moybl.bufobjects;

import com.moybl.sidl.ast.*;

import java.util.List;

public class JavaSchemaUtils extends SchemaUtils {

  public JavaSchemaUtils(CodeStyle codeStyle) {
    super(codeStyle);
  }

  @Override
  public String getFilePath(Definition definition) {
    List<String> path = definition.getName().getPath();
    StringBuilder sb = new StringBuilder();

    for (int i = path.size() - 1; i >= 0; i--) {
      String p = path.get(i);
      if (i != 0) {
        sb.insert(0, p.toLowerCase() + "/");
      }
    }

    return sb.toString();
  }

  @Override
  public String getTypeNameForDefinition(Definition definition) {
    StringBuilder pkg = new StringBuilder();
    List<String> path = definition.getName().getPath();

    for (int i = 0; i < path.size(); i++) {
      if (i < path.size() - 1) {
        if (i != 0) {
          pkg.append(".").append(toNamespaceName(path.get(i)));
        } else {
          pkg.append(toNamespaceName(path.get(i)));
        }
      }
    }

    String typeName = null;
    if (definition instanceof ClassDefinition) {
      typeName = toClassName(definition.getName().getSimpleName());
    } else if (definition instanceof StructDefinition) {
      typeName = toStructName(definition.getName().getSimpleName());
    } else if (definition instanceof InterfaceDefinition) {
      typeName = toInterfaceName(definition.getName().getSimpleName());
    } else if (definition instanceof EnumDefinition) {
      typeName = toClassName(definition.getName().getSimpleName());
    }

    if (pkg.length() != 0) {
      typeName = pkg.append(".").append(typeName).toString();
    }

    return typeName;
  }

  @Override
  public String getBufferObjectIdName(Definition definition) {
    StringBuilder sb = new StringBuilder();
    List<String> path = definition.getName().getPath();

    for (int i = 0; i < path.size(); i++) {
      sb.append(path.get(i));
    }

    sb.append("Id");

    return toConstant(sb.toString());
  }

}
