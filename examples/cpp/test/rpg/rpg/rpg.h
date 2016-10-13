// Generated with https://github.com/paidgeek/bufobjects

#ifndef BUFOBJECTS_RPG_H
#define BUFOBJECTS_RPG_H

#include <iostream>
#include "bufobjects.h"

// forward declarations




namespace rpg {}
namespace rpg {
namespace inventory {
class Inventory;
}
}
namespace rpg {
namespace inventory {
class Item;
}
}

namespace rpg { namespace inventory {}}

namespace rpg {
namespace inventory {
class Item;
}
}

namespace rpg {

struct Position {

  float x = 0.0f;

  float y = 0.0f;

  Position();
  Position(float x, float y);
  Position(const Position& from);
  void clear();
  void writeTo(bufobjects::BufferBuilder& bb) const;
  void readFrom(bufobjects::BufferBuilder& bb);
  void writeJsonTo(std::ostream& os) const;
};

}

namespace rpg {

class Character
  : public bufobjects::BufferObject {
public:

  static constexpr uint32_t kBuffsLength = 8;

  class Builder;

  Character();
  Character(std::string name, rpg::Position position, float speed, rpg::inventory::Inventory* bag,
            std::map<std::string, /* this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@532760d8, com.moybl.sidl.ast.ClassDefinition@57fa26b7]" */

              rpg::inventory::Item*> equipment, std::array<double, 8> buffs);
  void init(std::string name, rpg::Position position, float speed, rpg::inventory::Inventory* bag,
            std::map<std::string, /* this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@532760d8, com.moybl.sidl.ast.ClassDefinition@57fa26b7]" */

              rpg::inventory::Item*> equipment, std::array<double, 8> buffs);
  Character(const Character& from);
  Character& operator=(const Character& from);
  ~Character();
  uint16_t bufferObjectId() const override;
  void clear() override;
  void copyTo(bufobjects::BufferObject& obj) const override;
  uint32_t size() const override;
  void writeTo(bufobjects::BufferBuilder& bb) const override;
  void readFrom(bufobjects::BufferBuilder& bb) override;
  void writeJsonTo(std::ostream& os) const override;
  inline const std::string& getName() const { return name_; }
  inline std::string& getName() { return name_; }
  inline void setName(const std::string& name) { name_ = name_; }

  inline const rpg::Position& getPosition() const { return position_; }
  inline rpg::Position& getPosition() { return position_; }
  inline void setPosition(const rpg::Position& position) { position_ = position_; }

  inline const float& getSpeed() const { return speed_; }
  inline float& getSpeed() { return speed_; }
  inline void setSpeed(const float& speed) { speed_ = speed_; }

  inline rpg::inventory::Inventory* getBag() {
    return bag_;
    _cached_size_ = 0;
  }
  inline const rpg::inventory::Inventory* getBag() const { return bag_; }
  inline void setBag(rpg::inventory::Inventory* bag) {
    bag_ = bag_;
    _cached_size_ = 0;
  }

  inline const std::map<std::string, /* this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@532760d8, com.moybl.sidl.ast.ClassDefinition@57fa26b7]" */

    rpg::inventory::Item*>& getEquipment() const { return equipment_; }
  inline std::map<std::string, /* this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@532760d8, com.moybl.sidl.ast.ClassDefinition@57fa26b7]" */

    rpg::inventory::Item*>& getEquipment() { return equipment_; }
  inline void setEquipment(
    const std::map<std::string, /* this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@532760d8, com.moybl.sidl.ast.ClassDefinition@57fa26b7]" */

      rpg::inventory::Item*>& equipment) { equipment_ = equipment_; }

  inline /* this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@532760d8, com.moybl.sidl.ast.ClassDefinition@57fa26b7]" */

  rpg::inventory::Item* getEquipment(const std::string& key) { return equipment_[key]; }
  inline void setEquipment(
    const std::string& key, /* this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@532760d8, com.moybl.sidl.ast.ClassDefinition@57fa26b7]" */

    rpg::inventory::Item*& value) { equipment_[key] = value; }
  inline const std::array<double, 8>& getBuffs() const { return buffs_; }
  inline std::array<double, 8>& getBuffs() { return buffs_; }
  inline void setBuffs(const std::array<double, 8>& buffs) { buffs_ = buffs_; }

  inline const double& getBuffs(int index) const { return buffs_[index]; }
  inline double& getBuffs(int index) { return buffs_[index]; }
  inline void setBuffs(int index, const double& value) { buffs_[index] = value; }

  inline bool hasBag() { return bag_ != nullptr; }

  static void writeDirectTo(bufobjects::BufferBuilder& bb, const std::string& name,
                            const /* this comment seems to fix a jtwig bug "" */

                            rpg::Position& position, const float& speed,
                            const /* this comment seems to fix a jtwig bug "[]" */

                            rpg::inventory::Inventory& bag,
                            const std::map<std::string, /* this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@532760d8, com.moybl.sidl.ast.ClassDefinition@57fa26b7]" */

                              rpg::inventory::Item*>& equipment,
                            const std::array<double, 8>& buffs);
  static void writeDirectIdentifiedTo(bufobjects::BufferBuilder& bb, const std::string& name,
                                      const /* this comment seems to fix a jtwig bug "" */

                                      rpg::Position& position, const float& speed,
                                      const /* this comment seems to fix a jtwig bug "[]" */

                                      rpg::inventory::Inventory& bag,
                                      const std::map<std::string, /* this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@532760d8, com.moybl.sidl.ast.ClassDefinition@57fa26b7]" */

                                        rpg::inventory::Item*>& equipment,
                                      const std::array<double, 8>& buffs);
protected:
  std::string name_;
  rpg::Position position_;
  float speed_ = 0.0f;
  rpg::inventory::Inventory* bag_ = nullptr;
  std::map<std::string, /* this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@532760d8, com.moybl.sidl.ast.ClassDefinition@57fa26b7]" */

    rpg::inventory::Item*> equipment_;
  std::array<double, 8> buffs_;

private:
  mutable uint32_t _cached_size_;
};

class Character::Builder {
public:
  Builder();

  Builder& setName(const std::string& name);

  Builder& setPosition(const rpg::Position& position);

  Builder& setSpeed(const float& speed);

  Builder& setBag(rpg::inventory::Inventory* bag);

  Builder& setEquipment(
    const std::map<std::string, /* this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@532760d8, com.moybl.sidl.ast.ClassDefinition@57fa26b7]" */

      rpg::inventory::Item*>& equipment);

  Builder& setEquipment(
    const std::string& key, /* this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@532760d8, com.moybl.sidl.ast.ClassDefinition@57fa26b7]" */

    rpg::inventory::Item* value);

  Builder& setBuffs(const std::array<double, 8>& buffs);

  Builder& setBuffs(int index, const double& value);

  Character* build();
private:

  std::string name_;

  rpg::Position position_;

  float speed_ = 0.0f;

  rpg::inventory::Inventory* bag_ = nullptr;

  std::map<std::string, /* this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@532760d8, com.moybl.sidl.ast.ClassDefinition@57fa26b7]" */

    rpg::inventory::Item*> equipment_;

  std::array<double, 8> buffs_;

};

}

#endif