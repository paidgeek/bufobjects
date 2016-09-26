// Generated with https://github.com/paidgeek/bufobjects
    #ifndef RPG_INVENTORY_ITEM_H
#define RPG_INVENTORY_ITEM_H

#include "../../buffer_object.h"


#include "../../rpg/inventory/quality.h"
  namespace rpg {namespace inventory {}}
  
    namespace rpg {
  

  
    namespace inventory {
  

  



class Item
: public bufobjects::BufferObject{

protected:
rpg::inventory::Quality quality_;
uint64_t cost_;
std::string name_;


public:

  typedef rpg::inventory::Item* Ptr;


Item();
Item(rpg::inventory::Quality quality,uint64_t cost,std::string name);
virtual uint32_t Size() const;
virtual void Reset();


    rpg::inventory::Quality GetQuality();
    void SetQuality(rpg::inventory::Quality quality);
  

  
    const uint64_t& GetCost() const;
    void SetCost(const uint64_t& cost);
  

  
    const std::string& GetName() const;
    void SetName(const std::string& name);
  

  


};


  
    }
  

  
    }
  

  


#endif
