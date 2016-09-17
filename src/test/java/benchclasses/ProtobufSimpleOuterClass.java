// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protobuf_simple.proto
package benchclasses;

public final class ProtobufSimpleOuterClass {
  private ProtobufSimpleOuterClass() {}
  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistryLite registry) {
  }

  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistry registry) {
    registerAllExtensions(
        (com.google.protobuf.ExtensionRegistryLite) registry);
  }
  public interface ProtobufSimpleOrBuilder extends
      // @@protoc_insertion_point(interface_extends:ProtobufSimple)
      com.google.protobuf.MessageOrBuilder {

    /**
     * <code>optional string name = 1;</code>
     */
    java.lang.String getName();
    /**
     * <code>optional string name = 1;</code>
     */
    com.google.protobuf.ByteString
        getNameBytes();

    /**
     * <code>optional double value = 2;</code>
     */
    double getValue();

    /**
     * <code>repeated int32 arr = 3;</code>
     */
    java.util.List<java.lang.Integer> getArrList();
    /**
     * <code>repeated int32 arr = 3;</code>
     */
    int getArrCount();
    /**
     * <code>repeated int32 arr = 3;</code>
     */
    int getArr(int index);
  }
  /**
   * Protobuf type {@code ProtobufSimple}
   */
  public  static final class ProtobufSimple extends
      com.google.protobuf.GeneratedMessageV3 implements
      // @@protoc_insertion_point(message_implements:ProtobufSimple)
      ProtobufSimpleOrBuilder {
    // Use ProtobufSimple.newBuilder() to construct.
    private ProtobufSimple(com.google.protobuf.GeneratedMessageV3.Builder<?> builder) {
      super(builder);
    }
    private ProtobufSimple() {
      name_ = "";
      value_ = 0D;
      arr_ = java.util.Collections.emptyList();
    }

    @java.lang.Override
    public final com.google.protobuf.UnknownFieldSet
    getUnknownFields() {
      return com.google.protobuf.UnknownFieldSet.getDefaultInstance();
    }
    private ProtobufSimple(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      this();
      int mutable_bitField0_ = 0;
      try {
        boolean done = false;
        while (!done) {
          int tag = input.readTag();
          switch (tag) {
            case 0:
              done = true;
              break;
            default: {
              if (!input.skipField(tag)) {
                done = true;
              }
              break;
            }
            case 10: {
              java.lang.String s = input.readStringRequireUtf8();

              name_ = s;
              break;
            }
            case 17: {

              value_ = input.readDouble();
              break;
            }
            case 24: {
              if (!((mutable_bitField0_ & 0x00000004) == 0x00000004)) {
                arr_ = new java.util.ArrayList<java.lang.Integer>();
                mutable_bitField0_ |= 0x00000004;
              }
              arr_.add(input.readInt32());
              break;
            }
            case 26: {
              int length = input.readRawVarint32();
              int limit = input.pushLimit(length);
              if (!((mutable_bitField0_ & 0x00000004) == 0x00000004) && input.getBytesUntilLimit() > 0) {
                arr_ = new java.util.ArrayList<java.lang.Integer>();
                mutable_bitField0_ |= 0x00000004;
              }
              while (input.getBytesUntilLimit() > 0) {
                arr_.add(input.readInt32());
              }
              input.popLimit(limit);
              break;
            }
          }
        }
      } catch (com.google.protobuf.InvalidProtocolBufferException e) {
        throw e.setUnfinishedMessage(this);
      } catch (java.io.IOException e) {
        throw new com.google.protobuf.InvalidProtocolBufferException(
            e).setUnfinishedMessage(this);
      } finally {
        if (((mutable_bitField0_ & 0x00000004) == 0x00000004)) {
          arr_ = java.util.Collections.unmodifiableList(arr_);
        }
        makeExtensionsImmutable();
      }
    }
    public static final com.google.protobuf.Descriptors.Descriptor
        getDescriptor() {
      return ProtobufSimpleOuterClass.internal_static_ProtobufSimple_descriptor;
    }

    protected com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
        internalGetFieldAccessorTable() {
      return ProtobufSimpleOuterClass.internal_static_ProtobufSimple_fieldAccessorTable
          .ensureFieldAccessorsInitialized(
              ProtobufSimpleOuterClass.ProtobufSimple.class, ProtobufSimpleOuterClass.ProtobufSimple.Builder.class);
    }

    private int bitField0_;
    public static final int NAME_FIELD_NUMBER = 1;
    private volatile java.lang.Object name_;
    /**
     * <code>optional string name = 1;</code>
     */
    public java.lang.String getName() {
      java.lang.Object ref = name_;
      if (ref instanceof java.lang.String) {
        return (java.lang.String) ref;
      } else {
        com.google.protobuf.ByteString bs = 
            (com.google.protobuf.ByteString) ref;
        java.lang.String s = bs.toStringUtf8();
        name_ = s;
        return s;
      }
    }
    /**
     * <code>optional string name = 1;</code>
     */
    public com.google.protobuf.ByteString
        getNameBytes() {
      java.lang.Object ref = name_;
      if (ref instanceof java.lang.String) {
        com.google.protobuf.ByteString b = 
            com.google.protobuf.ByteString.copyFromUtf8(
                (java.lang.String) ref);
        name_ = b;
        return b;
      } else {
        return (com.google.protobuf.ByteString) ref;
      }
    }

    public static final int VALUE_FIELD_NUMBER = 2;
    private double value_;
    /**
     * <code>optional double value = 2;</code>
     */
    public double getValue() {
      return value_;
    }

    public static final int ARR_FIELD_NUMBER = 3;
    private java.util.List<java.lang.Integer> arr_;
    /**
     * <code>repeated int32 arr = 3;</code>
     */
    public java.util.List<java.lang.Integer>
        getArrList() {
      return arr_;
    }
    /**
     * <code>repeated int32 arr = 3;</code>
     */
    public int getArrCount() {
      return arr_.size();
    }
    /**
     * <code>repeated int32 arr = 3;</code>
     */
    public int getArr(int index) {
      return arr_.get(index);
    }
    private int arrMemoizedSerializedSize = -1;

    private byte memoizedIsInitialized = -1;
    public final boolean isInitialized() {
      byte isInitialized = memoizedIsInitialized;
      if (isInitialized == 1) return true;
      if (isInitialized == 0) return false;

      memoizedIsInitialized = 1;
      return true;
    }

    public void writeTo(com.google.protobuf.CodedOutputStream output)
                        throws java.io.IOException {
      getSerializedSize();
      if (!getNameBytes().isEmpty()) {
        com.google.protobuf.GeneratedMessageV3.writeString(output, 1, name_);
      }
      if (value_ != 0D) {
        output.writeDouble(2, value_);
      }
      if (getArrList().size() > 0) {
        output.writeUInt32NoTag(26);
        output.writeUInt32NoTag(arrMemoizedSerializedSize);
      }
      for (int i = 0; i < arr_.size(); i++) {
        output.writeInt32NoTag(arr_.get(i));
      }
    }

    public int getSerializedSize() {
      int size = memoizedSize;
      if (size != -1) return size;

      size = 0;
      if (!getNameBytes().isEmpty()) {
        size += com.google.protobuf.GeneratedMessageV3.computeStringSize(1, name_);
      }
      if (value_ != 0D) {
        size += com.google.protobuf.CodedOutputStream
          .computeDoubleSize(2, value_);
      }
      {
        int dataSize = 0;
        for (int i = 0; i < arr_.size(); i++) {
          dataSize += com.google.protobuf.CodedOutputStream
            .computeInt32SizeNoTag(arr_.get(i));
        }
        size += dataSize;
        if (!getArrList().isEmpty()) {
          size += 1;
          size += com.google.protobuf.CodedOutputStream
              .computeInt32SizeNoTag(dataSize);
        }
        arrMemoizedSerializedSize = dataSize;
      }
      memoizedSize = size;
      return size;
    }

    private static final long serialVersionUID = 0L;
    @java.lang.Override
    public boolean equals(final java.lang.Object obj) {
      if (obj == this) {
       return true;
      }
      if (!(obj instanceof ProtobufSimpleOuterClass.ProtobufSimple)) {
        return super.equals(obj);
      }
      ProtobufSimpleOuterClass.ProtobufSimple other = (ProtobufSimpleOuterClass.ProtobufSimple) obj;

      boolean result = true;
      result = result && getName()
          .equals(other.getName());
      result = result && (
          java.lang.Double.doubleToLongBits(getValue())
          == java.lang.Double.doubleToLongBits(
              other.getValue()));
      result = result && getArrList()
          .equals(other.getArrList());
      return result;
    }

    @java.lang.Override
    public int hashCode() {
      if (memoizedHashCode != 0) {
        return memoizedHashCode;
      }
      int hash = 41;
      hash = (19 * hash) + getDescriptorForType().hashCode();
      hash = (37 * hash) + NAME_FIELD_NUMBER;
      hash = (53 * hash) + getName().hashCode();
      hash = (37 * hash) + VALUE_FIELD_NUMBER;
      hash = (53 * hash) + com.google.protobuf.Internal.hashLong(
          java.lang.Double.doubleToLongBits(getValue()));
      if (getArrCount() > 0) {
        hash = (37 * hash) + ARR_FIELD_NUMBER;
        hash = (53 * hash) + getArrList().hashCode();
      }
      hash = (29 * hash) + unknownFields.hashCode();
      memoizedHashCode = hash;
      return hash;
    }

    public static ProtobufSimpleOuterClass.ProtobufSimple parseFrom(
        com.google.protobuf.ByteString data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static ProtobufSimpleOuterClass.ProtobufSimple parseFrom(
        com.google.protobuf.ByteString data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static ProtobufSimpleOuterClass.ProtobufSimple parseFrom(byte[] data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static ProtobufSimpleOuterClass.ProtobufSimple parseFrom(
        byte[] data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static ProtobufSimpleOuterClass.ProtobufSimple parseFrom(java.io.InputStream input)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseWithIOException(PARSER, input);
    }
    public static ProtobufSimpleOuterClass.ProtobufSimple parseFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseWithIOException(PARSER, input, extensionRegistry);
    }
    public static ProtobufSimpleOuterClass.ProtobufSimple parseDelimitedFrom(java.io.InputStream input)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseDelimitedWithIOException(PARSER, input);
    }
    public static ProtobufSimpleOuterClass.ProtobufSimple parseDelimitedFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseDelimitedWithIOException(PARSER, input, extensionRegistry);
    }
    public static ProtobufSimpleOuterClass.ProtobufSimple parseFrom(
        com.google.protobuf.CodedInputStream input)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseWithIOException(PARSER, input);
    }
    public static ProtobufSimpleOuterClass.ProtobufSimple parseFrom(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseWithIOException(PARSER, input, extensionRegistry);
    }

    public Builder newBuilderForType() { return newBuilder(); }
    public static Builder newBuilder() {
      return DEFAULT_INSTANCE.toBuilder();
    }
    public static Builder newBuilder(ProtobufSimpleOuterClass.ProtobufSimple prototype) {
      return DEFAULT_INSTANCE.toBuilder().mergeFrom(prototype);
    }
    public Builder toBuilder() {
      return this == DEFAULT_INSTANCE
          ? new Builder() : new Builder().mergeFrom(this);
    }

    @java.lang.Override
    protected Builder newBuilderForType(
        com.google.protobuf.GeneratedMessageV3.BuilderParent parent) {
      Builder builder = new Builder(parent);
      return builder;
    }
    /**
     * Protobuf type {@code ProtobufSimple}
     */
    public static final class Builder extends
        com.google.protobuf.GeneratedMessageV3.Builder<Builder> implements
        // @@protoc_insertion_point(builder_implements:ProtobufSimple)
        ProtobufSimpleOuterClass.ProtobufSimpleOrBuilder {
      public static final com.google.protobuf.Descriptors.Descriptor
          getDescriptor() {
        return ProtobufSimpleOuterClass.internal_static_ProtobufSimple_descriptor;
      }

      protected com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
          internalGetFieldAccessorTable() {
        return ProtobufSimpleOuterClass.internal_static_ProtobufSimple_fieldAccessorTable
            .ensureFieldAccessorsInitialized(
                ProtobufSimpleOuterClass.ProtobufSimple.class, ProtobufSimpleOuterClass.ProtobufSimple.Builder.class);
      }

      // Construct using ProtobufSimpleOuterClass.ProtobufSimple.newBuilder()
      private Builder() {
        maybeForceBuilderInitialization();
      }

      private Builder(
          com.google.protobuf.GeneratedMessageV3.BuilderParent parent) {
        super(parent);
        maybeForceBuilderInitialization();
      }
      private void maybeForceBuilderInitialization() {
        if (com.google.protobuf.GeneratedMessageV3
                .alwaysUseFieldBuilders) {
        }
      }
      public Builder clear() {
        super.clear();
        name_ = "";

        value_ = 0D;

        arr_ = java.util.Collections.emptyList();
        bitField0_ = (bitField0_ & ~0x00000004);
        return this;
      }

      public com.google.protobuf.Descriptors.Descriptor
          getDescriptorForType() {
        return ProtobufSimpleOuterClass.internal_static_ProtobufSimple_descriptor;
      }

      public ProtobufSimpleOuterClass.ProtobufSimple getDefaultInstanceForType() {
        return ProtobufSimpleOuterClass.ProtobufSimple.getDefaultInstance();
      }

      public ProtobufSimpleOuterClass.ProtobufSimple build() {
        ProtobufSimpleOuterClass.ProtobufSimple result = buildPartial();
        if (!result.isInitialized()) {
          throw newUninitializedMessageException(result);
        }
        return result;
      }

      public ProtobufSimpleOuterClass.ProtobufSimple buildPartial() {
        ProtobufSimpleOuterClass.ProtobufSimple result = new ProtobufSimpleOuterClass.ProtobufSimple(this);
        int from_bitField0_ = bitField0_;
        int to_bitField0_ = 0;
        result.name_ = name_;
        result.value_ = value_;
        if (((bitField0_ & 0x00000004) == 0x00000004)) {
          arr_ = java.util.Collections.unmodifiableList(arr_);
          bitField0_ = (bitField0_ & ~0x00000004);
        }
        result.arr_ = arr_;
        result.bitField0_ = to_bitField0_;
        onBuilt();
        return result;
      }

      public Builder clone() {
        return (Builder) super.clone();
      }
      public Builder setField(
          com.google.protobuf.Descriptors.FieldDescriptor field,
          Object value) {
        return (Builder) super.setField(field, value);
      }
      public Builder clearField(
          com.google.protobuf.Descriptors.FieldDescriptor field) {
        return (Builder) super.clearField(field);
      }
      public Builder clearOneof(
          com.google.protobuf.Descriptors.OneofDescriptor oneof) {
        return (Builder) super.clearOneof(oneof);
      }
      public Builder setRepeatedField(
          com.google.protobuf.Descriptors.FieldDescriptor field,
          int index, Object value) {
        return (Builder) super.setRepeatedField(field, index, value);
      }
      public Builder addRepeatedField(
          com.google.protobuf.Descriptors.FieldDescriptor field,
          Object value) {
        return (Builder) super.addRepeatedField(field, value);
      }
      public Builder mergeFrom(com.google.protobuf.Message other) {
        if (other instanceof ProtobufSimpleOuterClass.ProtobufSimple) {
          return mergeFrom((ProtobufSimpleOuterClass.ProtobufSimple)other);
        } else {
          super.mergeFrom(other);
          return this;
        }
      }

      public Builder mergeFrom(ProtobufSimpleOuterClass.ProtobufSimple other) {
        if (other == ProtobufSimpleOuterClass.ProtobufSimple.getDefaultInstance()) return this;
        if (!other.getName().isEmpty()) {
          name_ = other.name_;
          onChanged();
        }
        if (other.getValue() != 0D) {
          setValue(other.getValue());
        }
        if (!other.arr_.isEmpty()) {
          if (arr_.isEmpty()) {
            arr_ = other.arr_;
            bitField0_ = (bitField0_ & ~0x00000004);
          } else {
            ensureArrIsMutable();
            arr_.addAll(other.arr_);
          }
          onChanged();
        }
        onChanged();
        return this;
      }

      public final boolean isInitialized() {
        return true;
      }

      public Builder mergeFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws java.io.IOException {
        ProtobufSimpleOuterClass.ProtobufSimple parsedMessage = null;
        try {
          parsedMessage = PARSER.parsePartialFrom(input, extensionRegistry);
        } catch (com.google.protobuf.InvalidProtocolBufferException e) {
          parsedMessage = (ProtobufSimpleOuterClass.ProtobufSimple) e.getUnfinishedMessage();
          throw e.unwrapIOException();
        } finally {
          if (parsedMessage != null) {
            mergeFrom(parsedMessage);
          }
        }
        return this;
      }
      private int bitField0_;

      private java.lang.Object name_ = "";
      /**
       * <code>optional string name = 1;</code>
       */
      public java.lang.String getName() {
        java.lang.Object ref = name_;
        if (!(ref instanceof java.lang.String)) {
          com.google.protobuf.ByteString bs =
              (com.google.protobuf.ByteString) ref;
          java.lang.String s = bs.toStringUtf8();
          name_ = s;
          return s;
        } else {
          return (java.lang.String) ref;
        }
      }
      /**
       * <code>optional string name = 1;</code>
       */
      public com.google.protobuf.ByteString
          getNameBytes() {
        java.lang.Object ref = name_;
        if (ref instanceof String) {
          com.google.protobuf.ByteString b = 
              com.google.protobuf.ByteString.copyFromUtf8(
                  (java.lang.String) ref);
          name_ = b;
          return b;
        } else {
          return (com.google.protobuf.ByteString) ref;
        }
      }
      /**
       * <code>optional string name = 1;</code>
       */
      public Builder setName(
          java.lang.String value) {
        if (value == null) {
    throw new NullPointerException();
  }
  
        name_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>optional string name = 1;</code>
       */
      public Builder clearName() {
        
        name_ = getDefaultInstance().getName();
        onChanged();
        return this;
      }
      /**
       * <code>optional string name = 1;</code>
       */
      public Builder setNameBytes(
          com.google.protobuf.ByteString value) {
        if (value == null) {
    throw new NullPointerException();
  }
  checkByteStringIsUtf8(value);
        
        name_ = value;
        onChanged();
        return this;
      }

      private double value_ ;
      /**
       * <code>optional double value = 2;</code>
       */
      public double getValue() {
        return value_;
      }
      /**
       * <code>optional double value = 2;</code>
       */
      public Builder setValue(double value) {
        
        value_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>optional double value = 2;</code>
       */
      public Builder clearValue() {
        
        value_ = 0D;
        onChanged();
        return this;
      }

      private java.util.List<java.lang.Integer> arr_ = java.util.Collections.emptyList();
      private void ensureArrIsMutable() {
        if (!((bitField0_ & 0x00000004) == 0x00000004)) {
          arr_ = new java.util.ArrayList<java.lang.Integer>(arr_);
          bitField0_ |= 0x00000004;
         }
      }
      /**
       * <code>repeated int32 arr = 3;</code>
       */
      public java.util.List<java.lang.Integer>
          getArrList() {
        return java.util.Collections.unmodifiableList(arr_);
      }
      /**
       * <code>repeated int32 arr = 3;</code>
       */
      public int getArrCount() {
        return arr_.size();
      }
      /**
       * <code>repeated int32 arr = 3;</code>
       */
      public int getArr(int index) {
        return arr_.get(index);
      }
      /**
       * <code>repeated int32 arr = 3;</code>
       */
      public Builder setArr(
          int index, int value) {
        ensureArrIsMutable();
        arr_.set(index, value);
        onChanged();
        return this;
      }
      /**
       * <code>repeated int32 arr = 3;</code>
       */
      public Builder addArr(int value) {
        ensureArrIsMutable();
        arr_.add(value);
        onChanged();
        return this;
      }
      /**
       * <code>repeated int32 arr = 3;</code>
       */
      public Builder addAllArr(
          java.lang.Iterable<? extends java.lang.Integer> values) {
        ensureArrIsMutable();
        com.google.protobuf.AbstractMessageLite.Builder.addAll(
            values, arr_);
        onChanged();
        return this;
      }
      /**
       * <code>repeated int32 arr = 3;</code>
       */
      public Builder clearArr() {
        arr_ = java.util.Collections.emptyList();
        bitField0_ = (bitField0_ & ~0x00000004);
        onChanged();
        return this;
      }
      public final Builder setUnknownFields(
          final com.google.protobuf.UnknownFieldSet unknownFields) {
        return this;
      }

      public final Builder mergeUnknownFields(
          final com.google.protobuf.UnknownFieldSet unknownFields) {
        return this;
      }


      // @@protoc_insertion_point(builder_scope:ProtobufSimple)
    }

    // @@protoc_insertion_point(class_scope:ProtobufSimple)
    private static final ProtobufSimpleOuterClass.ProtobufSimple DEFAULT_INSTANCE;
    static {
      DEFAULT_INSTANCE = new ProtobufSimpleOuterClass.ProtobufSimple();
    }

    public static ProtobufSimpleOuterClass.ProtobufSimple getDefaultInstance() {
      return DEFAULT_INSTANCE;
    }

    private static final com.google.protobuf.Parser<ProtobufSimple>
        PARSER = new com.google.protobuf.AbstractParser<ProtobufSimple>() {
      public ProtobufSimple parsePartialFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws com.google.protobuf.InvalidProtocolBufferException {
          return new ProtobufSimple(input, extensionRegistry);
      }
    };

    public static com.google.protobuf.Parser<ProtobufSimple> parser() {
      return PARSER;
    }

    @java.lang.Override
    public com.google.protobuf.Parser<ProtobufSimple> getParserForType() {
      return PARSER;
    }

    public ProtobufSimpleOuterClass.ProtobufSimple getDefaultInstanceForType() {
      return DEFAULT_INSTANCE;
    }

  }

  private static final com.google.protobuf.Descriptors.Descriptor
    internal_static_ProtobufSimple_descriptor;
  private static final 
    com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
      internal_static_ProtobufSimple_fieldAccessorTable;

  public static com.google.protobuf.Descriptors.FileDescriptor
      getDescriptor() {
    return descriptor;
  }
  private static  com.google.protobuf.Descriptors.FileDescriptor
      descriptor;
  static {
    java.lang.String[] descriptorData = {
      "\n\025protobuf_simple.proto\":\n\016ProtobufSimpl" +
      "e\022\014\n\004name\030\001 \001(\t\022\r\n\005value\030\002 \001(\001\022\013\n\003arr\030\003 " +
      "\003(\005b\006proto3"
    };
    com.google.protobuf.Descriptors.FileDescriptor.InternalDescriptorAssigner assigner =
        new com.google.protobuf.Descriptors.FileDescriptor.    InternalDescriptorAssigner() {
          public com.google.protobuf.ExtensionRegistry assignDescriptors(
              com.google.protobuf.Descriptors.FileDescriptor root) {
            descriptor = root;
            return null;
          }
        };
    com.google.protobuf.Descriptors.FileDescriptor
      .internalBuildGeneratedFileFrom(descriptorData,
        new com.google.protobuf.Descriptors.FileDescriptor[] {
        }, assigner);
    internal_static_ProtobufSimple_descriptor =
      getDescriptor().getMessageTypes().get(0);
    internal_static_ProtobufSimple_fieldAccessorTable = new
      com.google.protobuf.GeneratedMessageV3.FieldAccessorTable(
        internal_static_ProtobufSimple_descriptor,
        new java.lang.String[] { "Name", "Value", "Arr", });
  }

  // @@protoc_insertion_point(outer_class_scope)
}