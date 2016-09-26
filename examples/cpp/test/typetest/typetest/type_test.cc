// Generated with https://github.com/paidgeek/bufobjects

#include "type_test.h"



#include "../typetest/small_class.h"
// this comment seems to fix a jtwig bug "[]"



#include "../typetest/small_class.h"
// this comment seems to fix a jtwig bug "[]"



#include "../typetest/small_class.h"
// this comment seems to fix a jtwig bug "[]"



#include "../typetest/small_class.h"
// this comment seems to fix a jtwig bug "[]"



  
    namespace typetest {
  

  


TypeTest::TypeTest() { }

TypeTest::TypeTest(uint32_t u_int,int32_t s_int,std::array<int32_t, 3> int_array,typetest::SmallStruct f_struct,std::array<typetest::SmallStruct, 3> f_struct_array,std::string string,std::vector<int32_t> int_vector,std::array<std::string, 3> string_array,std::vector<std::string> string_vector,std::map<int32_t, std::string> int_string_map,typetest::SmallClass* f_class,std::array<typetest::SmallClass*, 3> f_class_array,std::vector<typetest::SmallClass*> f_class_vector,std::map<std::string, typetest::SmallClass*> f_class_map,std::vector<typetest::SmallStruct> f_struct_vector,std::map<int32_t, typetest::SmallStruct> f_struct_map)
:u_int_(u_int),s_int_(s_int),int_array_(int_array),f_struct_(f_struct),f_struct_array_(f_struct_array),string_(string),int_vector_(int_vector),string_array_(string_array),string_vector_(string_vector),int_string_map_(int_string_map),f_class_(f_class),f_class_array_(f_class_array),f_class_vector_(f_class_vector),f_class_map_(f_class_map),f_struct_vector_(f_struct_vector),f_struct_map_(f_struct_map){}

TypeTest::~TypeTest() {
  
    
  
    
  
    
  
    
  
    
  
    
  
    
  
    
  
    
  
    
  
    
      delete(f_class_);
    
  
    
      for(uint32_t i = 0; i < kFClassArrayLength; i++) {
        delete(f_class_array_[i]);
      }
    
  
    
      for(uint32_t i = 0; i < f_class_vector_.size(); i++) {
        delete(f_class_vector_[i]);
      }
      f_class_vector_.clear();
    
  
    
      for (const auto& kv : f_class_map_) {
        delete(kv.second);
      }
      f_class_map_.clear();
    
  
    
  
    
  

}

void TypeTest::Init(uint32_t u_int,int32_t s_int,std::array<int32_t, 3> int_array,typetest::SmallStruct f_struct,std::array<typetest::SmallStruct, 3> f_struct_array,std::string string,std::vector<int32_t> int_vector,std::array<std::string, 3> string_array,std::vector<std::string> string_vector,std::map<int32_t, std::string> int_string_map,typetest::SmallClass*& f_class,std::array<typetest::SmallClass*, 3> f_class_array,std::vector<typetest::SmallClass*> f_class_vector,std::map<std::string, typetest::SmallClass*> f_class_map,std::vector<typetest::SmallStruct> f_struct_vector,std::map<int32_t, typetest::SmallStruct> f_struct_map) {u_int_ = u_int;s_int_ = s_int;int_array_ = int_array;f_struct_ = f_struct;f_struct_array_ = f_struct_array;string_ = string;int_vector_ = int_vector;string_array_ = string_array;string_vector_ = string_vector;int_string_map_ = int_string_map;f_class_ = f_class;f_class_array_ = f_class_array;f_class_vector_ = f_class_vector;f_class_map_ = f_class_map;f_struct_vector_ = f_struct_vector;f_struct_map_ = f_struct_map;}
TypeTest::Ptr TypeTest::New(uint32_t u_int,int32_t s_int,std::array<int32_t, 3> int_array,typetest::SmallStruct f_struct,std::array<typetest::SmallStruct, 3> f_struct_array,std::string string,std::vector<int32_t> int_vector,std::array<std::string, 3> string_array,std::vector<std::string> string_vector,std::map<int32_t, std::string> int_string_map,typetest::SmallClass*& f_class,std::array<typetest::SmallClass*, 3> f_class_array,std::vector<typetest::SmallClass*> f_class_vector,std::map<std::string, typetest::SmallClass*> f_class_map,std::vector<typetest::SmallStruct> f_struct_vector,std::map<int32_t, typetest::SmallStruct> f_struct_map) {

  return new typetest::TypeTest{u_int,s_int,int_array,f_struct,f_struct_array,string,int_vector,string_array,string_vector,int_string_map,f_class,f_class_array,f_class_vector,f_class_map,f_struct_vector,f_struct_map};

}

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
u_int_ = 0;s_int_ = 0;int_array_ = std::array<int32_t, 3>{};f_struct_.Reset();f_struct_array_ = std::array<typetest::SmallStruct, 3>{};string_ = std::string{};int_vector_.clear();string_array_ = std::array<std::string, 3>{};string_vector_.clear();int_string_map_.clear();f_class_ = nullptr;f_class_array_ = std::array<typetest::SmallClass*, 3>{};f_class_vector_.clear();f_class_map_.clear();f_struct_vector_.clear();f_struct_map_.clear();

}

