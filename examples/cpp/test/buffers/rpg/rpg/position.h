// Generated with https://github.com/paidgeek/bufobjects
    #ifndef RPG_POSITION_H
#define RPG_POSITION_H

#include "../buffer_object.h"
  
    namespace rpg {
  

  


struct Position {
float x_;
float y_;

Position();
Position(float x,float y);
Position(const Position& from);
void Reset();
void WriteTo(bufobjects::BufferObjectBuilder& bob) const;
void ReadFrom(bufobjects::BufferObjectBuilder& bob);
};


  
    }
  

  


#endif
