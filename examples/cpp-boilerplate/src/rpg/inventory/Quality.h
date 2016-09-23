// Generated with https://github.com/paidgeek/bufobjects
#ifndef RPG_INVENTORY_QUALITY_H
#define RPG_INVENTORY_QUALITY_H

#include <cstdint>
#include <string>
#include <map>

namespace rpg {

  namespace inventory {

    enum class Quality : uint8_t {
      kCommon = 1, kRare = 2, kEpic = 3
    };

    namespace Quality {
      std::string GetName(Quality value) {
        switch (value) {
          case Quality::kCommon:
            return "Common";
          case Quality::kRare:
            return "Rare";
          case Quality::kEpic:
            return "Epic";
        }
      }
    }

  }

}

#endif