void TypeTest::CopyTo(bufobjects::BufferObject& _obj) const {
TypeTest& _dst = static_cast< TypeTest& >(_obj);

_dst.u_int_ = u_int_;_dst.s_int_ = s_int_;_dst.int_array_ = std::array< int32_t, 3>( int_array_ );
      _dst.f_struct_ = f_struct_;
    _dst.f_struct_array_ = std::array< typetest::SmallStruct, 3>( f_struct_array_ );_dst.string_ = string_;_dst.int_vector_ = std::vector< int32_t >(int_vector_);_dst.string_array_ = std::array< std::string, 3>( string_array_ );_dst.string_vector_ = std::vector< std::string >(string_vector_);_dst.int_string_map_ = std::map< int32_t, std::string >(int_string_map_);
    if(f_class_ != nullptr) {
      f_class_->CopyTo(*_dst.f_class_);
    }
    _dst.f_class_array_ = std::array< typetest::SmallClass*, 3>( f_class_array_ );_dst.f_class_vector_ = std::vector< typetest::SmallClass* >(f_class_vector_);_dst.f_class_map_ = std::map< std::string, typetest::SmallClass* >(f_class_map_);_dst.f_struct_vector_ = std::vector< typetest::SmallStruct >(f_struct_vector_);_dst.f_struct_map_ = std::map< int32_t, typetest::SmallStruct >(f_struct_map_);

}

