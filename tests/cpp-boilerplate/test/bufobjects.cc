#include "gtest/gtest.h"
#include "bufobjects.h"

TEST(BufferObjects, VarInt32) {
  uint8_t *buf = new uint8_t[1024];
  memset(buf, 0, 1024);

  uint8_t *p = buf;

  p = bufobjects::WriteVarUInt32(42, p);
  p = bufobjects::WriteVarUInt32(UINT32_MAX, p);
  p = bufobjects::WriteVarInt32(-13, p);
  p = bufobjects::WriteVarInt32(13, p);
  p = bufobjects::WriteVarInt32(-923434, p);
  p = bufobjects::WriteVarInt32(INT32_MAX, p);

  p = buf;
  uint32_t v1 = 0, v2 = 0;
  int32_t v3 = 0, v4 = 0, v5 = 0, v6 = 0;

  p = bufobjects::ReadVarUInt32(&v1, p);
  p = bufobjects::ReadVarUInt32(&v2, p);
  p = bufobjects::ReadVarInt32(&v3, p);
  p = bufobjects::ReadVarInt32(&v4, p);
  p = bufobjects::ReadVarInt32(&v5, p);
  p = bufobjects::ReadVarInt32(&v6, p);

  ASSERT_EQ(42, v1);
  ASSERT_EQ(UINT32_MAX, v2);
  ASSERT_EQ(-13, v3);
  ASSERT_EQ(13, v4);
  ASSERT_EQ(-923434, v5);
  ASSERT_EQ(INT32_MAX, v6);

  delete[](buf);
}

TEST(BufferObjects, VarInt64) {
  uint8_t *buf = new uint8_t[1024];
  memset(buf, 0, 1024);
  uint8_t *p = buf;

  p = bufobjects::WriteVarUInt64(42, p);
  p = bufobjects::WriteVarUInt64(UINT64_MAX, p);
  p = bufobjects::WriteVarInt64(-13, p);
  p = bufobjects::WriteVarInt64(13, p);
  p = bufobjects::WriteVarInt64(-923434, p);
  p = bufobjects::WriteVarInt64(INT64_MAX, p);

  p = buf;
  uint64_t v1 = 0, v2 = 0;
  int64_t v3 = 0, v4 = 0, v5 = 0, v6 = 0;

  p = bufobjects::ReadVarUInt64(&v1, p);
  p = bufobjects::ReadVarUInt64(&v2, p);
  p = bufobjects::ReadVarInt64(&v3, p);
  p = bufobjects::ReadVarInt64(&v4, p);
  p = bufobjects::ReadVarInt64(&v5, p);
  p = bufobjects::ReadVarInt64(&v6, p);

  ASSERT_EQ(42, v1);
  ASSERT_EQ(UINT64_MAX, v2);
  ASSERT_EQ(-13, v3);
  ASSERT_EQ(13, v4);
  ASSERT_EQ(-923434, v5);
  ASSERT_EQ(INT64_MAX, v6);

  delete[](buf);
}

TEST(BufferObjects, String) {
  uint8_t *buf = new uint8_t[1024];
  memset(buf, 0, 1024);
  uint8_t *p = buf;

  p = bufobjects::WriteString("Hello, World!", p);
  p = bufobjects::WriteString("", p);

  p = buf;
  std::string s;
  p = bufobjects::ReadString(&s, p);
  ASSERT_EQ("Hello, World!", s);
  p = bufobjects::ReadString(&s, p);
  ASSERT_EQ("", s);

  delete[](buf);
}

TEST(BufferObject, WriteRead) {
  uint8_t *buf = new uint8_t[1024];
  memset(buf, 0, 1024);
  uint8_t *p = buf;

  rpg::Simple simple{"Bobby", 42.0, {1, 1, 2, 3, 5}, {3.14f, 0.72f}};

  p = bufobjects::WriteTo(&simple, p);
  simple.Reset();
  p = buf;

  bufobjects::BufferObject *bo = bufobjects::ReadFrom(&p);
  simple = *static_cast<rpg::Simple*>(bo);

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
