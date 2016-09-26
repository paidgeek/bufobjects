// Generated with https://github.com/paidgeek/bufobjects

#include "bo_test_sub.h"



  
    namespace gen {
  

  


BoTestSub::BoTestSub() { }

BoTestSub::BoTestSub(float x,double y)
:x_(x),y_(y){}

BoTestSub::~BoTestSub() {
  
    
  
    
  

}

void BoTestSub::Init(float x,double y) {x_ = x;y_ = y;}
BoTestSub::Ptr BoTestSub::New(float x,double y) {

  return new gen::BoTestSub{x,y};

}

BoTestSub::BoTestSub(const BoTestSub& from) {
  from.CopyTo(*this);
}

BoTestSub& BoTestSub::operator=(const BoTestSub& from) {
  from.CopyTo(*this);
  return *this;
}

uint16_t BoTestSub::BufferObjectId() const {
  return bufobjects::kGenBoTestSubId;
}

void BoTestSub::Reset() {
x_ = 0.0f;y_ = 0.0;

}

void BoTestSub::CopyTo(bufobjects::BufferObject& obj) const {
BoTestSub& dst = static_cast< BoTestSub& >(obj);

dst.x_ = x_;dst.y_ = y_;
}

uint32_t BoTestSub::Size() const {
uint32_t size = 0;

size += 4; // size for "f32"
  size += 8; // size for "f64"
  
return size;
}

void BoTestSub::WriteTo(bufobjects::BufferObjectBuilder& _bob) const {
uint32_t needed = this->Size();
if(_bob.GetRemaining() < needed) {
  _bob.GrowBuffer(needed);
}
#if defined(BUFOBJECTS_LITTLE_ENDIAN)

_bob.WriteData((void*)this, sizeof(x_) +sizeof(y_) + 0);
  

  


#else

{
    _bob.WriteFloat32(x_);
  
  }
{
    _bob.WriteFloat64(y_);
  
  }


#endif

}

void BoTestSub::ReadFrom(bufobjects::BufferObjectBuilder& _bob) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)

_bob.ReadData((void*)this, sizeof(x_) +sizeof(y_) + 0);
  

  


#else

{
    x_ = _bob.ReadFloat32();
  
  }
{
    y_ = _bob.ReadFloat64();
  
  }


#endif

}

void BoTestSub::WriteDirectTo(bufobjects::BufferObjectBuilder& _bob,float x,double y) {
{
    _bob.WriteFloat32(x);
  
  }{
    _bob.WriteFloat64(y);
  
  }
};
void BoTestSub::WriteDirectIdentifiedTo(bufobjects::BufferObjectBuilder& _bob,float x,double y) {
_bob.WriteUInt16(bufobjects::kGenBoTestSubId);
BoTestSub::WriteDirectTo(_bob,x,y);
};




  
    }
  

  

