#include <sstream>
#include <iostream>
#include "rpg/rpg.h"
#include "rpg/rpg_inventory.h"
#include "doctest.h"

using namespace rpg;
using namespace rpg::inventory;

TEST_CASE ("WriteCharacterJson") {
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

  std::stringstream ss;
  character->WriteJsonTo(ss);

    CHECK_EQ(
    "{\"name\":\"Bobby\",\"position\":{\"x\":-1,\"y\":1},\"speed\":3,\"bag\":{\"capacity\":10,\"items\":[{\"_id\":2,\"damage\":\"10\",\"name\":\"A\",\"quality\":1,\"cost\":\"5\"},{\"_id\":3,\"defense\":\"15\",\"name\":\"B\",\"quality\":2,\"cost\":\"15\"}]},\"equipment\":{\"Head\":{\"_id\":3,\"defense\":\"100\",\"name\":\"Fedora\",\"quality\":3,\"cost\":\"42\"},\"MainHand\":{\"_id\":2,\"damage\":\"50\",\"name\":\"Knife\",\"quality\":1,\"cost\":\"10\"}},\"buffs\":[32,64,0,0,0,0,0,0]}",
    ss.str());

  delete(character);
}
