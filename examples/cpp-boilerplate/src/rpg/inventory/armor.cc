// Generated with https://github.com/paidgeek/bufobjects

#include "armor.h"


#include "../../rpg/inventory/quality.h";
#include "../../rpg/inventory/item.h";
  
    namespace rpg {
  

  
    namespace inventory {
  

  


Armor::Armor() {
  Reset();
}

Armor::Armor(uint64_t defense,std::string name,rpg::inventory::Quality& quality,uint64_t cost)
:defense_(defense),name_(name),quality_(quality),cost_(cost){}

void Armor::Init(uint64_t defense,std::string name,rpg::inventory::Quality& quality,uint64_t cost) {defense_ = defense;name_ = name;quality_ = quality;cost_ = cost;}

Armor::Armor(const Armor& from) {
  from.CopyTo(*this);
}

Armor& Armor::operator=(const Armor& from) {
  from.CopyTo(*this);
  return *this;
}

uint16_t Armor::BufferObjectId() const {
  return bufobjects::BufferObject::kRpgInventoryArmorId;
}

void Armor::Reset() {
rpg::inventory::Item::Reset();defense_ = 0;

}

void Armor::CopyTo(bufobjects::BufferObject& obj) const {
Armor& dst = static_cast< Armor& >(obj);

dst.defense_ = defense_;dst.name_ = name_;dst.quality_ = quality_;dst.cost_ = cost_;
}

uint32_t Armor::Size() const {
uint32_t size = rpg::inventory::Item::Size();

size += 8; // size for "u64"
  
return size;
}

void Armor::WriteTo(bufobjects::BufferObjectBuilder& bob) const {
uint32_t needed = Size();
if(bob.GetRemaining() < needed) {
bob.GrowBuffer(needed);
}
{
    bob.WriteUInt64(defense_);
  
  }{
    bob.WriteString(name_);
  
  }{
    bob.WriteUInt8(static_cast< uint8_t >(quality_));
  
  }{
    bob.WriteUInt64(cost_);
  
  }
}

void Armor::ReadFrom(bufobjects::BufferObjectBuilder& bob) {
{
    defense_ = bob.ReadUInt64();
  
  }{
    name_ = bob.ReadString();
  
  }{
    quality_ = static_cast< rpg::inventory::Quality >(bob.ReadUInt8());
  
  }{
    cost_ = bob.ReadUInt64();
  
  }
}const uint64_t& Armor::GetDefense() const {
    return defense_;
  }

  void Armor::SetDefense(const uint64_t& defense) {
    defense_ = defense;
  }

  

  
    }
  

  
    }