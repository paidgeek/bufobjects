#include "doctest.h"
#include "rpg/_all.h"
#include "rpg/inventory/_all.h"
#include <iostream>

using namespace rpg;
using namespace rpg::inventory;

Character::Ptr NewCharacter() {
  return Character::Builder()
    .SetName("Bobby")
    .SetPosition({-1, 1})
    .SetSpeed(3.0f)
    .SetBag(Inventory::Builder()
              .SetCapacity(10)
              .SetItems({
                          Weapon::Builder()
                            .SetName("A")
                            .SetCost(5)
                            .SetQuality(Quality::kCommon)
                            .SetDamage(10)
                            .Build(),
                          Armor::Builder()
                            .SetName("B")
                            .SetCost(15)
                            .SetQuality(Quality::kRare)
                            .SetDefense(10)
                            .Build()
                        })
              .Build())
    .SetBuffs({32.0, 64.0})
    .Build();
}

TEST_CASE ("CharacterWriteRead") {
  auto character = NewCharacter();
  auto bob = bufobjects::BufferObjectBuilder{};

    CHECK_EQ("Bobby", character->GetName());
    CHECK_EQ(3.0f, character->GetSpeed());
    CHECK_EQ(32.0, character->GetBuffs()[0]);
    CHECK_EQ(64.0, character->GetBuffs()[1]);
  auto weapon = std::dynamic_pointer_cast<Weapon>(character->GetBag()->GetItemsAt(0));
    CHECK_EQ("A", weapon->GetName());
    CHECK_EQ(5, weapon->GetCost());
    CHECK_EQ(Quality::kCommon, weapon->GetQuality());
    CHECK_EQ(10, weapon->GetDamage());
  auto armor = std::dynamic_pointer_cast<Armor>(character->GetBag()->GetItemsAt(1));
    CHECK_EQ("B", armor->GetName());
    CHECK_EQ(15, armor->GetCost());
    CHECK_EQ(Quality::kRare, armor->GetQuality());
    CHECK_EQ(10, armor->GetDefense());

  character->Reset();

}
