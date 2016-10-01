// Generated with https://github.com/paidgeek/bufobjects
    

#ifndef BUFOBJECTS_GEN_H
#define BUFOBJECTS_GEN_H

#include <iostream>
#include "buffer_object.h"

// forward declarations

  
    
  
    namespace gen {class BoTestSub;}
  




  
  
    

  
      namespace gen {
  

  


class BoTestSub
: public bufobjects::BufferObject{

protected:
float x_;double y_;

public:



BoTestSub();
BoTestSub(float x,double y);
void Init(float x,double y);
BoTestSub(const BoTestSub& from);
BoTestSub& operator=(const BoTestSub& from);
~BoTestSub();
uint16_t BufferObjectId() const override;
void Reset() override;
void CopyTo(bufobjects::BufferObject& obj) const override;
uint32_t Size() const override;
void WriteTo(bufobjects::BufferBuilder& bb) const override;
void ReadFrom(bufobjects::BufferBuilder& bb) override;
void WriteJsonTo(std::ostream &os);
    inline const float& GetX() const { return x_; }
    inline void SetX(const float& x) { x_ = x; }
  

  
    inline const double& GetY() const { return y_; }
    inline void SetY(const double& y) { y_ = y; }
  

  

static void WriteDirectTo(bufobjects::BufferBuilder& bb,const float& x,const double& y);
static void WriteDirectIdentifiedTo(bufobjects::BufferBuilder& bb,const float& x,const double& y);
};




  
    }
  

  


  

  
  
    

  
      namespace gen {
  

  


class BoTest
: public bufobjects::BufferObject{

protected:
std::string str_value_;std::vector<int32_t> int_array_;gen::BoTestSub* sub_ = nullptr;

public:



BoTest();
BoTest(std::string str_value,std::vector<int32_t> int_array,gen::BoTestSub* sub);
void Init(std::string str_value,std::vector<int32_t> int_array,gen::BoTestSub* sub);
BoTest(const BoTest& from);
BoTest& operator=(const BoTest& from);
~BoTest();
uint16_t BufferObjectId() const override;
void Reset() override;
void CopyTo(bufobjects::BufferObject& obj) const override;
uint32_t Size() const override;
void WriteTo(bufobjects::BufferBuilder& bb) const override;
void ReadFrom(bufobjects::BufferBuilder& bb) override;
void WriteJsonTo(std::ostream &os);
    inline const std::string& GetStrValue() const { return str_value_; }
    inline void SetStrValue(const std::string& str_value) { str_value_ = str_value; }
  

  
    inline const std::vector<int32_t>& GetIntArray() const { return int_array_; }
    inline void SetIntArray(const std::vector<int32_t>& int_array) { int_array_ = int_array; }
  

  
    
      inline const int32_t& GetIntArray(int index) const { return int_array_[index]; }
      inline void SetIntArray(int index, const int32_t& value) { int_array_[index] = value; }
    
  
    inline gen::BoTestSub* GetSub() { return sub_; }
    inline void SetSub(gen::BoTestSub* sub) { sub_ = sub; }
  

  

    inline bool HasSub() { return sub_ != nullptr; }
  
static void WriteDirectTo(bufobjects::BufferBuilder& bb,const std::string& str_value,const std::vector<int32_t>& int_array,const gen::BoTestSub& sub);
static void WriteDirectIdentifiedTo(bufobjects::BufferBuilder& bb,const std::string& str_value,const std::vector<int32_t>& int_array,const gen::BoTestSub& sub);
};




  
    }
  

  


  


#endif