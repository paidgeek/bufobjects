// Generated with https://github.com/paidgeek/bufobjects


#include "./../rpg/rpg.h"

#include "./../rpg/inventory/inventory.h"



  
  
    
  
    namespace rpg {
  

  


Position::Position() { }

Position::Position(float x,float y)
:x(x),y(y){}

Position::Position(const Position& from) {
  memcpy(this, &from, sizeof(Position));
}

void Position::Reset() {
x = 0.0f;y = 0.0f;

}

void Position::WriteTo(bufobjects::BufferBuilder& _bb) const {
if(_bb.GetRemaining() < sizeof(Position)) {
  _bb.GrowBuffer(sizeof(Position));
}
#if defined(BUFOBJECTS_LITTLE_ENDIAN)

_bb.WriteData((void*) this, sizeof(Position));

#else

{_bb.WriteFloat32(x);}
{_bb.WriteFloat32(y);}


#endif

}

void Position::ReadFrom(bufobjects::BufferBuilder& _bb) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)

_bb.ReadData((void*) this, sizeof(Position));

#else

{x = _bb.ReadFloat32();}{y = _bb.ReadFloat32();}

#endif

}

void Position::WriteJsonTo(std::ostream &_os) {
_os << '{';

uint32_t _i = 0;
_os << "\"" << "x" << "\":";
    _os << x;
  

  
    _os << ',';
  

_os << "\"" << "y" << "\":";
    _os << y;
  

  


_os << '}';

}


  
    }
  

  


  

  
  
    

  
    namespace rpg {
  

  


Character::Character() { }

Character::Character(std::string name,rpg::Position position,float speed,rpg::inventory::Inventory* bag,std::map<std::string, rpg::inventory::Item*> equipment,std::array<double, 8> buffs)
:name_(name),position_(position),speed_(speed),bag_(std::move(bag)),equipment_(equipment),buffs_(buffs){}

Character::~Character() {

    
  
    
  
    
  
    
      delete(bag_);
    
  
    
      for (const auto& kv : equipment_) {
        delete(kv.second);
      }
      equipment_.clear();
    
  
    
  
}

void Character::Init(std::string name,rpg::Position position,float speed,rpg::inventory::Inventory* bag,std::map<std::string, rpg::inventory::Item*> equipment,std::array<double, 8> buffs) {name_ = name;position_ = position;speed_ = speed;bag_ = std::move(bag);equipment_ = equipment;buffs_ = buffs;}

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
name_.clear();position_.Reset();speed_ = 0.0f;delete(bag_);
    bag_ = nullptr;
    
      for (const auto& kv : equipment_) {
        delete(kv.second);
      }
    
    equipment_.clear();
    
    buffs_ = std::array<double, 8>{};
  

}

void Character::CopyTo(bufobjects::BufferObject& _obj) const {
Character& _dst = static_cast< Character& >(_obj);

_dst.name_ = name_;
      _dst.position_ = position_;
    _dst.speed_ = speed_;
    if(bag_ != nullptr) {
      bag_->CopyTo(*_dst.bag_);
    }
    _dst.equipment_ = std::map< std::string, rpg::inventory::Item* >(equipment_);_dst.buffs_ = std::array< double, 8>( buffs_ );

}

uint32_t Character::Size() const {
uint32_t _size = 0;


    _size += bufobjects::BufferBuilder::GetStringSize(name_);
  
    
      _size += sizeof(rpg::Position);
    
  _size += 4; // size for "f32"
  
    
      _size += 1; // +1 for "is null" byte
      if(bag_ != nullptr) {
      _size += bag_->Size();
        // this comment seems to fix a jtwig bug "[]"
        
      }
    
  _size += bufobjects::BufferBuilder::GetVarUInt32Size(static_cast< uint32_t >(equipment_.size()));

    

    
        for(const auto& _kv : equipment_) {
          
            _size += bufobjects::BufferBuilder::GetStringSize(_kv.first);
          
          if(_kv.second != nullptr) {
            _size += _kv.second->Size();
            // this comment seems to fix a jtwig bug ""
            
              
                _size += 2; // size of bufferObjectId
              
            
          }
        }
        _size += equipment_.size(); // for "is null" byte
      
    _size += kBuffsLength * 8;
    
return _size;
}

void Character::WriteTo(bufobjects::BufferBuilder& _bb) const {
uint32_t _needed = this->Size();
if(_bb.GetRemaining() < _needed) {
  _bb.GrowBuffer(_needed);
}
{
    _bb.WriteString(name_);
  
  }
{
    position_.WriteTo(_bb);
  
  }
{
    _bb.WriteFloat32(speed_);
  
  }
{
    if(bag_ == nullptr) {
        _bb.WriteUInt8(0x80);
      } else {
        _bb.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        bag_->WriteTo(_bb);
      }
  
  }
{_bb.WriteVarUInt32(static_cast< uint32_t >(equipment_.size()));
    for(const auto& _kv : equipment_) {
    _bb.WriteString(_kv.first);
    if(_kv.second == nullptr) {
        _bb.WriteUInt8(0x80);
      } else {
        _bb.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@4edde6e5, com.moybl.sidl.ast.ClassDefinition@70177ecd]"
        
          _bb.WriteUInt16(_kv.second->BufferObjectId());
        
        _kv.second->WriteTo(_bb);
      }
    }
  
  }
{for(const auto& _e : buffs_) {
    _bb.WriteFloat64(_e);
    }
  }


}

