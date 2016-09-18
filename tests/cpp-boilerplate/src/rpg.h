#ifndef BUFOBJECTS_RPG_H
#define BUFOBJECTS_RPG_H

#include "buffer_objects.h"

namespace rpg {
  struct Simple {
    std::string name;
    double value;
    std::vector<int32_t> arr;

    Simple() {
      Reset();
    }

    Simple(std::string name, double value, std::vector<int32_t> arr)
      : name(name),
        value(value),
        arr(arr) {}

    inline uint8_t *WriteTo(uint8_t *buf) {

    }

    inline uint8_t *ReadFrom(uint8_t *buf) {

    }

    inline void Reset() {
      name = "";
      value = 0.0;
      arr.clear();
    }
  };
}

#endif
