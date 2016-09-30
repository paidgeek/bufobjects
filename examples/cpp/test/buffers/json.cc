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
                          Weapon::New(10, "A", Quality::kCommon, 5),
                          Armor::New(15, "B", Quality::kRare, 15)
                        })
              .Build())
    .SetEquipment("MainHand", Weapon::New(50, "Knife",Quality::kCommon, 10))
    .SetEquipment("Head", Armor::New(100, "Fedora",Quality::kEpic, 42))
    .SetBuffs({32.0, 64.0})
    .Build();

  std::stringstream ss;
  character->WriteJsonTo(ss);

  std::cout << std::endl << ss.str() << std::endl << std::endl;

  delete(character);
}
