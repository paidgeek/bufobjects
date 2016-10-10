// Generated with https://github.com/paidgeek/bufobjects


#include "./../rpg/rpg.h"

#include "./../rpg/inventory/inventory.h"

namespace rpg {

Position::Position() {}

Position::Position(float x, float y)
  : x(x), y(y) {}

Position::Position(const Position& from) {
  memcpy(this, &from, sizeof(Position));
}

void Position::Clear() {
  x = 0.0f;
  y = 0.0f;

}

void Position::WriteTo(bufobjects::BufferBuilder& _bb) const {
  if (_bb.GetRemaining() < sizeof(Position)) {
    _bb.GrowBuffer(sizeof(Position));
  }
#if defined(BUFOBJECTS_LITTLE_ENDIAN)

  _bb.WriteData((void*) this, sizeof(Position));

#else

  {_bb.WriteFloat32(x);}
  {_bb.WriteFloat32(y);}


#endif

}

void Position::ReadFrom(bufobjects::BufferBuilder& _bb) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)

  _bb.ReadData((void*) this, sizeof(Position));

#else

  {x = _bb.ReadFloat32();}{y = _bb.ReadFloat32();}

#endif

}

void Position::WriteJsonTo(std::ostream& _os) const {
  _os << '{';

  uint32_t _i = 0;
  _os << "\"" << "x" << "\":";
  _os << x;

  _os << ',';

  _os << "\"" << "y" << "\":";
  _os << y;

  _os << '}';

}

}

