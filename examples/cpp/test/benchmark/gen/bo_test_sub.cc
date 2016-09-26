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

void BoTestSub::WriteTo(bufobjects::BufferObjectBuilder& bob) const {
uint32_t needed = this->Size();
if(bob.GetRemaining() < needed) {
  bob.GrowBuffer(needed);
}
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
{bob.WriteData((void*)this, sizeof(x_) +sizeof(y_) + 0);
  

  

}

#else
{{
    bob.WriteFloat32(x_);
  
  }{
    bob.WriteFloat64(y_);
  
  }}
#endif

}

void BoTestSub::ReadFrom(bufobjects::BufferObjectBuilder& bob) {
{
    x_ = bob.ReadFloat32();
  
  }{
    y_ = bob.ReadFloat64();
  
  }
}
    const float& BoTestSub::GetX() const {
      return x_;
    }
    void BoTestSub::SetX(const float& x) {
      x_ = x;
    }
  

  
    const double& BoTestSub::GetY() const {
      return y_;
    }
    void BoTestSub::SetY(const double& y) {
      y_ = y;
    }
  

  
void BoTestSub::WriteDirectTo(bufobjects::BufferObjectBuilder& bob,float x,double y) {
{
    bob.WriteFloat32(x);
  
  }{
    bob.WriteFloat64(y);
  
  }
};
void BoTestSub::WriteDirectIdentifiedTo(bufobjects::BufferObjectBuilder& bob,float x,double y) {
bob.WriteUInt16(bufobjects::kGenBoTestSubId);
BoTestSub::WriteDirectTo(bob,x,y);
};




  
    }
  

  
