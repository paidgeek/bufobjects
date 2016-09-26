package com.moybl.bufobjects;

import com.moybl.sidl.Token;
import com.moybl.sidl.ast.*;

import java.util.Comparator;

public class FieldsComparator implements Comparator<Field> {

  @Override
  public int compare(Field left, Field right) {
    boolean leftScalar = false;
    boolean rightScalar = false;

    if (left.getType() instanceof PrimaryType) {
      PrimaryType pt = (PrimaryType) left.getType();
      leftScalar = isScalarType(pt);
    } else if (left.getType() instanceof ArrayType) {
      ArrayType at = (ArrayType) left.getType();
      leftScalar = isScalarType(at.getType());
    }

    if (right.getType() instanceof PrimaryType) {
      PrimaryType pt = (PrimaryType) right.getType();
      rightScalar = isScalarType(pt);
    } else if (right.getType() instanceof ArrayType) {
      ArrayType at = (ArrayType) right.getType();
      rightScalar = isScalarType(at.getType());
    }

    if (leftScalar && !rightScalar) {
      return -1;
    } else if (!leftScalar && rightScalar) {
      return 1;
    }

    return 0;
  }

  private boolean isScalarType(PrimaryType type) {
    return type.getDefinition() instanceof StructDefinition || type
      .getDefinition() instanceof EnumDefinition || isScalarToken(type.getToken());
  }

  private boolean isScalarToken(Token token) {
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

}
