#ifndef BUFOBJECTS_BUFFER_OBJECT_H
#define BUFOBJECTS_BUFFER_OBJECT_H

#include <memory>
#include "buffer_object_builder.h"

namespace bufobjects {
  class BufferObject {
  public:
    virtual void WriteTo(const std::unique_ptr<BufferObjectBuilder> &bob) = 0;

    virtual void ReadFrom(const std::unique_ptr<BufferObjectBuilder> &bob) = 0;

    virtual void Reset() = 0;
  };
}

#endif
