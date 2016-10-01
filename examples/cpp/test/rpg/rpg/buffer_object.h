// Generated with https://github.com/paidgeek/bufobjects

#ifndef BUFOBJECTS_BUFFER_OBJECT_H
#define BUFOBJECTS_BUFFER_OBJECT_H

#include <cstdint>
#include <string>
#include <vector>
#include <map>
#include <array>
#include "buffer_builder.h"

namespace bufobjects {

class BufferBuilder;

class BufferObject {
public:
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

inline void WriteIdentifiedTo(BufferBuilder& _bb, BufferObject* obj) {
  _bb.WriteUInt16(obj->BufferObjectId());
  obj->WriteTo(_bb);
}

inline void WriteIdentifiedTo(BufferBuilder& _bb, const BufferObject& obj) {
  _bb.WriteUInt16(obj.BufferObjectId());
  obj.WriteTo(_bb);
}

BufferObject* ReadIdentifiedFrom(BufferBuilder& bb);

}

#endif
