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

    std::map<Quality, std::string> QualityNames = {
      {Quality::kCommon, "Common"},
      {Quality::kRare,   "Rare"},
      {Quality::kEpic,   "Epic"}
    };

  }

}

#endif