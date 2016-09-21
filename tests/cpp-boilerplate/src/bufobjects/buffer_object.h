#ifndef BUFOBJECTS_BUFFER_OBJECT_H
#define BUFOBJECTS_BUFFER_OBJECT_H

#include <memory>
#include "buffer_object_builder.h"

namespace bufobjects {

  class BufferObject {
  public:
    BufferObject() {}
    virtual BufferObject *New() const = 0;
    virtual uint16_t BufferObjectId() const = 0;
    virtual uint32_t Size() const { return 0; }
    virtual void WriteTo(BufferObjectBuilder *bob) const = 0;
    virtual void ReadFrom(BufferObjectBuilder *bob) = 0;
    virtual void Reset() = 0;
  };

}

#endif
