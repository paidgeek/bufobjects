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

TEST(BufferObjects, WriteAndRead) {
  uint8_t *buf = new uint8_t[1024];
  uint8_t *p = buf;

  p = bufobjects::WriteBool(true, p);
  p = bufobjects::WriteBool(false, p);
  p = bufobjects::WriteInt8(-42, p);
  p = bufobjects::WriteUInt8(42, p);
  p = bufobjects::WriteInt16(-1337, p);
  p = bufobjects::WriteUInt16(1337, p);
  p = bufobjects::WriteInt32(-1337, p);
  p = bufobjects::WriteUInt32(1337, p);
  p = bufobjects::WriteInt64(-1337, p);
  p = bufobjects::WriteUInt64(1337, p);

  PrintBuffer(buf, 32);

  p = buf;
  bool v1, v2;
  int8_t v3;
  uint8_t v4;
  int16_t v5;
  uint16_t v6;
  int32_t v7;
  uint32_t v8;
  int64_t v9;
  uint64_t v10;
  p = bufobjects::ReadBool(&v1, p);
  p = bufobjects::ReadBool(&v2, p);
  p = bufobjects::ReadInt8(&v3, p);
  p = bufobjects::ReadUInt8(&v4, p);
  p = bufobjects::ReadInt16(&v5, p);
  p = bufobjects::ReadUInt16(&v6, p);
  p = bufobjects::ReadInt32(&v7, p);
  p = bufobjects::ReadUInt32(&v8, p);
  p = bufobjects::ReadInt64(&v9, p);
  p = bufobjects::ReadUInt64(&v10, p);

  ASSERT_TRUE(v1);
  ASSERT_FALSE(v2);
  ASSERT_EQ(-42, v3);
  ASSERT_EQ(42, v4);
  ASSERT_EQ(-1337, v5);
  ASSERT_EQ(1337, v6);
  ASSERT_EQ(-1337, v7);
  ASSERT_EQ(1337, v8);
  ASSERT_EQ(-1337, v9);
  ASSERT_EQ(1337, v10);

  delete[](buf);
}

TEST(BufferObjects, Simple) {
  rpg::Simple simple{"Bobby", 42.0, {1, 1, 2, 3, 5}};
  ASSERT_EQ("Bobby", simple.name);
  ASSERT_EQ(42.0, simple.value);
  ASSERT_EQ(2, simple.arr[2]);
  ASSERT_EQ(3, simple.arr[3]);
  ASSERT_EQ(5, simple.arr[4]);

  simple.Reset();
  ASSERT_EQ("", simple.name);
  ASSERT_EQ(0, simple.value);
  ASSERT_EQ(0, simple.arr.size());
}

TEST(BufferObjects, SimpleWriteTo) {
  rpg::Simple simple{"Bobby", 42.0, {1, 1, 2, 3, 5}};
  uint8_t *buf = new uint8_t[48];

  simple.WriteTo(buf);

  delete[](buf);
}
