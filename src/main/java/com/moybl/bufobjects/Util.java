package com.moybl.bufobjects;

import com.moybl.sidl.*;
import com.moybl.sidl.ast.*;
import com.moybl.sidl.semantics.NameLinker;

import org.apache.commons.io.FileUtils;

import java.io.*;
import java.util.*;

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

}
