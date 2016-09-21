package rpg;

// Generated with https://github.com/paidgeek/bufobjects

import java.nio.*;
import java.nio.charset.Charset;

public class BufferObjectBuilder {

  public static final int MAX_VAR_INT32_BYTES = 5;
  public static final int MAX_VAR_INT64_BYTES = 10;
  private static final Charset CHARSET_UTF8 = Charset.forName("UTF-8");

  private ByteBuffer buffer;
  private int maxCapacity;

  public BufferObjectBuilder(int initialCapacity, int maxCapacity) {
    this.maxCapacity = maxCapacity;
    buffer = ByteBuffer.allocate(initialCapacity);
    buffer.order(ByteOrder.LITTLE_ENDIAN);
  }

  public BufferObjectBuilder() {
    this(1024, 8192);
  }

  public BufferObjectBuilder(ByteBuffer buffer) {
    this.buffer = buffer;
    buffer.clear();
    buffer.order(ByteOrder.LITTLE_ENDIAN);
    maxCapacity = buffer.capacity() << 3;
  }

  public void growBuffer(int reserve) {
    if (buffer.capacity() == maxCapacity) {
      throw new BufferOverflowException();
    }

    int newCapacity = Math.min(maxCapacity, Math
      .max(buffer.capacity() + reserve - buffer.remaining(), buffer.capacity() * 2));
    int pos = buffer.position();

    ByteBuffer newBuffer = ByteBuffer.allocate(newCapacity);
    newBuffer.order(ByteOrder.LITTLE_ENDIAN);

    buffer.rewind();
    newBuffer.put(buffer);
    newBuffer.position(pos);

    buffer = newBuffer;
  }

  public int getRemaining() {
    return buffer.remaining();
  }

  public void writeString(byte[] value) {
    writeVarUInt32(value.length);
    buffer.put(value);
  }

  public byte[] readString() {
    int length = readVarUInt32();
    byte[] value = new byte[length];
    buffer.get(value);
    return value;
  }

  public void writeVarInt32(int value) {
    writeVarUInt32((value << 1) ^ (value >> 31));
  }

  public void writeVarUInt32(int value) {
    do {
      int bits = value & 0x7F;
      value >>>= 7;
      buffer.put((byte) (bits + ((value != 0) ? 0x80 : 0)));
    } while (value != 0);
  }

  public int readVarInt32() {
    int uint = readVarUInt32();
    int tmp = (((uint << 31) >> 31) ^ uint) >> 1;
    return tmp ^ (uint & (1 << 31));
  }

  public int readVarUInt32() {
    int tmp = buffer.get();

    if (tmp >= 0) {
      return tmp;
    }

    int value = tmp & 0x7f;
    if ((tmp = buffer.get()) >= 0) {
      value |= tmp << 7;
    } else {
      value |= (tmp & 0x7f) << 7;
      if ((tmp = buffer.get()) >= 0) {
        value |= tmp << 14;
      } else {
        value |= (tmp & 0x7f) << 14;
        if ((tmp = buffer.get()) >= 0) {
          value |= tmp << 21;
        } else {
          value |= (tmp & 0x7f) << 21;
          value |= (tmp = buffer.get()) << 28;
          while (tmp < 0) {
            tmp = buffer.get();
          }
        }
      }
    }

    return value;
  }

  public void writeVarInt64(long value) {
    writeVarUInt64((value << 1) ^ (value >> 63));
  }

  public void writeVarUInt64(long value) {
    while (true) {
      int bits = ((int) value) & 0x7f;
      value >>>= 7;

      if (value == 0) {
        buffer.put((byte) bits);
        break;
      }

      buffer.put((byte) (bits | 0x80));
    }
  }

  public long readVarInt64() {
    long uint = readVarUInt64();
    long tmp = (((uint << 63) >> 63) ^ uint) >> 1;
    return tmp ^ (uint & (1L << 63));
  }

