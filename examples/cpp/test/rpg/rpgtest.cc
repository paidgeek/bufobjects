#include "rpg/rpg.h"
#include "rpg/inventory/inventory.h"
#include "doctest.h"

using namespace rpg;
using namespace rpg::inventory;

TEST_CASE ("CharacterWriteRead") {
  auto character = std::unique_ptr<Character>{
    Character::Builder()
      .setName("Bobby")
      .setPosition({-1, 1})
      .setSpeed(3.0f)
      .setBag(Inventory::Builder()
                .setCapacity(10)
                .setItems({
                            new Weapon{10, "A", Quality::COMMON, 5},
                            new Armor{15, "B", Quality::RARE, 15}
                          })
                .build())
      .setEquipment("MainHand", new Weapon{50, "Knife", Quality::COMMON, 10})
      .setEquipment("Head", new Armor{100, "Fedora", Quality::EPIC, 42})
      .setBuffs({32.0, 64.0})
      .build()
  };
  bufobjects::BufferBuilder bb;

  bufobjects::writeIdentifiedTo(bb, character.get());
  character->clear();
  bb.Rewind();

  character.reset(dynamic_cast<Character*>(bufobjects::readIdentifiedFrom(bb)));

    CHECK_EQ("Bobby", character->getName());
    CHECK_EQ(3.0f, character->getSpeed());
    CHECK_EQ(32.0, character->getBuffs(0));
    CHECK_EQ(64.0, character->getBuffs(1));
    CHECK_EQ(-1, character->getPosition().x);
    CHECK_EQ(1, character->getPosition().y);

    CHECK(character->hasBag());
  auto weapon = dynamic_cast<Weapon*>(character->getBag()->getItems(0));
    CHECK_EQ("A", weapon->getName());
    CHECK_EQ(5, weapon->getCost());
    CHECK_EQ(Quality::COMMON, weapon->getQuality());
    CHECK_EQ(10, weapon->getDamage());
  auto armor = dynamic_cast<Armor*>(character->getBag()->getItems(1));
    CHECK_EQ("B", armor->getName());
    CHECK_EQ(15, armor->getCost());
    CHECK_EQ(Quality::RARE, armor->getQuality());
    CHECK_EQ(15, armor->getDefense());
  weapon = dynamic_cast<Weapon*>(character->getEquipment("MainHand"));
    CHECK_EQ("Knife", weapon->getName());
    CHECK_EQ(10, weapon->getCost());
    CHECK_EQ(Quality::COMMON, weapon->getQuality());
    CHECK_EQ(50, weapon->getDamage());
  armor = dynamic_cast<Armor*>(character->getEquipment("Head"));
    CHECK_EQ("Fedora", armor->getName());
    CHECK_EQ(42, armor->getCost());
    CHECK_EQ(Quality::EPIC, armor->getQuality());
    CHECK_EQ(100, armor->getDefense());
}
