// Generated with https://github.com/paidgeek/bufobjects
    #ifndef RPG_INVENTORY_ITEM_H
#define RPG_INVENTORY_ITEM_H

#include "../../buffer_object.h"


namespace rpg {namespace inventory {enum class Quality;}}
  
    namespace rpg {
  

  
    namespace inventory {
  

  



class Item
: public bufobjects::BufferObject{

protected:

  std::string name_;
  

  rpg::inventory::Quality& quality_;
  

  uint64_t cost_;
  


public:

virtual uint32_t Size() const;
virtual void Reset();

const std::string& GetName() const;
  void SetName(const std::string& name);
  const rpg::inventory::Quality& GetQuality() const;
  void SetQuality(const rpg::inventory::Quality& quality);
  const uint64_t& GetCost() const;
  void SetCost(const uint64_t& cost);
  


};


  
    }
  

  
    }
  

  


#endif