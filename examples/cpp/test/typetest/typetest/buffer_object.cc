// Generated with https://github.com/paidgeek/bufobjects

#include "buffer_object.h"

  #include "./../typetest/typetest.h"


namespace bufobjects {

BufferObject* ReadIdentifiedFrom(BufferBuilder& _bb) {
  uint16_t id = _bb.ReadUInt16();
  BufferObject* obj = nullptr;

  switch(id) {
case ktypetestSmallClassId:
      obj = new typetest::SmallClass{};
    break;
  case ktypetestTypeTestId:
      obj = new typetest::TypeTest{};
    break;
  }
  if(obj != nullptr) {
    obj->ReadFrom(_bb);
  }
  return obj;
}

}
