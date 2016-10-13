// Generated with https://github.com/paidgeek/bufobjects

#ifndef BUFOBJECTS_RPG_INVENTORY_H
#define BUFOBJECTS_RPG_INVENTORY_H

#include <iostream>
#include "../bufobjects.h"

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

namespace inventory {

enum class Quality : uint8_t {
  COMMON = 1, RARE = 2, EPIC = 3
};

}

}

namespace rpg {

namespace inventory {

class Item
  : public bufobjects::BufferObject {
public:

  Item();
  Item(std::string name, rpg::inventory::Quality quality, uint64_t cost);
  virtual ~Item() {};
  virtual uint32_t size() const override;
  virtual void clear() override;
  virtual void writeJsonTo(std::ostream& os) const = 0;

  inline const std::string& getName() const { return name_; }
  inline std::string& getName() { return name_; }
  inline void setName(const std::string& name) { name_ = name_; }

  inline const rpg::inventory::Quality& getQuality() const { return quality_; }
  inline rpg::inventory::Quality& getQuality() { return quality_; }
  inline void setQuality(const rpg::inventory::Quality& quality) { quality_ = quality_; }

  inline const uint64_t& getCost() const { return cost_; }
  inline uint64_t& getCost() { return cost_; }
  inline void setCost(const uint64_t& cost) { cost_ = cost_; }

protected:
  std::string name_;
  rpg::inventory::Quality quality_ = static_cast< rpg::inventory::Quality >(0);
  uint64_t cost_ = 0;

private:
  mutable uint32_t _cached_size_;
};

}

}

namespace rpg {

namespace inventory {

class Weapon
  : public rpg::inventory::Item {
public:

  Weapon();
  Weapon(uint64_t damage, std::string name, rpg::inventory::Quality quality, uint64_t cost);
  void init(uint64_t damage, std::string name, rpg::inventory::Quality quality, uint64_t cost);
  Weapon(const Weapon& from);
  Weapon& operator=(const Weapon& from);
  ~Weapon();
  uint16_t bufferObjectId() const override;
  void clear() override;
  void copyTo(bufobjects::BufferObject& obj) const override;
  uint32_t size() const override;
  void writeTo(bufobjects::BufferBuilder& bb) const override;
  void readFrom(bufobjects::BufferBuilder& bb) override;
  void writeJsonTo(std::ostream& os) const override;
  inline const uint64_t& getDamage() const { return damage_; }
  inline uint64_t& getDamage() { return damage_; }
  inline void setDamage(const uint64_t& damage) { damage_ = damage_; }

  static void
  writeDirectTo(bufobjects::BufferBuilder& bb, const uint64_t& damage, const std::string& name,
                const /* this comment seems to fix a jtwig bug "" */

                rpg::inventory::Quality& quality, const uint64_t& cost);
  static void writeDirectIdentifiedTo(bufobjects::BufferBuilder& bb, const uint64_t& damage,
                                      const std::string& name,
                                      const /* this comment seems to fix a jtwig bug "" */

                                      rpg::inventory::Quality& quality, const uint64_t& cost);
protected:
  uint64_t damage_ = 0;

private:
  mutable uint32_t _cached_size_;
};

}

}

namespace rpg {

namespace inventory {

class Armor
  : public rpg::inventory::Item {
public:

  Armor();
  Armor(uint64_t defense, std::string name, rpg::inventory::Quality quality, uint64_t cost);
  void init(uint64_t defense, std::string name, rpg::inventory::Quality quality, uint64_t cost);
  Armor(const Armor& from);
  Armor& operator=(const Armor& from);
  ~Armor();
  uint16_t bufferObjectId() const override;
  void clear() override;
  void copyTo(bufobjects::BufferObject& obj) const override;
  uint32_t size() const override;
  void writeTo(bufobjects::BufferBuilder& bb) const override;
  void readFrom(bufobjects::BufferBuilder& bb) override;
  void writeJsonTo(std::ostream& os) const override;
  inline const uint64_t& getDefense() const { return defense_; }
  inline uint64_t& getDefense() { return defense_; }
  inline void setDefense(const uint64_t& defense) { defense_ = defense_; }

  static void
  writeDirectTo(bufobjects::BufferBuilder& bb, const uint64_t& defense, const std::string& name,
                const /* this comment seems to fix a jtwig bug "" */

                rpg::inventory::Quality& quality, const uint64_t& cost);
  static void writeDirectIdentifiedTo(bufobjects::BufferBuilder& bb, const uint64_t& defense,
                                      const std::string& name,
                                      const /* this comment seems to fix a jtwig bug "" */

                                      rpg::inventory::Quality& quality, const uint64_t& cost);
protected:
  uint64_t defense_ = 0;

private:
  mutable uint32_t _cached_size_;
};

}

}

