// Generated with https://github.com/paidgeek/bufobjects
    #ifndef RPG_INVENTORY_ARMOR_H
#define RPG_INVENTORY_ARMOR_H

#include "../../buffer_object.h"


namespace rpg {namespace inventory {enum class Quality;}}namespace rpg {namespace inventory {class Item;}}
  
      namespace rpg {
  

  
      namespace inventory {
  

  


class Armor
: public rpg::inventory::Item{

protected:
uint64_t defense_;


public:


Armor();
Armor(uint64_t defense,std::string name,rpg::inventory::Quality& quality,uint64_t cost);
void Init(uint64_t defense,std::string name,rpg::inventory::Quality& quality,uint64_t cost);
Armor(const Armor& from);
Armor& operator=(const Armor& from);
uint16_t BufferObjectId() const;
void Reset();
void CopyTo(bufobjects::BufferObject& obj) const;
uint32_t Size() const;
void WriteTo(bufobjects::BufferObjectBuilder& bob) const;
void ReadFrom(bufobjects::BufferObjectBuilder& bob);const uint64_t& GetDefense() const;
  void SetDefense(const uint64_t& defense);
  
};


  
    }
  

  
    }
  

  


#endif