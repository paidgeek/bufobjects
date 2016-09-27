// Generated with https://github.com/paidgeek/bufobjects


#include "rpg.h"

#include "rpg_inventory.h"



  
  

  
  
    

  
    namespace rpg {
  

  
    namespace inventory {
  

  


Item::Item() { }

Item::Item(rpg::inventory::Quality quality,uint64_t cost,std::string name)
:quality_(quality),cost_(cost),name_(name){}

uint32_t Item::Size() const {
  return 0;
}

void Item::Reset() { }


  
    }
  

  
    }
  

  


  

  
  
    

  
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



  
    
  
  
  
  _bob.WriteData((void*)(&damage_), sizeof(damage_) +sizeof(quality_) +sizeof(cost_) + 0);
  

  

  

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



  
    
  
  
  
  _bob.ReadData((void*)(&damage_), sizeof(damage_) +sizeof(quality_) +sizeof(cost_) + 0);
  

  

  

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
  

  


  

  
  
    

  
    namespace rpg {
  

  
    namespace inventory {
  

  


Inventory::Inventory() { }

Inventory::Inventory(uint32_t capacity,std::vector<rpg::inventory::Item*> items)
:capacity_(capacity),items_(items){}


Inventory::~Inventory() {
  
    
  
    
      for(uint32_t i = 0; i < items_.size(); i++) {
        delete(items_[i]);
      }
      items_.clear();
    
  

}


void Inventory::Init(uint32_t capacity,std::vector<rpg::inventory::Item*> items) {capacity_ = capacity;items_ = items;}
Inventory::Ptr Inventory::New(uint32_t capacity,std::vector<rpg::inventory::Item*> items) {

  return new rpg::inventory::Inventory{capacity,items};

}

Inventory::Inventory(const Inventory& from) {
  from.CopyTo(*this);
}

Inventory& Inventory::operator=(const Inventory& from) {
  from.CopyTo(*this);
  return *this;
}

uint16_t Inventory::BufferObjectId() const {
  return bufobjects::kRpgInventoryInventoryId;
}

void Inventory::Reset() {
capacity_ = 0;items_.clear();

}

void Inventory::CopyTo(bufobjects::BufferObject& _obj) const {
Inventory& _dst = static_cast< Inventory& >(_obj);

_dst.capacity_ = capacity_;_dst.items_ = std::vector< rpg::inventory::Item* >(items_);

}

uint32_t Inventory::Size() const {
uint32_t _size = 0;

_size += 4; // size for "u32"
  _size += bufobjects::BufferObjectBuilder::GetVarUInt32Size(static_cast< uint32_t >(items_.size()));
    
        for(const auto& _e : items_) {
          if(_e != nullptr) {
            _size += _e->Size();
            // this comment seems to fix a jtwig bug ""
            
              
                _size += 2; // size of bufferObjectId
              
            
          }
        }
        _size += items_.size(); // for "is null" byte
      
    
return _size;
}

void Inventory::WriteTo(bufobjects::BufferObjectBuilder& _bob) const {
uint32_t _needed = this->Size();
if(_bob.GetRemaining() < _needed) {
  _bob.GrowBuffer(_needed);
}
#if defined(BUFOBJECTS_LITTLE_ENDIAN)



  
    
  
  _bob.WriteData((void*)(&capacity_), sizeof(capacity_) + 0);
  

  {_bob.WriteVarUInt32(static_cast< uint32_t >(items_.size()));
      for(const auto& _e : items_) {
        if(_e == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@4edde6e5, com.moybl.sidl.ast.ClassDefinition@70177ecd]"
        
          _bob.WriteUInt16(_e->BufferObjectId());
        
        _e->WriteTo(_bob);
      }
      }
    }

  


#else

{
    _bob.WriteUInt32(capacity_);
  
  }
{_bob.WriteVarUInt32(static_cast< uint32_t >(items_.size()));
    for(const auto& _e : items_) {
    if(_e == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@4edde6e5, com.moybl.sidl.ast.ClassDefinition@70177ecd]"
        
          _bob.WriteUInt16(_e->BufferObjectId());
        
        _e->WriteTo(_bob);
      }
    }
  }


#endif

}

