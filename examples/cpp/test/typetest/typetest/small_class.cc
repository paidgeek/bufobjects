// Generated with https://github.com/paidgeek/bufobjects

#include "small_class.h"



  
    namespace typetest {
  

  


SmallClass::SmallClass() { }

SmallClass::SmallClass(int32_t value)
:value_(value){}

SmallClass::~SmallClass() {
  
    
  

}

void SmallClass::Init(int32_t value) {value_ = value;}
SmallClass::Ptr SmallClass::New(int32_t value) {

  return new typetest::SmallClass{value};

}

SmallClass::SmallClass(const SmallClass& from) {
  from.CopyTo(*this);
}

SmallClass& SmallClass::operator=(const SmallClass& from) {
  from.CopyTo(*this);
  return *this;
}

uint16_t SmallClass::BufferObjectId() const {
  return bufobjects::ktypetestSmallClassId;
}

void SmallClass::Reset() {
value_ = 0;

}

void SmallClass::CopyTo(bufobjects::BufferObject& _obj) const {
SmallClass& _dst = static_cast< SmallClass& >(_obj);

_dst.value_ = value_;

}

uint32_t SmallClass::Size() const {
uint32_t _size = 0;

_size += 4; // size for "i32"
  
return _size;
}

void SmallClass::WriteTo(bufobjects::BufferObjectBuilder& _bob) const {
uint32_t _needed = this->Size();
if(_bob.GetRemaining() < _needed) {
  _bob.GrowBuffer(_needed);
}
#if defined(BUFOBJECTS_LITTLE_ENDIAN)



  
    
  _bob.WriteData((void*)(&value_), sizeof(value_) + 0);
  


#else

{
    _bob.WriteInt32(value_);
  
  }


#endif

}

void SmallClass::ReadFrom(bufobjects::BufferObjectBuilder& _bob) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)



  
    
  _bob.ReadData((void*)(&value_), sizeof(value_) + 0);
  


#else

{
    value_ = _bob.ReadInt32();
  
  }


#endif

}

void SmallClass::WriteDirectTo(bufobjects::BufferObjectBuilder& _bob,int32_t value) {
{
    _bob.WriteInt32(value);
  
  }
};
void SmallClass::WriteDirectIdentifiedTo(bufobjects::BufferObjectBuilder& _bob,int32_t value) {
_bob.WriteUInt16(bufobjects::ktypetestSmallClassId);
SmallClass::WriteDirectTo(_bob,value);
};




  
    }
  

  

