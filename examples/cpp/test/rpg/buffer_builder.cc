#include "doctest.h"
#include "rpg/bufobjects.h"

using namespace bufobjects;

TEST_CASE ("Ints") {
  BufferBuilder bb;

  bb.WriteInt8(-42);
  bb.WriteUInt8(42);
  bb.WriteInt16(-42);
  bb.WriteUInt16(42);
  bb.WriteInt32(-42);
  bb.WriteUInt32(42);
  bb.WriteInt64(-42);
  bb.WriteUInt64(42);

  bb.Rewind();

  CHECK_EQ(-42, bb.ReadInt8());
  CHECK_EQ(42, bb.ReadUInt8());
  CHECK_EQ(-42, bb.ReadInt16());
  CHECK_EQ(42, bb.ReadUInt16());
  CHECK_EQ(-42, bb.ReadInt32());
  CHECK_EQ(42, bb.ReadUInt32());
  CHECK_EQ(-42, bb.ReadInt64());
  CHECK_EQ(42, bb.ReadUInt64());
}

TEST_CASE ("Grow") {
  BufferBuilder bb{std::unique_ptr<BufferAllocator>{ new HeapBufferAllocator{} }, 5, 10000};

  for (int i = 0; i < 1000; i++) {
    if (bb.GetRemaining() < 8) {
      bb.GrowBuffer(8);
    }

    bb.WriteUInt64(static_cast<uint64_t>(i));
  }

  bb.Rewind();

  for (int i = 0; i < 1000; i++) {
      CHECK_EQ(i, bb.ReadUInt64());
  }
}

TEST_CASE ("VarInt32") {
  BufferBuilder bb;

  bb.WriteVarUInt32(42);
  bb.WriteVarUInt32(UINT32_MAX);
  bb.WriteVarInt32(-13);
  bb.WriteVarInt32(13);
  bb.WriteVarInt32(-923434);
  bb.WriteVarInt32(INT32_MAX);

  bb.Rewind();

  CHECK_EQ(42, bb.ReadVarUInt32());
  CHECK_EQ(UINT32_MAX, bb.ReadVarUInt32());
  CHECK_EQ(-13, bb.ReadVarInt32());
  CHECK_EQ(13, bb.ReadVarInt32());
  CHECK_EQ(-923434, bb.ReadVarInt32());
  CHECK_EQ(INT32_MAX, bb.ReadVarInt32());
}

TEST_CASE ("VarInt64") {
  BufferBuilder bb;

  bb.WriteVarUInt64(42);
  bb.WriteVarUInt64(UINT64_MAX);
  bb.WriteVarInt64(-13);
  bb.WriteVarInt64(13);
  bb.WriteVarInt64(-923434);
  bb.WriteVarInt64(INT64_MAX);

  bb.Rewind();

  CHECK_EQ(42, bb.ReadVarUInt64());
  CHECK_EQ(UINT64_MAX, bb.ReadVarUInt64());
  CHECK_EQ(-13, bb.ReadVarInt64());
  CHECK_EQ(13, bb.ReadVarInt64());
  CHECK_EQ(-923434, bb.ReadVarInt64());
  CHECK_EQ(INT64_MAX, bb.ReadVarInt64());
}

TEST_CASE ("Floats") {
  BufferBuilder bb;

  bb.WriteFloat32(3.14f);
  bb.WriteFloat64(3.14);
  bb.WriteFloat32(-34500.4354360f);
  bb.WriteFloat64(-9235934.00002344);

  bb.Rewind();

  CHECK_EQ(3.14f, bb.ReadFloat32());
  CHECK_EQ(3.14, bb.ReadFloat64());
  CHECK_EQ(-34500.4354360f, bb.ReadFloat32());
  CHECK_EQ(-9235934.00002344, bb.ReadFloat64());
}

TEST_CASE ("String") {
  BufferBuilder bb;

  bb.WriteString("Hello, World!");
  bb.WriteString("");

  bb.Rewind();

  CHECK_EQ("Hello, World!", bb.ReadString());
  CHECK_EQ("", bb.ReadString());
}
