#include "../doctest.h"
#include "rpg/rpg/_all.h"
#include "rpg/rpg/inventory/_all.h"

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
    .Equipment("MainHand", Weapon::New(50, Quality::kCommon, 10, "Knife"))
    .Equipment("Head", Armor::New(100, Quality::kEpic, 42, "Fedora"))
    .Buffs({32.0, 64.0})
    .Build();
}

void CheckCharacter(Character::Ptr character) {
    CHECK_EQ("Bobby", character->GetName());
    CHECK_EQ(3.0f, character->GetSpeed());
    CHECK_EQ(32.0, character->GetBuffs()[0]);
    CHECK_EQ(64.0, character->GetBuffs()[1]);

  auto weapon = static_cast<Weapon*>(character->GetBag()->GetItems(0));
    CHECK_EQ("A", weapon->GetName());
    CHECK_EQ(5, weapon->GetCost());
    CHECK_EQ(Quality::kCommon, weapon->GetQuality());
    CHECK_EQ(10, weapon->GetDamage());
  auto armor = static_cast<Armor*>(character->GetBag()->GetItems(1));
    CHECK_EQ("B", armor->GetName());
    CHECK_EQ(15, armor->GetCost());
    CHECK_EQ(Quality::kRare, armor->GetQuality());
    CHECK_EQ(10, armor->GetDefense());
  weapon = static_cast<Weapon*>(character->GetEquipment("MainHand"));
    CHECK_EQ("Knife", weapon->GetName());
    CHECK_EQ(10, weapon->GetCost());
    CHECK_EQ(Quality::kCommon, weapon->GetQuality());
    CHECK_EQ(50, weapon->GetDamage());
  armor = static_cast<Armor*>(character->GetEquipment("Head"));
    CHECK_EQ("Fedora", armor->GetName());
    CHECK_EQ(42, armor->GetCost());
    CHECK_EQ(Quality::kEpic, armor->GetQuality());
    CHECK_EQ(100, armor->GetDefense());
}

TEST_CASE ("CharacterWriteRead") {
  auto character = NewCharacter();
  auto bob = bufobjects::BufferObjectBuilder{};

  CheckCharacter(character);

  bufobjects::WriteIdentifiedTo(bob, character);
  character->Reset();
  bob.Rewind();

  character = static_cast<Character*>(bufobjects::ReadIdentifiedFrom(bob));

  CheckCharacter(character);

  delete(character);
}
