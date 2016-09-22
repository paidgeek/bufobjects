// Generated with https://github.com/paidgeek/bufobjects

#ifndef BUFOBJECTS_BUFFER_OBJECT_H
#define BUFOBJECTS_BUFFER_OBJECT_H

#include <memory>
#include "buffer_object_builder.h"
#include "Character.h"

namespace bufobjects {
  class BufferObject {
  public:
    BufferObject() {}
    virtual uint16_t BufferObjectId() const = 0;
    virtual void Reset() = 0;
    virtual void CopyTo(BufferObject *dst) = 0;
    virtual void WriteTo(BufferObjectBuilder &bob) const = 0;
    virtual void ReadFrom(BufferObjectBuilder &bob) = 0;
    uint32_t size() {
      return 0;
    }

    enum : uint16_t {
      kRPGCharacterId = 1
    };

    void WriteIdentifiedTo(BufferObjectBuilder &bob, const BufferObject &obj) {
      bob.WriteUInt16(obj.BufferObjectId());
      obj.WriteTo(bob);
    }

    std::unique_ptr<BufferObject> ReadIdentifiedFrom(BufferObjectBuilder &bob) {
      uint16_t id = bob.ReadUInt16();
      std::unique_ptr<BufferObject> obj;
      switch (id) {
        case kRPGCharacterId:
          obj = std::make_unique<rpg.Character>();
          obj.ReadFrom(bob);
          break;
      }
      return obj;
    }
  }

}