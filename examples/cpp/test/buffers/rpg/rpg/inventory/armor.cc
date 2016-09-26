// Generated with https://github.com/paidgeek/bufobjects

#include "armor.h"



  
    namespace rpg {
  

  
    namespace inventory {
  

  


Armor::Armor() { }

Armor::Armor(uint64_t defense,rpg::inventory::Quality quality,uint64_t cost,std::string name)
:rpg::inventory::Item(quality,cost,name)
  
    ,
  defense_(defense){}


Armor::~Armor() {
  
    
  

}


void Armor::Init(uint64_t defense,rpg::inventory::Quality quality,uint64_t cost,std::string name) {defense_ = defense;quality_ = quality;cost_ = cost;name_ = name;}
Armor::Ptr Armor::New(uint64_t defense,rpg::inventory::Quality quality,uint64_t cost,std::string name) {

  return new rpg::inventory::Armor{defense,quality,cost,name};

}

Armor::Armor(const Armor& from) {
  from.CopyTo(*this);
}

Armor& Armor::operator=(const Armor& from) {
  from.CopyTo(*this);
  return *this;
}

uint16_t Armor::BufferObjectId() const {
  return bufobjects::kRpgInventoryArmorId;
}

void Armor::Reset() {
rpg::inventory::Item::Reset();defense_ = 0;

}

void Armor::CopyTo(bufobjects::BufferObject& _obj) const {
Armor& _dst = static_cast< Armor& >(_obj);

_dst.defense_ = defense_;_dst.quality_ = quality_;_dst.cost_ = cost_;_dst.name_ = name_;

}

uint32_t Armor::Size() const {
uint32_t _size = rpg::inventory::Item::Size();

_size += 8; // size for "u64"
  
return _size;
}

void Armor::WriteTo(bufobjects::BufferObjectBuilder& _bob) const {
uint32_t _needed = this->Size();
if(_bob.GetRemaining() < _needed) {
  _bob.GrowBuffer(_needed);
}
#if defined(BUFOBJECTS_LITTLE_ENDIAN)



  
    
  
  
  
  _bob.WriteData((void*)(&defense_), sizeof(defense_) +sizeof(quality_) +sizeof(cost_) + 0);
  

  

  

  {
      _bob.WriteString(name_);
    
    }

  


#else

{
    _bob.WriteUInt64(defense_);
  
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

void Armor::ReadFrom(bufobjects::BufferObjectBuilder& _bob) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)



  
    
  
  
  
  _bob.ReadData((void*)(&defense_), sizeof(defense_) +sizeof(quality_) +sizeof(cost_) + 0);
  

  

  

  {
      name_ = _bob.ReadString();
    
    }
  


#else

{
    defense_ = _bob.ReadUInt64();
  
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

void Armor::WriteDirectTo(bufobjects::BufferObjectBuilder& _bob,uint64_t defense,rpg::inventory::Quality quality,uint64_t cost,std::string name) {
{
    _bob.WriteUInt64(defense);
  
  }{
    _bob.WriteUInt8(static_cast< uint8_t >(quality));
  
  }{
    _bob.WriteUInt64(cost);
  
  }{
    _bob.WriteString(name);
  
  }
};
void Armor::WriteDirectIdentifiedTo(bufobjects::BufferObjectBuilder& _bob,uint64_t defense,rpg::inventory::Quality quality,uint64_t cost,std::string name) {
_bob.WriteUInt16(bufobjects::kRpgInventoryArmorId);
Armor::WriteDirectTo(_bob,defense,quality,cost,name);
};




  
    }
  

  
    }
  

  

