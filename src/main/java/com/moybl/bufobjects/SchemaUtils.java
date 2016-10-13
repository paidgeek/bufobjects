package com.moybl.bufobjects;

import com.moybl.sidl.Token;
import com.moybl.sidl.ast.*;

import org.jtwig.JtwigModel;
import org.jtwig.JtwigTemplate;

public abstract class SchemaUtils {

  protected CodeStyle codeStyle;
  private JtwigTemplate namespaceNameTemplate;
  private JtwigTemplate classNameTemplate;
  private JtwigTemplate interfaceNameTemplate;
  private JtwigTemplate structNameTemplate;
  private JtwigTemplate enumNameTemplate;
  private JtwigTemplate classFieldTemplate;
  private JtwigTemplate structFieldTemplate;
  private JtwigTemplate methodTemplate;
  private JtwigTemplate parameterTemplate;
  private JtwigTemplate getterTemplate;
  private JtwigTemplate setterTemplate;
  private JtwigTemplate enumValueTemplate;
  private JtwigTemplate constantTemplate;

  public SchemaUtils(CodeStyle codeStyle) {
    this.codeStyle = codeStyle;

    namespaceNameTemplate = JtwigTemplate.inlineTemplate(codeStyle.getNamespaceName());
    classNameTemplate = JtwigTemplate.inlineTemplate(codeStyle.getClassName());
    interfaceNameTemplate = JtwigTemplate.inlineTemplate(codeStyle.getInterfaceName());
    structNameTemplate = JtwigTemplate.inlineTemplate(codeStyle.getStructName());
    enumNameTemplate = JtwigTemplate.inlineTemplate(codeStyle.getEnumName());
    classFieldTemplate = JtwigTemplate.inlineTemplate(codeStyle.getClassField());
    structFieldTemplate = JtwigTemplate.inlineTemplate(codeStyle.getStructField());
    methodTemplate = JtwigTemplate.inlineTemplate(codeStyle.getMethod());
    parameterTemplate = JtwigTemplate.inlineTemplate(codeStyle.getParameter());
    getterTemplate = JtwigTemplate.inlineTemplate(codeStyle.getGetter());
    setterTemplate = JtwigTemplate.inlineTemplate(codeStyle.getSetter());
    enumValueTemplate = JtwigTemplate.inlineTemplate(codeStyle.getEnumValue());
    constantTemplate = JtwigTemplate.inlineTemplate(codeStyle.getConstant());
  }

  public String toUpperCase(String s) {
    StringBuilder sb = new StringBuilder();

    for (int i = 0; i < s.length(); i++) {
      char ch = s.charAt(i);

      if (i > 0 && Character.isUpperCase(ch)) {
        sb.append("_");
      }

      sb.append(Character.toUpperCase(ch));
    }

    return sb.toString();
  }

  public String toSnakeCase(String s) {
    return toUpperCase(s).toLowerCase();
  }

  public String toCamelCase(String s) {
    return Character.toLowerCase(s.charAt(0)) + s.substring(1);
  }

  public String getClassName(Object obj) {
    return obj.getClass().getSimpleName();
  }

  public boolean isScalarType(Type type) {
    PrimaryType pt = null;

    if (type instanceof PrimaryType) {
      pt = (PrimaryType) type;
    } else if (type instanceof ArrayType) {
      pt = ((ArrayType) type).getType();
    } else {
      return false;
    }

    return pt.getDefinition() instanceof StructDefinition || pt
      .getDefinition() instanceof EnumDefinition || isScalarToken(pt.getToken());
  }

  public boolean isScalarToken(Token token) {
    return token == Token.TYPE_BOOL ||
      token == Token.TYPE_INT8 ||
      token == Token.TYPE_INT16 ||
      token == Token.TYPE_INT32 ||
      token == Token.TYPE_INT64 ||
      token == Token.TYPE_UINT8 ||
      token == Token.TYPE_UINT16 ||
      token == Token.TYPE_UINT32 ||
      token == Token.TYPE_UINT64 ||
      token == Token.TYPE_FLOAT32 ||
      token == Token.TYPE_FLOAT64;
  }

  public boolean hasAttribute(Definition definition, String name) {
    return definition.getAttributes().containsKey(name);
  }

  public String toNamespaceName(String name) {
    return namespaceNameTemplate.render(new JtwigModel().with("utils", this).with("name", name));
  }

  public String toClassName(String name) {
    return classNameTemplate.render(new JtwigModel().with("utils", this).with("name", name));
  }

  public String toStructName(String name) {
    return structNameTemplate.render(new JtwigModel().with("utils", this).with("name", name));
  }

  public String toEnumName(String name) {
    return enumNameTemplate.render(new JtwigModel().with("utils", this).with("name", name));
  }

  public String toInterfaceName(String name) {
    return interfaceNameTemplate.render(new JtwigModel().with("utils", this).with("name", name));
  }

  public String toClassField(String name) {
    return classFieldTemplate.render(new JtwigModel().with("utils", this).with("name", name));
  }

  public String toStructField(String name) {
    return structFieldTemplate.render(new JtwigModel().with("utils", this).with("name", name));
  }

  public String toMethod(String name) {
    return methodTemplate.render(new JtwigModel().with("utils", this).with("name", name));
  }

  public String toParameter(String name) {
    return parameterTemplate.render(new JtwigModel().with("utils", this).with("name", name));
  }

  public String toGetter(String name) {
    return getterTemplate.render(new JtwigModel().with("utils", this).with("name", name));
  }

  public String toSetter(String name) {
    return setterTemplate.render(new JtwigModel().with("utils", this).with("name", name));
  }

  public String toEnumValue(String name) {
    return enumValueTemplate.render(new JtwigModel().with("utils", this).with("name", name));
  }

  public String toConstant(String name) {
    return constantTemplate.render(new JtwigModel().with("utils", this).with("name", name));
  }

  public abstract String getFilePath(Definition definition);

  public abstract String getTypeNameForDefinition(Definition definition);

  public abstract String getBufferObjectIdName(Definition definition);

}
