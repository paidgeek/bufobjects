#include "../doctest.h"
#include "typetest/_all.h"
#include <iostream>

using namespace typetest;

TypeTest::Ptr CreateObj() {
  return TypeTest::Builder()
    .UInt(4325)
    .SInt(-91)
    .String("Hello")

    .IntArray({85, 325, 9068})
    .IntVector({439643, 3, 125})
    .StringArray({"awdikj", "d", "wPFLW#KPLGW$TGLKWE$LKT$WEOLT"})
    .StringVector({"sefghg", "a", "seogjosjgeow4gje4o5jzmheokz"})
    .IntStringMap({{20,       "20"},
                   {42,       "42"},
                   {43239466, "g4weowj4tg9304tu9405uj04r59"}})

    .FClass(SmallClass::New(42))
    .FClassArray({SmallClass::New(42), SmallClass::New(42), SmallClass::New(42)})
    .FClassVector({SmallClass::New(42), SmallClass::New(42), SmallClass::New(42)})
    .FClassMap("1", SmallClass::New(42))
    .FClassMap("jofwj4oejgo", SmallClass::New(42))

    .FStruct(SmallStruct{42})
    .FStructArray({SmallStruct{42}, SmallStruct{42}, SmallStruct{42}})
    .FStructVector({SmallStruct{42}, SmallStruct{42}, SmallStruct{42}})
    .FStructMap(1, SmallStruct{42})
    .FStructMap(32958, SmallStruct{42})

    .Build();
}

void CheckObj(TypeTest::Ptr obj) {
    CHECK_EQ(4325, obj->GetUInt());
    CHECK_EQ(-91, obj->GetSInt());
    CHECK_EQ("Hello", obj->GetString());

    CHECK_EQ(85, obj->GetIntArray(0));
    CHECK_EQ(325, obj->GetIntArray(1));
    CHECK_EQ(9068, obj->GetIntArray(2));
    CHECK_EQ(439643, obj->GetIntVector(0));
    CHECK_EQ(3, obj->GetIntVector(1));
    CHECK_EQ(125, obj->GetIntVector(2));
    CHECK_EQ("awdikj", obj->GetStringArray(0));
    CHECK_EQ("d", obj->GetStringArray(1));
    CHECK_EQ("wPFLW#KPLGW$TGLKWE$LKT$WEOLT", obj->GetStringArray(2));
    CHECK_EQ("sefghg", obj->GetStringVector(0));
    CHECK_EQ("a", obj->GetStringVector(1));
    CHECK_EQ("seogjosjgeow4gje4o5jzmheokz", obj->GetStringVector(2));
    CHECK_EQ("20", obj->GetIntStringMap(20));
    CHECK_EQ("42", obj->GetIntStringMap(42));
    CHECK_EQ("g4weowj4tg9304tu9405uj04r59", obj->GetIntStringMap(43239466));

    CHECK_EQ(42, obj->GetFClass()->GetValue());
  for (auto &e : obj->GetFClassArray()) {
      CHECK_EQ(42, e->GetValue());
  }
  for (auto &e : obj->GetFClassVector()) {
      CHECK_EQ(42, e->GetValue());
  }
    CHECK_EQ(42, obj->GetFClassMap("1")->GetValue());
    CHECK_EQ(42, obj->GetFClassMap("jofwj4oejgo")->GetValue());

    CHECK_EQ(42, obj->GetFStruct().value_);
  for (auto &e : obj->GetFStructArray()) {
      CHECK_EQ(42, e.value_);
  }
  for (auto &e : obj->GetFStructVector()) {
      CHECK_EQ(42, e.value_);
  }
    CHECK_EQ(42, obj->GetFStructMap(1).value_);
    CHECK_EQ(42, obj->GetFStructMap(32958).value_);
}

TEST_CASE ("SmallClass") {
  auto obj = SmallClass::New(42);
  auto bob = bufobjects::BufferObjectBuilder{};

    CHECK_EQ(42, obj->GetValue());
  obj->WriteTo(bob);
    CHECK_EQ(obj->Size(), bob.GetOffset());

  obj->Reset();
  bob.Rewind();
  obj->ReadFrom(bob);

    CHECK_EQ(42, obj->GetValue());

  delete (obj);
}

TEST_CASE ("SmallStruct") {
  auto obj = SmallStruct{42};
  auto bob = bufobjects::BufferObjectBuilder{};

    CHECK_EQ(42, obj.value_);
  obj.WriteTo(bob);
    CHECK_EQ(sizeof(SmallStruct), bob.GetOffset());

  obj.Reset();
  bob.Rewind();
  obj.ReadFrom(bob);

    CHECK_EQ(42, obj.value_);
}

TEST_CASE ("TypeTest") {
  auto obj = CreateObj();
  auto bob = bufobjects::BufferObjectBuilder{};

  CheckObj(obj);
  obj->WriteTo(bob);

  CHECK_EQ(obj->Size(), bob.GetOffset());

  obj->Reset();
  bob.Rewind();

  obj->ReadFrom(bob);
  CheckObj(obj);

  delete (obj);
}
