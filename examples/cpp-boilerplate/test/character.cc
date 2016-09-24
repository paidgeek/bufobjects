#include "doctest.h"
#include "rpg/_all.h"
#include "rpg/inventory/_all.h"

using namespace rpg;

std::shared_ptr<inventory::Inventory> NewInventory() {
  return std::shared_ptr<inventory::Inventory>{new inventory::Inventory{
    10,
    {
      std::shared_ptr<inventory::Item>{new inventory::Weapon{
        5,
        "A",
        inventory::Quality::kCommon,
        10
      }},
      std::shared_ptr<inventory::Item>{new inventory::Armor{
        15,
        "B",
        inventory::Quality::kRare,
        10
      }}
    }
  }};
}

std::shared_ptr<Character> NewCharacter() {
  return std::shared_ptr<Character>{new Character{"Bobby",
                                                  Position{-1, 1},
                                                  3.0f,
                                                  NewInventory(),
                                                  nullptr,
                                                  {32.0, 64.0}}};
}

TEST_CASE ("Basics") {
  auto character = NewCharacter();

    CHECK_EQ("Bobby", character->GetName());
    CHECK_EQ(3.0f, character->GetSpeed());
    CHECK_EQ(32.0, character->GetBuffs()[0]);
    CHECK_EQ(64.0, character->GetBuffs()[1]);

  character->Reset();

    CHECK_EQ("", character->GetName());
    CHECK_EQ(0.0f, character->GetSpeed());
    CHECK_EQ(0.0, character->GetBuffs()[0]);
    CHECK_EQ(0.0, character->GetBuffs()[1]);

  character->SetName("Bobby");
  character->SetSpeed(3.0f);
  character->SetBuffs({32.0, 64.0});

    CHECK_EQ("Bobby", character->GetName());
    CHECK_EQ(3.0f, character->GetSpeed());
    CHECK_EQ(32.0, character->GetBuffs()[0]);
    CHECK_EQ(64.0, character->GetBuffs()[1]);
}
/*
TEST_CASE ("CopyFrom") {
  auto character = NewCharacter();
  auto copy = Character{};

  copy = character;

    CHECK_EQ("Bobby", character.GetName());
    CHECK_EQ(3.0f, character.GetSpeed());
    CHECK_EQ(32.0, character.GetBuffs()[0]);
    CHECK_EQ(64.0, character.GetBuffs()[1]);

    CHECK_EQ("Bobby", copy.GetName());
    CHECK_EQ(3.0f, copy.GetSpeed());
    CHECK_EQ(32.0, copy.GetBuffs()[0]);
    CHECK_EQ(64.0, copy.GetBuffs()[1]);
}

TEST_CASE ("WriteRead") {
  auto character = NewCharacter();
  auto bob = bufobjects::BufferObjectBuilder{};

  character.WriteTo(bob);
  character.Reset();
  bob.Rewind();
  character.ReadFrom(bob);

    CHECK_EQ("Bobby", character.GetName());
    CHECK_EQ(3.0f, character.GetSpeed());
    CHECK_EQ(32.0, character.GetBuffs()[0]);
    CHECK_EQ(64.0, character.GetBuffs()[1]);
}

TEST_CASE("WriteReadIdentified") {
  auto character = NewCharacter();
}
*/