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

BoTest::BoTest(const BoTest& from) {
  from.CopyTo(*this);
}

BoTest& BoTest::operator=(const BoTest& from) {
  from.CopyTo(*this);
  return *this;
}

uint16_t BoTest::BufferObjectId() const {
  return bufobjects::BufferObject::kGenBoTestId;
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

void BoTest::WriteTo(bufobjects::BufferObjectBuilder& bob) const {
uint32_t needed = this->Size();
if(bob.GetRemaining() < needed) {
  bob.GrowBuffer(needed);
}
{
    bob.WriteString(str_value_);
  
  }{uint32_t size = static_cast< uint32_t >(int_array_.size());
    bob.WriteVarUInt32(size);
    for(int i = 0; i < size; i++) {
      int32_t e = int_array_[i];
      bob.WriteInt32(e);
    }
  
  }{
    if(sub_ == nullptr) {
        bob.WriteUInt8(0x80);
      } else {
        bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        sub_->WriteTo(bob);
      }
  
  }
}

void BoTest::ReadFrom(bufobjects::BufferObjectBuilder& bob) {
{
    str_value_ = bob.ReadString();
  
  }{uint32_t size = bob.ReadVarUInt32();
    int_array_.clear();
    int_array_.reserve(size);
    int32_t e;
    for(uint32_t i = 0; i < size; i++) {
      e = bob.ReadInt32();
      int_array_.push_back(e);
    }
  
  }{
    // this comment seems to fix a jtwig bug "[]"
      
        if (bob.ReadUInt8() == 0x81) {
          if (sub_ == nullptr) {
            
              sub_ = new gen::BoTestSub{};
            
          }
          sub_->ReadFrom(bob);
        } else {
          sub_ = nullptr;
        }
  
  }
}
    const std::string& BoTest::GetStrValue() const {
      return str_value_;
    }
    void BoTest::SetStrValue(const std::string& str_value) {
      str_value_ = str_value;
    }
  

  
    const std::vector<int32_t>& BoTest::GetIntArray() const {
      return int_array_;
    }
    void BoTest::SetIntArray(const std::vector<int32_t>& int_array) {
      int_array_ = int_array;
    }
  

  
    
      const int32_t& BoTest::GetIntArrayAt(int index) const {
        return int_array_[index];
      }
      void BoTest::SetIntArrayAt(int index, const int32_t& value) {
        int_array_[index] = value;
      }
    
  
    gen::BoTestSub* BoTest::GetSub() {
      return sub_;
    }
    void BoTest::SetSub(gen::BoTestSub* sub) {
      sub_ = sub;
    }
  

  
void BoTest::WriteDirectTo(bufobjects::BufferObjectBuilder& bob,std::string str_value,std::vector<int32_t> int_array,gen::BoTestSub* sub) {
{
    bob.WriteString(str_value);
  
  }{uint32_t size = static_cast< uint32_t >(int_array.size());
    bob.WriteVarUInt32(size);
    for(int i = 0; i < size; i++) {
    int32_t e = int_array[i];
    bob.WriteInt32(e);
    }
  
  }{
    if(sub == nullptr) {
        bob.WriteUInt8(0x80);
      } else {
        bob.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        sub->WriteTo(bob);
      }
  
  }
};
void BoTest::WriteDirectIdentifiedTo(bufobjects::BufferObjectBuilder& bob,std::string str_value,std::vector<int32_t> int_array,gen::BoTestSub* sub) {
bob.WriteUInt16(kGenBoTestId);
BoTest::WriteDirectTo(bob,str_value,int_array,sub);
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
  

  
    
      BoTest::Builder& BoTest::Builder::SetIntArrayAt(int index, const int32_t& value) {
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


  
    }
  

  

