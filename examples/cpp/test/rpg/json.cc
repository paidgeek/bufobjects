#include <sstream>
#include <iostream>
#include "rpg/rpg.h"
#include "rpg/inventory/inventory.h"
#include "doctest.h"

using namespace rpg;
using namespace rpg::inventory;

TEST_CASE ("WriteCharacterJson") {
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

  std::stringstream ss;
  character->writeJsonTo(ss);

    CHECK_EQ(
    "{\"name\":\"Bobby\",\"position\":{\"x\":-1,\"y\":1},\"speed\":3,\"bag\":{\"capacity\":10,\"items\":[{\"_id\":2,\"damage\":\"10\",\"name\":\"A\",\"quality\":1,\"cost\":\"5\"},{\"_id\":3,\"defense\":\"15\",\"name\":\"B\",\"quality\":2,\"cost\":\"15\"}]},\"equipment\":{\"Head\":{\"_id\":3,\"defense\":\"100\",\"name\":\"Fedora\",\"quality\":3,\"cost\":\"42\"},\"MainHand\":{\"_id\":2,\"damage\":\"50\",\"name\":\"Knife\",\"quality\":1,\"cost\":\"10\"}},\"buffs\":[32,64,0,0,0,0,0,0]}",
    ss.str());
}
