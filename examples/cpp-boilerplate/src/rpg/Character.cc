// Generated with https://github.com/paidgeek/bufobjects

#include "character.h"

#include "../rpg/inventory/item.h";

namespace rpg {

  Character::Character() {
    Reset();
  }

  Character::Character(std::string name, float speed, rpg::inventory::Item &main_hand,
                       std::array<double, 8> buffs)
    : name_(name), speed_(speed), main_hand_(main_hand), buffs_(buffs) {}

  void Character::Init(std::string name, float speed, rpg::inventory::Item &main_hand,
                       std::array<double, 8> buffs) {
    name_ = name;
    speed_ = speed;
    main_hand_ = main_hand;
    buffs_ = buffs;
  }

  Character::Character(const Character &from) {
    from.CopyTo(*this);
  }

  Character &Character::operator=(const Character &from) {
    from.CopyTo(*this);
    return *this;
  }

  uint16_t Character::BufferObjectId() const {
    return bufobjects::BufferObject::kRpgCharacterId;
  }

  void Character::Reset() {
    name_ = std::string{};
    speed_ = 0.0f;
    main_hand_ = nullptr;
    buffs_ = std::array<double, 8>{};

  }

  void Character::CopyTo(bufobjects::BufferObject &obj) const {
    Character &dst = static_cast< Character & >(obj);

    dst.name_ = name_;
    dst.speed_ = speed_;
    if (main_hand_ != nullptr) {
      main_hand_.CopyTo(dst.main_hand_);
    }
    dst.buffs_ = std::array<double, 8>(buffs_);
  }

  uint32_t Character::Size() const {
    uint32_t size = 0;

    size += bufobjects::BufferObjectBuilder::GetStringSize(name_);
    size += 4; // size for "f32"

    size += 1; // +1 for "is null" byte
    if (main_hand_ != nullptr) {
      size += this.main_hand.size();
      // this comment seems to fix a jtwig bug "true"


      size += 2; // size of bufferObjectId


    }
    size += kBuffsLength * 8;

    return size;
  }

  void Character::WriteTo(bufobjects::BufferObjectBuilder &bob) const {
    uint32_t needed = Size();
    if (bob.GetRemaining() < needed) {
      bob.GrowBuffer(needed);
    }
    {
      bob.WriteString(name_);

    }
    {
      bob.WriteFloat32(speed_);

    }
    {
      if (main_hand_ == null) {
        bob.WriteUInt8((byte) 0x80);
      } else {
        bob.WriteUInt8((byte) 0x81);
        // this comment seems to fix a jtwig bug true

        bob.WriteUInt16(main_hand_.bufferObjectId());

        main_hand_.writeTo(bob);
      }

    }
    {
      for (uint32_t i = 0; i < kBuffsLength; i++) {
        bob.WriteFloat64(buffs_[i]);
      }
    }
  }

  void Character::ReadFrom(bufobjects::BufferObjectBuilder &bob) {
    {
      name_ = bob.ReadString();

    }
    {
      speed_ = bob.ReadFloat32();

    }
    {
      // this comment seems to fix a jtwig bug "true"

      if (bob.readUInt8() == (byte) 0x81) {
        uint16_t id = bob.ReadUInt16();
        switch (id) {
          case kRpgInventoryWeaponId:
            main_hand_ = new rpg::inventory::Weapon();
            break;
          case kRpgInventoryArmorId:
            main_hand_ = new rpg::inventory::Armor();
            break;
        }
        main_hand_.ReadFrom(bob);
      } else {
        main_hand_ = null;
      }

    }
    {
      for (uint32_t i = 0; i < kBuffsLength; i++) {
        buffs_[i] = bob.ReadFloat64();
      }
    }
  }
  const std::string &Character::GetName() const {
    return name_;
  }

  void Character::SetName(const std::string &name) {
    name_ = name;
  }

  const float &Character::GetSpeed() const {
    return speed_;
  }

  void Character::SetSpeed(const float &speed) {
    speed_ = speed;
  }

  const rpg::inventory::Item &Character::GetMainHand() const {
    return main_hand_;
  }

  void Character::SetMainHand(const rpg::inventory::Item &main_hand) {
    main_hand_ = main_hand;
  }

  const std::array<double, 8> &Character::GetBuffs() const {
    return buffs_;
  }

  void Character::SetBuffs(const std::array<double, 8> &buffs) {
    buffs_ = buffs;
  }

  const double &Character::GetBuffsAt(int index) const {
    return buffs_[index];
  }

  void Character::SetBuffsAt(int index, const double &value) {
    buffs_[index] = value;
  }

}