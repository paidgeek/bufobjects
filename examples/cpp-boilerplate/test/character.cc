#include "doctest.h"
#include "rpg/rpg.h"

using namespace rpg;

std::unique_ptr<Character> NewCharacter() {
  return std::unique_ptr<Character>{new Character{"Bobby", 3.0f, {32.0, 64.0}}};
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
}

TEST_CASE("CopyFrom") {
  auto character = NewCharacter();
  auto copy = std::unique_ptr<Character>{new Character{}};

  auto hard = *character;
  hard.CopyTo(*copy);

  CHECK_EQ("Bobby", character->GetName());
  CHECK_EQ(3.0f, character->GetSpeed());
  CHECK_EQ(32.0, character->GetBuffs()[0]);
  CHECK_EQ(64.0, character->GetBuffs()[1]);

  CHECK_EQ("Bobby", copy->GetName());
  CHECK_EQ(3.0f, copy->GetSpeed());
  CHECK_EQ(32.0, copy->GetBuffs()[0]);
  CHECK_EQ(64.0, copy->GetBuffs()[1]);
}

TEST_CASE("WriteRead") {
  auto character = NewCharacter();
  auto bob = bufobjects::BufferObjectBuilder{};
}
