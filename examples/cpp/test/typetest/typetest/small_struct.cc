// Generated with https://github.com/paidgeek/bufobjects

#include "small_struct.h"
  
    namespace typetest {
  

  


SmallStruct::SmallStruct() { }

SmallStruct::SmallStruct(int32_t value)
:value_(value){}

SmallStruct::SmallStruct(const SmallStruct& from) {
  memcpy(this, &from, sizeof(SmallStruct));
}

void SmallStruct::Reset() {
  *this = SmallStruct{};
}

void SmallStruct::WriteTo(bufobjects::BufferObjectBuilder& _bob) const {
if(_bob.GetRemaining() < sizeof(SmallStruct)) {
  _bob.GrowBuffer(sizeof(SmallStruct));
}
#if defined(BUFOBJECTS_LITTLE_ENDIAN)

_bob.WriteData((void*) this, sizeof(SmallStruct));

#else

{_bob.WriteInt32(value_);}


#endif
}

void SmallStruct::ReadFrom(bufobjects::BufferObjectBuilder& _bob) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)

_bob.ReadData((void*) this, sizeof(SmallStruct));

#else

{value_ = _bob.ReadInt32();}

#endif

}


  
    }
  

  

