#include "rpg/buffer_builder.h"
#include "rpg/rpg.h"
#include "rpg/rpg_inventory.h"
#include "doctest.h"

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
                          Weapon::New(10, "A", Quality::kCommon, 5),
                          Armor::New(15, "B", Quality::kRare, 15)
                        })
              .Build())
    .SetEquipment("MainHand", Weapon::New(50, "Knife",Quality::kCommon, 10))
    .SetEquipment("Head", Armor::New(100, "Fedora",Quality::kEpic, 42))
    .SetBuffs({32.0, 64.0})
    .Build();
  auto bb = bufobjects::BufferBuilder{};

  bufobjects::WriteIdentifiedTo(bb, character);
  character->Reset();
  bb.Rewind();

  character = dynamic_cast<Character::Ptr>(bufobjects::ReadIdentifiedFrom(bb));

    CHECK_EQ("Bobby", character->GetName());
    CHECK_EQ(3.0f, character->GetSpeed());
    CHECK_EQ(32.0, character->GetBuffs()[0]);
    CHECK_EQ(64.0, character->GetBuffs()[1]);
    CHECK_EQ(-1, character->GetPosition().x);
    CHECK_EQ(1, character->GetPosition().y);

  auto weapon = dynamic_cast<Weapon::Ptr>(character->GetBag()->GetItems(0));
    CHECK_EQ("A", weapon->GetName());
    CHECK_EQ(5, weapon->GetCost());
    CHECK_EQ(Quality::kCommon, weapon->GetQuality());
    CHECK_EQ(10, weapon->GetDamage());
  auto armor = dynamic_cast<Armor::Ptr>(character->GetBag()->GetItems(1));
    CHECK_EQ("B", armor->GetName());
    CHECK_EQ(15, armor->GetCost());
    CHECK_EQ(Quality::kRare, armor->GetQuality());
    CHECK_EQ(15, armor->GetDefense());
  weapon = dynamic_cast<Weapon::Ptr>(character->GetEquipment("MainHand"));
    CHECK_EQ("Knife", weapon->GetName());
    CHECK_EQ(10, weapon->GetCost());
    CHECK_EQ(Quality::kCommon, weapon->GetQuality());
    CHECK_EQ(50, weapon->GetDamage());
  armor = dynamic_cast<Armor::Ptr>(character->GetEquipment("Head"));
    CHECK_EQ("Fedora", armor->GetName());
    CHECK_EQ(42, armor->GetCost());
    CHECK_EQ(Quality::kEpic, armor->GetQuality());
    CHECK_EQ(100, armor->GetDefense());

  delete(character);
}
