// Generated with https://github.com/paidgeek/bufobjects

#include "item.h"



  
    namespace rpg {
  

  
    namespace inventory {
  

  


Item::Item() { }

Item::Item(rpg::inventory::Quality quality,uint64_t cost,std::string name)
:quality_(quality),cost_(cost),name_(name){}

uint32_t Item::Size() const {
  return 0;
}

void Item::Reset() { }


  
    }
  

  
    }
  

  

