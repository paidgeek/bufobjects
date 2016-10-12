package com.moybl.bufobjects;

import com.moybl.sidl.ast.Definition;

import java.util.List;

public class CppSchemaUtils extends SchemaUtils {

  @Override
  public String toClassFieldName(String name) {
    return toSnakeCase(name) + "_";
  }

  @Override
  public String toStructFieldName(String name) {
    return toSnakeCase(name);
  }

  @Override
  public String toGetterName(String name) {
    return toSnakeCase(name);
  }

  @Override
  public String toSetterName(String name) {
    return "set_" + toSnakeCase(name);
  }

  @Override
  public String toEnumValueName(String name) {
    return "k" + name;
  }

  @Override
  public String getFilePath(Definition definition) {
    List<String> path = definition.getName().getPath();
    StringBuilder sb = new StringBuilder();

    for (int i = path.size() - 1; i >= 0; i--) {
      String p = path.get(i);
      if (i != path.size() - 1) {
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
          pkg.append("::").append(path.get(i).toLowerCase());
        } else {
          pkg.append(path.get(i).toLowerCase());
        }
      }
    }

    String typeName = definition.getName().getSimpleName();

    if (pkg.length() != 0) {
      typeName = pkg.append("::").append(typeName).toString();
    }

    return typeName;
  }

  @Override
  public String getBufferObjectIdName(Definition definition) {
    StringBuilder sb = new StringBuilder();
    List<String> path = definition.getName().getPath();

    sb.append("k");

    for (int i = 0; i < path.size(); i++) {
      String p = path.get(i);
      sb.append(p);
    }

    sb.append("Id");

    return sb.toString();
  }

}
