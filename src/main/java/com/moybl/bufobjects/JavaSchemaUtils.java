package com.moybl.bufobjects;

import com.moybl.sidl.ast.Definition;

import java.util.List;

public class JavaSchemaUtils extends SchemaUtils {

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
          pkg.append(".").append(path.get(i).toLowerCase());
        } else {
          pkg.append(path.get(i).toLowerCase());
        }
      }
    }

    String typeName = definition.getName().getSimpleName();

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
      sb.append(path.get(i).toUpperCase()).append("_");
    }

    sb.append("ID");

    return sb.toString();
  }

}