void Inventory::ReadFrom(bufobjects::BufferObjectBuilder& _bob) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)



  
    
  
  _bob.ReadData((void*)(&capacity_), sizeof(capacity_) + 0);
  

  {uint32_t _size = _bob.ReadVarUInt32();
      items_.clear();
      items_.reserve(_size);
      rpg::inventory::Item* _e;
      for(uint32_t i = 0; i < _size; i++) {
        // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@4edde6e5, com.moybl.sidl.ast.ClassDefinition@70177ecd]"
      
        if (_bob.ReadUInt8() == 0x81) {
          uint16_t id = _bob.ReadUInt16();
          switch(id) {
              case bufobjects::kRpgInventoryWeaponId:
              
                _e = new rpg::inventory::Weapon{};
                _e->ReadFrom(_bob);
              
              break;
              case bufobjects::kRpgInventoryArmorId:
              
                _e = new rpg::inventory::Armor{};
                _e->ReadFrom(_bob);
              
              break;}
        } else {
          _e = nullptr;
        }
        items_.push_back(_e);
      }
    }
  


#else

{
    capacity_ = _bob.ReadUInt32();
  
  }
{uint32_t _size = _bob.ReadVarUInt32();
    items_.clear();
    items_.reserve(_size);
    rpg::inventory::Item* e;
    for(uint32_t i = 0; i < _size; i++) {
      // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@4edde6e5, com.moybl.sidl.ast.ClassDefinition@70177ecd]"
      
        if (_bob.ReadUInt8() == 0x81) {
          uint16_t id = _bob.ReadUInt16();
          switch(id) {
              case bufobjects::kRpgInventoryWeaponId:
              
                e = new rpg::inventory::Weapon{};
                e->ReadFrom(_bob);
              
              break;
              case bufobjects::kRpgInventoryArmorId:
              
                e = new rpg::inventory::Armor{};
                e->ReadFrom(_bob);
              
              break;}
        } else {
          e = nullptr;
        }
      items_.push_back(e);
    }
  }


#endif

}

void Inventory::WriteDirectTo(bufobjects::BufferObjectBuilder& _bob,uint32_t capacity,std::vector<rpg::inventory::Item*> items) {
{
    _bob.WriteUInt32(capacity);
  
  }{_bob.WriteVarUInt32(static_cast< uint32_t >(items.size()));
    for(const auto& _e : items) {
    if(_e == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@4edde6e5, com.moybl.sidl.ast.ClassDefinition@70177ecd]"
        
          _bob.WriteUInt16(_e->BufferObjectId());
        
        _e->WriteTo(_bob);
      }
    }
  }
};
void Inventory::WriteDirectIdentifiedTo(bufobjects::BufferObjectBuilder& _bob,uint32_t capacity,std::vector<rpg::inventory::Item*> items) {
_bob.WriteUInt16(bufobjects::kRpgInventoryInventoryId);
Inventory::WriteDirectTo(_bob,capacity,items);
};


  Inventory::Builder::Builder() { }

    Inventory::Builder& Inventory::Builder::Capacity(const uint32_t& capacity) {
      capacity_ = capacity;
      return *this;
    }
  

  
    Inventory::Builder& Inventory::Builder::Items(const std::vector<rpg::inventory::Item*>& items) {
      items_ = items;
      return *this;
    }
  

  
    
      Inventory::Builder& Inventory::Builder::Items(int index, rpg::inventory::Item* value) {
        items_[index] = value;
        return *this;
      }
      Inventory::Builder& Inventory::Builder::AddItems(rpg::inventory::Item* value) {
       items_.push_back(value);
        return *this;
      }
      Inventory::Builder& Inventory::Builder::AddItems(std::vector<rpg::inventory::Item*> values) {
        items_.insert(std::end(items_), std::begin(values), std::end(values));
        return *this;
      }
    
  
Inventory::Ptr Inventory::Builder::Build() {

  return new Inventory{
  capacity_,items_
  };

}

void Inventory::Builder::WriteTo(bufobjects::BufferObjectBuilder& _bob) {
  Inventory::WriteDirectTo(_bob,capacity_,items_);
}

void Inventory::Builder::WriteIdentifiedTo(bufobjects::BufferObjectBuilder& _bob) {
Inventory::WriteDirectIdentifiedTo(_bob,capacity_,items_);
}




  
    }
  

  
    }