#include <chrono>
#include <iostream>
#include <vector>
#include <functional>

#include "flatbuffers/flatbuffers.h"
#include "gen/test_generated.h"
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

int main() {
  const uint32_t n = 50;
  const uint32_t m = 10000;
  const int veclen = 3;

  std::vector<Bench *> benchmarks{
    new Bench{
      "FlatBuffers",
      []() -> uint32_t {
        uint32_t len = 0;
        FlatBufferBuilder fbb;

        {
          // encode
          Offset<benchfb::FooBar> vec[veclen];
          for (int i = 0; i < veclen; i++) {
            auto foo = benchfb::Foo(0xABADCAFEABADCAFE + i, 10000 + i, '@' + i, 1000000 + i);
            auto bar = benchfb::Bar(foo, 123456 + i, 3.14159f + i, 10000 + i);
            auto name = fbb.CreateString("Hello, World!");
            auto foobar = benchfb::CreateFooBar(fbb, &bar, name, 3.1415432432445543543 + i,
                                                '!' + i);
            vec[i] = foobar;
          }
          auto location = fbb.CreateString("https://github.com/paidgeek/bufobjects");
          auto foobarvec = fbb.CreateVector(vec, veclen);
          auto foobarcontainer = CreateFooBarContainer(fbb, foobarvec, true,
                                                       benchfb::Fruit_Bananas, location);
          fbb.Finish(foobarcontainer);
          len = fbb.GetSize();
        }

        {
          auto foobarcontainer = benchfb::GetFooBarContainer(fbb.GetBufferPointer());
          foobarcontainer->initialized();
          foobarcontainer->location()->Length();
          foobarcontainer->fruit();
          for (unsigned int i = 0; i < foobarcontainer->list()->Length(); i++) {
            auto foobar = foobarcontainer->list()->Get(i);
            foobar->name()->Length();
            foobar->postfix();
            foobar->rating();
            auto bar = foobar->sibling();
            bar->ratio();
            bar->size();
            bar->time();
            auto &foo = bar->parent();
            foo.count();
            foo.id();
            foo.length();
            foo.prefix();
          }
        }

        return len;
      }
    },
    new Bench{
      "BufferObjects",
      []() -> uint32_t {
        uint32_t len = 0;
        bufobjects::BufferBuilder bb{};

        {
          // encode
          std::vector<benchbo::FooBar*> v;
          for (int i = 0; i < veclen; i++) {
            v.push_back(new benchbo::FooBar{
              benchbo::Bar{
                benchbo::Foo{
                  0xABADCAFEABADCAFE + i,
                  10000 + i,
                  '@' + i,
                  1000000 + i
                },
                123456 + i,
                3.14159f + i,
                10000 + i
              },
              "Hello, World!",
              3.1415432432445543543 + i,
              '!' + i
            });
          }
          benchbo::FooBarContainer::WriteDirectTo(bb, v, true, benchbo::Fruit::kBananas, "https://github.com/paidgeek/bufobjects");
        }

        len = bb.GetOffset();
        bb.Rewind();

        {
          // decode
          auto foobarcontainer = new benchbo::FooBarContainer{};
          foobarcontainer->ReadFrom(bb);

          foobarcontainer->GetInitialized();
          foobarcontainer->GetLocation();
          foobarcontainer->GetFruit();
          for (unsigned int i = 0; i < foobarcontainer->GetList().size(); i++) {
            auto foobar = foobarcontainer->GetList(i);
            foobar->GetName();
            foobar->GetPostfix();
            foobar->GetRating();
            auto bar = foobar->GetSibling();
            bar.ratio;
            bar.size;
            bar.time;
            auto foo = bar.parent;
            foo.count;
            foo.id;
            foo.length;
            foo.prefix;
          }
        }

        return len;
      }
    }
  };

  for (int i = 0; i < benchmarks.size() * n; i++) {
    auto b = benchmarks[i % benchmarks.size()];
    auto startTime = std::chrono::high_resolution_clock::now();

    for(int j = 0; j < m; j++) {
      b->len = b->perform();
    }

    b->total_time += std::chrono::duration_cast<std::chrono::milliseconds>(
      std::chrono::high_resolution_clock::now() - startTime).count();
  }

  for (int i = 0; i < benchmarks.size(); i++) {
    auto b = benchmarks[i];
    std::cout << b->name << ": " << (b->total_time / (double) n) << "ms, " << "len: " << b->len << std::endl;
  }

  return 0;
}
