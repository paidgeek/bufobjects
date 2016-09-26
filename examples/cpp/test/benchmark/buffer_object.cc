// Generated with https://github.com/paidgeek/bufobjects

#include "buffer_object.h"
#include "gen/bo_test_sub.h"
    #include "gen/bo_test.h"
    

namespace bufobjects {
  void WriteIdentifiedTo(BufferObjectBuilder& _bob, BufferObject::Ptr obj) {
    _bob.WriteUInt16(obj->BufferObjectId());
    obj->WriteTo(_bob);
  }

  BufferObject::Ptr ReadIdentifiedFrom(BufferObjectBuilder& _bob) {
    uint16_t id = _bob.ReadUInt16();
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
      obj->ReadFrom(_bob);
    }
    return obj;
  }
}
