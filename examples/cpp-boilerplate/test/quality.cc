#include "doctest.h"
#include "rpg/inventory/inventory.h"

using namespace rpg;

TEST_CASE("Basics") {
  auto q = rpg::inventory::Quality::kEpic;

  CHECK_EQ("Epic", rpg::inventory::Quality::GetName(q));
}
