// Generated with https://github.com/paidgeek/bufobjects

#include "buffer_object.h"
#include "gen.h"


namespace bufobjects {
  void WriteIdentifiedTo(BufferBuilder& _bb, BufferObject::Ptr obj) {
    _bb.WriteUInt16(obj->BufferObjectId());
    obj->WriteTo(_bb);
  }

  BufferObject::Ptr ReadIdentifiedFrom(BufferBuilder& _bb) {
    uint16_t id = _bb.ReadUInt16();
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
      obj->ReadFrom(_bb);
    }
    return obj;
  }
}
