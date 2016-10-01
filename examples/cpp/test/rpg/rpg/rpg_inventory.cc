// Generated with https://github.com/paidgeek/bufobjects


#include "rpg.h"

#include "rpg_inventory.h"



  
  

  
  
    

  
    namespace rpg {
  

  
    namespace inventory {
  

  


Item::Item() { }

Item::Item(std::string name,rpg::inventory::Quality quality,uint64_t cost)
:name_(name),quality_(quality),cost_(cost){}

uint32_t Item::Size() const {
uint32_t _size = 0;


    _size += bufobjects::BufferBuilder::GetStringSize(name_);
  _size += 1; // size for "u8"
  _size += 8; // size for "u64"
  
return _size;
}

void Item::Reset() {
name_.clear();quality_ = static_cast< rpg::inventory::Quality >(0);cost_ = 0;

}


  
    }
  

  
    }
  

  


  

  
  
    

  
    namespace rpg {
  

  
    namespace inventory {
  

  


Weapon::Weapon() { }

Weapon::Weapon(uint64_t damage,std::string name,rpg::inventory::Quality quality,uint64_t cost)
:rpg::inventory::Item(name,quality,cost)
  
    ,
  damage_(damage){}

Weapon::~Weapon() {

    
  
}

void Weapon::Init(uint64_t damage,std::string name,rpg::inventory::Quality quality,uint64_t cost) {damage_ = damage;name_ = name;quality_ = quality;cost_ = cost;}

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

_dst.damage_ = damage_;_dst.name_ = name_;_dst.quality_ = quality_;_dst.cost_ = cost_;

}

uint32_t Weapon::Size() const {
uint32_t _size = rpg::inventory::Item::Size();

_size += 8; // size for "u64"
  
return _size;
}

void Weapon::WriteTo(bufobjects::BufferBuilder& _bb) const {
uint32_t _needed = this->Size();
if(_bb.GetRemaining() < _needed) {
  _bb.GrowBuffer(_needed);
}
{
    _bb.WriteUInt64(damage_);
  
  }
{
    _bb.WriteString(name_);
  
  }
{
    _bb.WriteUInt8(static_cast< uint8_t >(quality_));
  
  }
{
    _bb.WriteUInt64(cost_);
  
  }


}

void Weapon::ReadFrom(bufobjects::BufferBuilder& _bb) {
{
    damage_ = _bb.ReadUInt64();
  
  }
{
    name_ = _bb.ReadString();
  
  }
{
    quality_ = static_cast< rpg::inventory::Quality >(_bb.ReadUInt8());
  
  }
{
    cost_ = _bb.ReadUInt64();
  
  }


}

void Weapon::WriteJsonTo(std::ostream &_os) {
  _os << '{';


  _os << "\"_id\":";_os << this->BufferObjectId();
    _os << ',';
  


uint32_t _i = 0;
_os << "\"" << "damage" << "\":";
    _os << "\"" << damage_ << "\"";
  

  
    _os << ',';
  

_os << "\"" << "name" << "\":";
    _os << "\"" << name_ << "\"";
  

  
    _os << ',';
  

_os << "\"" << "quality" << "\":";
    _os << static_cast< uint16_t >(quality_);
  

  
    _os << ',';
  

_os << "\"" << "cost" << "\":";
    _os << "\"" << cost_ << "\"";
  

  


_os << '}';

}

void Weapon::WriteDirectTo(bufobjects::BufferBuilder& _bb,const uint64_t& damage,const std::string& name,const rpg::inventory::Quality& quality,const uint64_t& cost) {
{
    _bb.WriteUInt64(damage);
  
  }{
    _bb.WriteString(name);
  
  }{
    _bb.WriteUInt8(static_cast< uint8_t >(quality));
  
  }{
    _bb.WriteUInt64(cost);
  
  }
};
void Weapon::WriteDirectIdentifiedTo(bufobjects::BufferBuilder& _bb,const uint64_t& damage,const std::string& name,const rpg::inventory::Quality& quality,const uint64_t& cost) {
_bb.WriteUInt16(bufobjects::kRpgInventoryWeaponId);
Weapon::WriteDirectTo(_bb,damage,name,quality,cost);
};




  
    }
  

  
    }
  

  


  

  
  
    

  
    namespace rpg {
  

  
    namespace inventory {
  

  


Armor::Armor() { }

Armor::Armor(uint64_t defense,std::string name,rpg::inventory::Quality quality,uint64_t cost)
:rpg::inventory::Item(name,quality,cost)
  
    ,
  defense_(defense){}

Armor::~Armor() {

    
  
}

void Armor::Init(uint64_t defense,std::string name,rpg::inventory::Quality quality,uint64_t cost) {defense_ = defense;name_ = name;quality_ = quality;cost_ = cost;}

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

_dst.defense_ = defense_;_dst.name_ = name_;_dst.quality_ = quality_;_dst.cost_ = cost_;

}

uint32_t Armor::Size() const {
uint32_t _size = rpg::inventory::Item::Size();

_size += 8; // size for "u64"
  
return _size;
}

void Armor::WriteTo(bufobjects::BufferBuilder& _bb) const {
uint32_t _needed = this->Size();
if(_bb.GetRemaining() < _needed) {
  _bb.GrowBuffer(_needed);
}
{
    _bb.WriteUInt64(defense_);
  
  }
{
    _bb.WriteString(name_);
  
  }
{
    _bb.WriteUInt8(static_cast< uint8_t >(quality_));
  
  }
{
    _bb.WriteUInt64(cost_);
  
  }


}

void Armor::ReadFrom(bufobjects::BufferBuilder& _bb) {
{
    defense_ = _bb.ReadUInt64();
  
  }
{
    name_ = _bb.ReadString();
  
  }
{
    quality_ = static_cast< rpg::inventory::Quality >(_bb.ReadUInt8());
  
  }
{
    cost_ = _bb.ReadUInt64();
  
  }


}

void Armor::WriteJsonTo(std::ostream &_os) {
  _os << '{';


  _os << "\"_id\":";_os << this->BufferObjectId();
    _os << ',';
  


uint32_t _i = 0;
_os << "\"" << "defense" << "\":";
    _os << "\"" << defense_ << "\"";
  

  
    _os << ',';
  

_os << "\"" << "name" << "\":";
    _os << "\"" << name_ << "\"";
  

  
    _os << ',';
  

_os << "\"" << "quality" << "\":";
    _os << static_cast< uint16_t >(quality_);
  

  
    _os << ',';
  

_os << "\"" << "cost" << "\":";
    _os << "\"" << cost_ << "\"";
  

  


_os << '}';

}

void Armor::WriteDirectTo(bufobjects::BufferBuilder& _bb,const uint64_t& defense,const std::string& name,const rpg::inventory::Quality& quality,const uint64_t& cost) {
{
    _bb.WriteUInt64(defense);
  
  }{
    _bb.WriteString(name);
  
  }{
    _bb.WriteUInt8(static_cast< uint8_t >(quality));
  
  }{
    _bb.WriteUInt64(cost);
  
  }
};
void Armor::WriteDirectIdentifiedTo(bufobjects::BufferBuilder& _bb,const uint64_t& defense,const std::string& name,const rpg::inventory::Quality& quality,const uint64_t& cost) {
_bb.WriteUInt16(bufobjects::kRpgInventoryArmorId);
Armor::WriteDirectTo(_bb,defense,name,quality,cost);
};




  
    }
  

  
    }
  

  


  

  
  
    

  
    namespace rpg {
  

  
    namespace inventory {
  

  


Inventory::Inventory() { }

Inventory::Inventory(uint32_t capacity,std::vector<rpg::inventory::Item*> items)
:capacity_(capacity),items_(items){}

Inventory::~Inventory() {

    
  
    
      for(auto e : items_) {
        delete(e);
      }
      items_.clear();
    
  
}

void Inventory::Init(uint32_t capacity,std::vector<rpg::inventory::Item*> items) {capacity_ = capacity;items_ = items;}

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
capacity_ = 0;
    
      for(auto e : items_) {
        delete(e);
      }
    
    items_.clear();
  

}

void Inventory::CopyTo(bufobjects::BufferObject& _obj) const {
Inventory& _dst = static_cast< Inventory& >(_obj);

_dst.capacity_ = capacity_;_dst.items_ = std::vector< rpg::inventory::Item* >(items_);

}

uint32_t Inventory::Size() const {
uint32_t _size = 0;

_size += 4; // size for "u32"
  _size += bufobjects::BufferBuilder::GetVarUInt32Size(static_cast< uint32_t >(items_.size()));
    
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

void Inventory::WriteTo(bufobjects::BufferBuilder& _bb) const {
uint32_t _needed = this->Size();
if(_bb.GetRemaining() < _needed) {
  _bb.GrowBuffer(_needed);
}
{
    _bb.WriteUInt32(capacity_);
  
  }
{_bb.WriteVarUInt32(static_cast< uint32_t >(items_.size()));
    for(const auto& _e : items_) {
    if(_e == nullptr) {
        _bb.WriteUInt8(0x80);
      } else {
        _bb.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@4edde6e5, com.moybl.sidl.ast.ClassDefinition@70177ecd]"
        
          _bb.WriteUInt16(_e->BufferObjectId());
        
        _e->WriteTo(_bb);
      }
    }
  }


}

void Inventory::ReadFrom(bufobjects::BufferBuilder& _bb) {
{
    capacity_ = _bb.ReadUInt32();
  
  }
{uint32_t _size = _bb.ReadVarUInt32();
    items_.clear();
    items_.reserve(_size);
    rpg::inventory::Item* e;
    for(uint32_t i = 0; i < _size; i++) {
      // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@4edde6e5, com.moybl.sidl.ast.ClassDefinition@70177ecd]"
      
        if (_bb.ReadUInt8() == 0x81) {
          uint16_t id = _bb.ReadUInt16();
          switch(id) {
              case bufobjects::kRpgInventoryWeaponId:
                e = new rpg::inventory::Weapon{};
                e->ReadFrom(_bb);
              break;
              case bufobjects::kRpgInventoryArmorId:
                e = new rpg::inventory::Armor{};
                e->ReadFrom(_bb);
              break;}
        } else {
          e = nullptr;
        }
      items_.push_back(e);
    }
  }


}

void Inventory::WriteJsonTo(std::ostream &_os) {
  _os << '{';



uint32_t _i = 0;
_os << "\"" << "capacity" << "\":";
    _os << capacity_;
  

  
    _os << ',';
  

_os << "\"" << "items" << "\":";_os << '[';
    _i = 0;
    for(const auto& _e : items_) {
      if(_e == nullptr) {
        _os << "null";
      } else {
        _e->WriteJsonTo(_os);
      }
      if(++_i < items_.size()) {
        _os << ',';
      }
    }
    _os << ']';

  


_os << '}';

}

void Inventory::WriteDirectTo(bufobjects::BufferBuilder& _bb,const uint32_t& capacity,const std::vector<rpg::inventory::Item*>& items) {
{
    _bb.WriteUInt32(capacity);
  
  }{_bb.WriteVarUInt32(static_cast< uint32_t >(items.size()));
    for(const auto& _e : items) {
      if(_e == nullptr) {
        _bb.WriteUInt8(0x80);
      } else {
        _bb.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@4edde6e5, com.moybl.sidl.ast.ClassDefinition@70177ecd]"
        
          _bb.WriteUInt16(_e->BufferObjectId());
        
        _e->WriteTo(_bb);
      }
    }
  }
};
void Inventory::WriteDirectIdentifiedTo(bufobjects::BufferBuilder& _bb,const uint32_t& capacity,const std::vector<rpg::inventory::Item*>& items) {
_bb.WriteUInt16(bufobjects::kRpgInventoryInventoryId);
Inventory::WriteDirectTo(_bb,capacity,items);
};


  Inventory::Builder::Builder() { }

    Inventory::Builder& Inventory::Builder::SetCapacity(const uint32_t& capacity) {
      capacity_ = capacity;
      return *this;
    }
  

  
    Inventory::Builder& Inventory::Builder::SetItems(const std::vector<rpg::inventory::Item*>& items) {
      items_ = items;
      return *this;
    }
  

  
    
      Inventory::Builder& Inventory::Builder::SetItems(int index, rpg::inventory::Item* value) {
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
    
  
Inventory* Inventory::Builder::Build() {
  return new Inventory{
  capacity_,items_
  };
}




  
    }
  

  
    }