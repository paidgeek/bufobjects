// Generated with https://github.com/paidgeek/bufobjects


#include "./../typetest/typetest.h"



  
  
    

  
    namespace typetest {
  

  


SmallClass::SmallClass() { }

SmallClass::SmallClass(int32_t value)
:value_(value){}

SmallClass::~SmallClass() {

    
  
}

void SmallClass::Init(int32_t value) {value_ = value;}

SmallClass::SmallClass(const SmallClass& from) {
  from.CopyTo(*this);
}

SmallClass& SmallClass::operator=(const SmallClass& from) {
  from.CopyTo(*this);
  return *this;
}

uint16_t SmallClass::BufferObjectId() const {
  return bufobjects::ktypetestSmallClassId;
}

void SmallClass::Reset() {
value_ = 0;

}

void SmallClass::CopyTo(bufobjects::BufferObject& _obj) const {
SmallClass& _dst = static_cast< SmallClass& >(_obj);

_dst.value_ = value_;

}

uint32_t SmallClass::Size() const {
uint32_t _size = 0;

_size += 4; // size for "i32"
  
return _size;
}

void SmallClass::WriteTo(bufobjects::BufferBuilder& _bb) const {
uint32_t _needed = this->Size();
if(_bb.GetRemaining() < _needed) {
  _bb.GrowBuffer(_needed);
}
{
    _bb.WriteInt32(value_);
  
  }


}

void SmallClass::ReadFrom(bufobjects::BufferBuilder& _bb) {
{
    value_ = _bb.ReadInt32();
  
  }


}

void SmallClass::WriteJsonTo(std::ostream &_os) {
  _os << '{';



uint32_t _i = 0;
_os << "\"value\":";
    _os << value_;
  

  


_os << '}';

}

void SmallClass::WriteDirectTo(bufobjects::BufferBuilder& _bb,const int32_t& value) {
{
    _bb.WriteInt32(value);
  
  }
};
void SmallClass::WriteDirectIdentifiedTo(bufobjects::BufferBuilder& _bb,const int32_t& value) {
_bb.WriteUInt16(bufobjects::ktypetestSmallClassId);
SmallClass::WriteDirectTo(_bb,value);
};




  
    }
  

  


  

  
  
    
  
    namespace typetest {
  

  


SmallStruct::SmallStruct() { }

SmallStruct::SmallStruct(int32_t value)
:value(value){}

SmallStruct::SmallStruct(const SmallStruct& from) {
  memcpy(this, &from, sizeof(SmallStruct));
}

void SmallStruct::Reset() {
value = 0;

}

void SmallStruct::WriteTo(bufobjects::BufferBuilder& _bb) const {
if(_bb.GetRemaining() < sizeof(SmallStruct)) {
  _bb.GrowBuffer(sizeof(SmallStruct));
}
#if defined(BUFOBJECTS_LITTLE_ENDIAN)

_bb.WriteData((void*) this, sizeof(SmallStruct));

#else

{_bb.WriteInt32(value);}


#endif

}

void SmallStruct::ReadFrom(bufobjects::BufferBuilder& _bb) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)

_bb.ReadData((void*) this, sizeof(SmallStruct));

#else

{value = _bb.ReadInt32();}

#endif

}

