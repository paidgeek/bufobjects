// Generated with https://github.com/paidgeek/bufobjects

#include "inventory.h"



#include "../../rpg/inventory/item.h"
// this comment seems to fix a jtwig bug "true"
#include "../../rpg/inventory/weapon.h"
  #include "../../rpg/inventory/armor.h"
  


  
    namespace rpg {
  

  
    namespace inventory {
  

  


Inventory::Inventory() { }

Inventory::Inventory(uint32_t capacity,std::vector<rpg::inventory::Item*> items)
:capacity_(capacity),items_(items){}

void Inventory::Init(uint32_t capacity,std::vector<rpg::inventory::Item*> items) {capacity_ = capacity;items_ = items;}

Inventory::Inventory(const Inventory& from) {
  from.CopyTo(*this);
}

Inventory& Inventory::operator=(const Inventory& from) {
  from.CopyTo(*this);
  return *this;
}

uint16_t Inventory::BufferObjectId() const {
  return bufobjects::BufferObject::kRpgInventoryInventoryId;
}

void Inventory::Reset() {
capacity_ = 0;items_.clear();

}

void Inventory::CopyTo(bufobjects::BufferObject& obj) const {
Inventory& dst = static_cast< Inventory& >(obj);

dst.capacity_ = capacity_;dst.items_ = std::vector< rpg::inventory::Item* >(items_);
}

uint32_t Inventory::Size() const {
uint32_t size = 0;

size += 4; // size for "u32"
  size += bufobjects::BufferObjectBuilder::GetVarUInt32Size(static_cast< uint32_t >(items_.size()));
    
        for(uint32_t i = 0; i < items_.size(); i++) {
          if(items_[i] != nullptr) {
            size += items_[i]->Size();
            // this comment seems to fix a jtwig bug ""
            
              
                size += 2; // size of bufferObjectId
              
            
          }
        }
      
      size += items_.size(); // for "is null" byte
    
return size;
}

void Inventory::WriteTo(bufobjects::BufferObjectBuilder& bob) const {
uint32_t needed = this->Size();
if(bob.GetRemaining() < needed) {
  bob.GrowBuffer(needed);
}
{
    bob.WriteUInt32(capacity_);
  
  }{uint32_t size = static_cast< uint32_t >(items_.size());
    bob.WriteVarUInt32(size);
    for(int i = 0; i < size; i++) {
      rpg::inventory::Item* e = items_[i];
      if(e == nullptr) {
        bob.WriteUInt8(0x80);
      } else {
        bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "true"
        
          bob.WriteUInt16(e->BufferObjectId());
        
        e->WriteTo(bob);
      }
    }
  
  }
}

void Inventory::ReadFrom(bufobjects::BufferObjectBuilder& bob) {
{
    capacity_ = bob.ReadUInt32();
  
  }{uint32_t size = bob.ReadVarUInt32();
    items_.clear();
    items_.reserve(size);
    rpg::inventory::Item* e;
    for(uint32_t i = 0; i < size; i++) {
      // this comment seems to fix a jtwig bug "true"
      
        if (bob.ReadUInt8() == 0x81) {
          uint16_t id = bob.ReadUInt16();
          switch(id) {
              case kRpgInventoryWeaponId:
              
                e = new rpg::inventory::Weapon{};
              
              break;
              case kRpgInventoryArmorId:
              
                e = new rpg::inventory::Armor{};
              
              break;}
          e->ReadFrom(bob);
        } else {
          e = nullptr;
        }
      items_.push_back(e);
    }
  
  }
}
    const uint32_t& Inventory::GetCapacity() const {
      return capacity_;
    }
    void Inventory::SetCapacity(const uint32_t& capacity) {
      capacity_ = capacity;
    }
  

  
    const std::vector<rpg::inventory::Item*>& Inventory::GetItems() const {
      return items_;
    }
    void Inventory::SetItems(const std::vector<rpg::inventory::Item*>& items) {
      items_ = items;
    }
  

  
    
      rpg::inventory::Item* Inventory::GetItemsAt(int index) const {
        return items_[index];
      }
      void Inventory::SetItemsAt(int index, rpg::inventory::Item* value) {
        items_[index] = value;
      }
    
  
void Inventory::WriteDirectTo(bufobjects::BufferObjectBuilder& bob,uint32_t capacity,std::vector<rpg::inventory::Item*> items) {
{
    bob.WriteUInt32(capacity);
  
  }{uint32_t size = static_cast< uint32_t >(items.size());
    bob.WriteVarUInt32(size);
    for(int i = 0; i < size; i++) {
    rpg::inventory::Item* e = items[i];
    if(e == nullptr) {
        bob.WriteUInt8(0x80);
      } else {
        bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "true"
        
          bob.WriteUInt16(e->BufferObjectId());
        
        e->WriteTo(bob);
      }
    }
  
  }
};
void Inventory::WriteDirectIdentifiedTo(bufobjects::BufferObjectBuilder& bob,uint32_t capacity,std::vector<rpg::inventory::Item*> items) {
bob.WriteUInt16(kRpgInventoryInventoryId);
Inventory::WriteDirectTo(bob,capacity,items);
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
  

  
    
      Inventory::Builder& Inventory::Builder::SetItemsAt(int index, rpg::inventory::Item* value) {
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


  
    }
  

  
    }
  

  

