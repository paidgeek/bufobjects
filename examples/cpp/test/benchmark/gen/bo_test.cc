// Generated with https://github.com/paidgeek/bufobjects

#include "bo_test.h"



#include "../gen/bo_test_sub.h"
// this comment seems to fix a jtwig bug "[]"



  
    namespace gen {
  

  


BoTest::BoTest() { }

BoTest::BoTest(std::string str_value,std::vector<int32_t> int_array,gen::BoTestSub* sub)
:str_value_(str_value),int_array_(int_array),sub_(sub){}

BoTest::~BoTest() {
  
    
  
    
  
    
      delete(sub_);
    
  

}

void BoTest::Init(std::string str_value,std::vector<int32_t> int_array,gen::BoTestSub*& sub) {str_value_ = str_value;int_array_ = int_array;sub_ = sub;}
BoTest::Ptr BoTest::New(std::string str_value,std::vector<int32_t> int_array,gen::BoTestSub*& sub) {

  return new gen::BoTest{str_value,int_array,sub};

}

BoTest::BoTest(const BoTest& from) {
  from.CopyTo(*this);
}

BoTest& BoTest::operator=(const BoTest& from) {
  from.CopyTo(*this);
  return *this;
}

uint16_t BoTest::BufferObjectId() const {
  return bufobjects::kGenBoTestId;
}

void BoTest::Reset() {
str_value_ = std::string{};int_array_.clear();sub_ = nullptr;

}

void BoTest::CopyTo(bufobjects::BufferObject& obj) const {
BoTest& dst = static_cast< BoTest& >(obj);

dst.str_value_ = str_value_;dst.int_array_ = std::vector< int32_t >(int_array_);
    if(sub_ != nullptr) {
      sub_->CopyTo(*dst.sub_);
    }
    
}

uint32_t BoTest::Size() const {
uint32_t size = 0;


    size += bufobjects::BufferObjectBuilder::GetStringSize(str_value_);
  size += bufobjects::BufferObjectBuilder::GetVarUInt32Size(static_cast< uint32_t >(int_array_.size()));
    size += int_array_.size() * 4; // size for "i32"
    
    
      size += 1; // +1 for "is null" byte
      if(sub_ != nullptr) {
        size += sub_->Size();
        // this comment seems to fix a jtwig bug "[]"
        
      }
    
  
return size;
}

void BoTest::WriteTo(bufobjects::BufferObjectBuilder& _bob) const {
uint32_t needed = this->Size();
if(_bob.GetRemaining() < needed) {
  _bob.GrowBuffer(needed);
}
#if defined(BUFOBJECTS_LITTLE_ENDIAN)


  {
      _bob.WriteString(str_value_);
    
    }

  

  {uint32_t _size = static_cast< uint32_t >(int_array_.size());
      _bob.WriteVarUInt32(_size);
      for(int i = 0; i < _size; i++) {
      int32_t e = int_array_[i];
      _bob.WriteInt32(e);
      }
    
    }

  

  {
      if(sub_ == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        sub_->WriteTo(_bob);
      }
    
    }

  


#else

{
    _bob.WriteString(str_value_);
  
  }
{uint32_t _size = static_cast< uint32_t >(int_array_.size());
    _bob.WriteVarUInt32(_size);
    for(int i = 0; i < _size; i++) {
    int32_t e = int_array_[i];
    _bob.WriteInt32(e);
    }
  
  }
{
    if(sub_ == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        sub_->WriteTo(_bob);
      }
  
  }


#endif

}

void BoTest::ReadFrom(bufobjects::BufferObjectBuilder& _bob) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)


  {
      str_value_ = _bob.ReadString();
    
    }
  

  {uint32_t size = _bob.ReadVarUInt32();
      int_array_.clear();
      int_array_.reserve(size);
      int32_t e;
      for(uint32_t i = 0; i < size; i++) {
      e = _bob.ReadInt32();
      int_array_.push_back(e);
      }
    
    }
  

  {
      // this comment seems to fix a jtwig bug "[]"
      
        if (_bob.ReadUInt8() == 0x81) {
          if (sub_ == nullptr) {
            
              sub_ = new gen::BoTestSub{};
            
          }
          sub_->ReadFrom(_bob);
        } else {
          sub_ = nullptr;
        }
    
    }
  


#else

{
    str_value_ = _bob.ReadString();
  
  }
{uint32_t size = _bob.ReadVarUInt32();
    int_array_.clear();
    int_array_.reserve(size);
    int32_t e;
    for(uint32_t i = 0; i < size; i++) {
      e = _bob.ReadInt32();
      int_array_.push_back(e);
    }
  
  }
{
    // this comment seems to fix a jtwig bug "[]"
      
        if (_bob.ReadUInt8() == 0x81) {
          if (sub_ == nullptr) {
            
              sub_ = new gen::BoTestSub{};
            
          }
          sub_->ReadFrom(_bob);
        } else {
          sub_ = nullptr;
        }
  
  }


#endif

}

void BoTest::WriteDirectTo(bufobjects::BufferObjectBuilder& _bob,std::string str_value,std::vector<int32_t> int_array,gen::BoTestSub* sub) {
{
    _bob.WriteString(str_value);
  
  }{uint32_t _size = static_cast< uint32_t >(int_array.size());
    _bob.WriteVarUInt32(_size);
    for(int i = 0; i < _size; i++) {
    int32_t e = int_array[i];
    _bob.WriteInt32(e);
    }
  
  }{
    if(sub == nullptr) {
        _bob.WriteUInt8(0x80);
      } else {
        _bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        sub->WriteTo(_bob);
      }
  
  }
};
void BoTest::WriteDirectIdentifiedTo(bufobjects::BufferObjectBuilder& _bob,std::string str_value,std::vector<int32_t> int_array,gen::BoTestSub* sub) {
_bob.WriteUInt16(bufobjects::kGenBoTestId);
BoTest::WriteDirectTo(_bob,str_value,int_array,sub);
};


  BoTest::Builder::Builder() { }

    BoTest::Builder& BoTest::Builder::StrValue(const std::string& str_value) {
      str_value_ = str_value;
      return *this;
    }
  

  
    BoTest::Builder& BoTest::Builder::IntArray(const std::vector<int32_t>& int_array) {
      int_array_ = int_array;
      return *this;
    }
  

  
    
      BoTest::Builder& BoTest::Builder::IntArray(int index, const int32_t& value) {
        int_array_[index] = value;
        return *this;
      }
      BoTest::Builder& BoTest::Builder::AddIntArray(const int32_t& value) {
        int_array_.push_back(value);
        return *this;
      }
      BoTest::Builder& BoTest::Builder::AddIntArray(const std::vector<int32_t>& values) {
        int_array_.insert(std::end(int_array_), std::begin(values), std::end(values));
        return *this;
      }
    
  
    BoTest::Builder& BoTest::Builder::Sub(gen::BoTestSub* sub) {
      sub_ = sub;
      return *this;
    }
  

  
BoTest::Ptr BoTest::Builder::Build() {

  return new BoTest{
  str_value_,int_array_,sub_
  };

}

void BoTest::Builder::WriteTo(bufobjects::BufferObjectBuilder& _bob) {
  BoTest::WriteDirectTo(_bob,str_value_,int_array_,sub_);
}

void BoTest::Builder::WriteIdentifiedTo(bufobjects::BufferObjectBuilder& _bob) {
BoTest::WriteDirectIdentifiedTo(_bob,str_value_,int_array_,sub_);
}




  
    }
  

  

