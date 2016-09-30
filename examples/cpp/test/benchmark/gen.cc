// Generated with https://github.com/paidgeek/bufobjects


#include "gen.h"



  
  
    

  
    namespace gen {
  

  


BoTestSub::BoTestSub() { }

BoTestSub::BoTestSub(float x,double y)
:x_(x),y_(y){}


BoTestSub::~BoTestSub() {
  
    
  
    
  

}


void BoTestSub::Init(float x,double y) {x_ = x;y_ = y;}
BoTestSub::Ptr BoTestSub::New(float x,double y) {

  return new gen::BoTestSub{x,y};

}

BoTestSub::BoTestSub(const BoTestSub& from) {
  from.CopyTo(*this);
}

BoTestSub& BoTestSub::operator=(const BoTestSub& from) {
  from.CopyTo(*this);
  return *this;
}

uint16_t BoTestSub::BufferObjectId() const {
  return bufobjects::kGenBoTestSubId;
}

void BoTestSub::Reset() {
x_ = 0.0f;y_ = 0.0;

}

void BoTestSub::CopyTo(bufobjects::BufferObject& _obj) const {
BoTestSub& _dst = static_cast< BoTestSub& >(_obj);

_dst.x_ = x_;_dst.y_ = y_;

}

uint32_t BoTestSub::Size() const {
uint32_t _size = 0;

_size += 4; // size for "f32"
  _size += 8; // size for "f64"
  
return _size;
}

void BoTestSub::WriteTo(bufobjects::BufferBuilder& _bb) const {
uint32_t _needed = this->Size();
if(_bb.GetRemaining() < _needed) {
  _bb.GrowBuffer(_needed);
}
{
    _bb.WriteFloat32(x_);
  
  }
{
    _bb.WriteFloat64(y_);
  
  }


}

void BoTestSub::ReadFrom(bufobjects::BufferBuilder& _bb) {
{
    x_ = _bb.ReadFloat32();
  
  }
{
    y_ = _bb.ReadFloat64();
  
  }


}

void BoTestSub::WriteDirectTo(bufobjects::BufferBuilder& _bb,float x,double y) {
{
    _bb.WriteFloat32(x);
  
  }{
    _bb.WriteFloat64(y);
  
  }
};
void BoTestSub::WriteDirectIdentifiedTo(bufobjects::BufferBuilder& _bb,float x,double y) {
_bb.WriteUInt16(bufobjects::kGenBoTestSubId);
BoTestSub::WriteDirectTo(_bb,x,y);
};




  
    }
  

  


  

  
  
    

  
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

void BoTest::CopyTo(bufobjects::BufferObject& _obj) const {
BoTest& _dst = static_cast< BoTest& >(_obj);

_dst.str_value_ = str_value_;_dst.int_array_ = std::vector< int32_t >(int_array_);
    if(sub_ != nullptr) {
      sub_->CopyTo(*_dst.sub_);
    }
    

}

uint32_t BoTest::Size() const {
uint32_t _size = 0;


    _size += bufobjects::BufferBuilder::GetStringSize(str_value_);
  _size += bufobjects::BufferBuilder::GetVarUInt32Size(static_cast< uint32_t >(int_array_.size()));
    _size += int_array_.size() * 4; // size for "i32"
    
    
      _size += 1; // +1 for "is null" byte
      if(sub_ != nullptr) {
      _size += sub_->Size();
        // this comment seems to fix a jtwig bug "[]"
        
      }
    
  
return _size;
}

void BoTest::WriteTo(bufobjects::BufferBuilder& _bb) const {
uint32_t _needed = this->Size();
if(_bb.GetRemaining() < _needed) {
  _bb.GrowBuffer(_needed);
}
{
    _bb.WriteString(str_value_);
  
  }
{_bb.WriteVarUInt32(static_cast< uint32_t >(int_array_.size()));
    for(const auto& _e : int_array_) {
    _bb.WriteInt32(_e);
    }
  }
{
    if(sub_ == nullptr) {
        _bb.WriteUInt8(0x80);
      } else {
        _bb.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        sub_->WriteTo(_bb);
      }
  
  }


}

void BoTest::ReadFrom(bufobjects::BufferBuilder& _bb) {
{
    str_value_ = _bb.ReadString();
  
  }
{uint32_t _size = _bb.ReadVarUInt32();
    int_array_.clear();
    int_array_.reserve(_size);
    int32_t e;
    for(uint32_t i = 0; i < _size; i++) {
      e = _bb.ReadInt32();
      int_array_.push_back(e);
    }
  }
{
    // this comment seems to fix a jtwig bug "[]"
      
        if (_bb.ReadUInt8() == 0x81) {
          if (sub_ == nullptr) {
            
              sub_ = new gen::BoTestSub{};
            
          }
          sub_->ReadFrom(_bb);
        } else {
          sub_ = nullptr;
        }
  
  }


}

void BoTest::WriteDirectTo(bufobjects::BufferBuilder& _bb,std::string str_value,std::vector<int32_t> int_array,gen::BoTestSub* sub) {
{
    _bb.WriteString(str_value);
  
  }{_bb.WriteVarUInt32(static_cast< uint32_t >(int_array.size()));
    for(const auto& _e : int_array) {
    _bb.WriteInt32(_e);
    }
  }{
    if(sub == nullptr) {
        _bb.WriteUInt8(0x80);
      } else {
        _bb.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        sub->WriteTo(_bb);
      }
  
  }
};
void BoTest::WriteDirectIdentifiedTo(bufobjects::BufferBuilder& _bb,std::string str_value,std::vector<int32_t> int_array,gen::BoTestSub* sub) {
_bb.WriteUInt16(bufobjects::kGenBoTestId);
BoTest::WriteDirectTo(_bb,str_value,int_array,sub);
};


  BoTest::Builder::Builder() { }

    BoTest::Builder& BoTest::Builder::SetStrValue(const std::string& str_value) {
      str_value_ = str_value;
      return *this;
    }
  

  
    BoTest::Builder& BoTest::Builder::SetIntArray(const std::vector<int32_t>& int_array) {
      int_array_ = int_array;
      return *this;
    }
  

  
    
      BoTest::Builder& BoTest::Builder::SetIntArray(int index, const int32_t& value) {
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
    
  
    BoTest::Builder& BoTest::Builder::SetSub(gen::BoTestSub* sub) {
      sub_ = sub;
      return *this;
    }
  

  
BoTest::Ptr BoTest::Builder::Build() {

  return new BoTest{
  str_value_,int_array_,sub_
  };

}

void BoTest::Builder::WriteTo(bufobjects::BufferBuilder& _bb) {
  BoTest::WriteDirectTo(_bb,str_value_,int_array_,sub_);
}

void BoTest::Builder::WriteIdentifiedTo(bufobjects::BufferBuilder& _bb) {
BoTest::WriteDirectIdentifiedTo(_bb,str_value_,int_array_,sub_);
}




  
    }