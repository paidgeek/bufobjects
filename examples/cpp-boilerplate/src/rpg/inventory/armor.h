// Generated with https://github.com/paidgeek/bufobjects
#ifndef RPG_INVENTORY_ARMOR_H
#define RPG_INVENTORY_ARMOR_H

#include "../../buffer_object.h"

namespace rpg { namespace inventory { enum class Quality; }}
namespace rpg { namespace inventory { class Item; }}

namespace rpg {

  namespace inventory {

    class Armor
      : public rpg::inventory::Item {

    protected:
      uint64_t defense_;

    public:

      Armor();
      Armor(uint64_t defense, std::string name, uint8_t quality, uint64_t cost);
      void Init(uint64_t defense, std::string name, uint8_t quality, uint64_t cost);
      Armor(const Armor &from);
      Armor &operator=(const Armor &from);
      uint16_t BufferObjectId() const override;
      void Reset() override;
      void CopyTo(bufobjects::BufferObject &obj) const override;
      uint32_t Size() const override;
      void WriteTo(bufobjects::BufferObjectBuilder &bob) const override;
      void ReadFrom(bufobjects::BufferObjectBuilder &bob) override;
      const uint64_t &GetDefense() const;
      void SetDefense(const uint64_t &defense);

    };

  }

}

#endif