#ifndef BUFOBJECTS_BUFOBJECTS_UTIL_H
#define BUFOBJECTS_BUFOBJECTS_UTIL_H

#include <iostream>
#include <cstdint>
#include <string>
#include <cstring>
#include <vector>
#include <array>

#ifdef _MSC_VER
#define BUFOBJECTS_LITTLE_ENDIAN 1
#if _MSC_VER >= 1300 && !defined(__INTEL_COMPILER)
#pragma runtime_checks("c", off)
#endif
#else

#include <sys/param.h>

#if ((defined(__LITTLE_ENDIAN__) && !defined(__BIG_ENDIAN__)) || \
         (defined(__BYTE_ORDER) && __BYTE_ORDER == __LITTLE_ENDIAN))
#define BUFOBJECTS_LITTLE_ENDIAN 1
#endif
#endif

namespace bufobjects {

  inline uint8_t *WriteBool(bool value, uint8_t *buf) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
    memcpy(buf, &value, sizeof(value));
#else
    buf[0] = static_cast<uint8_t>(value);
#endif
    return buf + sizeof(value);
  }

  inline uint8_t *WriteInt8(int8_t value, uint8_t *buf) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
    memcpy(buf, &value, sizeof(value));
#else
    buf[0] = static_cast<uint8_t>(value);
#endif
    return buf + sizeof(value);
  }

  inline uint8_t *WriteInt16(int16_t value, uint8_t *buf) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
    memcpy(buf, &value, sizeof(value));
#else
    buf[0] = static_cast<uint8_t>(value);
    buf[1] = static_cast<uint8_t>(value >> 8);
#endif
    return buf + sizeof(value);
  }

  inline uint8_t *WriteInt32(int32_t value, uint8_t *buf) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
    memcpy(buf, &value, sizeof(value));
#else
    buf[0] = static_cast<uint8_t>(value);
    buf[1] = static_cast<uint8_t>(value >> 8);
    buf[2] = static_cast<uint8_t>(value >> 16);
    buf[3] = static_cast<uint8_t>(value >> 24);
#endif
    return buf + sizeof(value);
  }

  inline uint8_t *WriteInt64(int64_t value, uint8_t *buf) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
    memcpy(buf, &value, sizeof(value));
#else
    buf[0] = static_cast<uint8_t>(value);
    buf[1] = static_cast<uint8_t>(value >> 8);
    buf[2] = static_cast<uint8_t>(value >> 16);
    buf[3] = static_cast<uint8_t>(value >> 24);
    buf[4] = static_cast<uint8_t>(value >> 32);
    buf[5] = static_cast<uint8_t>(value >> 40);
    buf[6] = static_cast<uint8_t>(value >> 48);
    buf[7] = static_cast<uint8_t>(value >> 56);
#endif
    return buf + sizeof(value);
  }

  inline uint8_t *WriteUInt8(uint8_t value, uint8_t *buf) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
    memcpy(buf, &value, sizeof(value));
#else
    buf[0] = static_cast<uint8_t>(value);
#endif
    return buf + sizeof(value);
  }

  inline uint8_t *WriteUInt16(uint16_t value, uint8_t *buf) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
    memcpy(buf, &value, sizeof(value));
#else
    buf[0] = static_cast<uint8_t>(value);
    buf[1] = static_cast<uint8_t>(value >> 8);
#endif
    return buf + sizeof(value);
  }

  inline uint8_t *WriteUInt32(uint32_t value, uint8_t *buf) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
    memcpy(buf, &value, sizeof(value));
#else
    buf[0] = static_cast<uint8_t>(value);
    buf[1] = static_cast<uint8_t>(value >> 8);
    buf[2] = static_cast<uint8_t>(value >> 16);
    buf[3] = static_cast<uint8_t>(value >> 24);
#endif
    return buf + sizeof(value);
  }

  inline uint8_t *WriteUInt64(uint64_t value, uint8_t *buf) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
    memcpy(buf, &value, sizeof(value));
#else
    buf[0] = static_cast<uint8_t>(value);
    buf[1] = static_cast<uint8_t>(value >> 8);
    buf[2] = static_cast<uint8_t>(value >> 16);
    buf[3] = static_cast<uint8_t>(value >> 24);
    buf[4] = static_cast<uint8_t>(value >> 32);
    buf[5] = static_cast<uint8_t>(value >> 40);
    buf[6] = static_cast<uint8_t>(value >> 48);
    buf[7] = static_cast<uint8_t>(value >> 56);
