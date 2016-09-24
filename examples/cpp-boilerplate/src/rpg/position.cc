// Generated with https://github.com/paidgeek/bufobjects

#include "position.h"
  
    namespace rpg {
  

  


Position::Position() { }

Position::Position(float x,float y)
:x_(x),y_(y){}

Position::Position(const Position& from) {
memcpy(this, &from, sizeof(Position));
}

void Position::Reset() {
  *this = Position{};
}

void Position::WriteTo(bufobjects::BufferObjectBuilder& bob) const {
if(bob.GetRemaining() < kSize) {
  bob.GrowBuffer(kSize);
}
{bob.WriteFloat32(x_);}{bob.WriteFloat32(y_);}
}

void Position::ReadFrom(bufobjects::BufferObjectBuilder& bob) {
{x_ = bob.ReadFloat32();}{y_ = bob.ReadFloat32();}
}


  
    }