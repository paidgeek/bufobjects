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
    return null;
  }

  @Override
  public String getBufferObjectIdName(Definition definition) {
    return null;
  }

}
