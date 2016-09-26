// Generated with https://github.com/paidgeek/bufobjects

#include "buffer_object.h"
#include "gen/bo_test_sub.h"
    #include "gen/bo_test.h"
    

namespace bufobjects {
  void WriteIdentifiedTo(BufferObjectBuilder& bob, BufferObject::Ptr obj) {
    bob.WriteUInt16(obj->BufferObjectId());
    obj->WriteTo(bob);
  }

  BufferObject::Ptr ReadIdentifiedFrom(BufferObjectBuilder& bob) {
    uint16_t id = bob.ReadUInt16();
    BufferObject::Ptr obj;

    switch(id) {
case kGenBoTestSubId:
      obj = new gen::BoTestSub();
      break;
    case kGenBoTestId:
      obj = new gen::BoTest();
      break;
    }
    if(obj) {
      obj->ReadFrom(bob);
    }
    return obj;
  }
}
