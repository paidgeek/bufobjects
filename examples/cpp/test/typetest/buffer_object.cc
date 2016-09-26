// Generated with https://github.com/paidgeek/bufobjects

#include "buffer_object.h"
#include "typetest/small_class.h"
    #include "typetest/type_test.h"
    

namespace bufobjects {
  void WriteIdentifiedTo(BufferObjectBuilder& _bob, BufferObject::Ptr obj) {
    _bob.WriteUInt16(obj->BufferObjectId());
    obj->WriteTo(_bob);
  }

  BufferObject::Ptr ReadIdentifiedFrom(BufferObjectBuilder& _bob) {
    uint16_t id = _bob.ReadUInt16();
    BufferObject::Ptr obj;

    switch(id) {
case ktypetestSmallClassId:
      obj = new typetest::SmallClass();
      break;
    case ktypetestTypeTestId:
      obj = new typetest::TypeTest();
      break;
    }
    if(obj) {
      obj->ReadFrom(_bob);
    }
    return obj;
  }
}
