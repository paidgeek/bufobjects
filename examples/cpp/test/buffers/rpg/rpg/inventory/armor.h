// Generated with https://github.com/paidgeek/bufobjects
    #ifndef RPG_INVENTORY_ARMOR_H
#define RPG_INVENTORY_ARMOR_H

#include "../../buffer_object.h"


#include "../../rpg/inventory/quality.h"
  

#include "../../rpg/inventory/item.h"

namespace rpg {namespace inventory {}}
  
      namespace rpg {
  

  
      namespace inventory {
  

  


class Armor
: public rpg::inventory::Item{

protected:
uint64_t defense_;


public:

  typedef rpg::inventory::Armor* Ptr;




Armor();
Armor(uint64_t defense,rpg::inventory::Quality quality,uint64_t cost,std::string name);

~Armor();

void Init(uint64_t defense,rpg::inventory::Quality quality,uint64_t cost,std::string name);
static Ptr New(uint64_t defense,rpg::inventory::Quality quality,uint64_t cost,std::string name);
Armor(const Armor& from);
Armor& operator=(const Armor& from);
explicit operator bufobjects::BufferObject::Ptr() {
  return static_cast< bufobjects::BufferObject::Ptr >(this);
}
uint16_t BufferObjectId() const;
void Reset();
void CopyTo(bufobjects::BufferObject& obj) const;
uint32_t Size() const;
void WriteTo(bufobjects::BufferObjectBuilder& bob) const;
void ReadFrom(bufobjects::BufferObjectBuilder& bob);
    inline const uint64_t& GetDefense() const { return defense_; }
    inline void SetDefense(const uint64_t& defense) { defense_ = defense; }
  

  
static void WriteDirectTo(bufobjects::BufferObjectBuilder& bob,uint64_t defense,rpg::inventory::Quality quality,uint64_t cost,std::string name);
static void WriteDirectIdentifiedTo(bufobjects::BufferObjectBuilder& bob,uint64_t defense,rpg::inventory::Quality quality,uint64_t cost,std::string name);
};




  
    }
  

  
    }
  

  


#endif