uint32_t TypeTest::Size() const {
uint32_t _size = 0;

_size += 4; // size for "u32"
  _size += 4; // size for "i32"
  _size += kIntArrayLength * 4;
    
    
      _size += sizeof(typetest::SmallStruct);
    
  
        _size += kFStructArrayLength * sizeof(typetest::SmallStruct);
      
    
    _size += bufobjects::BufferObjectBuilder::GetStringSize(string_);
  _size += bufobjects::BufferObjectBuilder::GetVarUInt32Size(static_cast< uint32_t >(int_vector_.size()));
    _size += int_vector_.size() * 4; // size for "i32"
    
      for(const auto& _e : string_array_) {
        _size += bufobjects::BufferObjectBuilder::GetStringSize(_e);
      }
    _size += bufobjects::BufferObjectBuilder::GetVarUInt32Size(static_cast< uint32_t >(string_vector_.size()));
    
      for(const auto& _e : string_vector_) {
        _size += bufobjects::BufferObjectBuilder::GetStringSize(_e);
      }
    _size += bufobjects::BufferObjectBuilder::GetVarUInt32Size(static_cast< uint32_t >(int_string_map_.size()));

    
      _size += int_string_map_.size() * 4;
    

    
      for(const auto& _kv : int_string_map_) {
        _size += bufobjects::BufferObjectBuilder::GetStringSize(_kv.second);
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
      
    _size += bufobjects::BufferObjectBuilder::GetVarUInt32Size(static_cast< uint32_t >(f_class_vector_.size()));
    
        for(const auto& _e : f_class_vector_) {
          if(_e != nullptr) {
            _size += _e->Size();
            // this comment seems to fix a jtwig bug ""
            
          }
        }
        _size += f_class_vector_.size(); // for "is null" byte
      
    _size += bufobjects::BufferObjectBuilder::GetVarUInt32Size(static_cast< uint32_t >(f_class_map_.size()));

    

    
        for(const auto& _kv : f_class_map_) {
          
            _size += bufobjects::BufferObjectBuilder::GetStringSize(_kv.first);
          
          if(_kv.second != nullptr) {
            _size += _kv.second->Size();
            // this comment seems to fix a jtwig bug ""
            
          }
        }
        _size += f_class_map_.size(); // for "is null" byte
      
    _size += bufobjects::BufferObjectBuilder::GetVarUInt32Size(static_cast< uint32_t >(f_struct_vector_.size()));
    
        _size += f_struct_vector_.size() * sizeof(typetest::SmallStruct);
      
    _size += bufobjects::BufferObjectBuilder::GetVarUInt32Size(static_cast< uint32_t >(f_struct_map_.size()));

    
      _size += f_struct_map_.size() * 4;
    

    
        _size += f_struct_map_.size() * sizeof(typetest::SmallStruct);
      
    
return _size;
}

void TypeTest::WriteTo(bufobjects::BufferObjectBuilder& _bob) const {
uint32_t _needed = this->Size();
if(_bob.GetRemaining() < _needed) {
  _bob.GrowBuffer(_needed);
}
#if defined(BUFOBJECTS_LITTLE_ENDIAN)



  
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  _bob.WriteData((void*)(&u_int_), sizeof(u_int_) +sizeof(s_int_) +sizeof(int_array_) +sizeof(f_struct_) +sizeof(f_struct_array_) + 0);
  

  

  

  

  

  {
      _bob.WriteString(string_);
    
    }

  

  {_bob.WriteVarUInt32(static_cast< uint32_t >(int_vector_.size()));
      for(const auto& _e : int_vector_) {
        _bob.WriteInt32(_e);
      }
    }

  

  {for(const auto& _e : string_array_) {
        _bob.WriteString(_e);
      }
    }

  

  {_bob.WriteVarUInt32(static_cast< uint32_t >(string_vector_.size()));
      for(const auto& _e : string_vector_) {
        _bob.WriteString(_e);
      }
    }

  

  {_bob.WriteVarUInt32(static_cast< uint32_t >(int_string_map_.size()));
      for(const auto& _kv : int_string_map_) {
        _bob.WriteInt32(_kv.first);
        _bob.WriteString(_kv.second);
      }
    
    }

  

  {
      if(f_class_ == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        f_class_->WriteTo(_bob);
      }
    
    }

  

  {for(const auto& _e : f_class_array_) {
        if(_e == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        _e->WriteTo(_bob);
      }
      }
    }

  

  {_bob.WriteVarUInt32(static_cast< uint32_t >(f_class_vector_.size()));
      for(const auto& _e : f_class_vector_) {
        if(_e == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        _e->WriteTo(_bob);
      }
      }
    }

  

  {_bob.WriteVarUInt32(static_cast< uint32_t >(f_class_map_.size()));
      for(const auto& _kv : f_class_map_) {
        _bob.WriteString(_kv.first);
        if(_kv.second == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        _kv.second->WriteTo(_bob);
      }
      }
    
    }

  

  {_bob.WriteVarUInt32(static_cast< uint32_t >(f_struct_vector_.size()));
      for(const auto& _e : f_struct_vector_) {
        _e.WriteTo(_bob);
      }
    }

  

  {_bob.WriteVarUInt32(static_cast< uint32_t >(f_struct_map_.size()));
      for(const auto& _kv : f_struct_map_) {
        _bob.WriteInt32(_kv.first);
        _kv.second.WriteTo(_bob);
      }
    
    }

  


#else

{
    _bob.WriteUInt32(u_int_);
  
  }
{
    _bob.WriteInt32(s_int_);
  
  }
{for(const auto& _e : int_array_) {
    _bob.WriteInt32(_e);
    }
  }
{
    f_struct_.WriteTo(_bob);
  
  }
{for(const auto& _e : f_struct_array_) {
    _e.WriteTo(_bob);
    }
  }
{
    _bob.WriteString(string_);
  
  }
{_bob.WriteVarUInt32(static_cast< uint32_t >(int_vector_.size()));
    for(const auto& _e : int_vector_) {
    _bob.WriteInt32(_e);
    }
  }
{for(const auto& _e : string_array_) {
    _bob.WriteString(_e);
    }
  }
{_bob.WriteVarUInt32(static_cast< uint32_t >(string_vector_.size()));
    for(const auto& _e : string_vector_) {
    _bob.WriteString(_e);
    }
  }
{_bob.WriteVarUInt32(static_cast< uint32_t >(int_string_map_.size()));
    for(const auto& _kv : int_string_map_) {
    _bob.WriteInt32(_kv.first);
    _bob.WriteString(_kv.second);
    }
  
  }
{
    if(f_class_ == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        f_class_->WriteTo(_bob);
      }
  
  }
{for(const auto& _e : f_class_array_) {
    if(_e == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        _e->WriteTo(_bob);
      }
    }
  }
{_bob.WriteVarUInt32(static_cast< uint32_t >(f_class_vector_.size()));
    for(const auto& _e : f_class_vector_) {
    if(_e == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        _e->WriteTo(_bob);
      }
    }
  }
{_bob.WriteVarUInt32(static_cast< uint32_t >(f_class_map_.size()));
    for(const auto& _kv : f_class_map_) {
    _bob.WriteString(_kv.first);
    if(_kv.second == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        _kv.second->WriteTo(_bob);
      }
    }
  
  }
{_bob.WriteVarUInt32(static_cast< uint32_t >(f_struct_vector_.size()));
    for(const auto& _e : f_struct_vector_) {
    _e.WriteTo(_bob);
    }
  }
{_bob.WriteVarUInt32(static_cast< uint32_t >(f_struct_map_.size()));
    for(const auto& _kv : f_struct_map_) {
    _bob.WriteInt32(_kv.first);
    _kv.second.WriteTo(_bob);
    }
  
  }


#endif

}

void TypeTest::ReadFrom(bufobjects::BufferObjectBuilder& _bob) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)



  
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  _bob.ReadData((void*)(&u_int_), sizeof(u_int_) +sizeof(s_int_) +sizeof(int_array_) +sizeof(f_struct_) +sizeof(f_struct_array_) + 0);
  

  

  

  

  

  {
      string_ = _bob.ReadString();
    
    }
  

  {uint32_t _size = _bob.ReadVarUInt32();
      int_vector_.clear();
      int_vector_.reserve(_size);
      int32_t _e;
      for(uint32_t i = 0; i < _size; i++) {
        _e = _bob.ReadInt32();
        int_vector_.push_back(_e);
      }
    }
  

  {
      for(uint32_t i = 0; i < kStringArrayLength; i++) {
      string_array_[i] = _bob.ReadString();
      }
    }
  

  {uint32_t _size = _bob.ReadVarUInt32();
      string_vector_.clear();
      string_vector_.reserve(_size);
      std::string _e;
      for(uint32_t i = 0; i < _size; i++) {
        _e = _bob.ReadString();
        string_vector_.push_back(_e);
      }
    }
  

  {uint32_t _size = _bob.ReadVarUInt32();
      int_string_map_.clear();
      int32_t _key;
      std::string _value;
      for(uint32_t i = 0; i < _size; i++) {
        _key = _bob.ReadInt32();
        _value = _bob.ReadString();
        int_string_map_[_key] = _value;
      }
    
    }
  

  {
      // this comment seems to fix a jtwig bug "[]"
      
        if (_bob.ReadUInt8() == 0x81) {
          if (f_class_ == nullptr) {
            
              f_class_ = new typetest::SmallClass{};
            
          }
          f_class_->ReadFrom(_bob);
        } else {
          f_class_ = nullptr;
        }
    
    }
  

  {
      for(uint32_t i = 0; i < kFClassArrayLength; i++) {
      // this comment seems to fix a jtwig bug "[]"
      
        if (_bob.ReadUInt8() == 0x81) {
          if (f_class_array_[i] == nullptr) {
            
              f_class_array_[i] = new typetest::SmallClass{};
            
          }
          f_class_array_[i]->ReadFrom(_bob);
        } else {
          f_class_array_[i] = nullptr;
        }
      }
    }
  

  {uint32_t _size = _bob.ReadVarUInt32();
      f_class_vector_.clear();
      f_class_vector_.reserve(_size);
      typetest::SmallClass* _e;
      for(uint32_t i = 0; i < _size; i++) {
        // this comment seems to fix a jtwig bug "[]"
      
        if (_bob.ReadUInt8() == 0x81) {
          if (_e == nullptr) {
            
              _e = new typetest::SmallClass{};
            
          }
          _e->ReadFrom(_bob);
        } else {
          _e = nullptr;
        }
        f_class_vector_.push_back(_e);
      }
    }
  

  {uint32_t _size = _bob.ReadVarUInt32();
      f_class_map_.clear();
      std::string _key;
      typetest::SmallClass* _value;
      for(uint32_t i = 0; i < _size; i++) {
        _key = _bob.ReadString();
        // this comment seems to fix a jtwig bug "[]"
      
        if (_bob.ReadUInt8() == 0x81) {
          if (_value == nullptr) {
            
              _value = new typetest::SmallClass{};
            
          }
          _value->ReadFrom(_bob);
        } else {
          _value = nullptr;
        }
        f_class_map_[_key] = _value;
      }
    
    }
  

  {uint32_t _size = _bob.ReadVarUInt32();
      f_struct_vector_.clear();
      f_struct_vector_.reserve(_size);
      typetest::SmallStruct _e;
      for(uint32_t i = 0; i < _size; i++) {
        _e.ReadFrom(_bob);
        f_struct_vector_.push_back(_e);
      }
    }
  

  {uint32_t _size = _bob.ReadVarUInt32();
      f_struct_map_.clear();
      int32_t _key;
      typetest::SmallStruct _value;
      for(uint32_t i = 0; i < _size; i++) {
        _key = _bob.ReadInt32();
        _value.ReadFrom(_bob);
        f_struct_map_[_key] = _value;
      }
    
    }
  


