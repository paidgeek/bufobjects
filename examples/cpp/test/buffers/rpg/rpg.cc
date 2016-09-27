// Generated with https://github.com/paidgeek/bufobjects


#include "rpg.h"

#include "rpg_inventory.h"



  
  
    
  
    namespace rpg {
  

  


Position::Position() { }

Position::Position(float x,float y)
:x_(x),y_(y){}

Position::Position(const Position& from) {
  memcpy(this, &from, sizeof(Position));
}

void Position::Reset() {
  *this = Position{};
}

void Position::WriteTo(bufobjects::BufferObjectBuilder& _bob) const {
if(_bob.GetRemaining() < sizeof(Position)) {
  _bob.GrowBuffer(sizeof(Position));
}
#if defined(BUFOBJECTS_LITTLE_ENDIAN)

_bob.WriteData((void*) this, sizeof(Position));

#else

{_bob.WriteFloat32(x_);}
{_bob.WriteFloat32(y_);}


#endif
}

void Position::ReadFrom(bufobjects::BufferObjectBuilder& _bob) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)

_bob.ReadData((void*) this, sizeof(Position));

#else

{x_ = _bob.ReadFloat32();}{y_ = _bob.ReadFloat32();}

#endif

}


  
    }
  

  


  

  
  
    

  
    namespace rpg {
  

  


Character::Character() { }

Character::Character(rpg::Position position,float speed,std::array<double, 8> buffs,std::string name,rpg::inventory::Inventory* bag,std::map<std::string, rpg::inventory::Item*> equipment)
:position_(position),speed_(speed),buffs_(buffs),name_(name),bag_(bag),equipment_(equipment){}


Character::~Character() {
  
    
  
    
  
    
  
    
  
    
      delete(bag_);
    
  
    
      for (const auto& kv : equipment_) {
        delete(kv.second);
      }
      equipment_.clear();
    
  

}


void Character::Init(rpg::Position position,float speed,std::array<double, 8> buffs,std::string name,rpg::inventory::Inventory*& bag,std::map<std::string, rpg::inventory::Item*> equipment) {position_ = position;speed_ = speed;buffs_ = buffs;name_ = name;bag_ = bag;equipment_ = equipment;}
Character::Ptr Character::New(rpg::Position position,float speed,std::array<double, 8> buffs,std::string name,rpg::inventory::Inventory*& bag,std::map<std::string, rpg::inventory::Item*> equipment) {

  return new rpg::Character{position,speed,buffs,name,bag,equipment};

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
position_.Reset();speed_ = 0.0f;buffs_ = std::array<double, 8>{};name_ = std::string{};bag_ = nullptr;equipment_.clear();

}

void Character::CopyTo(bufobjects::BufferObject& _obj) const {
Character& _dst = static_cast< Character& >(_obj);


      _dst.position_ = position_;
    _dst.speed_ = speed_;_dst.buffs_ = std::array< double, 8>( buffs_ );_dst.name_ = name_;
    if(bag_ != nullptr) {
      bag_->CopyTo(*_dst.bag_);
    }
    _dst.equipment_ = std::map< std::string, rpg::inventory::Item* >(equipment_);

}

uint32_t Character::Size() const {
uint32_t _size = 0;


    
      _size += sizeof(rpg::Position);
    
  _size += 4; // size for "f32"
  _size += kBuffsLength * 8;
    
    _size += bufobjects::BufferObjectBuilder::GetStringSize(name_);
  
    
      _size += 1; // +1 for "is null" byte
      if(bag_ != nullptr) {
      _size += bag_->Size();
        // this comment seems to fix a jtwig bug "[]"
        
      }
    
  _size += bufobjects::BufferObjectBuilder::GetVarUInt32Size(static_cast< uint32_t >(equipment_.size()));

    

    
        for(const auto& _kv : equipment_) {
          
            _size += bufobjects::BufferObjectBuilder::GetStringSize(_kv.first);
          
          if(_kv.second != nullptr) {
            _size += _kv.second->Size();
            // this comment seems to fix a jtwig bug ""
            
              
                _size += 2; // size of bufferObjectId
              
            
          }
        }
        _size += equipment_.size(); // for "is null" byte
      
    
return _size;
}

void Character::WriteTo(bufobjects::BufferObjectBuilder& _bob) const {
uint32_t _needed = this->Size();
if(_bob.GetRemaining() < _needed) {
  _bob.GrowBuffer(_needed);
}
#if defined(BUFOBJECTS_LITTLE_ENDIAN)



  
    
  
  
  
  
  
  _bob.WriteData((void*)(&position_), sizeof(position_) +sizeof(speed_) +sizeof(buffs_) + 0);
  

  

  

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

  

  {_bob.WriteVarUInt32(static_cast< uint32_t >(equipment_.size()));
      for(const auto& _kv : equipment_) {
        _bob.WriteString(_kv.first);
        if(_kv.second == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@4edde6e5, com.moybl.sidl.ast.ClassDefinition@70177ecd]"
        
          _bob.WriteUInt16(_kv.second->BufferObjectId());
        
        _kv.second->WriteTo(_bob);
      }
      }
    
    }

  


#else

{
    position_.WriteTo(_bob);
  
  }
{
    _bob.WriteFloat32(speed_);
  
  }
{for(const auto& _e : buffs_) {
    _bob.WriteFloat64(_e);
    }
  }
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
{_bob.WriteVarUInt32(static_cast< uint32_t >(equipment_.size()));
    for(const auto& _kv : equipment_) {
    _bob.WriteString(_kv.first);
    if(_kv.second == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@4edde6e5, com.moybl.sidl.ast.ClassDefinition@70177ecd]"
        
          _bob.WriteUInt16(_kv.second->BufferObjectId());
        
        _kv.second->WriteTo(_bob);
      }
    }
  
  }


