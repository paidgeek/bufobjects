// Generated with https://github.com/paidgeek/bufobjects

#ifndef BUFOBJECTS_BUFFER_OBJECT_H
#define BUFOBJECTS_BUFFER_OBJECT_H

#include <vector>
#include <map>
#include <array>

namespace bufobjects {

  class BufferBuilder;

  class BufferObject {
  public:
    typedef BufferObject* Ptr;
    BufferObject() {}
    virtual uint16_t BufferObjectId() const = 0;
    virtual void Reset() = 0;
    virtual void CopyTo(BufferObject& dst) const = 0;
    virtual void WriteTo(BufferBuilder& bb) const = 0;
    virtual void ReadFrom(BufferBuilder& bb) = 0;
    virtual uint32_t Size() const = 0;
  };

  
  
        
        
        
        
  enum BufferObjectIds : uint16_t {
    kRpgCharacterId = 1,
kRpgInventoryWeaponId = 2,
kRpgInventoryArmorId = 3,
kRpgInventoryInventoryId = 4
  };

  void WriteIdentifiedTo(BufferBuilder& bb, BufferObject::Ptr obj);
  BufferObject::Ptr ReadIdentifiedFrom(BufferBuilder& bb);

}

#endif
