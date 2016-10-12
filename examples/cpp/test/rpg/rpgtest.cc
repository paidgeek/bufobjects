#include "rpg/rpg.h"
#include "rpg/inventory/inventory.h"
#include "doctest.h"
#include <cassert>

using namespace rpg;
using namespace rpg::inventory;

TEST_CASE ("CharacterWriteRead") {
  auto character = Character::Builder()
    .SetName("Bobby")
    .SetPosition({-1, 1})
    .SetSpeed(3.0f)
    .SetBag(Inventory::Builder()
              .SetCapacity(10)
              .SetItems({
                          new Weapon{10, "A", Quality::kCommon, 5},
                          new Armor{15, "B", Quality::kRare, 15}
                        })
              .Build())
    .SetEquipment("MainHand", new Weapon{50, "Knife", Quality::kCommon, 10})
    .SetEquipment("Head", new Armor{100, "Fedora", Quality::kEpic, 42})
    .SetBuffs({32.0, 64.0})
    .Build();
  bufobjects::BufferBuilder bb;

  bufobjects::WriteIdentifiedTo(bb, character);
  character->Clear();
  bb.Rewind();

  character = dynamic_cast<Character*>(bufobjects::ReadIdentifiedFrom(bb));

    CHECK_EQ("Bobby", character->name());
    CHECK_EQ(3.0f, character->speed());
    CHECK_EQ(32.0, character->buffs(0));
    CHECK_EQ(64.0, character->buffs(1));
    CHECK_EQ(-1, character->position().x);
    CHECK_EQ(1, character->position().y);

    CHECK(character->has_bag());
  auto weapon = dynamic_cast<Weapon*>(character->bag()->items(0));
    CHECK_EQ("A", weapon->name());
    CHECK_EQ(5, weapon->cost());
    CHECK_EQ(Quality::kCommon, weapon->quality());
    CHECK_EQ(10, weapon->damage());
  auto armor = dynamic_cast<Armor*>(character->bag()->items(1));
    CHECK_EQ("B", armor->name());
    CHECK_EQ(15, armor->cost());
    CHECK_EQ(Quality::kRare, armor->quality());
    CHECK_EQ(15, armor->defense());
  weapon = dynamic_cast<Weapon*>(character->equipment("MainHand"));
    CHECK_EQ("Knife", weapon->name());
    CHECK_EQ(10, weapon->cost());
    CHECK_EQ(Quality::kCommon, weapon->quality());
    CHECK_EQ(50, weapon->damage());
  armor = dynamic_cast<Armor*>(character->equipment("Head"));
    CHECK_EQ("Fedora", armor->name());
    CHECK_EQ(42, armor->cost());
    CHECK_EQ(Quality::kEpic, armor->quality());
    CHECK_EQ(100, armor->defense());

  delete(character);
}
