#ifndef BUFOBJECTS_JSON_BUILDER_H
#define BUFOBJECTS_JSON_BUILDER_H

#include <iostream>

namespace bufobjects {
  class JsonBuilder {
  public:
    static inline void BeginObject(std::ostream &out) {
      out << "{";
    }
    static inline void EndObject(std::ostream &out) {
      out << "}";
    }

    static inline void WriteInt8(std::ostream& out, const char* name, const int8_t value) {
      out << "\"" << name << "\":" << value;
    }
    static inline void WriteInt16(std::ostream& out, const char* name, const int16_t value) {
      out << "\"" << name << "\":" << value;
    }
    static inline void WriteInt32(std::ostream& out, const char* name, const int32_t value) {
      out << "\"" << name << "\":" << value;
    }
    static inline void WriteInt64(std::ostream& out, const char* name, const int64_t value) {
      out << "\"" << name << "\":\"" << value << "\"";
    }
    static inline void WriteUInt8(std::ostream& out, const char* name, const uint8_t value) {
      out << "\"" << name << "\":" << value;
    }
    static inline void WriteUInt16(std::ostream& out, const char* name, const uint16_t value) {
      out << "\"" << name << "\":" << value;
    }
    static inline void WriteUInt32(std::ostream& out, const char* name, const uint32_t value) {
      out << "\"" << name << "\":" << value;
    }
    static inline void WriteUInt64(std::ostream& out, const char* name, const uint64_t value) {
      out << "\"" << name << "\":\"" << value << "\"";
    }
    static inline void WriteString(std::ostream& out, const char* name, const std::string value) {
      out << "\"" << name << "\":\"" << value << "\"";
    }
  };
}

#endif
