// Generated with https://github.com/paidgeek/bufobjects

#ifndef BUFOBJECTS_RPG_H
#define BUFOBJECTS_RPG_H

#include <iostream>
#include "bufobjects.h"

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
  Position(const Position& from);
  void Clear();
  void WriteTo(bufobjects::BufferBuilder& bb) const;
  void ReadFrom(bufobjects::BufferBuilder& bb);
  void WriteJsonTo(std::ostream& os) const;
};

}

namespace rpg {

class Character
  : public bufobjects::BufferObject {
private:
  mutable uint32_t cached_size_;
protected:
  std::string name_;
  rpg::Position position_;
  float speed_;
  rpg::inventory::Inventory* bag_ = nullptr;
  std::map<std::string, /* this comment seems to fix a jtwig bug "true" */

    rpg::inventory::Item*> equipment_;
  std::array<double, 8> buffs_;

public:

  static const uint32_t kBuffsLength = 8;

  class Builder;

  Character();
  Character(std::string name, rpg::Position position, float speed, rpg::inventory::Inventory* bag,
            std::map<std::string, /* this comment seems to fix a jtwig bug "true" */

              rpg::inventory::Item*> equipment, std::array<double, 8> buffs);
  void Init(std::string name, rpg::Position position, float speed, rpg::inventory::Inventory* bag,
            std::map<std::string, /* this comment seems to fix a jtwig bug "true" */

              rpg::inventory::Item*> equipment, std::array<double, 8> buffs);
  Character(const Character& from);
  Character& operator=(const Character& from);
  ~Character();
  uint16_t BufferObjectId() const override;
  void Clear() override;
  void CopyTo(bufobjects::BufferObject& obj) const override;
  uint32_t Size() const override;
  void WriteTo(bufobjects::BufferBuilder& bb) const override;
  void ReadFrom(bufobjects::BufferBuilder& bb) override;
  void WriteJsonTo(std::ostream& os) const override;
  inline const std::string& GetName() const { return name_; }
  inline std::string& GetName() { return name_; }
  inline void SetName(const std::string& name) { name_ = name; }

  inline const rpg::Position& GetPosition() const { return position_; }
  inline rpg::Position& GetPosition() { return position_; }
  inline void SetPosition(const rpg::Position& position) { position_ = position; }

  inline const float& GetSpeed() const { return speed_; }
  inline float& GetSpeed() { return speed_; }
  inline void SetSpeed(const float& speed) { speed_ = speed; }

  inline rpg::inventory::Inventory* GetBag() {
    return bag_;
    cached_size_ = 0;
  }
  inline const rpg::inventory::Inventory* GetBag() const { return bag_; }
  inline void SetBag(rpg::inventory::Inventory* bag) {
    bag_ = bag;
    cached_size_ = 0;
  }

  inline const std::map<std::string, /* this comment seems to fix a jtwig bug "true" */

    rpg::inventory::Item*>& GetEquipment() const { return equipment_; }
  inline std::map<std::string, /* this comment seems to fix a jtwig bug "true" */

    rpg::inventory::Item*>& GetEquipment() { return equipment_; }
  inline void
  SetEquipment(const std::map<std::string, /* this comment seems to fix a jtwig bug "true" */

    rpg::inventory::Item*>& equipment) { equipment_ = equipment; }

  inline /* this comment seems to fix a jtwig bug "true" */

  rpg::inventory::Item* GetEquipment(const std::string& key) { return equipment_[key]; }
  inline void
  SetEquipment(const std::string& key, /* this comment seems to fix a jtwig bug "true" */

               rpg::inventory::Item*& value) { equipment_[key] = value; }
  inline const std::array<double, 8>& GetBuffs() const { return buffs_; }
  inline std::array<double, 8>& GetBuffs() { return buffs_; }
  inline void SetBuffs(const std::array<double, 8>& buffs) { buffs_ = buffs; }

  inline const double& GetBuffs(int index) const { return buffs_[index]; }
  inline double& GetBuffs(int index) { return buffs_[index]; }
  inline void SetBuffs(int index, const double& value) { buffs_[index] = value; }

  inline bool HasBag() { return bag_ != nullptr; }

  static void WriteDirectTo(bufobjects::BufferBuilder& bb, const std::string& name,
                            const /* this comment seems to fix a jtwig bug "" */

                            rpg::Position& position, const float& speed,
                            const /* this comment seems to fix a jtwig bug "[]" */

                            rpg::inventory::Inventory& bag,
                            const std::map<std::string, /* this comment seems to fix a jtwig bug "true" */

                              rpg::inventory::Item*>& equipment,
                            const std::array<double, 8>& buffs);
  static void WriteDirectIdentifiedTo(bufobjects::BufferBuilder& bb, const std::string& name,
                                      const /* this comment seems to fix a jtwig bug "" */

                                      rpg::Position& position, const float& speed,
                                      const /* this comment seems to fix a jtwig bug "[]" */

                                      rpg::inventory::Inventory& bag,
                                      const std::map<std::string, /* this comment seems to fix a jtwig bug "true" */

                                        rpg::inventory::Item*>& equipment,
                                      const std::array<double, 8>& buffs);
};

class Character::Builder {
private:
  std::string name_;
  rpg::Position position_;
  float speed_;
  rpg::inventory::Inventory* bag_;
  std::map<std::string, /* this comment seems to fix a jtwig bug "true" */

    rpg::inventory::Item*> equipment_;
  std::array<double, 8> buffs_;

public:
  Builder();

  Builder& SetName(const std::string& name);

  Builder& SetPosition(const rpg::Position& position);

  Builder& SetSpeed(const float& speed);

  Builder& SetBag(rpg::inventory::Inventory* bag);

  Builder&
  SetEquipment(const std::map<std::string, /* this comment seems to fix a jtwig bug "true" */

    rpg::inventory::Item*>& equipment);

  Builder& SetEquipment(const std::string& key, /* this comment seems to fix a jtwig bug "true" */

                        rpg::inventory::Item* value);

  Builder& SetBuffs(const std::array<double, 8>& buffs);

  Builder& SetBuffs(int index, const double& value);

  Character* Build();
};

}

#endif