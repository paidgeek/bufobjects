// Generated with https://github.com/paidgeek/bufobjects
    #ifndef RPG_INVENTORY_WEAPON_H
#define RPG_INVENTORY_WEAPON_H

#include "../../buffer_object.h"


#include "../../rpg/inventory/quality.h"
  

#include "../../rpg/inventory/item.h"

namespace rpg {namespace inventory {}}
  
      namespace rpg {
  

  
      namespace inventory {
  

  


class Weapon
: public rpg::inventory::Item{

protected:
uint64_t damage_;


public:

  typedef rpg::inventory::Weapon* Ptr;




Weapon();
Weapon(uint64_t damage,rpg::inventory::Quality quality,uint64_t cost,std::string name);

~Weapon();

void Init(uint64_t damage,rpg::inventory::Quality quality,uint64_t cost,std::string name);
static Ptr New(uint64_t damage,rpg::inventory::Quality quality,uint64_t cost,std::string name);
Weapon(const Weapon& from);
Weapon& operator=(const Weapon& from);
explicit operator bufobjects::BufferObject::Ptr() {
  return static_cast< bufobjects::BufferObject::Ptr >(this);
}
uint16_t BufferObjectId() const;
void Reset();
void CopyTo(bufobjects::BufferObject& obj) const;
uint32_t Size() const;
void WriteTo(bufobjects::BufferObjectBuilder& bob) const;
void ReadFrom(bufobjects::BufferObjectBuilder& bob);
    inline const uint64_t& GetDamage() const { return damage_; }
    inline void SetDamage(const uint64_t& damage) { damage_ = damage; }
  

  
static void WriteDirectTo(bufobjects::BufferObjectBuilder& bob,uint64_t damage,rpg::inventory::Quality quality,uint64_t cost,std::string name);
static void WriteDirectIdentifiedTo(bufobjects::BufferObjectBuilder& bob,uint64_t damage,rpg::inventory::Quality quality,uint64_t cost,std::string name);
};




  
    }
  

  
    }
  

  


#endif
