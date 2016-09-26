// Generated with https://github.com/paidgeek/bufobjects

#include "inventory.h"



#include "../../rpg/inventory/item.h"
// this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@7a4f0f29, com.moybl.sidl.ast.ClassDefinition@45283ce2]"
#include "../../rpg/inventory/weapon.h"
  #include "../../rpg/inventory/armor.h"
  


  
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

_bob.WriteData((void*)this, sizeof(capacity_) + 0);
  

  {_bob.WriteVarUInt32(static_cast< uint32_t >(items_.size()));
      for(const auto& _e : items_) {
        if(_e == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@7a4f0f29, com.moybl.sidl.ast.ClassDefinition@45283ce2]"
        
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
        // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@7a4f0f29, com.moybl.sidl.ast.ClassDefinition@45283ce2]"
        
          _bob.WriteUInt16(_e->BufferObjectId());
        
        _e->WriteTo(_bob);
      }
    }
  }


#endif

}

void Inventory::ReadFrom(bufobjects::BufferObjectBuilder& _bob) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)

_bob.ReadData((void*)this, sizeof(capacity_) + 0);
  

  {uint32_t _size = _bob.ReadVarUInt32();
      items_.clear();
      items_.reserve(_size);
      rpg::inventory::Item* _e;
      for(uint32_t i = 0; i < _size; i++) {
        // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@7a4f0f29, com.moybl.sidl.ast.ClassDefinition@45283ce2]"
      
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
      // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@7a4f0f29, com.moybl.sidl.ast.ClassDefinition@45283ce2]"
      
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
        // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@7a4f0f29, com.moybl.sidl.ast.ClassDefinition@45283ce2]"
        
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
  

  

