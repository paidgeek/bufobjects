// Generated with https://github.com/paidgeek/bufobjects

#ifndef BUFOBJECTS_BUFFER_OBJECT_H
#define BUFOBJECTS_BUFFER_OBJECT_H

#include <memory>
#include "buffer_object_builder.h"

namespace bufobjects {

  
    template< typename T, typename S >
    inline T* PointerCast(S* p) {
      return static_cast< T* >(p);
    }
  

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

    
    
          
          

    enum BufferObjectIds : uint16_t {
      kGenBoTestSubId = 1,
kGenBoTestId = 2
    };

    static void WriteIdentifiedTo(BufferObjectBuilder& bob, BufferObject& obj);
    static BufferObject::Ptr ReadIdentifiedFrom(BufferObjectBuilder& bob);
  };

}

#endif
