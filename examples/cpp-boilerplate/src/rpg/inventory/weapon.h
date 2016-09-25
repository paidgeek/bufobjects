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
  typedef std::shared_ptr<rpg::inventory::Weapon> Ptr;

  class Builder;

Weapon();
Weapon(uint64_t damage,std::string name,rpg::inventory::Quality quality,uint64_t cost);
void Init(uint64_t damage,std::string name,rpg::inventory::Quality quality,uint64_t cost);
Weapon(const Weapon& from);
Weapon& operator=(const Weapon& from);
uint16_t BufferObjectId() const;
void Reset();
void CopyTo(bufobjects::BufferObject& obj) const;
uint32_t Size() const;
void WriteTo(bufobjects::BufferObjectBuilder& bob) const;
void ReadFrom(bufobjects::BufferObjectBuilder& bob);const uint64_t& GetDamage() const;
  void SetDamage(const uint64_t& damage);
  
static void WriteDirectTo(bufobjects::BufferObjectBuilder& bob,uint64_t damage,std::string name,rpg::inventory::Quality quality,uint64_t cost);
static void WriteDirectIdentifiedTo(bufobjects::BufferObjectBuilder& bob,uint64_t damage,std::string name,rpg::inventory::Quality quality,uint64_t cost);
};

class Weapon::Builder {
private:
uint64_t damage_;
std::string name_;
rpg::inventory::Quality quality_;
uint64_t cost_;

public:
  Builder();
Builder& SetDamage(const uint64_t& damage);
  Builder& SetName(const std::string& name);
  Builder& SetQuality(const rpg::inventory::Quality& quality);
  Builder& SetCost(const uint64_t& cost);
  
std::shared_ptr< Weapon > Build();
};


  
    }
  

  
    }
  

  


#endif