#else

{
    u_int_ = _bob.ReadUInt32();
  
  }
{
    s_int_ = _bob.ReadInt32();
  
  }
{
    for(uint32_t i = 0; i < kIntArrayLength; i++) {
      int_array_[i] = _bob.ReadInt32();
    }
  }
{
    f_struct_.ReadFrom(_bob);
  
  }
{
    for(uint32_t i = 0; i < kFStructArrayLength; i++) {
      f_struct_array_[i].ReadFrom(_bob);
    }
  }
{
    string_ = _bob.ReadString();
  
  }
{uint32_t _size = _bob.ReadVarUInt32();
    int_vector_.clear();
    int_vector_.reserve(_size);
    int32_t e;
    for(uint32_t i = 0; i < _size; i++) {
      e = _bob.ReadInt32();
      int_vector_.push_back(e);
    }
  }
{
    for(uint32_t i = 0; i < kStringArrayLength; i++) {
      string_array_[i] = _bob.ReadString();
    }
  }
{uint32_t _size = _bob.ReadVarUInt32();
    string_vector_.clear();
    string_vector_.reserve(_size);
    std::string e;
    for(uint32_t i = 0; i < _size; i++) {
      e = _bob.ReadString();
      string_vector_.push_back(e);
    }
  }
{uint32_t _size = _bob.ReadVarUInt32();
    int_string_map_.clear();
    int32_t _key;
    std::string _value;
    for(uint32_t i = 0; i < _size; i++) {
      _key = _bob.ReadInt32();
      _value = _bob.ReadString();
      int_string_map_[_key] = _value;
    }
  
  }
{
    // this comment seems to fix a jtwig bug "[]"
      
        if (_bob.ReadUInt8() == 0x81) {
          if (f_class_ == nullptr) {
            
              f_class_ = new typetest::SmallClass{};
            
          }
          f_class_->ReadFrom(_bob);
        } else {
          f_class_ = nullptr;
        }
  
  }
{
    for(uint32_t i = 0; i < kFClassArrayLength; i++) {
      // this comment seems to fix a jtwig bug "[]"
      
        if (_bob.ReadUInt8() == 0x81) {
          if (f_class_array_[i] == nullptr) {
            
              f_class_array_[i] = new typetest::SmallClass{};
            
          }
          f_class_array_[i]->ReadFrom(_bob);
        } else {
          f_class_array_[i] = nullptr;
        }
    }
  }
{uint32_t _size = _bob.ReadVarUInt32();
    f_class_vector_.clear();
    f_class_vector_.reserve(_size);
    typetest::SmallClass* e;
    for(uint32_t i = 0; i < _size; i++) {
      // this comment seems to fix a jtwig bug "[]"
      
        if (_bob.ReadUInt8() == 0x81) {
          if (e == nullptr) {
            
              e = new typetest::SmallClass{};
            
          }
          e->ReadFrom(_bob);
        } else {
          e = nullptr;
        }
      f_class_vector_.push_back(e);
    }
  }
{uint32_t _size = _bob.ReadVarUInt32();
    f_class_map_.clear();
    std::string _key;
    typetest::SmallClass* _value;
    for(uint32_t i = 0; i < _size; i++) {
      _key = _bob.ReadString();
      // this comment seems to fix a jtwig bug "[]"
      
        if (_bob.ReadUInt8() == 0x81) {
          if (_value == nullptr) {
            
              _value = new typetest::SmallClass{};
            
          }
          _value->ReadFrom(_bob);
        } else {
          _value = nullptr;
        }
      f_class_map_[_key] = _value;
    }
  
  }
{uint32_t _size = _bob.ReadVarUInt32();
    f_struct_vector_.clear();
    f_struct_vector_.reserve(_size);
    typetest::SmallStruct e;
    for(uint32_t i = 0; i < _size; i++) {
      e.ReadFrom(_bob);
      f_struct_vector_.push_back(e);
    }
  }
{uint32_t _size = _bob.ReadVarUInt32();
    f_struct_map_.clear();
    int32_t _key;
    typetest::SmallStruct _value;
    for(uint32_t i = 0; i < _size; i++) {
      _key = _bob.ReadInt32();
      _value.ReadFrom(_bob);
      f_struct_map_[_key] = _value;
    }
  
  }


