// Generated with https://github.com/paidgeek/bufobjects

#include "item.h"



  
    namespace rpg {
  

  
    namespace inventory {
  

  


Item::Item() { }

Item::Item(std::string name,rpg::inventory::Quality quality,uint64_t cost)
:name_(name),quality_(quality),cost_(cost){}

uint32_t Item::Size() const {
  return 0;
}

void Item::Reset() { }


    const std::string& Item::GetName() const {
      return name_;
    }
    void Item::SetName(const std::string& name) {
      name_ = name;
    }
  

  
    rpg::inventory::Quality Item::GetQuality() {
      return quality_;
    }
    void Item::SetQuality(rpg::inventory::Quality quality) {
      quality_ = quality;
    }
  

  
    const uint64_t& Item::GetCost() const {
      return cost_;
    }
    void Item::SetCost(const uint64_t& cost) {
      cost_ = cost;
    }
  

  



  
    }
  

  
    }
  

  