  public long readVarUInt64() {
    long tmp = buffer.get();

    if (tmp >= 0) {
      return tmp;
    }

    long value = tmp & 0x7f;
    if ((tmp = buffer.get()) >= 0) {
      value |= tmp << 7;
    } else {
      value |= (tmp & 0x7f) << 7;
      if ((tmp = buffer.get()) >= 0) {
        value |= tmp << 14;
      } else {
        value |= (tmp & 0x7f) << 14;
        if ((tmp = buffer.get()) >= 0) {
          value |= tmp << 21;
        } else {
          value |= (tmp & 0x7f) << 21;
          if ((tmp = buffer.get()) >= 0) {
            value |= tmp << 28;
          } else {
            value |= (tmp & 0x7f) << 28;
            if ((tmp = buffer.get()) >= 0) {
              value |= tmp << 35;
            } else {
              value |= (tmp & 0x7f) << 35;
              if ((tmp = buffer.get()) >= 0) {
                value |= tmp << 42;
              } else {
                value |= (tmp & 0x7f) << 42;
                if ((tmp = buffer.get()) >= 0) {
                  value |= tmp << 49;
                } else {
                  value |= (tmp & 0x7f) << 49;
                  if ((tmp = buffer.get()) >= 0) {
                    value |= tmp << 56;
                  } else {
                    value |= (tmp & 0x7f) << 56;
                    value |= ((long) buffer.get()) << 63;
                  }
                }
              }
            }
          }
        }
      }
    }

    return value;
  }

  public void writeBool(boolean value) {
    buffer.put((byte) (value ? 1 : 0));
  }

  public boolean readBool() {
    return buffer.get() == 1;
  }

  public void writeInt8(byte value) {
    buffer.put(value);
  }

  public void writeUInt8(byte value) {
    buffer.put(value);
  }

  public void writeInt16(short value) {
    buffer.putShort(value);
  }

  public void writeUInt16(short value) {
    buffer.putShort(value);
  }

  public void writeInt32(int value) {
    buffer.putInt(value);
  }

  public void writeUInt32(int value) {
    buffer.putInt(value);
  }

  public void writeInt64(long value) {
    buffer.putLong(value);
  }

  public void writeUInt64(long value) {
    buffer.putLong(value);
  }

  public void writeFloat32(float value) {
    buffer.putFloat(value);
  }

  public void writeFloat64(double value) {
    buffer.putDouble(value);
  }

  public byte readInt8() {
    return buffer.get();
  }

  public byte readUInt8() {
    return buffer.get();
  }

  public short readInt16() {
    return buffer.getShort();
  }

  public short readUInt16() {
    return buffer.getShort();
  }

  public int readInt32() {
    return buffer.getInt();
  }

  public int readUInt32() {
    return buffer.getInt();
  }

  public long readInt64() {
    return buffer.getLong();
  }

  public long readUInt64() {
    return buffer.getLong();
  }

  public float readFloat32() {
    return buffer.getFloat();
  }

  public double readFloat64() {
    return buffer.getDouble();
  }

  public void rewind() {
    buffer.rewind();
  }

  public int getOffset() {
    return buffer.position();
  }

  public int getCapacity() {
    return buffer.capacity();
  }

  public ByteBuffer getBuffer() {
    return buffer;
  }

  public byte[] getData() {
    return buffer.array();
  }

  public static int getVarInt32Size(int value) {
    return getVarUInt32Size((value << 1) ^ (value >> 31));
  }

  public static int getVarUInt32Size(int value) {
    int size = 0;

    do {
      size++;
      value >>>= 7;
    } while (value != 0);

    return size;
  }

  public static int getVarInt64Size(long value) {
    return getVarUInt64Size((value << 1) ^ (value >> 63));
  }

  public static int getVarUInt64Size(long value) {
    int size = 0;

    do {
      size++;
      value >>>= 7;
    } while (value != 0);

    return size;
  }

  public static int getStringSize(byte[] value) {
    if (value == null) {
      return 1;
    }
    return value.length + getVarUInt32Size(value.length);
  }

  public static byte[] getStringBytes(String value) {
    if(value == null) {
      return new byte[0];
    }
    return value.getBytes(CHARSET_UTF8);
  }

  public static String getStringFromBytes(byte[] value) {
    if (value == null) {
      return "";
    }
    return new String(value, 0, value.length, CHARSET_UTF8);
  }

}