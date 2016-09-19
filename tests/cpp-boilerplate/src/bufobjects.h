#ifndef BUFFER_OBJECTS_H
#define BUFFER_OBJECTS_H

#include "bufobjects_util.h"
#include "rpg.h"

namespace bufobjects {

  enum : uint32_t {
    kSimpleId = 1
  };

  inline uint8_t *WriteTo(BufferObject *obj, uint8_t *buf) {
    buf = WriteUInt32(obj->GetBufferObjectId(), buf);
    return obj->WriteTo(buf);
  }

  inline BufferObject *ReadFrom(uint8_t **buf) {
    uint32_t id;
    *buf = ReadUInt32(&id, *buf);
    BufferObject *obj;

    switch (id) {
      case kSimpleId:
        obj = &rpg::Simple{};
        break;
      default:
        return nullptr;
    }

    *buf = obj->ReadFrom(*buf);
    return obj;
  }

}

#endif