void SmallStruct::WriteJsonTo(std::ostream &_os) {
_os << '{';

uint32_t _i = 0;
_os << "\"" << "value" << "\":";
    _os << value;
  

  


_os << '}';

}


  
    }
  

  


  

  
  
    

  
    namespace typetest {
  

  


TypeTest::TypeTest() { }

TypeTest::TypeTest(uint32_t u_int,int32_t s_int,std::string string,std::array<int32_t, 3> int_array,std::vector<int32_t> int_vector,std::array<std::string, 3> string_array,std::vector<std::string> string_vector,std::map<int32_t, std::string> int_string_map,typetest::SmallClass* f_class,std::array<typetest::SmallClass*, 3> f_class_array,std::vector<typetest::SmallClass*> f_class_vector,std::map<std::string, typetest::SmallClass*> f_class_map,typetest::SmallStruct f_struct,std::array<typetest::SmallStruct, 3> f_struct_array,std::vector<typetest::SmallStruct> f_struct_vector,std::map<int32_t, typetest::SmallStruct> f_struct_map)
:u_int_(u_int),s_int_(s_int),string_(string),int_array_(int_array),int_vector_(int_vector),string_array_(string_array),string_vector_(string_vector),int_string_map_(int_string_map),f_class_(std::move(f_class)),f_class_array_(f_class_array),f_class_vector_(f_class_vector),f_class_map_(f_class_map),f_struct_(f_struct),f_struct_array_(f_struct_array),f_struct_vector_(f_struct_vector),f_struct_map_(f_struct_map){}

TypeTest::~TypeTest() {

    
  
    
  
    
  
    
  
    
  
    
  
    
  
    
  
    
      delete(f_class_);
    
  
    
      for(auto e : f_class_array_) {
        delete(e);
      }
    
  
    
      for(auto e : f_class_vector_) {
        delete(e);
      }
      f_class_vector_.clear();
    
  
    
      for (const auto& kv : f_class_map_) {
        delete(kv.second);
      }
      f_class_map_.clear();
    
  
    
  
    
  
    
  
    
  
}

void TypeTest::Init(uint32_t u_int,int32_t s_int,std::string string,std::array<int32_t, 3> int_array,std::vector<int32_t> int_vector,std::array<std::string, 3> string_array,std::vector<std::string> string_vector,std::map<int32_t, std::string> int_string_map,typetest::SmallClass* f_class,std::array<typetest::SmallClass*, 3> f_class_array,std::vector<typetest::SmallClass*> f_class_vector,std::map<std::string, typetest::SmallClass*> f_class_map,typetest::SmallStruct f_struct,std::array<typetest::SmallStruct, 3> f_struct_array,std::vector<typetest::SmallStruct> f_struct_vector,std::map<int32_t, typetest::SmallStruct> f_struct_map) {u_int_ = u_int;s_int_ = s_int;string_ = string;int_array_ = int_array;int_vector_ = int_vector;string_array_ = string_array;string_vector_ = string_vector;int_string_map_ = int_string_map;f_class_ = std::move(f_class);f_class_array_ = f_class_array;f_class_vector_ = f_class_vector;f_class_map_ = f_class_map;f_struct_ = f_struct;f_struct_array_ = f_struct_array;f_struct_vector_ = f_struct_vector;f_struct_map_ = f_struct_map;}

TypeTest::TypeTest(const TypeTest& from) {
  from.CopyTo(*this);
}

TypeTest& TypeTest::operator=(const TypeTest& from) {
  from.CopyTo(*this);
  return *this;
}

uint16_t TypeTest::BufferObjectId() const {
  return bufobjects::ktypetestTypeTestId;
}

void TypeTest::Reset() {
u_int_ = 0;s_int_ = 0;string_.clear();
    
    int_array_ = std::array<int32_t, 3>{};
  
    
    int_vector_.clear();
  
    
    string_array_ = std::array<std::string, 3>{};
  
    
    string_vector_.clear();
  
    
    int_string_map_.clear();delete(f_class_);
    f_class_ = nullptr;
    
      for(auto e : f_class_array_) {
        delete(e);
      }
    
    f_class_array_ = std::array<typetest::SmallClass*, 3>{};
  
    
      for(auto e : f_class_vector_) {
        delete(e);
      }
    
    f_class_vector_.clear();
  
    
      for (const auto& kv : f_class_map_) {
        delete(kv.second);
      }
    
    f_class_map_.clear();f_struct_.Reset();
    
    f_struct_array_ = std::array<typetest::SmallStruct, 3>{};
  
    
    f_struct_vector_.clear();
  
    
    f_struct_map_.clear();

}

void TypeTest::CopyTo(bufobjects::BufferObject& _obj) const {
TypeTest& _dst = static_cast< TypeTest& >(_obj);

_dst.u_int_ = u_int_;_dst.s_int_ = s_int_;_dst.string_ = string_;_dst.int_array_ = std::array< int32_t, 3>( int_array_ );_dst.int_vector_ = std::vector< int32_t >(int_vector_);_dst.string_array_ = std::array< std::string, 3>( string_array_ );_dst.string_vector_ = std::vector< std::string >(string_vector_);_dst.int_string_map_ = std::map< int32_t, std::string >(int_string_map_);
    if(f_class_ != nullptr) {
      f_class_->CopyTo(*_dst.f_class_);
    }
    _dst.f_class_array_ = std::array< typetest::SmallClass*, 3>( f_class_array_ );_dst.f_class_vector_ = std::vector< typetest::SmallClass* >(f_class_vector_);_dst.f_class_map_ = std::map< std::string, typetest::SmallClass* >(f_class_map_);
      _dst.f_struct_ = f_struct_;
    _dst.f_struct_array_ = std::array< typetest::SmallStruct, 3>( f_struct_array_ );_dst.f_struct_vector_ = std::vector< typetest::SmallStruct >(f_struct_vector_);_dst.f_struct_map_ = std::map< int32_t, typetest::SmallStruct >(f_struct_map_);

}

uint32_t TypeTest::Size() const {
uint32_t _size = 0;

_size += 4; // size for "u32"
  _size += 4; // size for "i32"
  
    _size += bufobjects::BufferBuilder::GetStringSize(string_);
  _size += kIntArrayLength * 4;
    _size += bufobjects::BufferBuilder::GetVarUInt32Size(static_cast< uint32_t >(int_vector_.size()));
    _size += int_vector_.size() * 4; // size for "i32"
    
      for(const auto& _e : string_array_) {
        _size += bufobjects::BufferBuilder::GetStringSize(_e);
      }
    _size += bufobjects::BufferBuilder::GetVarUInt32Size(static_cast< uint32_t >(string_vector_.size()));
    
      for(const auto& _e : string_vector_) {
        _size += bufobjects::BufferBuilder::GetStringSize(_e);
      }
    _size += bufobjects::BufferBuilder::GetVarUInt32Size(static_cast< uint32_t >(int_string_map_.size()));

    
      _size += int_string_map_.size() * 4;
    

    
      for(const auto& _kv : int_string_map_) {
        _size += bufobjects::BufferBuilder::GetStringSize(_kv.second);
      }
    
    
      _size += 1; // +1 for "is null" byte
      if(f_class_ != nullptr) {
      _size += f_class_->Size();
        // this comment seems to fix a jtwig bug "[]"
        
      }
    
  
        for(const auto& _e : f_class_array_) {
          if(_e != nullptr) {
            _size += _e->Size();
            // this comment seems to fix a jtwig bug ""
            
          }
        }
        _size += kFClassArrayLength; // size for "is null" byte
      
    _size += bufobjects::BufferBuilder::GetVarUInt32Size(static_cast< uint32_t >(f_class_vector_.size()));
    
        for(const auto& _e : f_class_vector_) {
          if(_e != nullptr) {
            _size += _e->Size();
            // this comment seems to fix a jtwig bug ""
            
          }
        }
        _size += f_class_vector_.size(); // for "is null" byte
      
    _size += bufobjects::BufferBuilder::GetVarUInt32Size(static_cast< uint32_t >(f_class_map_.size()));

    

    
        for(const auto& _kv : f_class_map_) {
          
            _size += bufobjects::BufferBuilder::GetStringSize(_kv.first);
          
          if(_kv.second != nullptr) {
            _size += _kv.second->Size();
            // this comment seems to fix a jtwig bug ""
            
          }
        }
        _size += f_class_map_.size(); // for "is null" byte
      
    
    
      _size += sizeof(typetest::SmallStruct);
    
  
        _size += kFStructArrayLength * sizeof(typetest::SmallStruct);
      
    _size += bufobjects::BufferBuilder::GetVarUInt32Size(static_cast< uint32_t >(f_struct_vector_.size()));
    
        _size += f_struct_vector_.size() * sizeof(typetest::SmallStruct);
      
    _size += bufobjects::BufferBuilder::GetVarUInt32Size(static_cast< uint32_t >(f_struct_map_.size()));

    
      _size += f_struct_map_.size() * 4;
    

    
        _size += f_struct_map_.size() * sizeof(typetest::SmallStruct);
      
    
return _size;
}

void TypeTest::WriteTo(bufobjects::BufferBuilder& _bb) const {
uint32_t _needed = this->Size();
if(_bb.GetRemaining() < _needed) {
  _bb.GrowBuffer(_needed);
}
{
    _bb.WriteUInt32(u_int_);
  
  }
{
    _bb.WriteInt32(s_int_);
  
  }
{
    _bb.WriteString(string_);
  
  }
{for(const auto& _e : int_array_) {
    _bb.WriteInt32(_e);
    }
  }
{_bb.WriteVarUInt32(static_cast< uint32_t >(int_vector_.size()));
    for(const auto& _e : int_vector_) {
    _bb.WriteInt32(_e);
    }
  }
{for(const auto& _e : string_array_) {
    _bb.WriteString(_e);
    }
  }
{_bb.WriteVarUInt32(static_cast< uint32_t >(string_vector_.size()));
    for(const auto& _e : string_vector_) {
    _bb.WriteString(_e);
    }
  }
{_bb.WriteVarUInt32(static_cast< uint32_t >(int_string_map_.size()));
    for(const auto& _kv : int_string_map_) {
    _bb.WriteInt32(_kv.first);
    _bb.WriteString(_kv.second);
    }
  
  }
{
    if(f_class_ == nullptr) {
        _bb.WriteUInt8(0x80);
      } else {
        _bb.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        f_class_->WriteTo(_bb);
      }
  
  }
{for(const auto& _e : f_class_array_) {
    if(_e == nullptr) {
        _bb.WriteUInt8(0x80);
      } else {
        _bb.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        _e->WriteTo(_bb);
      }
    }
  }
{_bb.WriteVarUInt32(static_cast< uint32_t >(f_class_vector_.size()));
    for(const auto& _e : f_class_vector_) {
    if(_e == nullptr) {
        _bb.WriteUInt8(0x80);
      } else {
        _bb.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        _e->WriteTo(_bb);
      }
    }
  }
{_bb.WriteVarUInt32(static_cast< uint32_t >(f_class_map_.size()));
    for(const auto& _kv : f_class_map_) {
    _bb.WriteString(_kv.first);
    if(_kv.second == nullptr) {
        _bb.WriteUInt8(0x80);
      } else {
        _bb.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        _kv.second->WriteTo(_bb);
      }
    }
  
  }
{
    f_struct_.WriteTo(_bb);
  
  }
{for(const auto& _e : f_struct_array_) {
    _e.WriteTo(_bb);
    }
  }
{_bb.WriteVarUInt32(static_cast< uint32_t >(f_struct_vector_.size()));
    for(const auto& _e : f_struct_vector_) {
    _e.WriteTo(_bb);
    }
  }
{_bb.WriteVarUInt32(static_cast< uint32_t >(f_struct_map_.size()));
    for(const auto& _kv : f_struct_map_) {
    _bb.WriteInt32(_kv.first);
    _kv.second.WriteTo(_bb);
    }
  
  }


}

void TypeTest::ReadFrom(bufobjects::BufferBuilder& _bb) {
{
    u_int_ = _bb.ReadUInt32();
  
  }
{
    s_int_ = _bb.ReadInt32();
  
  }
{
    string_ = _bb.ReadString();
  
  }
{
    for(uint32_t i = 0; i < kIntArrayLength; i++) {
      int_array_[i] = _bb.ReadInt32();
    }
  }
{uint32_t _size = _bb.ReadVarUInt32();
    int_vector_.clear();
    int_vector_.reserve(_size);
    int32_t e;
    for(uint32_t i = 0; i < _size; i++) {
      e = _bb.ReadInt32();
      int_vector_.push_back(e);
    }
  }
{
    for(uint32_t i = 0; i < kStringArrayLength; i++) {
      string_array_[i] = _bb.ReadString();
    }
  }
{uint32_t _size = _bb.ReadVarUInt32();
    string_vector_.clear();
    string_vector_.reserve(_size);
    std::string e;
    for(uint32_t i = 0; i < _size; i++) {
      e = _bb.ReadString();
      string_vector_.push_back(e);
    }
  }
{uint32_t _size = _bb.ReadVarUInt32();
    int_string_map_.clear();
    int32_t _key;
    std::string _value;
    for(uint32_t i = 0; i < _size; i++) {
      _key = _bb.ReadInt32();
      _value = _bb.ReadString();int_string_map_[_key] = _value;}
  
  }
{
    // this comment seems to fix a jtwig bug "[]"
      
        if (_bb.ReadUInt8() == 0x81) {
          if (f_class_ == nullptr) {
            f_class_ = new typetest::SmallClass{};
          }
          f_class_->ReadFrom(_bb);
        } else {
          f_class_ = nullptr;
        }
  
  }
{
    for(uint32_t i = 0; i < kFClassArrayLength; i++) {
      // this comment seems to fix a jtwig bug "[]"
      
        if (_bb.ReadUInt8() == 0x81) {
          if (f_class_array_[i] == nullptr) {
            f_class_array_[i] = new typetest::SmallClass{};
          }
          f_class_array_[i]->ReadFrom(_bb);
        } else {
          f_class_array_[i] = nullptr;
        }
    }
  }
{uint32_t _size = _bb.ReadVarUInt32();
    f_class_vector_.clear();
    f_class_vector_.reserve(_size);
    typetest::SmallClass* e;
    for(uint32_t i = 0; i < _size; i++) {
      // this comment seems to fix a jtwig bug "[]"
      
        if (_bb.ReadUInt8() == 0x81) {
          if (e == nullptr) {
            e = new typetest::SmallClass{};
          }
          e->ReadFrom(_bb);
        } else {
          e = nullptr;
        }
      f_class_vector_.push_back(e);
    }
  }
{uint32_t _size = _bb.ReadVarUInt32();
    f_class_map_.clear();
    std::string _key;
    typetest::SmallClass* _value;
    for(uint32_t i = 0; i < _size; i++) {
      _key = _bb.ReadString();
      // this comment seems to fix a jtwig bug "[]"
      
        if (_bb.ReadUInt8() == 0x81) {
          if (_value == nullptr) {
            _value = new typetest::SmallClass{};
          }
          _value->ReadFrom(_bb);
        } else {
          _value = nullptr;
        }f_class_map_[_key] = std::move(_value);}
  
  }
{
    f_struct_.ReadFrom(_bb);
  
  }
{
    for(uint32_t i = 0; i < kFStructArrayLength; i++) {
      f_struct_array_[i].ReadFrom(_bb);
    }
  }
{uint32_t _size = _bb.ReadVarUInt32();
    f_struct_vector_.clear();
    f_struct_vector_.reserve(_size);
    typetest::SmallStruct e;
    for(uint32_t i = 0; i < _size; i++) {
      e.ReadFrom(_bb);
      f_struct_vector_.push_back(e);
    }
  }
{uint32_t _size = _bb.ReadVarUInt32();
    f_struct_map_.clear();
    int32_t _key;
    typetest::SmallStruct _value;
    for(uint32_t i = 0; i < _size; i++) {
      _key = _bb.ReadInt32();
      _value.ReadFrom(_bb);f_struct_map_[_key] = _value;}
  
  }


}

void TypeTest::WriteJsonTo(std::ostream &_os) {
  _os << '{';



uint32_t _i = 0;
_os << "\"u_int\":";
    _os << u_int_;
  

  
    _os << ',';
  

_os << "\"s_int\":";
    _os << s_int_;
  

  
    _os << ',';
  

_os << "\"string\":";
    _os << "\"" << string_ << "\"";
  

  
    _os << ',';
  

_os << "\"int_array\":";_os << '[';
    _i = 0;
    for(const auto& _e : int_array_) {
      _os << _e;
      if(++_i < int_array_.size()) {
        _os << ',';
      }
    }
    _os << ']';

  
    _os << ',';
  

_os << "\"int_vector\":";_os << '[';
    _i = 0;
    for(const auto& _e : int_vector_) {
      _os << _e;
      if(++_i < int_vector_.size()) {
        _os << ',';
      }
    }
    _os << ']';

  
    _os << ',';
  

_os << "\"string_array\":";_os << '[';
    _i = 0;
    for(const auto& _e : string_array_) {
      _os << "\"" << _e << "\"";
      if(++_i < string_array_.size()) {
        _os << ',';
      }
    }
    _os << ']';

  
    _os << ',';
  

_os << "\"string_vector\":";_os << '[';
    _i = 0;
    for(const auto& _e : string_vector_) {
      _os << "\"" << _e << "\"";
      if(++_i < string_vector_.size()) {
        _os << ',';
      }
    }
    _os << ']';

  
    _os << ',';
  

_os << "\"int_string_map\":";_os << '{';
    _i = 0;
    for(const auto& _kv : int_string_map_) {
      _os << "\"" << _kv.first << "\":";
      _os << "\"" << _kv.second << "\"";
      if(++_i < int_string_map_.size()) {
        _os << ',';
      }
    }
    _os << '}';
  

  
    _os << ',';
  

_os << "\"f_class\":";
    if(f_class_ == nullptr) {
        _os << "null";
      } else {
        f_class_->WriteJsonTo(_os);
      }
  

  
    _os << ',';
  

_os << "\"f_class_array\":";_os << '[';
    _i = 0;
    for(const auto& _e : f_class_array_) {
      if(_e == nullptr) {
        _os << "null";
      } else {
        _e->WriteJsonTo(_os);
      }
      if(++_i < f_class_array_.size()) {
        _os << ',';
      }
    }
    _os << ']';

  
    _os << ',';
  

_os << "\"f_class_vector\":";_os << '[';
    _i = 0;
    for(const auto& _e : f_class_vector_) {
      if(_e == nullptr) {
        _os << "null";
      } else {
        _e->WriteJsonTo(_os);
      }
      if(++_i < f_class_vector_.size()) {
        _os << ',';
      }
    }
    _os << ']';

  
    _os << ',';
  

_os << "\"f_class_map\":";_os << '{';
    _i = 0;
    for(const auto& _kv : f_class_map_) {
      _os << "\"" << _kv.first << "\":";
      if(_kv.second == nullptr) {
        _os << "null";
      } else {
        _kv.second->WriteJsonTo(_os);
      }
      if(++_i < f_class_map_.size()) {
        _os << ',';
      }
    }
    _os << '}';
  

  
    _os << ',';
  

_os << "\"f_struct\":";
    f_struct_.WriteJsonTo(_os);
  

  
    _os << ',';
  

_os << "\"f_struct_array\":";_os << '[';
    _i = 0;
    for(const auto& _e : f_struct_array_) {
      _e.WriteJsonTo(_os);
      if(++_i < f_struct_array_.size()) {
        _os << ',';
      }
    }
    _os << ']';

  
    _os << ',';
  

_os << "\"f_struct_vector\":";_os << '[';
    _i = 0;
    for(const auto& _e : f_struct_vector_) {
      _e.WriteJsonTo(_os);
      if(++_i < f_struct_vector_.size()) {
        _os << ',';
      }
    }
    _os << ']';

  
    _os << ',';
  

_os << "\"f_struct_map\":";_os << '{';
    _i = 0;
    for(const auto& _kv : f_struct_map_) {
      _os << "\"" << _kv.first << "\":";
      _kv.second.WriteJsonTo(_os);
      if(++_i < f_struct_map_.size()) {
        _os << ',';
      }
    }
    _os << '}';
  

  


_os << '}';

}

void TypeTest::WriteDirectTo(bufobjects::BufferBuilder& _bb,const uint32_t& u_int,const int32_t& s_int,const std::string& string,const std::array<int32_t, 3>& int_array,const std::vector<int32_t>& int_vector,const std::array<std::string, 3>& string_array,const std::vector<std::string>& string_vector,const std::map<int32_t, std::string>& int_string_map,const typetest::SmallClass& f_class,const std::array<typetest::SmallClass*, 3>& f_class_array,const std::vector<typetest::SmallClass*>& f_class_vector,const std::map<std::string, typetest::SmallClass*>& f_class_map,const typetest::SmallStruct& f_struct,const std::array<typetest::SmallStruct, 3>& f_struct_array,const std::vector<typetest::SmallStruct>& f_struct_vector,const std::map<int32_t, typetest::SmallStruct>& f_struct_map) {
{
    _bb.WriteUInt32(u_int);
  
  }{
    _bb.WriteInt32(s_int);
  
  }{
    _bb.WriteString(string);
  
  }{for(const auto& _e : int_array) {
      _bb.WriteInt32(_e);
    }
  }{_bb.WriteVarUInt32(static_cast< uint32_t >(int_vector.size()));
    for(const auto& _e : int_vector) {
      _bb.WriteInt32(_e);
    }
  }{for(const auto& _e : string_array) {
      _bb.WriteString(_e);
    }
  }{_bb.WriteVarUInt32(static_cast< uint32_t >(string_vector.size()));
    for(const auto& _e : string_vector) {
      _bb.WriteString(_e);
    }
  }{_bb.WriteVarUInt32(static_cast< uint32_t >(int_string_map.size()));
    for(const auto& _kv : int_string_map) {
      _bb.WriteInt32(_kv.first);
      _bb.WriteString(_kv.second);
    }
  
  }{
    _bb.WriteUInt8(0x81);
      // this comment seems to fix a jtwig bug "[]"
      
      f_class.WriteTo(_bb);
  
  }{for(const auto& _e : f_class_array) {
      if(_e == nullptr) {
        _bb.WriteUInt8(0x80);
      } else {
        _bb.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        _e->WriteTo(_bb);
      }
    }
  }{_bb.WriteVarUInt32(static_cast< uint32_t >(f_class_vector.size()));
    for(const auto& _e : f_class_vector) {
      if(_e == nullptr) {
        _bb.WriteUInt8(0x80);
      } else {
        _bb.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        _e->WriteTo(_bb);
      }
    }
  }{_bb.WriteVarUInt32(static_cast< uint32_t >(f_class_map.size()));
    for(const auto& _kv : f_class_map) {
      _bb.WriteString(_kv.first);
      if(_kv.second == nullptr) {
        _bb.WriteUInt8(0x80);
      } else {
        _bb.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        _kv.second->WriteTo(_bb);
      }
    }
  
  }{
    f_struct.WriteTo(_bb);
  
  }{for(const auto& _e : f_struct_array) {
      _e.WriteTo(_bb);
    }
  }{_bb.WriteVarUInt32(static_cast< uint32_t >(f_struct_vector.size()));
    for(const auto& _e : f_struct_vector) {
      _e.WriteTo(_bb);
    }
  }{_bb.WriteVarUInt32(static_cast< uint32_t >(f_struct_map.size()));
    for(const auto& _kv : f_struct_map) {
      _bb.WriteInt32(_kv.first);
      _kv.second.WriteTo(_bb);
    }
  
  }
};
void TypeTest::WriteDirectIdentifiedTo(bufobjects::BufferBuilder& _bb,const uint32_t& u_int,const int32_t& s_int,const std::string& string,const std::array<int32_t, 3>& int_array,const std::vector<int32_t>& int_vector,const std::array<std::string, 3>& string_array,const std::vector<std::string>& string_vector,const std::map<int32_t, std::string>& int_string_map,const typetest::SmallClass& f_class,const std::array<typetest::SmallClass*, 3>& f_class_array,const std::vector<typetest::SmallClass*>& f_class_vector,const std::map<std::string, typetest::SmallClass*>& f_class_map,const typetest::SmallStruct& f_struct,const std::array<typetest::SmallStruct, 3>& f_struct_array,const std::vector<typetest::SmallStruct>& f_struct_vector,const std::map<int32_t, typetest::SmallStruct>& f_struct_map) {
_bb.WriteUInt16(bufobjects::ktypetestTypeTestId);
TypeTest::WriteDirectTo(_bb,u_int,s_int,string,int_array,int_vector,string_array,string_vector,int_string_map,f_class,f_class_array,f_class_vector,f_class_map,f_struct,f_struct_array,f_struct_vector,f_struct_map);
};




  
    }