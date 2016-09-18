#ifndef BUFFER_OBJECTS_H
#define BUFFER_OBJECTS_H

#include <iostream>
#include <cstdint>
#include <string>
#include <vector>

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

  inline uint8_t *WriteFloat32(float value, uint8_t *buf) {
    memcpy(buf, &value, sizeof(value));
    return buf + sizeof(value);
  }

  inline uint8_t *WriteFloat64(double value, uint8_t *buf) {
    memcpy(buf, &value, sizeof(value));
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

  inline uint8_t *WriteString(const std::string& value, uint8_t *buf) {
    memcpy(buf, value.data(), value.length());
    return buf + value.length();
  }

  inline uint8_t *ReadString(const std::string* value, uint8_t *buf) {
  }

  enum {
    kSimpleId = 1
  };

}

#endif
