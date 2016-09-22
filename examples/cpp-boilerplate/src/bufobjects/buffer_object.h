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
    virtual uint32_t Size() const { return 0; }
    virtual void WriteTo(BufferObjectBuilder& bob) const = 0;
    virtual void ReadFrom(BufferObjectBuilder& bob) = 0;
  };

  enum uint16_t {
    kRpgCharacterId = 1
  };

  constexpr void WriteIdentifiedTo(BufferObjectBuilder& bob, const BufferObject& obj) {
    bob.WriteUInt16(obj.BufferObjectId());
    obj.WriteTo(bob);
  }

  constexpr void ReadIdentifiedFrom(BufferObjectBuilder& bob, BufferObject& obj) {
    // TODO
  }

}

#endif
