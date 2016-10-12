// Generated with https://github.com/paidgeek/bufobjects


#include "./../../rpg/rpg.h"

#include "./../../rpg/inventory/inventory.h"



  
  

  
  
    

  
    namespace rpg {
  

  
    namespace inventory {
  

  


Item::Item() : _cached_size_(0) { }

Item::Item(std::string name,rpg::inventory::Quality quality,uint64_t cost)
:name_(name),quality_(quality),cost_(cost){
  _cached_size_ = 0;
}

uint32_t Item::Size() const {
  if (_cached_size_ != 0) {
    return _cached_size_;
  }
  _cached_size_ = 0;


    _cached_size_ += bufobjects::BufferBuilder::GetStringSize(name_);
  _cached_size_ += 1; // size for "u8"
  _cached_size_ += 8; // size for "u64"
  

  return _cached_size_;
}

void Item::Clear() {
name_.clear();quality_ = static_cast< rpg::inventory::Quality >(0);cost_ = 0;

_cached_size_ = 0;
}


  
    }
  

  
    }
  

  


  

  
  
    

  
    namespace rpg {
  

  
    namespace inventory {
  

  


Weapon::Weapon() : _cached_size_(0) { }

Weapon::Weapon(uint64_t damage,std::string name,rpg::inventory::Quality quality,uint64_t cost)
:/* this comment seems to fix a jtwig bug "" */
    
      rpg::inventory::Item(name,quality,cost)
  
    ,
  damage_(damage){
  _cached_size_ = 0;
}

Weapon::~Weapon() {


}

void Weapon::Init(uint64_t damage,std::string name,rpg::inventory::Quality quality,uint64_t cost) {damage_ = damage;name_ = name;quality_ = quality;cost_ = cost;
_cached_size_ = 0;
}

Weapon::Weapon(const Weapon& from) {
  from.CopyTo(*this);
  _cached_size_ = 0;
}

Weapon& Weapon::operator=(const Weapon& from) {
  from.CopyTo(*this);
  _cached_size_ = from._cached_size_;
  return *this;
}

uint16_t Weapon::BufferObjectId() const {
  return bufobjects::kRpgInventoryWeaponId;
}

void Weapon::Clear() {
/* this comment seems to fix a jtwig bug "" */
    
      rpg::inventory::Item::Clear();damage_ = 0;

_cached_size_ = 0;
}

void Weapon::CopyTo(bufobjects::BufferObject& _obj) const {
Weapon& _dst = static_cast< Weapon& >(_obj);
_dst._cached_size_ = _cached_size_;

_dst.damage_ = damage_;_dst.name_ = name_;_dst.quality_ = quality_;_dst.cost_ = cost_;

}

uint32_t Weapon::Size() const {
if (_cached_size_ != 0) {
  return _cached_size_;
}
_cached_size_ = /* this comment seems to fix a jtwig bug "" */
    
      rpg::inventory::Item::Size();

_cached_size_ += 8; // size for "u64"
  

return _cached_size_;
}

void Weapon::WriteTo(bufobjects::BufferBuilder& _bb) const {
uint32_t _needed = this->Size();
if(_bb.remaining() < _needed) {
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
    quality_ = static_cast< /* this comment seems to fix a jtwig bug "" */
    
      rpg::inventory::Quality >(_bb.ReadUInt8());
  
  }
{
    cost_ = _bb.ReadUInt64();
  
  }


_cached_size_ = 0;
}

void Weapon::WriteJsonTo(std::ostream &_os) const {
  _os << '{';


  _os << "\"_id\":";_os << this->BufferObjectId();
    _os << ',';
  


uint32_t _i = 0;
_os << "\"damage\":";
    _os << "\"" << damage_ << "\"";
  

  
    _os << ',';
  

_os << "\"name\":";
    _os << "\"" << name_ << "\"";
  

  
    _os << ',';
  

_os << "\"quality\":";
    _os << static_cast< uint16_t >(quality_);
  

  
    _os << ',';
  

_os << "\"cost\":";
    _os << "\"" << cost_ << "\"";
  

  


_os << '}';

}

void Weapon::WriteDirectTo(bufobjects::BufferBuilder& _bb,const uint64_t& damage,const std::string& name,const /* this comment seems to fix a jtwig bug "" */
    
      rpg::inventory::Quality& quality,const uint64_t& cost) {
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
void Weapon::WriteDirectIdentifiedTo(bufobjects::BufferBuilder& _bb,const uint64_t& damage,const std::string& name,const /* this comment seems to fix a jtwig bug "" */
    
      rpg::inventory::Quality& quality,const uint64_t& cost) {
_bb.WriteUInt16(bufobjects::kRpgInventoryWeaponId);
Weapon::WriteDirectTo(_bb,damage,name,quality,cost);
};




  
    }
  

  
    }
  

  


  

  
  
    

  
    namespace rpg {
  

  
    namespace inventory {
  

  


Armor::Armor() : _cached_size_(0) { }

Armor::Armor(uint64_t defense,std::string name,rpg::inventory::Quality quality,uint64_t cost)
:/* this comment seems to fix a jtwig bug "" */
    
      rpg::inventory::Item(name,quality,cost)
  
    ,
  defense_(defense){
  _cached_size_ = 0;
}

Armor::~Armor() {


}

void Armor::Init(uint64_t defense,std::string name,rpg::inventory::Quality quality,uint64_t cost) {defense_ = defense;name_ = name;quality_ = quality;cost_ = cost;
_cached_size_ = 0;
}

Armor::Armor(const Armor& from) {
  from.CopyTo(*this);
  _cached_size_ = 0;
}

Armor& Armor::operator=(const Armor& from) {
  from.CopyTo(*this);
  _cached_size_ = from._cached_size_;
  return *this;
}

uint16_t Armor::BufferObjectId() const {
  return bufobjects::kRpgInventoryArmorId;
}

void Armor::Clear() {
/* this comment seems to fix a jtwig bug "" */
    
      rpg::inventory::Item::Clear();defense_ = 0;

_cached_size_ = 0;
}

void Armor::CopyTo(bufobjects::BufferObject& _obj) const {
Armor& _dst = static_cast< Armor& >(_obj);
_dst._cached_size_ = _cached_size_;

_dst.defense_ = defense_;_dst.name_ = name_;_dst.quality_ = quality_;_dst.cost_ = cost_;

}

uint32_t Armor::Size() const {
if (_cached_size_ != 0) {
  return _cached_size_;
}
_cached_size_ = /* this comment seems to fix a jtwig bug "" */
    
      rpg::inventory::Item::Size();

_cached_size_ += 8; // size for "u64"
  

return _cached_size_;
}

void Armor::WriteTo(bufobjects::BufferBuilder& _bb) const {
uint32_t _needed = this->Size();
if(_bb.remaining() < _needed) {
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
    quality_ = static_cast< /* this comment seems to fix a jtwig bug "" */
    
      rpg::inventory::Quality >(_bb.ReadUInt8());
  
  }
{
    cost_ = _bb.ReadUInt64();
  
  }


_cached_size_ = 0;
}

void Armor::WriteJsonTo(std::ostream &_os) const {
  _os << '{';


  _os << "\"_id\":";_os << this->BufferObjectId();
    _os << ',';
  


uint32_t _i = 0;
_os << "\"defense\":";
    _os << "\"" << defense_ << "\"";
  

  
    _os << ',';
  

_os << "\"name\":";
    _os << "\"" << name_ << "\"";
  

  
    _os << ',';
  

_os << "\"quality\":";
    _os << static_cast< uint16_t >(quality_);
  

  
    _os << ',';
  

_os << "\"cost\":";
    _os << "\"" << cost_ << "\"";
  

  


_os << '}';

}

void Armor::WriteDirectTo(bufobjects::BufferBuilder& _bb,const uint64_t& defense,const std::string& name,const /* this comment seems to fix a jtwig bug "" */
    
      rpg::inventory::Quality& quality,const uint64_t& cost) {
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
void Armor::WriteDirectIdentifiedTo(bufobjects::BufferBuilder& _bb,const uint64_t& defense,const std::string& name,const /* this comment seems to fix a jtwig bug "" */
    
      rpg::inventory::Quality& quality,const uint64_t& cost) {
_bb.WriteUInt16(bufobjects::kRpgInventoryArmorId);
Armor::WriteDirectTo(_bb,defense,name,quality,cost);
};




  
    }
  

  
    }
  

  


  

  
  
    

  
    namespace rpg {
  

  
    namespace inventory {
  

  


Inventory::Inventory() : _cached_size_(0) { }

Inventory::Inventory(uint32_t capacity,std::vector</* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item*> items)
:capacity_(capacity),items_(items){
  _cached_size_ = 0;
}

Inventory::~Inventory() {


}

void Inventory::Init(uint32_t capacity,std::vector</* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item*> items) {capacity_ = capacity;items_ = items;
_cached_size_ = 0;
}

Inventory::Inventory(const Inventory& from) {
  from.CopyTo(*this);
  _cached_size_ = 0;
}

Inventory& Inventory::operator=(const Inventory& from) {
  from.CopyTo(*this);
  _cached_size_ = from._cached_size_;
  return *this;
}

uint16_t Inventory::BufferObjectId() const {
  return bufobjects::kRpgInventoryInventoryId;
}

void Inventory::Clear() {
capacity_ = 0;
    items_.clear();
  

_cached_size_ = 0;
}

void Inventory::CopyTo(bufobjects::BufferObject& _obj) const {
Inventory& _dst = static_cast< Inventory& >(_obj);
_dst._cached_size_ = _cached_size_;

_dst.capacity_ = capacity_;_dst.items_ = std::vector< /* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item* >(items_);

}

uint32_t Inventory::Size() const {
if (_cached_size_ != 0) {
  return _cached_size_;
}
_cached_size_ = 0;

_cached_size_ += 4; // size for "u32"
  _cached_size_ += bufobjects::BufferBuilder::GetVarUInt32Size(static_cast< uint32_t >(items_.size()));
    
        for(const auto& _e : items_) {
        // this comment seems to fix a jtwig bug "true"
        
          _cached_size_ += _e->Size();
          
            _cached_size_ += 2; // size of bufferObjectId
          
        
        }
      
    

return _cached_size_;
}

void Inventory::WriteTo(bufobjects::BufferBuilder& _bb) const {
uint32_t _needed = this->Size();
if(_bb.remaining() < _needed) {
  _bb.GrowBuffer(_needed);
}
{
    _bb.WriteUInt32(capacity_);
  
  }
{_bb.WriteVarUInt32(static_cast< uint32_t >(items_.size()));
    for(const auto& _e : items_) {
    // this comment seems to fix a jtwig bug "true"
      
        _bb.WriteUInt16(_e->BufferObjectId());
        _e->WriteTo(_bb);
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
    /* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item* _e;
    for(uint32_t i = 0; i < _size; i++) {
      // this comment seems to fix a jtwig bug "true"
      
        uint16_t id = _bb.ReadUInt16();
        switch(id) {
            case bufobjects::kRpgInventoryWeaponId:
            _e = new rpg::inventory::Weapon{};
            _e->ReadFrom(_bb);
            break;
            case bufobjects::kRpgInventoryArmorId:
            _e = new rpg::inventory::Armor{};
            _e->ReadFrom(_bb);
            break;}
      items_.push_back(_e);
    }
  }


_cached_size_ = 0;
}

void Inventory::WriteJsonTo(std::ostream &_os) const {
  _os << '{';



uint32_t _i = 0;
_os << "\"capacity\":";
    _os << capacity_;
  

  
    _os << ',';
  

_os << "\"items\":";_os << '[';
    _i = 0;
    for(const auto& _e : items_) {
      /* this comment seems to fix a jtwig bug "true" */
    
      _e->WriteJsonTo(_os);
      if(++_i < items_.size()) {
        _os << ',';
      }
    }
    _os << ']';

  


_os << '}';

}

void Inventory::WriteDirectTo(bufobjects::BufferBuilder& _bb,const uint32_t& capacity,const std::vector</* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item*>& items) {
{
    _bb.WriteUInt32(capacity);
  
  }{_bb.WriteVarUInt32(static_cast< uint32_t >(items.size()));
    for(const auto& _e : items) {
      // this comment seems to fix a jtwig bug "true"
      
        _bb.WriteUInt16(_e->BufferObjectId());
        _e->WriteTo(_bb);
    }
  }
};
void Inventory::WriteDirectIdentifiedTo(bufobjects::BufferBuilder& _bb,const uint32_t& capacity,const std::vector</* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item*>& items) {
_bb.WriteUInt16(bufobjects::kRpgInventoryInventoryId);
Inventory::WriteDirectTo(_bb,capacity,items);
};


  Inventory::Builder::Builder() { }

    Inventory::Builder& Inventory::Builder::SetCapacity(const uint32_t& capacity) {
    capacity_ = capacity;
    return *this;
    }
  

  
    Inventory::Builder& Inventory::Builder::SetItems(const std::vector</* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item*>& items) {
    items_ = items;
    return *this;
    }
  

  
    
      Inventory::Builder& Inventory::Builder::SetItems(int index, /* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item* value) {
      items_[index] = value;
      return *this;
      }
      Inventory::Builder& Inventory::Builder::AddItems(/* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item* value) {
      items_.push_back(value);
      return *this;
      }
      Inventory::Builder& Inventory::Builder::AddItems(std::vector</* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item*> values) {
      items_.insert(std::end(items_), std::begin(values), std::end(values));
      return *this;
      }
    
  
Inventory* Inventory::Builder::Build() {
return new Inventory{
std::move(capacity_),std::move(items_)
};
}



  
    }
  

  
    }