#include "gtest/gtest.h"
#include "rpg.h"

void PrintBuffer(uint8_t *buf, int len) {
  for(int i = 0; i < len; i++){
    std::cout << (int)(buf[i]);
    if(i < len - 1) {
      std::cout << ", ";
    }
  }
  std::cout << std::endl;
}

TEST(Simple, Simple) {
  rpg::Simple simple{"Bobby", 42.0, {1, 1, 2, 3, 5}, {3.14f, 0.72f}};
  ASSERT_EQ("Bobby", simple.name);
  ASSERT_EQ(42.0, simple.value);
  ASSERT_EQ(1, simple.list[0]);
  ASSERT_EQ(1, simple.list[1]);
  ASSERT_EQ(2, simple.list[2]);
  ASSERT_EQ(3, simple.list[3]);
  ASSERT_EQ(5, simple.list[4]);
  ASSERT_EQ(3.14f, simple.arr[0]);
  ASSERT_EQ(0.72f, simple.arr[1]);

  simple.Reset();
  ASSERT_EQ("", simple.name);
  ASSERT_EQ(0, simple.value);
  ASSERT_EQ(0, simple.list.size());
  ASSERT_EQ(0.0f, simple.arr[0]);
  ASSERT_EQ(0.0f, simple.arr[1]);
}

TEST(Simple, SimpleWriteRead) {
  rpg::Simple simple{"Bobby", 42.0, {1, 1, 2, 3, 5}, {3.14f, 0.72f}};
  uint8_t *buf = new uint8_t[1024];
  memset(buf, 0, 1024);

  simple.WriteTo(buf);
  simple.Reset();
  simple.ReadFrom(buf);

  ASSERT_EQ("Bobby", simple.name);
  ASSERT_EQ(42.0, simple.value);
  ASSERT_EQ(1, simple.list[0]);
  ASSERT_EQ(1, simple.list[1]);
  ASSERT_EQ(2, simple.list[2]);
  ASSERT_EQ(3, simple.list[3]);
  ASSERT_EQ(5, simple.list[4]);
  ASSERT_EQ(3.14f, simple.arr[0]);
  ASSERT_EQ(0.72f, simple.arr[1]);

  delete[](buf);
}
