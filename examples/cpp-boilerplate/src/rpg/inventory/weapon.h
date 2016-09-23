// Generated with https://github.com/paidgeek/bufobjects
#ifndef RPG_INVENTORY_WEAPON_H
#define RPG_INVENTORY_WEAPON_H

#include "../../buffer_object.h"

namespace rpg { namespace inventory { enum class Quality; }}
namespace rpg { namespace inventory { class Item; }}

namespace rpg {

  namespace inventory {

    class Weapon
      : public rpg::inventory::Item {

    protected:
      uint64_t damage_;

    public:

      Weapon();
      Weapon(uint64_t damage, std::string name, uint8_t quality, uint64_t cost);
      void Init(uint64_t damage, std::string name, uint8_t quality, uint64_t cost);
      Weapon(const Weapon &from);
      Weapon &operator=(const Weapon &from);
      uint16_t BufferObjectId() const override;
      void Reset() override;
      void CopyTo(bufobjects::BufferObject &obj) const override;
      uint32_t Size() const override;
      void WriteTo(bufobjects::BufferObjectBuilder &bob) const override;
      void ReadFrom(bufobjects::BufferObjectBuilder &bob) override;
      const uint64_t &GetDamage() const;
      void SetDamage(const uint64_t &damage);

    };

  }

}

#endif