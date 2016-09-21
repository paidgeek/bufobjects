#include "gtest/gtest.h"
#include "rpg.h"

using namespace rpg;

std::unique_ptr<Character> NewCharacter() {
  return Character::Builder()
    .SetName("Bobby")
    .SetSpeed(3.0f)
    .SetBuffs({32.0, 64.0})
    .Build();
}

TEST(Character, Basics) {
  auto character = NewCharacter();

  ASSERT_EQ("Bobby", character->GetName());
  ASSERT_EQ(3.0f, character->GetSpeed());
  ASSERT_EQ(32.0, character->GetBuffs()[0]);
  ASSERT_EQ(64.0, character->GetBuffs()[1]);

  character->Reset();

  ASSERT_EQ("", character->GetName());
  ASSERT_EQ(0.0f, character->GetSpeed());
  ASSERT_EQ(0.0, character->GetBuffs()[0]);
  ASSERT_EQ(0.0, character->GetBuffs()[1]);
}

TEST(Character, CopyFrom) {
  auto character = NewCharacter();
  auto copy = character->New();

  auto hard = *character;

  copy->CopyFrom(hard);

  ASSERT_EQ("Bobby", character->GetName());
  ASSERT_EQ(3.0f, character->GetSpeed());
  ASSERT_EQ(32.0, character->GetBuffs()[0]);
  ASSERT_EQ(64.0, character->GetBuffs()[1]);

  ASSERT_EQ("Bobby", copy->GetName());
  ASSERT_EQ(3.0f, copy->GetSpeed());
  ASSERT_EQ(32.0, copy->GetBuffs()[0]);
  ASSERT_EQ(64.0, copy->GetBuffs()[1]);
}

TEST(Character, WriteRead) {
  auto character = NewCharacter();
  auto bob = bufobjects::BufferObjectBuilder{};
}
