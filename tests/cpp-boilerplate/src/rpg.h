#ifndef BUFOBJECTS_RPG_H
#define BUFOBJECTS_RPG_H

#include "bufobjects_util.h"

namespace rpg {
  struct Simple : bufobjects::BufferObject {
    std::string name;
    double value;
    std::vector<int32_t> list;
    std::array<float, 5> arr;
    static const int32_t kArrLength = 5;

    Simple() {
      Reset();
    }

    Simple(std::string name,
           double value,
           std::vector<int32_t> list,
           std::array<float, 5> arr)
      : name(name),
        value(value),
        list(list),
        arr(arr) {}

    inline uint32_t GetBufferObjectId() const {
      return 1;
    }

    inline uint8_t *WriteTo(uint8_t *buf) {
      buf = bufobjects::WriteString(this->name, buf);
      buf = bufobjects::WriteFloat64(this->value, buf);
      {
        int32_t size = static_cast<int32_t>(list.size());
        buf = bufobjects::WriteVarInt32(size, buf);
        for (int32_t i = 0; i < size; i++) {
          buf = bufobjects::WriteInt32(this->list[i], buf);
        }
      }
      {
        for (int32_t i = 0; i < kArrLength; i++) {
          buf = bufobjects::WriteFloat32(this->arr[i], buf);
        }
      }
      return buf;
    }

    inline uint8_t *ReadFrom(uint8_t *buf) {
      buf = bufobjects::ReadString(&this->name, buf);
      buf = bufobjects::ReadFloat64(&this->value, buf);
      {
        int32_t size;
        buf = bufobjects::ReadVarInt32(&size, buf);
        this->list.clear();
        this->list.reserve(static_cast<uint32_t>(size));
        int32_t e;
        while (size--) {
          buf = bufobjects::ReadInt32(&e, buf);
          this->list.push_back(e);
        }
      }
      {
        for (int32_t i = 0; i < kArrLength; i++) {
          buf = bufobjects::ReadFloat32(&this->arr[i], buf);
        }
      }
      return buf;
    }

    inline void Reset() {
      this->name = "";
      this->value = 0.0;
      this->list.clear();
      for (int32_t i = 0; i < kArrLength; i++) {
        this->arr[i] = 0.0f;
      }
    }
  };
}

#endif
