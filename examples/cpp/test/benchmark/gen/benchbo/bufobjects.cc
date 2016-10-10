// Generated with https://github.com/paidgeek/bufobjects

#include "bufobjects.h"

  #include "./../benchbo/bench_bo.h"


namespace bufobjects {

BufferObject* ReadIdentifiedFrom(BufferBuilder& _bb) {
  uint16_t id = _bb.ReadUInt16();
  BufferObject* obj = nullptr;

  switch(id) {
case kBenchBoBarId:
      obj = new benchbo::Bar{};
      obj->ReadFrom(_bb);
    break;
  case kBenchBoCatId:
      obj = new benchbo::Cat{};
      obj->ReadFrom(_bb);
    break;
  }
  return obj;
}

}
