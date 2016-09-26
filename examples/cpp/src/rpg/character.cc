// Generated with https://github.com/paidgeek/bufobjects

#include "character.h"



#include "../rpg/inventory/inventory.h"
// this comment seems to fix a jtwig bug "[]"



#include "../rpg/inventory/item.h"
// this comment seems to fix a jtwig bug "true"
#include "../rpg/inventory/weapon.h"
  #include "../rpg/inventory/armor.h"
  


  
    namespace rpg {
  

  


Character::Character() { }

Character::Character(rpg::Position position,float speed,std::array<double, 8> buffs,std::string name,rpg::inventory::Inventory* bag,rpg::inventory::Item* main_hand)
:position_(position),speed_(speed),buffs_(buffs),name_(name),bag_(bag),main_hand_(main_hand){}

Character::~Character() {
  
    
  
    
  
    
  
    
  
    
      delete(bag_);
    
  
    
      delete(main_hand_);
    
  

}

void Character::Init(rpg::Position position,float speed,std::array<double, 8> buffs,std::string name,rpg::inventory::Inventory*& bag,rpg::inventory::Item* main_hand) {position_ = position;speed_ = speed;buffs_ = buffs;name_ = name;bag_ = bag;main_hand_ = main_hand;}
Character::Ptr Character::New(rpg::Position position,float speed,std::array<double, 8> buffs,std::string name,rpg::inventory::Inventory*& bag,rpg::inventory::Item* main_hand) {

  return new rpg::Character{position,speed,buffs,name,bag,main_hand};

}

Character::Character(const Character& from) {
  from.CopyTo(*this);
}

Character& Character::operator=(const Character& from) {
  from.CopyTo(*this);
  return *this;
}

uint16_t Character::BufferObjectId() const {
  return bufobjects::kRpgCharacterId;
}

void Character::Reset() {
position_.Reset();speed_ = 0.0f;buffs_ = std::array<double, 8>{};name_ = std::string{};bag_ = nullptr;main_hand_ = nullptr;

}

void Character::CopyTo(bufobjects::BufferObject& obj) const {
Character& dst = static_cast< Character& >(obj);


    dst.position_ = position_;
    dst.speed_ = speed_;dst.buffs_ = std::array< double, 8>( buffs_ );dst.name_ = name_;
    if(bag_ != nullptr) {
      bag_->CopyTo(*dst.bag_);
    }
    
    if(main_hand_ != nullptr) {
      main_hand_->CopyTo(*dst.main_hand_);
    }
    
}

uint32_t Character::Size() const {
uint32_t size = 0;


    
      size += sizeof(rpg::Position);
    
  size += 4; // size for "f32"
  size += kBuffsLength * 8;
    
    size += bufobjects::BufferObjectBuilder::GetStringSize(name_);
  
    
      size += 1; // +1 for "is null" byte
      if(bag_ != nullptr) {
        size += bag_->Size();
        // this comment seems to fix a jtwig bug "[]"
        
      }
    
  
    
      size += 1; // +1 for "is null" byte
      if(main_hand_ != nullptr) {
        size += main_hand_->Size();
        // this comment seems to fix a jtwig bug "true"
        
          
            size += 2; // size of bufferObjectId
          
        
      }
    
  
return size;
}

void Character::WriteTo(bufobjects::BufferObjectBuilder& _bob) const {
uint32_t needed = this->Size();
if(_bob.GetRemaining() < needed) {
  _bob.GrowBuffer(needed);
}
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
{_bob.WriteData((void*)this, sizeof(position_) +sizeof(speed_) +sizeof(buffs_) + 0);
  

  

  

  {
      _bob.WriteString(name_);
    
    }

  

  {
      if(bag_ == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        bag_->WriteTo(_bob);
      }
    
    }

  

  {
      if(main_hand_ == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "true"
        
          _bob.WriteUInt16(main_hand_->BufferObjectId());
        
        main_hand_->WriteTo(_bob);
      }
    
    }

  

}

#else
{{
    position_.WriteTo(_bob);
  
  }{
    _bob.WriteFloat32(speed_);
  
  }{
    for(uint32_t i = 0; i < kBuffsLength; i++) {
    _bob.WriteFloat64(buffs_[i]);
    }
  }{
    _bob.WriteString(name_);
  
  }{
    if(bag_ == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        bag_->WriteTo(_bob);
      }
  
  }{
    if(main_hand_ == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "true"
        
          _bob.WriteUInt16(main_hand_->BufferObjectId());
        
        main_hand_->WriteTo(_bob);
      }
  
  }}
#endif

}

void Character::ReadFrom(bufobjects::BufferObjectBuilder& _bob) {
{
    position_.ReadFrom(_bob);
  
  }{
    speed_ = _bob.ReadFloat32();
  
  }{
    for(uint32_t i = 0; i < kBuffsLength; i++) {
      buffs_[i] = _bob.ReadFloat64();
    }
  }{
    name_ = _bob.ReadString();
  
  }{
    // this comment seems to fix a jtwig bug "[]"
      
        if (_bob.ReadUInt8() == 0x81) {
          if (bag_ == nullptr) {
            
              bag_ = new rpg::inventory::Inventory{};
            
          }
          bag_->ReadFrom(_bob);
        } else {
          bag_ = nullptr;
        }
  
  }{
    // this comment seems to fix a jtwig bug "true"
      
        if (_bob.ReadUInt8() == 0x81) {
          uint16_t id = _bob.ReadUInt16();
          switch(id) {
              case bufobjects::kRpgInventoryWeaponId:
              
                main_hand_ = new rpg::inventory::Weapon{};
              
              break;
              case bufobjects::kRpgInventoryArmorId:
              
                main_hand_ = new rpg::inventory::Armor{};
              
              break;}
          main_hand_->ReadFrom(_bob);
        } else {
          main_hand_ = nullptr;
        }
  
  }
}
    const rpg::Position& Character::GetPosition() const {
      return position_;
    }
    void Character::SetPosition(const rpg::Position& position) {
      position_ = position;
    }
  

  
    const float& Character::GetSpeed() const {
      return speed_;
    }
    void Character::SetSpeed(const float& speed) {
      speed_ = speed;
    }
  

  
    const std::array<double, 8>& Character::GetBuffs() const {
      return buffs_;
    }
    void Character::SetBuffs(const std::array<double, 8>& buffs) {
      buffs_ = buffs;
    }
  

  
    
      const double& Character::GetBuffsAt(int index) const {
        return buffs_[index];
      }
      void Character::SetBuffsAt(int index, const double& value) {
        buffs_[index] = value;
      }
    
  
    const std::string& Character::GetName() const {
      return name_;
    }
    void Character::SetName(const std::string& name) {
      name_ = name;
    }
  

  
    rpg::inventory::Inventory* Character::GetBag() {
      return bag_;
    }
    void Character::SetBag(rpg::inventory::Inventory* bag) {
      bag_ = bag;
    }
  

  
    rpg::inventory::Item* Character::GetMainHand() {
      return main_hand_;
    }
    void Character::SetMainHand(rpg::inventory::Item* main_hand) {
      main_hand_ = main_hand;
    }
  

  
void Character::WriteDirectTo(bufobjects::BufferObjectBuilder& _bob,rpg::Position position,float speed,std::array<double, 8> buffs,std::string name,rpg::inventory::Inventory* bag,rpg::inventory::Item* main_hand) {
{
    position.WriteTo(_bob);
  
  }{
    _bob.WriteFloat32(speed);
  
  }{
    for(uint32_t i = 0; i < kBuffsLength; i++) {
    _bob.WriteFloat64(buffs[i]);
    }
  }{
    _bob.WriteString(name);
  
  }{
    if(bag == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        bag->WriteTo(_bob);
      }
  
  }{
    if(main_hand == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "true"
        
          _bob.WriteUInt16(main_hand->BufferObjectId());
        
        main_hand->WriteTo(_bob);
      }
  
  }
};
void Character::WriteDirectIdentifiedTo(bufobjects::BufferObjectBuilder& _bob,rpg::Position position,float speed,std::array<double, 8> buffs,std::string name,rpg::inventory::Inventory* bag,rpg::inventory::Item* main_hand) {
_bob.WriteUInt16(bufobjects::kRpgCharacterId);
Character::WriteDirectTo(_bob,position,speed,buffs,name,bag,main_hand);
};


  Character::Builder::Builder() { }

    Character::Builder& Character::Builder::Position(const rpg::Position& position) {
      position_ = position;
      return *this;
    }
  

  
    Character::Builder& Character::Builder::Speed(const float& speed) {
      speed_ = speed;
      return *this;
    }
  

  
    Character::Builder& Character::Builder::Buffs(const std::array<double, 8>& buffs) {
      buffs_ = buffs;
      return *this;
    }
  

  
    
      Character::Builder& Character::Builder::Buffs(int index, const double& value) {
        buffs_[index] = value;
        return *this;
      }
    
  
    Character::Builder& Character::Builder::Name(const std::string& name) {
      name_ = name;
      return *this;
    }
  

  
    Character::Builder& Character::Builder::Bag(rpg::inventory::Inventory* bag) {
      bag_ = bag;
      return *this;
    }
  

  
    Character::Builder& Character::Builder::MainHand(rpg::inventory::Item* main_hand) {
      main_hand_ = main_hand;
      return *this;
    }
  

  
Character::Ptr Character::Builder::Build() {

  return new Character{
  position_,speed_,buffs_,name_,bag_,main_hand_
  };

}



  
    }
  

  

