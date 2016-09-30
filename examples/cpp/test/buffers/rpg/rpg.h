// Generated with https://github.com/paidgeek/bufobjects


#ifndef BUFOBJECTS_RPG_H
#define BUFOBJECTS_RPG_H

#include <iostream>
#include "buffer_object.h"

// forward declarations




namespace rpg {}
namespace rpg { namespace inventory { class Inventory; }}
namespace rpg { namespace inventory { class Item; }}

namespace rpg { namespace inventory {}}

namespace rpg { namespace inventory { class Item; }}

namespace rpg {

  struct Position {
    float x;
    float y;

    Position();
    Position(float x, float y);
    Position(const Position &from);
    void Reset();
    void WriteTo(bufobjects::BufferBuilder &bb) const;
    void ReadFrom(bufobjects::BufferBuilder &bb);
    void WriteJsonTo(std::ostream &os);
  };

}

namespace rpg {

  class Character
    : public bufobjects::BufferObject {

  protected:

    std::string name_;

    rpg::Position position_;

    float speed_;

    std::shared_ptr<rpg::inventory::Inventory> bag_ = nullptr;

    std::map<std::string, std::shared_ptr<rpg::inventory::Item>> equipment_;

    std::array<double, 8> buffs_;

  public:

    typedef std::shared_ptr<rpg::Character> Ptr;

    static const uint32_t kBuffsLength = 8;

    class Builder;

    Character();
    Character(std::string name, rpg::Position position, float speed,
              std::shared_ptr<rpg::inventory::Inventory> bag,
              std::map<std::string, std::shared_ptr<rpg::inventory::Item>> equipment,
              std::array<double, 8> buffs);

    void Init(std::string name, rpg::Position position, float speed,
              std::shared_ptr<rpg::inventory::Inventory> &bag,
              std::map<std::string, std::shared_ptr<rpg::inventory::Item>> equipment,
              std::array<double, 8> buffs);
    static Ptr New(std::string name, rpg::Position position, float speed,
                   std::shared_ptr<rpg::inventory::Inventory> &bag,
                   std::map<std::string, std::shared_ptr<rpg::inventory::Item>> equipment,
                   std::array<double, 8> buffs);
    Character(const Character &from);
    Character &operator=(const Character &from);
    explicit operator bufobjects::BufferObject::Ptr() {
      return static_cast< bufobjects::BufferObject::Ptr >(this);
    }
    uint16_t BufferObjectId() const;
    void Reset();
    void CopyTo(bufobjects::BufferObject &obj) const;
    uint32_t Size() const;
    void WriteTo(bufobjects::BufferBuilder &bb) const;
    void ReadFrom(bufobjects::BufferBuilder &bb);
    void WriteJsonTo(std::ostream &os);
    inline const std::string &GetName() const { return name_; }
    inline void SetName(const std::string &name) { name_ = name; }

    inline const rpg::Position &GetPosition() const { return position_; }
    inline void SetPosition(const rpg::Position &position) { position_ = position; }

    inline const float &GetSpeed() const { return speed_; }
    inline void SetSpeed(const float &speed) { speed_ = speed; }

    inline std::shared_ptr<rpg::inventory::Inventory> GetBag() { return bag_; }
    inline void SetBag(std::shared_ptr<rpg::inventory::Inventory> bag) { bag_ = bag; }

    inline const std::map<std::string, std::shared_ptr<rpg::inventory::Item>> &
    GetEquipment() const { return equipment_; }
    inline void SetEquipment(
      const std::map<std::string, std::shared_ptr<rpg::inventory::Item>> &equipment) { equipment_ = equipment; }

    inline std::shared_ptr<rpg::inventory::Item>
    GetEquipment(const std::string &key) { return equipment_[key]; }
    inline void SetEquipment(const std::string &key,
                             std::shared_ptr<rpg::inventory::Item> value) { equipment_[key] = value; }

    inline const std::array<double, 8> &GetBuffs() const { return buffs_; }
    inline void SetBuffs(const std::array<double, 8> &buffs) { buffs_ = buffs; }

    inline const double &GetBuffs(int index) const { return buffs_[index]; }
    inline void SetBuffs(int index, const double &value) { buffs_[index] = value; }

    static void
    WriteDirectTo(bufobjects::BufferBuilder &bb, std::string name, rpg::Position position,
                  float speed, std::shared_ptr<rpg::inventory::Inventory> bag,
                  std::map<std::string, std::shared_ptr<rpg::inventory::Item>> equipment,
                  std::array<double, 8> buffs);
    static void
    WriteDirectIdentifiedTo(bufobjects::BufferBuilder &bb, std::string name, rpg::Position position,
                            float speed, std::shared_ptr<rpg::inventory::Inventory> bag,
                            std::map<std::string, std::shared_ptr<rpg::inventory::Item>> equipment,
                            std::array<double, 8> buffs);
  };

  class Character::Builder {
  private:
    std::string name_;
    rpg::Position position_;
    float speed_;
    std::shared_ptr<rpg::inventory::Inventory> bag_;
    std::map<std::string, std::shared_ptr<rpg::inventory::Item>> equipment_;
    std::array<double, 8> buffs_;

  public:
    Builder();

    Builder &SetName(const std::string &name);

    Builder &SetPosition(const rpg::Position &position);

    Builder &SetSpeed(const float &speed);

    Builder &SetBag(std::shared_ptr<rpg::inventory::Inventory> bag);

    Builder &
    SetEquipment(const std::map<std::string, std::shared_ptr<rpg::inventory::Item>> &equipment);

    Builder &SetEquipment(const std::string &key, std::shared_ptr<rpg::inventory::Item> value);

    Builder &SetBuffs(const std::array<double, 8> &buffs);

    Builder &SetBuffs(int index, const double &value);

    Character::Ptr Build();
    void WriteTo(bufobjects::BufferBuilder &bb);
    void WriteIdentifiedTo(bufobjects::BufferBuilder &bb);
  };

}

#endif