#endif

}

void Character::ReadFrom(bufobjects::BufferObjectBuilder& _bob) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)



  
    
  
  
  
  
  
  _bob.ReadData((void*)(&position_), sizeof(position_) +sizeof(speed_) +sizeof(buffs_) + 0);
  

  

  

  {
      name_ = _bob.ReadString();
    
    }
  

  {
      // this comment seems to fix a jtwig bug "[]"
      
        if (_bob.ReadUInt8() == 0x81) {
          if (bag_ == nullptr) {
            
              bag_ = new rpg::inventory::Inventory{};
            
          }
          bag_->ReadFrom(_bob);
        } else {
          bag_ = nullptr;
        }
    
    }
  

  {uint32_t _size = _bob.ReadVarUInt32();
      equipment_.clear();
      std::string _key;
      rpg::inventory::Item* _value;
      for(uint32_t i = 0; i < _size; i++) {
        _key = _bob.ReadString();
        // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@4edde6e5, com.moybl.sidl.ast.ClassDefinition@70177ecd]"
      
        if (_bob.ReadUInt8() == 0x81) {
          uint16_t id = _bob.ReadUInt16();
          switch(id) {
              case bufobjects::kRpgInventoryWeaponId:
              
                _value = new rpg::inventory::Weapon{};
                _value->ReadFrom(_bob);
              
              break;
              case bufobjects::kRpgInventoryArmorId:
              
                _value = new rpg::inventory::Armor{};
                _value->ReadFrom(_bob);
              
              break;}
        } else {
          _value = nullptr;
        }
        equipment_[_key] = _value;
      }
    
    }
  


#else

{
    position_.ReadFrom(_bob);
  
  }
{
    speed_ = _bob.ReadFloat32();
  
  }
{
    for(uint32_t i = 0; i < kBuffsLength; i++) {
      buffs_[i] = _bob.ReadFloat64();
    }
  }
{
    name_ = _bob.ReadString();
  
  }
{
    // this comment seems to fix a jtwig bug "[]"
      
        if (_bob.ReadUInt8() == 0x81) {
          if (bag_ == nullptr) {
            
              bag_ = new rpg::inventory::Inventory{};
            
          }
          bag_->ReadFrom(_bob);
        } else {
          bag_ = nullptr;
        }
  
  }
{uint32_t _size = _bob.ReadVarUInt32();
    equipment_.clear();
    std::string _key;
    rpg::inventory::Item* _value;
    for(uint32_t i = 0; i < _size; i++) {
      _key = _bob.ReadString();
      // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@4edde6e5, com.moybl.sidl.ast.ClassDefinition@70177ecd]"
      
        if (_bob.ReadUInt8() == 0x81) {
          uint16_t id = _bob.ReadUInt16();
          switch(id) {
              case bufobjects::kRpgInventoryWeaponId:
              
                _value = new rpg::inventory::Weapon{};
                _value->ReadFrom(_bob);
              
              break;
              case bufobjects::kRpgInventoryArmorId:
              
                _value = new rpg::inventory::Armor{};
                _value->ReadFrom(_bob);
              
              break;}
        } else {
          _value = nullptr;
        }
      equipment_[_key] = _value;
    }
  
  }


#endif

}

void Character::WriteDirectTo(bufobjects::BufferObjectBuilder& _bob,rpg::Position position,float speed,std::array<double, 8> buffs,std::string name,rpg::inventory::Inventory* bag,std::map<std::string, rpg::inventory::Item*> equipment) {
{
    position.WriteTo(_bob);
  
  }{
    _bob.WriteFloat32(speed);
  
  }{for(const auto& _e : buffs) {
    _bob.WriteFloat64(_e);
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
  
  }{_bob.WriteVarUInt32(static_cast< uint32_t >(equipment.size()));
    for(const auto& _kv : equipment) {
    _bob.WriteString(_kv.first);
    if(_kv.second == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@4edde6e5, com.moybl.sidl.ast.ClassDefinition@70177ecd]"
        
          _bob.WriteUInt16(_kv.second->BufferObjectId());
        
        _kv.second->WriteTo(_bob);
      }
    }
  
  }
};
void Character::WriteDirectIdentifiedTo(bufobjects::BufferObjectBuilder& _bob,rpg::Position position,float speed,std::array<double, 8> buffs,std::string name,rpg::inventory::Inventory* bag,std::map<std::string, rpg::inventory::Item*> equipment) {
_bob.WriteUInt16(bufobjects::kRpgCharacterId);
Character::WriteDirectTo(_bob,position,speed,buffs,name,bag,equipment);
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
  

  
    Character::Builder& Character::Builder::Equipment(const std::map<std::string, rpg::inventory::Item*>& equipment) {
      equipment_ = equipment;
      return *this;
    }
  

  
    
    Character::Builder& Character::Builder::Equipment(const std::string& key, rpg::inventory::Item* value) {
      equipment_[key] = value;
      return *this;
    }

  
Character::Ptr Character::Builder::Build() {

  return new Character{
  position_,speed_,buffs_,name_,bag_,equipment_
  };

}

void Character::Builder::WriteTo(bufobjects::BufferObjectBuilder& _bob) {
  Character::WriteDirectTo(_bob,position_,speed_,buffs_,name_,bag_,equipment_);
}

void Character::Builder::WriteIdentifiedTo(bufobjects::BufferObjectBuilder& _bob) {
Character::WriteDirectIdentifiedTo(_bob,position_,speed_,buffs_,name_,bag_,equipment_);
}




  
    }