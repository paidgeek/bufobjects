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

void Position::WriteTo(bufobjects::BufferObjectBuilder& _bob) const {
if(_bob.GetRemaining() < sizeof(Position)) {
  _bob.GrowBuffer(sizeof(Position));
}
#if defined(BUFOBJECTS_LITTLE_ENDIAN)

_bob.WriteData((void*) this, sizeof(Position));

#else

{_bob.WriteFloat32(x_);}
{_bob.WriteFloat32(y_);}


#endif
}

void Position::ReadFrom(bufobjects::BufferObjectBuilder& _bob) {
{x_ = _bob.ReadFloat32();}{y_ = _bob.ReadFloat32();}
}


  
    }
  

  

