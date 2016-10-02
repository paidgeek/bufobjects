// Generated with https://github.com/paidgeek/bufobjects

#include "buffer_object.h"

  #include "./../benchbo/bench_bo.h"


namespace bufobjects {

BufferObject* ReadIdentifiedFrom(BufferBuilder& _bb) {
  uint16_t id = _bb.ReadUInt16();
  BufferObject* obj = nullptr;

  switch(id) {
case kBenchBoFooBarId:
      obj = new benchbo::FooBar{};
    break;
  case kBenchBoFooBarContainerId:
      obj = new benchbo::FooBarContainer{};
    break;
  }
  if(obj != nullptr) {
    obj->ReadFrom(_bb);
  }
  return obj;
}

}