namespace rpg {

Character::Character() {
  cached_size_ = 0;
}

Character::Character(std::string name, rpg::Position position, float speed,
                     rpg::inventory::Inventory* bag,
                     std::map<std::string, /* this comment seems to fix a jtwig bug "true" */

                       rpg::inventory::Item*> equipment, std::array<double, 8> buffs)
  : name_(name), position_(position), speed_(speed), bag_(std::move(bag)), equipment_(equipment),
    buffs_(buffs) {
  cached_size_ = 0;
}

Character::~Character() {

  delete (bag_);

}

void Character::Init(std::string name, rpg::Position position, float speed,
                     rpg::inventory::Inventory* bag,
                     std::map<std::string, /* this comment seems to fix a jtwig bug "true" */

                       rpg::inventory::Item*> equipment, std::array<double, 8> buffs) {
  name_ = name;
  position_ = position;
  speed_ = speed;
  bag_ = std::move(bag);
  equipment_ = equipment;
  buffs_ = buffs;
  cached_size_ = 0;
}

Character::Character(const Character& from) {
  from.CopyTo(*this);
  cached_size_ = 0;
}

Character& Character::operator=(const Character& from) {
  from.CopyTo(*this);
  cached_size_ = from.cached_size_;
  return *this;
}

uint16_t Character::BufferObjectId() const {
  return bufobjects::kRpgCharacterId;
}

void Character::Clear() {
  name_.clear();
  position_.Clear();
  speed_ = 0.0f;
  delete (bag_);
  bag_ = nullptr;
  equipment_.clear();

  buffs_ = std::array<double, 8>{};

  cached_size_ = 0;
}

void Character::CopyTo(bufobjects::BufferObject& _obj) const {
  Character& _dst = static_cast< Character& >(_obj);
  _dst.cached_size_ = cached_size_;

  _dst.name_ = name_;
  _dst.position_ = position_;
  _dst.speed_ = speed_;
  if (bag_ != nullptr) {
    bag_->CopyTo(*_dst.bag_);
  }
  _dst.equipment_ = std::map<std::string, /* this comment seems to fix a jtwig bug "true" */

    rpg::inventory::Item*>(equipment_);
  _dst.buffs_ = std::array<double, 8>(buffs_);

}

uint32_t Character::Size() const {
  if (cached_size_ != 0) {
    return cached_size_;
  }
  cached_size_ = 0;

  cached_size_ += bufobjects::BufferBuilder::GetStringSize(name_);

  cached_size_ += sizeof(rpg::Position);

  cached_size_ += 4; // size for "f32"


  cached_size_ += 1; // +1 for "is null" byte
  if (bag_ != nullptr) {
    cached_size_ += bag_->Size();
    // this comment seems to fix a jtwig bug "[]"

  }

  cached_size_ += bufobjects::BufferBuilder::GetVarUInt32Size(
    static_cast< uint32_t >(equipment_.size()));

  for (const auto& _kv : equipment_) {

    cached_size_ += bufobjects::BufferBuilder::GetStringSize(_kv.first);


    // this comment seems to fix a jtwig bug "true"

    cached_size_ += _kv.second->Size();

    cached_size_ += 2; // size of bufferObjectId


  }

  cached_size_ += kBuffsLength * 8;

  return cached_size_;
}

void Character::WriteTo(bufobjects::BufferBuilder& _bb) const {
  uint32_t _needed = this->Size();
  if (_bb.GetRemaining() < _needed) {
    _bb.GrowBuffer(_needed);
  }
  {
    _bb.WriteString(name_);

  }
  {
    position_.WriteTo(_bb);

  }
  {
    _bb.WriteFloat32(speed_);

  }
  {
    if (bag_ == nullptr) {
      _bb.WriteUInt8(0x80);
    } else {
      _bb.WriteUInt8(0x81);
      // this comment seems to fix a jtwig bug "[]"

      bag_->WriteTo(_bb);
    }

  }
  {
    _bb.WriteVarUInt32(static_cast< uint32_t >(equipment_.size()));
    for (const auto& _kv : equipment_) {
      _bb.WriteString(_kv.first);
      // this comment seems to fix a jtwig bug "true"

      _bb.WriteUInt16(_kv.second->BufferObjectId());
      _kv.second->WriteTo(_bb);
    }

  }
  {
    for (const auto& _e : buffs_) {
      _bb.WriteFloat64(_e);
    }
  }

}

void Character::ReadFrom(bufobjects::BufferBuilder& _bb) {
  {
    name_ = _bb.ReadString();

  }
  {
    position_.ReadFrom(_bb);

  }
  {
    speed_ = _bb.ReadFloat32();

  }
  {
    // this comment seems to fix a jtwig bug "[]"

    if (_bb.ReadUInt8() == 0x81) {
      if (bag_ == nullptr) {
        bag_ = new rpg::inventory::Inventory{};
      }
      bag_->ReadFrom(_bb);
    } else {
      bag_ = nullptr;
    }

  }
  {
    uint32_t _size = _bb.ReadVarUInt32();
    equipment_.clear();
    std::string _key;
    /* this comment seems to fix a jtwig bug "true" */

    rpg::inventory::Item* _value;
    for (uint32_t i = 0; i < _size; i++) {
      _key = _bb.ReadString();
      // this comment seems to fix a jtwig bug "true"

      uint16_t id = _bb.ReadUInt16();
      switch (id) {
        case bufobjects::kRpgInventoryWeaponId:
          _value = new rpg::inventory::Weapon{};
          _value->ReadFrom(_bb);
          break;
        case bufobjects::kRpgInventoryArmorId:
          _value = new rpg::inventory::Armor{};
          _value->ReadFrom(_bb);
          break;
      }
      equipment_[_key] = _value;
    }

  }
  {
    for (uint32_t i = 0; i < kBuffsLength; i++) {
      buffs_[i] = _bb.ReadFloat64();
    }
  }

  cached_size_ = 0;
}

void Character::WriteJsonTo(std::ostream& _os) const {
  _os << '{';

  uint32_t _i = 0;
  _os << "\"name\":";
  _os << "\"" << name_ << "\"";

  _os << ',';

  _os << "\"position\":";
  position_.WriteJsonTo(_os);

  _os << ',';

  _os << "\"speed\":";
  _os << speed_;

  _os << ',';

  _os << "\"bag\":";
  if (bag_ == nullptr) {
    _os << "null";
  } else {
    bag_->WriteJsonTo(_os);
  }

  _os << ',';

  _os << "\"equipment\":";
  _os << '{';
  _i = 0;
  for (const auto& _kv : equipment_) {
    _os << "\"" << _kv.first << "\":";
    /* this comment seems to fix a jtwig bug "true" */

    _kv.second->WriteJsonTo(_os);
    if (++_i < equipment_.size()) {
      _os << ',';
    }
  }
  _os << '}';

  _os << ',';

  _os << "\"buffs\":";
  _os << '[';
  _i = 0;
  for (const auto& _e : buffs_) {
    _os << _e;
    if (++_i < buffs_.size()) {
      _os << ',';
    }
  }
  _os << ']';

  _os << '}';

}

void Character::WriteDirectTo(bufobjects::BufferBuilder& _bb, const std::string& name,
                              const /* this comment seems to fix a jtwig bug "" */

                              rpg::Position& position, const float& speed,
                              const /* this comment seems to fix a jtwig bug "[]" */

                              rpg::inventory::Inventory& bag,
                              const std::map<std::string, /* this comment seems to fix a jtwig bug "true" */

                                rpg::inventory::Item*>& equipment,
                              const std::array<double, 8>& buffs) {
  {
    _bb.WriteString(name);

  }
  {
    position.WriteTo(_bb);

  }
  {
    _bb.WriteFloat32(speed);

  }
  {
    _bb.WriteUInt8(0x81);
    // this comment seems to fix a jtwig bug "[]"

    bag.WriteTo(_bb);

  }
  {
    _bb.WriteVarUInt32(static_cast< uint32_t >(equipment.size()));
    for (const auto& _kv : equipment) {
      _bb.WriteString(_kv.first);
      // this comment seems to fix a jtwig bug "true"

      _bb.WriteUInt16(_kv.second->BufferObjectId());
      _kv.second->WriteTo(_bb);
    }

  }
  {
    for (const auto& _e : buffs) {
      _bb.WriteFloat64(_e);
    }
  }
};
void Character::WriteDirectIdentifiedTo(bufobjects::BufferBuilder& _bb, const std::string& name,
                                        const /* this comment seems to fix a jtwig bug "" */

                                        rpg::Position& position, const float& speed,
                                        const /* this comment seems to fix a jtwig bug "[]" */

                                        rpg::inventory::Inventory& bag,
                                        const std::map<std::string, /* this comment seems to fix a jtwig bug "true" */

                                          rpg::inventory::Item*>& equipment,
                                        const std::array<double, 8>& buffs) {
  _bb.WriteUInt16(bufobjects::kRpgCharacterId);
  Character::WriteDirectTo(_bb, name, position, speed, bag, equipment, buffs);
};

Character::Builder::Builder() {}

Character::Builder& Character::Builder::SetName(const std::string& name) {
  name_ = name;
  return *this;
}

Character::Builder& Character::Builder::SetPosition(const rpg::Position& position) {
  position_ = position;
  return *this;
}

Character::Builder& Character::Builder::SetSpeed(const float& speed) {
  speed_ = speed;
  return *this;
}

Character::Builder& Character::Builder::SetBag(rpg::inventory::Inventory* bag) {
  bag_ = bag;
  return *this;
}

Character::Builder& Character::Builder::SetEquipment(
  const std::map<std::string, /* this comment seems to fix a jtwig bug "true" */

    rpg::inventory::Item*>& equipment) {
  equipment_ = equipment;
  return *this;
}

Character::Builder& Character::Builder::SetEquipment(
  const std::string& key, /* this comment seems to fix a jtwig bug "true" */

  rpg::inventory::Item* value) {
  equipment_[key] = value;
  return *this;
}
Character::Builder& Character::Builder::SetBuffs(const std::array<double, 8>& buffs) {
  buffs_ = buffs;
  return *this;
}

Character::Builder& Character::Builder::SetBuffs(int index, const double& value) {
  buffs_[index] = value;
  return *this;
}

Character* Character::Builder::Build() {
  return new Character{
    std::move(name_), std::move(position_), std::move(speed_), std::move(bag_),
    std::move(equipment_), std::move(buffs_)
  };
}

}