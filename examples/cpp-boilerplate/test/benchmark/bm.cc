#include <chrono>
#include <iostream>
#include <vector>
#include <functional>

#include "flatbuffers/flatbuffers.h"
#include "gen/_all.h"
#include "gen/test_generated.h"

using namespace bufobjects;
using namespace gen;
using namespace flatbuffers;

int main() {
  std::vector<std::function<void()>> funcs;
  std::vector<int32_t> v = {432, 534, 3, 4, 645, 4, 2, 3, 64, 57, 56, 8};
  std::vector<std::string> names = {"FlatBuffers", "BufferObjects"};
  std::array<uint64_t, 2> times{};
  const uint32_t n = 100;
  const uint32_t m = 1000;

  funcs.push_back([&]() {
    FlatBufferBuilder fbb{};

    auto sub = CreateFlatTestSub(fbb, 42.0f, 2.0);
    auto off = CreateFlatTestDirect(fbb, "ksgjdorghjdklhmklsejmfw", &v, sub);
    FinishFlatTestBuffer(fbb, off);

    auto test = GetFlatTest(fbb.GetBufferPointer());
    test->strValue()->str();
    test->intArray();
    test->sub()->x();
    test->sub()->y();
  });
  funcs.push_back([&]() {
    BufferObjectBuilder bob{};
    auto test = BoTest::Builder()
      .SetStrValue("ksgjdorghjdklhmklsejmfw")
      .SetIntArray(v)
      .SetSub(BoTestSub::Builder()
                .SetY(42.0f)
                .SetY(2.0)
                .Build())
      .Build();

    test->WriteTo(bob);
    bob.Rewind();
    test->ReadFrom(bob);

    test->GetStrValue();
    test->GetIntArray();
    test->GetSub()->GetX();
    test->GetSub()->GetY();
  });

  for (uint32_t i = 0; i < funcs.size() * n; i++) {
    auto startTime = std::chrono::high_resolution_clock::now();
    for (uint32_t j = 0; j < m; j++) {
      funcs[i % funcs.size()]();
    }

    times[i % funcs.size()] += std::chrono::duration_cast<std::chrono::milliseconds>(
      std::chrono::high_resolution_clock::now() - startTime).count();
  }

  for (uint32_t i = 0; i < funcs.size(); i++) {
    std::cout << names[i] << ": " <<  (times[i] / (double) n) << "ms" << std::endl;
  }

  return 0;
}
