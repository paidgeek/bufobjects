// Generated with https://github.com/paidgeek/bufobjects

#ifndef BUFOBJECTS_BUFFER_OBJECT_H
#define BUFOBJECTS_BUFFER_OBJECT_H

#include <memory>
#include "buffer_object_builder.h"

namespace bufobjects {
  class BufferObject {
  public:
    BufferObject() {}
    virtual uint16_t BufferObjectId() const = 0;
    virtual void Reset() = 0;
    virtual void CopyTo(BufferObject& dst) const = 0;
    virtual void WriteTo(BufferObjectBuilder& bob) const = 0;
    virtual void ReadFrom(BufferObjectBuilder& bob) = 0;
    virtual uint32_t Size() const = 0;

    
    static const uint16_t kRpgCharacterId = 1;
    static const uint16_t kRpgInventoryWeaponId = 2;
    static const uint16_t kRpgInventoryArmorId = 3;
  };

}

#endif