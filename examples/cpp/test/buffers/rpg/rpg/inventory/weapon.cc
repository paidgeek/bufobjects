// Generated with https://github.com/paidgeek/bufobjects

#include "weapon.h"



  
    namespace rpg {
  

  
    namespace inventory {
  

  


Weapon::Weapon() { }

Weapon::Weapon(uint64_t damage,rpg::inventory::Quality quality,uint64_t cost,std::string name)
:rpg::inventory::Item(quality,cost,name)
  
    ,
  damage_(damage){}

Weapon::~Weapon() {
  
    
  

}

void Weapon::Init(uint64_t damage,rpg::inventory::Quality quality,uint64_t cost,std::string name) {damage_ = damage;quality_ = quality;cost_ = cost;name_ = name;}
Weapon::Ptr Weapon::New(uint64_t damage,rpg::inventory::Quality quality,uint64_t cost,std::string name) {

  return new rpg::inventory::Weapon{damage,quality,cost,name};

}

Weapon::Weapon(const Weapon& from) {
  from.CopyTo(*this);
}

Weapon& Weapon::operator=(const Weapon& from) {
  from.CopyTo(*this);
  return *this;
}

uint16_t Weapon::BufferObjectId() const {
  return bufobjects::kRpgInventoryWeaponId;
}

void Weapon::Reset() {
rpg::inventory::Item::Reset();damage_ = 0;

}

void Weapon::CopyTo(bufobjects::BufferObject& _obj) const {
Weapon& _dst = static_cast< Weapon& >(_obj);

_dst.damage_ = damage_;_dst.quality_ = quality_;_dst.cost_ = cost_;_dst.name_ = name_;

}

uint32_t Weapon::Size() const {
uint32_t _size = rpg::inventory::Item::Size();

_size += 8; // size for "u64"
  
return _size;
}

void Weapon::WriteTo(bufobjects::BufferObjectBuilder& _bob) const {
uint32_t _needed = this->Size();
if(_bob.GetRemaining() < _needed) {
  _bob.GrowBuffer(_needed);
}
#if defined(BUFOBJECTS_LITTLE_ENDIAN)

_bob.WriteData((void*)this, sizeof(damage_) +sizeof(quality_) +sizeof(cost_) + 0);
  

  

  

  {
      _bob.WriteString(name_);
    
    }

  


#else

{
    _bob.WriteUInt64(damage_);
  
  }
{
    _bob.WriteUInt8(static_cast< uint8_t >(quality_));
  
  }
{
    _bob.WriteUInt64(cost_);
  
  }
{
    _bob.WriteString(name_);
  
  }


#endif

}

void Weapon::ReadFrom(bufobjects::BufferObjectBuilder& _bob) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)

_bob.ReadData((void*)this, sizeof(damage_) +sizeof(quality_) +sizeof(cost_) + 0);
  

  

  

  {
      name_ = _bob.ReadString();
    
    }
  


#else

{
    damage_ = _bob.ReadUInt64();
  
  }
{
    quality_ = static_cast< rpg::inventory::Quality >(_bob.ReadUInt8());
  
  }
{
    cost_ = _bob.ReadUInt64();
  
  }
{
    name_ = _bob.ReadString();
  
  }


#endif

}

void Weapon::WriteDirectTo(bufobjects::BufferObjectBuilder& _bob,uint64_t damage,rpg::inventory::Quality quality,uint64_t cost,std::string name) {
{
    _bob.WriteUInt64(damage);
  
  }{
    _bob.WriteUInt8(static_cast< uint8_t >(quality));
  
  }{
    _bob.WriteUInt64(cost);
  
  }{
    _bob.WriteString(name);
  
  }
};
void Weapon::WriteDirectIdentifiedTo(bufobjects::BufferObjectBuilder& _bob,uint64_t damage,rpg::inventory::Quality quality,uint64_t cost,std::string name) {
_bob.WriteUInt16(bufobjects::kRpgInventoryWeaponId);
Weapon::WriteDirectTo(_bob,damage,quality,cost,name);
};




  
    }
  

  
    }
  

  

