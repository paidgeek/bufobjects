// Generated with https://github.com/paidgeek/bufobjects
#ifndef RPG_INVENTORY_ITEM_H
#define RPG_INVENTORY_ITEM_H

#include "../../buffer_object.h"

namespace rpg {

  namespace inventory {

    class Item
      : public bufobjects::BufferObject {

    protected:
      std::string name_;
      uint8_t quality_;
      uint64_t cost_;

    public:

      uint32_t Size() const override;
      void Reset() override;

      const std::string &GetName() const;
      void SetName(const std::string &name);
      const uint8_t &GetQuality() const;
      void SetQuality(const uint8_t &quality);
      const uint64_t &GetCost() const;
      void SetCost(const uint64_t &cost);

    };

  }

}

#endif