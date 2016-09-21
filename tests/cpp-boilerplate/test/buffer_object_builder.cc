#include "gtest/gtest.h"
#include "bufobjects/bufobjects.h"

using namespace bufobjects;

TEST(BufferObjectBuilder, Ints) {
  auto bob = BufferObjectBuilder{};

  bob.WriteInt8(-42);
  bob.WriteUInt8(42);
  bob.WriteInt16(-42);
  bob.WriteUInt16(42);
  bob.WriteInt32(-42);
  bob.WriteUInt32(42);
  bob.WriteInt64(-42);
  bob.WriteUInt64(42);

  bob.Rewind();

  ASSERT_EQ(-42, bob.ReadInt8());
  ASSERT_EQ(42, bob.ReadUInt8());
  ASSERT_EQ(-42, bob.ReadInt16());
  ASSERT_EQ(42, bob.ReadUInt16());
  ASSERT_EQ(-42, bob.ReadInt32());
  ASSERT_EQ(42, bob.ReadUInt32());
  ASSERT_EQ(-42, bob.ReadInt64());
  ASSERT_EQ(42, bob.ReadUInt64());
}

TEST(BufferObjectBuilder, Grow) {
  auto bob = BufferObjectBuilder{5, 10000};

  for (int i = 0; i < 1000; i++) {
    if(bob.GetRemaining() < 8) {
      bob.GrowBuffer(8);
    }

    bob.WriteUInt64(static_cast<uint64_t>(i));
  }

  bob.Rewind();

  for (int i = 0; i < 1000; i++) {
    ASSERT_EQ(i, bob.ReadUInt64());
  }
}

TEST(BufferObjectBuilder, VarInt32) {
  auto bob = BufferObjectBuilder{};

  bob.WriteVarUInt32(42);
  bob.WriteVarUInt32(UINT32_MAX);
  bob.WriteVarInt32(-13);
  bob.WriteVarInt32(13);
  bob.WriteVarInt32(-923434);
  bob.WriteVarInt32(INT32_MAX);

  bob.Rewind();

  ASSERT_EQ(42, bob.ReadVarUInt32());
  ASSERT_EQ(UINT32_MAX, bob.ReadVarUInt32());
  ASSERT_EQ(-13, bob.ReadVarInt32());
  ASSERT_EQ(13, bob.ReadVarInt32());
  ASSERT_EQ(-923434, bob.ReadVarInt32());
  ASSERT_EQ(INT32_MAX, bob.ReadVarInt32());
}

TEST(BufferObjectBuilder, VarInt64) {
  auto bob = BufferObjectBuilder{};

  bob.WriteVarUInt64(42);
  bob.WriteVarUInt64(UINT64_MAX);
  bob.WriteVarInt64(-13);
  bob.WriteVarInt64(13);
  bob.WriteVarInt64(-923434);
  bob.WriteVarInt64(INT64_MAX);

  bob.Rewind();

  ASSERT_EQ(42, bob.ReadVarUInt64());
  ASSERT_EQ(UINT64_MAX, bob.ReadVarUInt64());
  ASSERT_EQ(-13, bob.ReadVarInt64());
  ASSERT_EQ(13, bob.ReadVarInt64());
  ASSERT_EQ(-923434, bob.ReadVarInt64());
  ASSERT_EQ(INT64_MAX, bob.ReadVarInt64());
}

TEST(BufferObjectBuilder, Floats) {
  auto bob = BufferObjectBuilder{};

  bob.WriteFloat32(3.14f);
  bob.WriteFloat64(3.14);
  bob.WriteFloat32(-34500.4354360f);
  bob.WriteFloat64(-9235934.00002344);

  bob.Rewind();

  ASSERT_EQ(3.14f, bob.ReadFloat32());
  ASSERT_EQ(3.14, bob.ReadFloat64());
  ASSERT_EQ(-34500.4354360f, bob.ReadFloat32());
  ASSERT_EQ(-9235934.00002344, bob.ReadFloat64());
}

TEST(BufferObjectBuilder, String) {
  auto bob = BufferObjectBuilder{};

  bob.WriteString("Hello, World!");
  bob.WriteString("");

  bob.Rewind();

  ASSERT_EQ("Hello, World!", bob.ReadString());
  ASSERT_EQ("", bob.ReadString());
}
