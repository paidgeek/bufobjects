package com.moybl.bufobjects;

public class BufferUtil {

  public static final int MAX_VAR_INT_BYTES = 5;
  public static final int MAX_VAR_LONG_BYTES = 10;

  public static int getVarIntSize(int value) {
    int size = 0;

    do {
      size++;
      value >>>= 7;
    } while (value != 0);

    return size;
  }

  public static long getVarLongSize(long value) {
    int size = 0;
    do {
      size++;
      value >>>= 7;
    } while (value != 0);

    return size;
  }

  public static int writeVarInt(int value, byte[] b, int off) {
    do {
      int bits = value & 0x7F;
      value >>>= 7;
      b[off++] = (byte) (bits + ((value != 0) ? 0x80 : 0));
    } while (value != 0);

    return off;
  }

  public static int writeVarLong(long value, byte[] b, int off) {
    while (true) {
      int bits = ((int) value) & 0x7f;
      value >>>= 7;

      if (value == 0) {
        b[off++] = (byte) bits;
        break;
      }

      b[off++] = (byte) (bits | 0x80);
    }

    return off;
  }

  public static int readVarInt(byte[] b, int off, int[] dst) {
    int tmp = b[off++];

    if (tmp >= 0) {
      dst[0] = tmp;
      return off;
    }

    int value = tmp & 0x7f;
    if ((tmp = b[off++]) >= 0) {
      value |= tmp << 7;
    } else {
      value |= (tmp & 0x7f) << 7;
      if ((tmp = b[off++]) >= 0) {
        value |= tmp << 14;
      } else {
        value |= (tmp & 0x7f) << 14;
        if ((tmp = b[off++]) >= 0) {
          value |= tmp << 21;
        } else {
          value |= (tmp & 0x7f) << 21;
          value |= (tmp = b[off++]) << 28;
          while (tmp < 0) {
            tmp = b[off++];
          }
        }
      }
    }

    dst[0] = value;
    return off;
  }

  public static int readVarLong(byte[] b, int off, long[] dst) {
    long tmp = b[off++];

    if (tmp >= 0) {
      dst[0] = tmp;
      return off;
    }

    long value = tmp & 0x7f;
    if ((tmp = b[off++]) >= 0) {
      value |= tmp << 7;
    } else {
      value |= (tmp & 0x7f) << 7;
      if ((tmp = b[off++]) >= 0) {
        value |= tmp << 14;
      } else {
        value |= (tmp & 0x7f) << 14;
        if ((tmp = b[off++]) >= 0) {
          value |= tmp << 21;
        } else {
          value |= (tmp & 0x7f) << 21;
          if ((tmp = b[off++]) >= 0) {
            value |= tmp << 28;
          } else {
            value |= (tmp & 0x7f) << 28;
            if ((tmp = b[off++]) >= 0) {
              value |= tmp << 35;
            } else {
              value |= (tmp & 0x7f) << 35;
              if ((tmp = b[off++]) >= 0) {
                value |= tmp << 42;
              } else {
                value |= (tmp & 0x7f) << 42;
                if ((tmp = b[off++]) >= 0) {
                  value |= tmp << 49;
                } else {
                  value |= (tmp & 0x7f) << 49;
                  if ((tmp = b[off++]) >= 0) {
                    value |= tmp << 56;
                  } else {
                    value |= (tmp & 0x7f) << 56;
                    value |= ((long) b[off++]) << 63;
                  }
                }
              }
            }
          }
        }
      }
    }

    dst[0] = value;
    return off;
  }

}