#endif
    return buf + sizeof(value);
  }

  inline uint8_t *ReadBool(bool *value, uint8_t *buf) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
    memcpy(value, buf, sizeof(*value));
#else
    *value = static_cast<bool>(*buf);
#endif
    return buf + sizeof(*value);
  }

  inline uint8_t *ReadInt8(int8_t *value, uint8_t *buf) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
    memcpy(value, buf, sizeof(*value));
#else
    *value = static_cast<int8_t>(*buf);
#endif
    return buf + sizeof(*value);
  }

  inline uint8_t *ReadInt16(int16_t *value, uint8_t *buf) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
    memcpy(value, buf, sizeof(*value));
#else
    *value = (static_cast<int16_t>(buf[0])) |
             (static_cast<int16_t>(buf[1]) << 8);
#endif
    return buf + sizeof(*value);
  }

  inline uint8_t *ReadInt32(int32_t *value, uint8_t *buf) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
    memcpy(value, buf, sizeof(*value));
#else
    *value = (static_cast<int32_t>(buf[0])) |
             (static_cast<int32_t>(buf[1]) << 8) |
             (static_cast<int32_t>(buf[2]) << 16) |
             (static_cast<int32_t>(buf[3]) << 24);
#endif
    return buf + sizeof(*value);
  }

  inline uint8_t *ReadInt64(int64_t *value, uint8_t *buf) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
    memcpy(value, buf, sizeof(*value));
#else
    *value = (static_cast<int64_t>(buf[0])) |
             (static_cast<int64_t>(buf[1]) << 8) |
             (static_cast<int64_t>(buf[2]) << 16) |
             (static_cast<int64_t>(buf[3]) << 24) |
             (static_cast<int64_t>(buf[4]) << 32) |
             (static_cast<int64_t>(buf[5]) << 40) |
             (static_cast<int64_t>(buf[6]) << 48) |
             (static_cast<int64_t>(buf[7]) << 56);
#endif
    return buf + sizeof(*value);
  }

  inline uint8_t *ReadUInt8(uint8_t *value, uint8_t *buf) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
    memcpy(value, buf, sizeof(*value));
#else
    *value = static_cast<int8_t>(*buf);
#endif
    return buf + sizeof(*value);
  }

  inline uint8_t *ReadUInt16(uint16_t *value, uint8_t *buf) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
    memcpy(value, buf, sizeof(*value));
#else
    *value = (static_cast<uint16_t>(buf[0])) |
             (static_cast<uint16_t>(buf[1])  << 8);
#endif
    return buf + sizeof(*value);
  }

  inline uint8_t *ReadUInt32(uint32_t *value, uint8_t *buf) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
    memcpy(value, buf, sizeof(*value));
#else
    *value = (static_cast<uint32_t>(buf[0])) |
             (static_cast<uint32_t>(buf[1]) << 8) |
             (static_cast<uint32_t>(buf[2]) << 16) |
             (static_cast<uint32_t>(buf[3]) << 24);
#endif
    return buf + sizeof(*value);
  }

  inline uint8_t *ReadUInt64(uint64_t *value, uint8_t *buf) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
    memcpy(value, buf, sizeof(*value));
#else
    *value = (static_cast<uint64_t>(buf[0])) |
             (static_cast<uint64_t>(buf[1]) << 8) |
             (static_cast<uint64_t>(buf[2]) << 16) |
             (static_cast<uint64_t>(buf[3]) << 24) |
             (static_cast<uint64_t>(buf[4]) << 32) |
             (static_cast<uint64_t>(buf[5]) << 40) |
             (static_cast<uint64_t>(buf[6]) << 48) |
             (static_cast<uint64_t>(buf[7]) << 56);