#endif

}

void TypeTest::WriteDirectTo(bufobjects::BufferObjectBuilder& _bob,uint32_t u_int,int32_t s_int,std::array<int32_t, 3> int_array,typetest::SmallStruct f_struct,std::array<typetest::SmallStruct, 3> f_struct_array,std::string string,std::vector<int32_t> int_vector,std::array<std::string, 3> string_array,std::vector<std::string> string_vector,std::map<int32_t, std::string> int_string_map,typetest::SmallClass* f_class,std::array<typetest::SmallClass*, 3> f_class_array,std::vector<typetest::SmallClass*> f_class_vector,std::map<std::string, typetest::SmallClass*> f_class_map,std::vector<typetest::SmallStruct> f_struct_vector,std::map<int32_t, typetest::SmallStruct> f_struct_map) {
{
    _bob.WriteUInt32(u_int);
  
  }{
    _bob.WriteInt32(s_int);
  
  }{for(const auto& _e : int_array) {
    _bob.WriteInt32(_e);
    }
  }{
    f_struct.WriteTo(_bob);
  
  }{for(const auto& _e : f_struct_array) {
    _e.WriteTo(_bob);
    }
  }{
    _bob.WriteString(string);
  
  }{_bob.WriteVarUInt32(static_cast< uint32_t >(int_vector.size()));
    for(const auto& _e : int_vector) {
    _bob.WriteInt32(_e);
    }
  }{for(const auto& _e : string_array) {
    _bob.WriteString(_e);
    }
  }{_bob.WriteVarUInt32(static_cast< uint32_t >(string_vector.size()));
    for(const auto& _e : string_vector) {
    _bob.WriteString(_e);
    }
  }{_bob.WriteVarUInt32(static_cast< uint32_t >(int_string_map.size()));
    for(const auto& _kv : int_string_map) {
    _bob.WriteInt32(_kv.first);
    _bob.WriteString(_kv.second);
    }
  
  }{
    if(f_class == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        f_class->WriteTo(_bob);
      }
  
  }{for(const auto& _e : f_class_array) {
    if(_e == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        _e->WriteTo(_bob);
      }
    }
  }{_bob.WriteVarUInt32(static_cast< uint32_t >(f_class_vector.size()));
    for(const auto& _e : f_class_vector) {
    if(_e == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        _e->WriteTo(_bob);
      }
    }
  }{_bob.WriteVarUInt32(static_cast< uint32_t >(f_class_map.size()));
    for(const auto& _kv : f_class_map) {
    _bob.WriteString(_kv.first);
    if(_kv.second == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        _kv.second->WriteTo(_bob);
      }
    }
  
  }{_bob.WriteVarUInt32(static_cast< uint32_t >(f_struct_vector.size()));
    for(const auto& _e : f_struct_vector) {
    _e.WriteTo(_bob);
    }
  }{_bob.WriteVarUInt32(static_cast< uint32_t >(f_struct_map.size()));
    for(const auto& _kv : f_struct_map) {
    _bob.WriteInt32(_kv.first);
    _kv.second.WriteTo(_bob);
    }
  
  }
};
void TypeTest::WriteDirectIdentifiedTo(bufobjects::BufferObjectBuilder& _bob,uint32_t u_int,int32_t s_int,std::array<int32_t, 3> int_array,typetest::SmallStruct f_struct,std::array<typetest::SmallStruct, 3> f_struct_array,std::string string,std::vector<int32_t> int_vector,std::array<std::string, 3> string_array,std::vector<std::string> string_vector,std::map<int32_t, std::string> int_string_map,typetest::SmallClass* f_class,std::array<typetest::SmallClass*, 3> f_class_array,std::vector<typetest::SmallClass*> f_class_vector,std::map<std::string, typetest::SmallClass*> f_class_map,std::vector<typetest::SmallStruct> f_struct_vector,std::map<int32_t, typetest::SmallStruct> f_struct_map) {
_bob.WriteUInt16(bufobjects::ktypetestTypeTestId);
TypeTest::WriteDirectTo(_bob,u_int,s_int,int_array,f_struct,f_struct_array,string,int_vector,string_array,string_vector,int_string_map,f_class,f_class_array,f_class_vector,f_class_map,f_struct_vector,f_struct_map);
};


  TypeTest::Builder::Builder() { }

    TypeTest::Builder& TypeTest::Builder::UInt(const uint32_t& u_int) {
      u_int_ = u_int;
      return *this;
    }
  

  
    TypeTest::Builder& TypeTest::Builder::SInt(const int32_t& s_int) {
      s_int_ = s_int;
      return *this;
    }
  

  
    TypeTest::Builder& TypeTest::Builder::IntArray(const std::array<int32_t, 3>& int_array) {
      int_array_ = int_array;
      return *this;
    }
  

  
    
      TypeTest::Builder& TypeTest::Builder::IntArray(int index, const int32_t& value) {
        int_array_[index] = value;
        return *this;
      }
    
  
    TypeTest::Builder& TypeTest::Builder::FStruct(const typetest::SmallStruct& f_struct) {
      f_struct_ = f_struct;
      return *this;
    }
  

  
    TypeTest::Builder& TypeTest::Builder::FStructArray(const std::array<typetest::SmallStruct, 3>& f_struct_array) {
      f_struct_array_ = f_struct_array;
      return *this;
    }
  

  
    
      TypeTest::Builder& TypeTest::Builder::FStructArray(int index, const typetest::SmallStruct& value) {
        f_struct_array_[index] = value;
        return *this;
      }
    
  
    TypeTest::Builder& TypeTest::Builder::String(const std::string& string) {
      string_ = string;
      return *this;
    }
  

  
    TypeTest::Builder& TypeTest::Builder::IntVector(const std::vector<int32_t>& int_vector) {
      int_vector_ = int_vector;
      return *this;
    }
  

  
    
      TypeTest::Builder& TypeTest::Builder::IntVector(int index, const int32_t& value) {
        int_vector_[index] = value;
        return *this;
      }
      TypeTest::Builder& TypeTest::Builder::AddIntVector(const int32_t& value) {
        int_vector_.push_back(value);
        return *this;
      }
      TypeTest::Builder& TypeTest::Builder::AddIntVector(const std::vector<int32_t>& values) {
        int_vector_.insert(std::end(int_vector_), std::begin(values), std::end(values));
        return *this;
      }
    
  
    TypeTest::Builder& TypeTest::Builder::StringArray(const std::array<std::string, 3>& string_array) {
      string_array_ = string_array;
      return *this;
    }
  

  
    
      TypeTest::Builder& TypeTest::Builder::StringArray(int index, const std::string& value) {
        string_array_[index] = value;
        return *this;
      }
    
  
    TypeTest::Builder& TypeTest::Builder::StringVector(const std::vector<std::string>& string_vector) {
      string_vector_ = string_vector;
      return *this;
    }
  

  
    
      TypeTest::Builder& TypeTest::Builder::StringVector(int index, const std::string& value) {
        string_vector_[index] = value;
        return *this;
      }
      TypeTest::Builder& TypeTest::Builder::AddStringVector(const std::string& value) {
        string_vector_.push_back(value);
        return *this;
      }
      TypeTest::Builder& TypeTest::Builder::AddStringVector(const std::vector<std::string>& values) {
        string_vector_.insert(std::end(string_vector_), std::begin(values), std::end(values));
        return *this;
      }
    
  
    TypeTest::Builder& TypeTest::Builder::IntStringMap(const std::map<int32_t, std::string>& int_string_map) {
      int_string_map_ = int_string_map;
      return *this;
    }
  

  
    
    TypeTest::Builder& TypeTest::Builder::IntStringMap(const int32_t& key, const std::string& value) {
      int_string_map_[key] = value;
      return *this;
    }

  
    TypeTest::Builder& TypeTest::Builder::FClass(typetest::SmallClass* f_class) {
      f_class_ = f_class;
      return *this;
    }
  

  
    TypeTest::Builder& TypeTest::Builder::FClassArray(const std::array<typetest::SmallClass*, 3>& f_class_array) {
      f_class_array_ = f_class_array;
      return *this;
    }
  

  
    
      TypeTest::Builder& TypeTest::Builder::FClassArray(int index, typetest::SmallClass* value) {
       f_class_array_[index] = value;
       return *this;
      }
    
  
    TypeTest::Builder& TypeTest::Builder::FClassVector(const std::vector<typetest::SmallClass*>& f_class_vector) {
      f_class_vector_ = f_class_vector;
      return *this;
    }
  

  
    
      TypeTest::Builder& TypeTest::Builder::FClassVector(int index, typetest::SmallClass* value) {
        f_class_vector_[index] = value;
        return *this;
      }
      TypeTest::Builder& TypeTest::Builder::AddFClassVector(typetest::SmallClass* value) {
       f_class_vector_.push_back(value);
        return *this;
      }
      TypeTest::Builder& TypeTest::Builder::AddFClassVector(std::vector<typetest::SmallClass*> values) {
        f_class_vector_.insert(std::end(f_class_vector_), std::begin(values), std::end(values));
        return *this;
      }
    
  
    TypeTest::Builder& TypeTest::Builder::FClassMap(const std::map<std::string, typetest::SmallClass*>& f_class_map) {
      f_class_map_ = f_class_map;
      return *this;
    }
  

  
    
    TypeTest::Builder& TypeTest::Builder::FClassMap(const std::string& key, typetest::SmallClass* value) {
      f_class_map_[key] = value;
      return *this;
    }

  
    TypeTest::Builder& TypeTest::Builder::FStructVector(const std::vector<typetest::SmallStruct>& f_struct_vector) {
      f_struct_vector_ = f_struct_vector;
      return *this;
    }
  

  
    
      TypeTest::Builder& TypeTest::Builder::FStructVector(int index, const typetest::SmallStruct& value) {
        f_struct_vector_[index] = value;
        return *this;
      }
      TypeTest::Builder& TypeTest::Builder::AddFStructVector(const typetest::SmallStruct& value) {
        f_struct_vector_.push_back(value);
        return *this;
      }
      TypeTest::Builder& TypeTest::Builder::AddFStructVector(const std::vector<typetest::SmallStruct>& values) {
        f_struct_vector_.insert(std::end(f_struct_vector_), std::begin(values), std::end(values));
        return *this;
      }
    
  
    TypeTest::Builder& TypeTest::Builder::FStructMap(const std::map<int32_t, typetest::SmallStruct>& f_struct_map) {
      f_struct_map_ = f_struct_map;
      return *this;
    }
  

  
    
    TypeTest::Builder& TypeTest::Builder::FStructMap(const int32_t& key, const typetest::SmallStruct& value) {
      f_struct_map_[key] = value;
      return *this;
    }

  
TypeTest::Ptr TypeTest::Builder::Build() {

  return new TypeTest{
  u_int_,s_int_,int_array_,f_struct_,f_struct_array_,string_,int_vector_,string_array_,string_vector_,int_string_map_,f_class_,f_class_array_,f_class_vector_,f_class_map_,f_struct_vector_,f_struct_map_
  };

}

void TypeTest::Builder::WriteTo(bufobjects::BufferObjectBuilder& _bob) {
  TypeTest::WriteDirectTo(_bob,u_int_,s_int_,int_array_,f_struct_,f_struct_array_,string_,int_vector_,string_array_,string_vector_,int_string_map_,f_class_,f_class_array_,f_class_vector_,f_class_map_,f_struct_vector_,f_struct_map_);
}

void TypeTest::Builder::WriteIdentifiedTo(bufobjects::BufferObjectBuilder& _bob) {
TypeTest::WriteDirectIdentifiedTo(_bob,u_int_,s_int_,int_array_,f_struct_,f_struct_array_,string_,int_vector_,string_array_,string_vector_,int_string_map_,f_class_,f_class_array_,f_class_vector_,f_class_map_,f_struct_vector_,f_struct_map_);
}




  
    }
  

  