void Character::ReadFrom(bufobjects::BufferBuilder& _bb) {
{
    name_ = _bb.ReadString();
  
  }
{
    position_.ReadFrom(_bb);
  
  }
{
    speed_ = _bb.ReadFloat32();
  
  }
{
    // this comment seems to fix a jtwig bug "[]"
      
        if (_bb.ReadUInt8() == 0x81) {
          if (bag_ == nullptr) {
            bag_ = new rpg::inventory::Inventory{};
          }
          bag_->ReadFrom(_bb);
        } else {
          bag_ = nullptr;
        }
  
  }
{uint32_t _size = _bb.ReadVarUInt32();
    equipment_.clear();
    std::string _key;
    rpg::inventory::Item* _value;
    for(uint32_t i = 0; i < _size; i++) {
      _key = _bb.ReadString();
      // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@4edde6e5, com.moybl.sidl.ast.ClassDefinition@70177ecd]"
      
        if (_bb.ReadUInt8() == 0x81) {
          uint16_t id = _bb.ReadUInt16();
          switch(id) {
              case bufobjects::kRpgInventoryWeaponId:
                _value = new rpg::inventory::Weapon{};
                _value->ReadFrom(_bb);
              break;
              case bufobjects::kRpgInventoryArmorId:
                _value = new rpg::inventory::Armor{};
                _value->ReadFrom(_bb);
              break;}
        } else {
          _value = nullptr;
        }equipment_[_key] = std::move(_value);}
  
  }
{
    for(uint32_t i = 0; i < kBuffsLength; i++) {
      buffs_[i] = _bb.ReadFloat64();
    }
  }


}

void Character::WriteJsonTo(std::ostream &_os) {
  _os << '{';



uint32_t _i = 0;
_os << "\"" << "name" << "\":";
    _os << "\"" << name_ << "\"";
  

  
    _os << ',';
  

_os << "\"" << "position" << "\":";
    position_.WriteJsonTo(_os);
  

  
    _os << ',';
  

_os << "\"" << "speed" << "\":";
    _os << speed_;
  

  
    _os << ',';
  

_os << "\"" << "bag" << "\":";
    if(bag_ == nullptr) {
        _os << "null";
      } else {
        bag_->WriteJsonTo(_os);
      }
  

  
    _os << ',';
  

_os << "\"" << "equipment" << "\":";_os << '{';
    _i = 0;
    for(const auto& _kv : equipment_) {
      _os << "\"" << _kv.first << "\":";
      if(_kv.second == nullptr) {
        _os << "null";
      } else {
        _kv.second->WriteJsonTo(_os);
      }
      if(++_i < equipment_.size()) {
        _os << ',';
      }
    }
    _os << '}';
  

  
    _os << ',';
  

_os << "\"" << "buffs" << "\":";_os << '[';
    _i = 0;
    for(const auto& _e : buffs_) {
      _os << _e;
      if(++_i < buffs_.size()) {
        _os << ',';
      }
    }
    _os << ']';

  


_os << '}';

}

void Character::WriteDirectTo(bufobjects::BufferBuilder& _bb,const std::string& name,const rpg::Position& position,const float& speed,const rpg::inventory::Inventory& bag,const std::map<std::string, rpg::inventory::Item*>& equipment,const std::array<double, 8>& buffs) {
{
    _bb.WriteString(name);
  
  }{
    position.WriteTo(_bb);
  
  }{
    _bb.WriteFloat32(speed);
  
  }{
    _bb.WriteUInt8(0x81);
      // this comment seems to fix a jtwig bug "[]"
      
      bag.WriteTo(_bb);
  
  }{_bb.WriteVarUInt32(static_cast< uint32_t >(equipment.size()));
    for(const auto& _kv : equipment) {
      _bb.WriteString(_kv.first);
      if(_kv.second == nullptr) {
        _bb.WriteUInt8(0x80);
      } else {
        _bb.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@4edde6e5, com.moybl.sidl.ast.ClassDefinition@70177ecd]"
        
          _bb.WriteUInt16(_kv.second->BufferObjectId());
        
        _kv.second->WriteTo(_bb);
      }
    }
  
  }{for(const auto& _e : buffs) {
      _bb.WriteFloat64(_e);
    }
  }
};
void Character::WriteDirectIdentifiedTo(bufobjects::BufferBuilder& _bb,const std::string& name,const rpg::Position& position,const float& speed,const rpg::inventory::Inventory& bag,const std::map<std::string, rpg::inventory::Item*>& equipment,const std::array<double, 8>& buffs) {
_bb.WriteUInt16(bufobjects::kRpgCharacterId);
Character::WriteDirectTo(_bb,name,position,speed,bag,equipment,buffs);
};


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
  

  
    Character::Builder& Character::Builder::SetBag(rpg::inventory::Inventory* bag) {
      bag_ = bag;
      return *this;
    }
  

  
    Character::Builder& Character::Builder::SetEquipment(const std::map<std::string, rpg::inventory::Item*>& equipment) {
      equipment_ = equipment;
      return *this;
    }
  

  
    
    Character::Builder& Character::Builder::SetEquipment(const std::string& key, rpg::inventory::Item* value) {
          equipment_[key] = value;
          return *this;
        }
    Character::Builder& Character::Builder::SetBuffs(const std::array<double, 8>& buffs) {
      buffs_ = buffs;
      return *this;
    }
  

  
    
      Character::Builder& Character::Builder::SetBuffs(int index, const double& value) {
        buffs_[index] = value;
        return *this;
      }
    
  
Character* Character::Builder::Build() {
  return new Character{
  name_,position_,speed_,std::move(bag_),equipment_,buffs_
  };
}




  
    }