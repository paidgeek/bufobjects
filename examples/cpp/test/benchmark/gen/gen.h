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

  float x_;
  

  double y_;
  


public:

  typedef std::shared_ptr<gen::BoTestSub> Ptr;




BoTestSub();
BoTestSub(float x,double y);

void Init(float x,double y);
static Ptr New(float x,double y);
BoTestSub(const BoTestSub& from);
BoTestSub& operator=(const BoTestSub& from);
explicit operator bufobjects::BufferObject::Ptr() {
  return static_cast< bufobjects::BufferObject::Ptr >(this);
}
uint16_t BufferObjectId() const;
void Reset();
void CopyTo(bufobjects::BufferObject& obj) const;
uint32_t Size() const;
void WriteTo(bufobjects::BufferBuilder& bb) const;
void ReadFrom(bufobjects::BufferBuilder& bb);
void WriteJsonTo(std::ostream &os);
    inline const float& GetX() const { return x_; }
    inline void SetX(const float& x) { x_ = x; }
  

  
    inline const double& GetY() const { return y_; }
    inline void SetY(const double& y) { y_ = y; }
  

  
static void WriteDirectTo(bufobjects::BufferBuilder& bb,float x,double y);
static void WriteDirectIdentifiedTo(bufobjects::BufferBuilder& bb,float x,double y);
};




  
    }
  

  


  

  
  
    

  
      namespace gen {
  

  


class BoTest
: public bufobjects::BufferObject{

protected:

  std::string str_value_;
  

  std::vector<int32_t> int_array_;
  

  std::shared_ptr<gen::BoTestSub> sub_ = nullptr;
  


public:

  typedef std::shared_ptr<gen::BoTest> Ptr;




BoTest();
BoTest(std::string str_value,std::vector<int32_t> int_array,std::shared_ptr<gen::BoTestSub> sub);

void Init(std::string str_value,std::vector<int32_t> int_array,std::shared_ptr<gen::BoTestSub>& sub);
static Ptr New(std::string str_value,std::vector<int32_t> int_array,std::shared_ptr<gen::BoTestSub>& sub);
BoTest(const BoTest& from);
BoTest& operator=(const BoTest& from);
explicit operator bufobjects::BufferObject::Ptr() {
  return static_cast< bufobjects::BufferObject::Ptr >(this);
}
uint16_t BufferObjectId() const;
void Reset();
void CopyTo(bufobjects::BufferObject& obj) const;
uint32_t Size() const;
void WriteTo(bufobjects::BufferBuilder& bb) const;
void ReadFrom(bufobjects::BufferBuilder& bb);
void WriteJsonTo(std::ostream &os);
    inline const std::string& GetStrValue() const { return str_value_; }
    inline void SetStrValue(const std::string& str_value) { str_value_ = str_value; }
  

  
    inline const std::vector<int32_t>& GetIntArray() const { return int_array_; }
    inline void SetIntArray(const std::vector<int32_t>& int_array) { int_array_ = int_array; }
  

  
    
      inline const int32_t& GetIntArray(int index) const { return int_array_[index]; }
      inline void SetIntArray(int index, const int32_t& value) { int_array_[index] = value; }
    
  
    inline std::shared_ptr<gen::BoTestSub> GetSub() { return sub_; }
    inline void SetSub(std::shared_ptr<gen::BoTestSub> sub) { sub_ = sub; }
  

  
static void WriteDirectTo(bufobjects::BufferBuilder& bb,std::string str_value,std::vector<int32_t> int_array,std::shared_ptr<gen::BoTestSub> sub);
static void WriteDirectIdentifiedTo(bufobjects::BufferBuilder& bb,std::string str_value,std::vector<int32_t> int_array,std::shared_ptr<gen::BoTestSub> sub);
};




  
    }
  

  


  


#endif