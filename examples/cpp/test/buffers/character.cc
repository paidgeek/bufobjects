#include "doctest.h"
#include "rpg/_all.h"
#include "rpg/inventory/_all.h"

using namespace rpg;
using namespace rpg::inventory;

Character::Ptr NewCharacter() {
  return Character::Builder()
    .Name("Bobby")
    .Position({-1, 1})
    .Speed(3.0f)
    .Bag(Inventory::Builder()
           .Capacity(10)
           .Items({
                    Weapon::New(10, Quality::kCommon, 5, "A"),
                    Armor::New(15, Quality::kRare, 15, "B")
                  })
           .Build())
    .Buffs({32.0, 64.0})
    .Build();
}

TEST_CASE ("CharacterWriteRead") {
  auto character = NewCharacter();
  auto bob = bufobjects::BufferObjectBuilder{};

    CHECK_EQ("Bobby", character->GetName());
    CHECK_EQ(3.0f, character->GetSpeed());
    CHECK_EQ(32.0, character->GetBuffs()[0]);
    CHECK_EQ(64.0, character->GetBuffs()[1]);

  auto weapon = bufobjects::PointerCast<Weapon>(character->GetBag()->GetItemsAt(0));
    CHECK_EQ("A", weapon->GetName());
    CHECK_EQ(5, weapon->GetCost());
    CHECK_EQ(Quality::kCommon, weapon->GetQuality());
    CHECK_EQ(10, weapon->GetDamage());
  auto armor = bufobjects::PointerCast<Armor>(character->GetBag()->GetItemsAt(1));
    CHECK_EQ("B", armor->GetName());
    CHECK_EQ(15, armor->GetCost());
    CHECK_EQ(Quality::kRare, armor->GetQuality());
    CHECK_EQ(10, armor->GetDefense());

  bufobjects::WriteIdentifiedTo(bob, character);
  character->Reset();
  bob.Rewind();

  character = bufobjects::PointerCast<Character>(bufobjects::ReadIdentifiedFrom(bob));

    CHECK_EQ("Bobby", character->GetName());
    CHECK_EQ(3.0f, character->GetSpeed());
    CHECK_EQ(32.0, character->GetBuffs()[0]);
    CHECK_EQ(64.0, character->GetBuffs()[1]);

  weapon = bufobjects::PointerCast<Weapon>(character->GetBag()->GetItemsAt(0));
    CHECK_EQ("A", weapon->GetName());
    CHECK_EQ(5, weapon->GetCost());
    CHECK_EQ(Quality::kCommon, weapon->GetQuality());
    CHECK_EQ(10, weapon->GetDamage());
  armor = bufobjects::PointerCast<Armor>(character->GetBag()->GetItemsAt(1));
    CHECK_EQ("B", armor->GetName());
    CHECK_EQ(15, armor->GetCost());
    CHECK_EQ(Quality::kRare, armor->GetQuality());
    CHECK_EQ(10, armor->GetDefense());

}