#endif
    return buf + sizeof(*value);
  }

  inline uint8_t *WriteVarUInt32(uint32_t value, uint8_t *buf) {
    buf[0] = static_cast<uint8_t >(value | 0x80);
    if (value >= (1 << 7)) {
      buf[1] = static_cast<uint8_t >((value >> 7) | 0x80);
      if (value >= (1 << 14)) {
        buf[2] = static_cast<uint8_t >((value >> 14) | 0x80);
        if (value >= (1 << 21)) {
          buf[3] = static_cast<uint8_t >((value >> 21) | 0x80);
          if (value >= (1 << 28)) {
            buf[4] = static_cast<uint8_t >(value >> 28);
            return buf + 5;
          } else {
            buf[3] &= 0x7F;
            return buf + 4;
          }
        } else {
          buf[2] &= 0x7F;
          return buf + 3;
        }
      } else {
        buf[1] &= 0x7F;
        return buf + 2;
      }
    } else {
      buf[0] &= 0x7F;
      return buf + 1;
    }

    return buf;
  }

  inline uint8_t *ReadVarUInt32(uint32_t *value, uint8_t *buf) {
    uint32_t b;
    uint32_t result = 0;

    b = *buf++;
    result = b & 0x7F;
    if (!(b & 0x80)) {
      *value = result;
      return buf;
    }
    b = *buf++;
    result |= (b & 0x7F) << 7;
    if (!(b & 0x80)) {
      *value = result;
      return buf;
    }
    b = *buf++;
    result |= (b & 0x7F) << 14;
    if (!(b & 0x80)) {
      *value = result;
      return buf;
    }
    b = *buf++;
    result |= (b & 0x7F) << 21;
    if (!(b & 0x80)) {
      *value = result;
      return buf;
    }
    b = *buf++;
    result |= (b & 0x7F) << 28;
    if (!(b & 0x80)) {
      *value = result;
      return buf;
    }

    for (int i = 0; i < 5; i++) {
      b = *buf++;
      if (!(b & 0x80)) {
        break;
      }
    }

    *value = result;
    return buf;
  }

  inline uint8_t *WriteVarInt32(int32_t value, uint8_t *buf) {
    uint32_t uvalue = static_cast<uint32_t>((value << 1) ^ (value >> 31));
    return WriteVarUInt32(uvalue, buf);
  }

  inline uint8_t *ReadVarInt32(int32_t *value, uint8_t *buf) {
    uint32_t result;
    buf = ReadVarUInt32(&result, buf);
    *value = (result >> 1) ^ -(static_cast<int32_t> (result & 1));
    return buf;
  }

  inline uint8_t *WriteVarUInt64(uint64_t value, uint8_t *buf) {
    uint32_t part0 = static_cast<uint32_t>(value);
    uint32_t part1 = static_cast<uint32_t>(value >> 28);
    uint32_t part2 = static_cast<uint32_t>(value >> 56);

    int size;
    if (part2 == 0) {
      if (part1 == 0) {
        if (part0 < (1 << 14)) {
          if (part0 < (1 << 7)) {
            size = 1;
            goto size1;
          } else {
            size = 2;
            goto size2;
          }
        } else {
          if (part0 < (1 << 21)) {
            size = 3;
            goto size3;
          } else {
            size = 4;
            goto size4;
          }
        }
      } else {
        if (part1 < (1 << 14)) {
          if (part1 < (1 << 7)) {
            size = 5;
            goto size5;
          } else {
            size = 6;
            goto size6;
          }
        } else {
          if (part1 < (1 << 21)) {
            size = 7;
            goto size7;
          } else {
            size = 8;
            goto size8;
          }
        }
      }
    } else {
      if (part2 < (1 << 7)) {
        size = 9;
        goto size9;
      } else {
        size = 10;
        goto size10;
      }
    }

    size10:
    buf[9] = static_cast<uint8_t>((part2 >> 7) | 0x80);
    size9 :
    buf[8] = static_cast<uint8_t>((part2) | 0x80);
    size8 :
    buf[7] = static_cast<uint8_t>((part1 >> 21) | 0x80);
    size7 :
    buf[6] = static_cast<uint8_t>((part1 >> 14) | 0x80);
    size6 :
    buf[5] = static_cast<uint8_t>((part1 >> 7) | 0x80);
    size5 :
    buf[4] = static_cast<uint8_t>((part1) | 0x80);
    size4 :
    buf[3] = static_cast<uint8_t>((part0 >> 21) | 0x80);
    size3 :
    buf[2] = static_cast<uint8_t>((part0 >> 14) | 0x80);
    size2 :
    buf[1] = static_cast<uint8_t>((part0 >> 7) | 0x80);
    size1 :
    buf[0] = static_cast<uint8_t>((part0) | 0x80);
    buf[size - 1] &= 0x7F;
    return buf + size;
  }

  inline uint8_t *ReadVarUInt64(uint64_t *value, uint8_t *buf) {
    uint64_t b;
    uint32_t part0 = 0, part1 = 0, part2 = 0;

    b = *buf++;
    part0 = static_cast<uint32_t>(b & 0x7F);
    if (!(b & 0x80)) {
      goto done;
    }
    b = *buf++;
    part0 |= static_cast<uint32_t>(b & 0x7F) << 7;
    if (!(b & 0x80)) {
      goto done;
    }
    b = *buf++;
    part0 |= static_cast<uint32_t>(b & 0x7F) << 14;
    if (!(b & 0x80)) {
      goto done;
    }
    b = *buf++;
    part0 |= static_cast<uint32_t>(b & 0x7F) << 21;
    if (!(b & 0x80)) {
      goto done;
    }
    b = *buf++;
    part1 = static_cast<uint32_t>(b & 0x7F);
    if (!(b & 0x80)) {
      goto done;
    }
    b = *buf++;
    part1 |= static_cast<uint32_t>(b & 0x7F) << 7;
    if (!(b & 0x80)) {
      goto done;
    }
    b = *buf++;
    part1 |= static_cast<uint32_t>(b & 0x7F) << 14;
    if (!(b & 0x80)) {
      goto done;
    }
    b = *buf++;
    part1 |= static_cast<uint32_t>(b & 0x7F) << 21;
    if (!(b & 0x80)) {
      goto done;
    }
    b = *buf++;
    part2 = static_cast<uint32_t>(b & 0x7F);
    if (!(b & 0x80)) {
      goto done;
    }
    b = *buf++;
    part2 |= static_cast<uint32_t>(b & 0x7F) << 7;
    if (!(b & 0x80)) {
      goto done;
    }

    done:
    *value = part0 | (static_cast<uint64_t>(part1) << 28) | (static_cast<uint64_t>(part2) << 56);
    return buf;
  }

  inline uint8_t *WriteVarInt64(int64_t value, uint8_t *buf) {
    uint64_t uvalue = static_cast<uint64_t>((value << 1) ^ (value >> 63));
    return WriteVarUInt64(uvalue, buf);
  }

  inline uint8_t *ReadVarInt64(int64_t *value, uint8_t *buf) {
    uint64_t result;
    buf = ReadVarUInt64(&result, buf);
    *value = (result >> 1) ^ -(static_cast<int64_t> (result & 1));
    return buf;
  }

  inline uint8_t *WriteFloat32(float value, uint8_t *buf) {
    memcpy(buf, &value, sizeof(value));
    return buf + sizeof(value);
  }

  inline uint8_t *WriteFloat64(double value, uint8_t *buf) {
    memcpy(buf, &value, sizeof(value));
    return buf + sizeof(value);
  }

  inline uint8_t *ReadFloat32(float *value, uint8_t *buf) {
    memcpy(value, buf, sizeof(*value));
    return buf + sizeof(*value);
  }

  inline uint8_t *ReadFloat64(double *value, uint8_t *buf) {
    memcpy(value, buf, sizeof(*value));
    return buf + sizeof(*value);
  }

  inline uint8_t *WriteString(const std::string &value, uint8_t *buf) {
    uint32_t len = static_cast<uint32_t>(value.length());
    buf = WriteVarUInt32(len, buf);
    memcpy(buf, value.data(), len);
    return buf + len;
  }

  inline uint8_t *ReadString(std::string *value, uint8_t *buf) {
    uint32_t len = 0;
    buf = ReadVarUInt32(&len, buf);
    char *data = new char[len + 1];
    data[len] = '\0';
    memcpy(data, buf, len);
    *value = std::string(data);
    delete[](data);
    return buf + len;
  }

  struct BufferObject {
    virtual uint32_t GetBufferObjectId() const = 0;
    virtual uint8_t *WriteTo(uint8_t *buf) = 0;
    virtual uint8_t *ReadFrom(uint8_t *buf) = 0;
    virtual void Reset() = 0;
  };

}

#endif