namespace rpg {

namespace inventory {

class Inventory
  : public bufobjects::BufferObject {
public:

  class Builder;

  Inventory();
  Inventory(uint32_t capacity,
            std::vector</* this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@532760d8, com.moybl.sidl.ast.ClassDefinition@57fa26b7]" */

              rpg::inventory::Item*> items);
  void init(uint32_t capacity,
            std::vector</* this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@532760d8, com.moybl.sidl.ast.ClassDefinition@57fa26b7]" */

              rpg::inventory::Item*> items);
  Inventory(const Inventory& from);
  Inventory& operator=(const Inventory& from);
  ~Inventory();
  uint16_t bufferObjectId() const override;
  void clear() override;
  void copyTo(bufobjects::BufferObject& obj) const override;
  uint32_t size() const override;
  void writeTo(bufobjects::BufferBuilder& bb) const override;
  void readFrom(bufobjects::BufferBuilder& bb) override;
  void writeJsonTo(std::ostream& os) const override;
  inline const uint32_t& getCapacity() const { return capacity_; }
  inline uint32_t& getCapacity() { return capacity_; }
  inline void setCapacity(const uint32_t& capacity) { capacity_ = capacity_; }

  inline const std::vector</* this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@532760d8, com.moybl.sidl.ast.ClassDefinition@57fa26b7]" */

    rpg::inventory::Item*>& getItems() const { return items_; }
  inline std::vector</* this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@532760d8, com.moybl.sidl.ast.ClassDefinition@57fa26b7]" */

    rpg::inventory::Item*>& getItems() { return items_; }
  inline void setItems(
    const std::vector</* this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@532760d8, com.moybl.sidl.ast.ClassDefinition@57fa26b7]" */

      rpg::inventory::Item*>& items) { items_ = items_; }

  inline /* this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@532760d8, com.moybl.sidl.ast.ClassDefinition@57fa26b7]" */

  rpg::inventory::Item* getItems(int index) {
    return items_[index];
    _cached_size_ = 0;
  }
  inline void setItems(
    int index, /* this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@532760d8, com.moybl.sidl.ast.ClassDefinition@57fa26b7]" */

    rpg::inventory::Item* value) {
    items_[index] = value;
    _cached_size_ = 0;
  }

  static void writeDirectTo(bufobjects::BufferBuilder& bb, const uint32_t& capacity,
                            const std::vector</* this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@532760d8, com.moybl.sidl.ast.ClassDefinition@57fa26b7]" */

                              rpg::inventory::Item*>& items);
  static void writeDirectIdentifiedTo(bufobjects::BufferBuilder& bb, const uint32_t& capacity,
                                      const std::vector</* this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@532760d8, com.moybl.sidl.ast.ClassDefinition@57fa26b7]" */

                                        rpg::inventory::Item*>& items);
protected:
  uint32_t capacity_ = 0;
  std::vector</* this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@532760d8, com.moybl.sidl.ast.ClassDefinition@57fa26b7]" */

    rpg::inventory::Item*> items_;

private:
  mutable uint32_t _cached_size_;
};

class Inventory::Builder {
public:
  Builder();

  Builder& setCapacity(const uint32_t& capacity);

  Builder& setItems(
    const std::vector</* this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@532760d8, com.moybl.sidl.ast.ClassDefinition@57fa26b7]" */

      rpg::inventory::Item*>& items);

  Builder& setItems(int index, rpg::inventory::Item* value);
  Builder& addItems(rpg::inventory::Item* value);
  Builder& addItems(
    std::vector</* this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@532760d8, com.moybl.sidl.ast.ClassDefinition@57fa26b7]" */

      rpg::inventory::Item*> values);

  Inventory* build();
private:

  uint32_t capacity_ = 0;

  std::vector</* this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@532760d8, com.moybl.sidl.ast.ClassDefinition@57fa26b7]" */

    rpg::inventory::Item*> items_;

};

}

}

#endif