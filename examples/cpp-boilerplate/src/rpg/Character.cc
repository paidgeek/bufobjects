// Generated with https://github.com/paidgeek/bufobjects

#include "character.h"



#include "../rpg/inventory/inventory.h"
// this comment seems to fix a jtwig bug "[]"



#include "../rpg/inventory/item.h"
// this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@2328c243, com.moybl.sidl.ast.ClassDefinition@bebdb06]"
#include "../rpg/inventory/weapon.h"
  #include "../rpg/inventory/armor.h"
  


  
    namespace rpg {
  

  


Character::Character() { }

Character::Character(std::string name,rpg::Position position,float speed,std::shared_ptr<rpg::inventory::Inventory> bag,std::shared_ptr<rpg::inventory::Item> main_hand,std::array<double, 8> buffs)
:name_(name),position_(position),speed_(speed),bag_(bag),main_hand_(main_hand),buffs_(buffs){}

void Character::Init(std::string name,rpg::Position position,float speed,std::shared_ptr<rpg::inventory::Inventory>& bag,std::shared_ptr<rpg::inventory::Item> main_hand,std::array<double, 8> buffs) {name_ = name;position_ = position;speed_ = speed;bag_ = bag;main_hand_ = main_hand;buffs_ = buffs;}

Character::Character(const Character& from) {
  from.CopyTo(*this);
}

Character& Character::operator=(const Character& from) {
  from.CopyTo(*this);
  return *this;
}

uint16_t Character::BufferObjectId() const {
  return bufobjects::BufferObject::kRpgCharacterId;
}

void Character::Reset() {
name_ = std::string{};position_.Reset();speed_ = 0.0f;bag_ = nullptr;main_hand_ = nullptr;buffs_ = std::array<double, 8>{};

}

void Character::CopyTo(bufobjects::BufferObject& obj) const {
Character& dst = static_cast< Character& >(obj);

dst.name_ = name_;
    dst.position_ = position_;
    dst.speed_ = speed_;
    if(bag_ != nullptr) {
      bag_->CopyTo(*dst.bag_);
    }
    
    if(main_hand_ != nullptr) {
      main_hand_->CopyTo(*dst.main_hand_);
    }
    dst.buffs_ = std::array< double, 8>( buffs_ );
}

uint32_t Character::Size() const {
uint32_t size = 0;


    size += bufobjects::BufferObjectBuilder::GetStringSize(name_);
  
    
      size += rpg::Position::kSize;
    
  size += 4; // size for "f32"
  
    
      size += 1; // +1 for "is null" byte
      if(bag_ != nullptr) {
        size += bag_->Size();
        // this comment seems to fix a jtwig bug "[]"
        
      }
    
  
    
      size += 1; // +1 for "is null" byte
      if(main_hand_ != nullptr) {
        size += main_hand_->Size();
        // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@2328c243, com.moybl.sidl.ast.ClassDefinition@bebdb06]"
        
          
            size += 2; // size of bufferObjectId
          
        
      }
    
  size += kBuffsLength * 8;
    
return size;
}

void Character::WriteTo(bufobjects::BufferObjectBuilder& bob) const {
uint32_t needed = Size();
if(bob.GetRemaining() < needed) {
bob.GrowBuffer(needed);
}
{
    bob.WriteString(name_);
  
  }{
    position_.WriteTo(bob);
  
  }{
    bob.WriteFloat32(speed_);
  
  }{
    if(bag_ == nullptr) {
        bob.WriteUInt8(0x80);
      } else {
        bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        bag_->WriteTo(bob);
      }
  
  }{
    if(main_hand_ == nullptr) {
        bob.WriteUInt8(0x80);
      } else {
        bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@2328c243, com.moybl.sidl.ast.ClassDefinition@bebdb06]"
        
          bob.WriteUInt16(main_hand_->BufferObjectId());
        
        main_hand_->WriteTo(bob);
      }
  
  }{
    for(uint32_t i = 0; i < kBuffsLength; i++) {
    bob.WriteFloat64(buffs_[i]);
    }
  }
}

void Character::ReadFrom(bufobjects::BufferObjectBuilder& bob) {
{
    name_ = bob.ReadString();
  
  }{
    position_.ReadFrom(bob);
  
  }{
    speed_ = bob.ReadFloat32();
  
  }{
    // this comment seems to fix a jtwig bug "[]"
      
        if (bob.ReadUInt8() == 0x81) {
          if (bag_ == nullptr) {
            bag_ = std::shared_ptr< rpg::inventory::Inventory >{ new rpg::inventory::Inventory() };
          } else {
            bag_->ReadFrom(bob);
          }
        } else {
          bag_ = nullptr;
        }
  
  }{
    // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@2328c243, com.moybl.sidl.ast.ClassDefinition@bebdb06]"
      
        if (bob.ReadUInt8() == 0x81) {
          uint16_t id = bob.ReadUInt16();
          switch(id) {
              case kRpgInventoryWeaponId:
              main_hand_ = std::shared_ptr< rpg::inventory::Weapon >{ new rpg::inventory::Weapon() };
              break;
              case kRpgInventoryArmorId:
              main_hand_ = std::shared_ptr< rpg::inventory::Armor >{ new rpg::inventory::Armor() };
              break;}
          main_hand_->ReadFrom(bob);
        } else {
          main_hand_ = nullptr;
        }
  
  }{
    for(uint32_t i = 0; i < kBuffsLength; i++) {
      buffs_[i] = bob.ReadFloat64();
    }
  }
}const std::string& Character::GetName() const {
    return name_;
  }

  void Character::SetName(const std::string& name) {
    name_ = name;
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

  const std::shared_ptr<rpg::inventory::Inventory>& Character::GetBag() const {
    return bag_;
  }

  void Character::SetBag(const std::shared_ptr<rpg::inventory::Inventory>& bag) {
    bag_ = bag;
  }

  const std::shared_ptr<rpg::inventory::Item>& Character::GetMainHand() const {
    return main_hand_;
  }

  void Character::SetMainHand(const std::shared_ptr<rpg::inventory::Item>& main_hand) {
    main_hand_ = main_hand;
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
  
Character::Builder::Builder() { }
Character::Builder& Character::Builder::SetName(const std::string& name) {
    name_ = name;
    return *this;
  }
  Character::Builder& Character::Builder::SetPosition(const rpg::Position& position) {
    position_ = position;
    return *this;
  }
  Character::Builder& Character::Builder::SetSpeed(const float& speed) {
    speed_ = speed;
    return *this;
  }
  Character::Builder& Character::Builder::SetBag(const std::shared_ptr<rpg::inventory::Inventory>& bag) {
    bag_ = bag;
    return *this;
  }
  Character::Builder& Character::Builder::SetMainHand(const std::shared_ptr<rpg::inventory::Item>& main_hand) {
    main_hand_ = main_hand;
    return *this;
  }
  Character::Builder& Character::Builder::SetBuffs(const std::array<double, 8>& buffs) {
    buffs_ = buffs;
    return *this;
  }
  
  Character::Builder& Character::Builder::SetBuffsAt(int index, const double& value) {
    buffs_[index] = value;
    return *this;
  }
  
std::shared_ptr< Character > Character::Builder::Build() {
  return std::shared_ptr< Character >{ new Character{
  name_,position_,speed_,bag_,main_hand_,buffs_
  } };
}


  
    }
  

  

