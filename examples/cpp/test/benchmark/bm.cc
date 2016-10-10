#include <chrono>
#include <iostream>
#include <vector>
#include <functional>

#include "flatbuffers/flatbuffers.h"
#include "gen/test_generated.h"
#include "gen/benchbo/bufobjects.h"
#include "gen/benchbo/bench_bo.h"

using namespace bufobjects;
using namespace flatbuffers;

struct Bench {
  std::string name;
  std::function<uint32_t()> perform;
  uint64_t total_time;
  uint32_t len;
  Bench(std::string name, std::function<uint32_t()> perform) : name(name), perform(perform) {
    total_time = 0;
    len = 0;
  }
};

static const uint32_t n = 5;
static const uint32_t m = 10000;
static const int veclen = 3;

#pragma GCC push_options
#pragma GCC optimize ("O0")
volatile void UseCat(benchbo::Cat* cat) {
  cat->GetInitialized();
  cat->GetLocation();
  cat->GetFruit();
  for (uint32_t j = 0; j < cat->GetList().size(); j++) {
    auto bar = cat->GetList(j);
    bar.GetName();
    bar.GetPostfix();
    bar.GetRating();
  }
}

volatile void UseCat(benchfb::Cat* cat) {
  cat->initialized();
  cat->location()->str().length();
  cat->fruit();
  for (uint32_t j = 0; j < cat->list()->Length(); j++) {
    auto bar = cat->list()->Get(j);
    bar->postfix();
    bar->rating();
    bar->name()->str().length();
  }
}
#pragma GCC pop_options

int main() {
  std::vector<Bench*> benchmarks{
    new Bench{
      "FlatBuffers",
      [=]() -> uint32_t {
        uint32_t len = 0;
        FlatBufferBuilder fbb;

        for (uint32_t i = 0; i < m; i++) {
          {
            // encode
            Offset<benchfb::Bar> vec[veclen];
            for (int j = 0; j < veclen; j++) {
              auto foo = benchfb::Foo{
                0xABADCAFEABADCAFE + j, 3.14 * j, '@' + j
              };
              auto name = fbb.CreateString("Hello, World!");
              auto bar = benchfb::CreateBar(fbb, &foo, name, 3.14 * j, '@' + j);

              vec[j] = bar;
            }
            auto location = fbb.CreateString("somewhere");
            auto barvec = fbb.CreateVector(vec, veclen);
            auto cat = benchfb::CreateCat(fbb, barvec, true, benchfb::Fruit_Bananas, location);
            fbb.Finish(cat);
            len = fbb.GetSize();
          }

          {
            auto cat = benchfb::GetCat(fbb.GetBufferPointer());
            UseCat(const_cast<benchfb::Cat*>(cat));
          }

          fbb.Clear();
          fbb.ClearOffsets();
        }

        return len;
      }
    },
    new Bench{
      "BufferObjects",
      [=]() -> uint32_t {
        uint32_t len = 0;
        bufobjects::BufferBuilder bb;

        std::vector<benchbo::Bar> v(veclen);
        for (int j = 0; j < veclen; j++) {
          v.push_back(benchbo::Bar{
            benchbo::Foo{
              0xABADCAFEABADCAFE + j, 3.14 * j, '@' + j
            },
            "Hello, World!",
            3.14 * j,
            '@' + j
          });
        }

        for (uint32_t i = 0; i < m; i++) {
          {
            // encode

            benchbo::Cat::WriteDirectTo(bb, v, true, benchbo::Fruit::kBananas,
                                                    "somewhere");
          }

          len = bb.GetOffset();
          bb.Rewind();

          {
            // decode
            benchbo::Cat cat;
            cat.ReadFrom(bb);

            UseCat(&cat);
          }

          bb.Rewind();
        }

        return len;
      }
    }
  };

  for (int i = 0; i < benchmarks.size() * n; i++) {
    auto b = benchmarks[i % benchmarks.size()];
    auto startTime = std::chrono::high_resolution_clock::now();

    b->len = b->perform();

    b->total_time += std::chrono::duration_cast<std::chrono::milliseconds>(
      std::chrono::high_resolution_clock::now() - startTime).count();
  }

  for (int i = 0; i < benchmarks.size(); i++) {
    auto b = benchmarks[i];
    std::cout << b->name << ": " << (b->total_time / (double) n) << "ms, " << "len: " << b->len
              << std::endl;
  }

  return 0;
}
