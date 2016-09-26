// Generated with https://github.com/paidgeek/bufobjects

#ifndef BUFOBJECTS_BUFFER_OBJECT_H
#define BUFOBJECTS_BUFFER_OBJECT_H

#include <memory>
#include <vector>
#include <map>
#include <array>
#include <functional>
#include "buffer_object_builder.h"

namespace bufobjects {

  class BufferObject {
  public:
  typedef BufferObject* Ptr;
    BufferObject() {}
    virtual uint16_t BufferObjectId() const = 0;
    virtual void Reset() = 0;
    virtual void CopyTo(BufferObject& dst) const = 0;
    virtual void WriteTo(BufferObjectBuilder& bob) const = 0;
    virtual void ReadFrom(BufferObjectBuilder& bob) = 0;
    virtual uint32_t Size() const = 0;

  };

  
  
        
        
        
        
  enum BufferObjectIds : uint16_t {
    kRpgCharacterId = 1,
kRpgInventoryWeaponId = 2,
kRpgInventoryArmorId = 3,
kRpgInventoryInventoryId = 4
  };

  void WriteIdentifiedTo(BufferObjectBuilder& bob, BufferObject::Ptr obj);
  BufferObject::Ptr ReadIdentifiedFrom(BufferObjectBuilder& bob);

}

#endif
