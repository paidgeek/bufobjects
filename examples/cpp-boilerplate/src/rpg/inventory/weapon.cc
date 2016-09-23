// Generated with https://github.com/paidgeek/bufobjects

#include "weapon.h"

#include "../../rpg/inventory/quality.h";
#include "../../rpg/inventory/item.h";

namespace rpg {

  namespace inventory {

    Weapon::Weapon() {
      Reset();
    }

    Weapon::Weapon(uint64_t damage, std::string name, uint8_t quality, uint64_t cost)
      : damage_(damage), name_(name), quality_(quality), cost_(cost) {}

    void Weapon::Init(uint64_t damage, std::string name, uint8_t quality, uint64_t cost) {
      damage_ = damage;
      name_ = name;
      quality_ = quality;
      cost_ = cost;
    }

    Weapon::Weapon(const Weapon &from) {
      from.CopyTo(*this);
    }

    Weapon &Weapon::operator=(const Weapon &from) {
      from.CopyTo(*this);
      return *this;
    }

    uint16_t Weapon::BufferObjectId() const {
      return bufobjects::BufferObject::kRpgInventoryWeaponId;
    }

    void Weapon::Reset() {
      super.Reset();
      damage_ = 0;

    }

    void Weapon::CopyTo(bufobjects::BufferObject &obj) const {
      Weapon &dst = static_cast< Weapon & >(obj);

      dst.damage_ = damage_;
      dst.name_ = name_;
      dst.quality_ = quality_;
      dst.cost_ = cost_;
    }

    uint32_t Weapon::Size() const {
      uint32_t size = super.size();

      size += 8; // size for "u64"

      return size;
    }

    void Weapon::WriteTo(bufobjects::BufferObjectBuilder &bob) const {
      uint32_t needed = Size();
      if (bob.GetRemaining() < needed) {
        bob.GrowBuffer(needed);
      }
      {
        bob.WriteUInt64(damage_);

      }
      {
        bob.WriteString(name_);

      }
      {
        bob.WriteUInt8(quality_);

      }
      {
        bob.WriteUInt64(cost_);

      }
    }

    void Weapon::ReadFrom(bufobjects::BufferObjectBuilder &bob) {
      {
        damage_ = bob.ReadUInt64();

      }
      {
        name_ = bob.ReadString();

      }
      {
        quality_ = bob.ReadUInt8();

      }
      {
        cost_ = bob.ReadUInt64();

      }
    }
    const uint64_t &Weapon::GetDamage() const {
      return damage_;
    }

    void Weapon::SetDamage(const uint64_t &damage) {
      damage_ = damage;
    }

  }

}