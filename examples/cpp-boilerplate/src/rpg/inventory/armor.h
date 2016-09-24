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

  class Builder;

Armor();
Armor(uint64_t defense,std::string name,rpg::inventory::Quality quality,uint64_t cost);
void Init(uint64_t defense,std::string name,rpg::inventory::Quality quality,uint64_t cost);
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

class Armor::Builder {
private:
uint64_t defense_;
std::string name_;
rpg::inventory::Quality quality_;
uint64_t cost_;

public:
  Builder();
Builder& SetDefense(const uint64_t& defense);
  Builder& SetName(const std::string& name);
  Builder& SetQuality(const rpg::inventory::Quality& quality);
  Builder& SetCost(const uint64_t& cost);
  
std::shared_ptr< Armor > Build();
};


  
    }
  

  
    }
  

  


#endif