// Generated with https://github.com/paidgeek/bufobjects

#ifndef BUFOBJECTS_BENCHBO_H
#define BUFOBJECTS_BENCHBO_H

#include <iostream>
#include "bufobjects.h"

// forward declarations

  
    
  
    
  
    namespace benchbo {}
  
    namespace benchbo {class Bar;}namespace benchbo {}
  




  
  
    
  
    namespace benchbo {
  

  


enum class Fruit : int16_t {
kApples = 0,kPears = 1,kBananas = 2
};


  
    }
  

  


  

  
  
    
  
    namespace benchbo {
  

  


struct Foo {
int32_t time;
float ration;
uint16_t size;

Foo();
Foo(int32_t time,float ration,uint16_t size);
Foo(const Foo& from);
void Clear();
void WriteTo(bufobjects::BufferBuilder& bb) const;
void ReadFrom(bufobjects::BufferBuilder& bb);
void WriteJsonTo(std::ostream &os) const;
};


  
    }
  

  


  

  
  
    

  
      namespace benchbo {
  

  


class Bar
: public bufobjects::BufferObject{
private:
  mutable uint32_t cached_size_;
protected:
benchbo::Foo foo_;std::string name_;double rating_;uint8_t postfix_;

public:



Bar();
Bar(benchbo::Foo foo,std::string name,double rating,uint8_t postfix);
void Init(benchbo::Foo foo,std::string name,double rating,uint8_t postfix);
Bar(const Bar& from);
Bar& operator=(const Bar& from);
~Bar();
uint16_t BufferObjectId() const override;
void Clear() override;
void CopyTo(bufobjects::BufferObject& obj) const override;
uint32_t Size() const override;
void WriteTo(bufobjects::BufferBuilder& bb) const override;
void ReadFrom(bufobjects::BufferBuilder& bb) override;
void WriteJsonTo(std::ostream &os) const override;
    inline const benchbo::Foo& GetFoo() const { return foo_; }
    inline benchbo::Foo& GetFoo() { return foo_; }
    inline void SetFoo(const benchbo::Foo& foo) { foo_ = foo; }
  

  
    inline const std::string& GetName() const { return name_; }
    inline std::string& GetName() { return name_; }
    inline void SetName(const std::string& name) { name_ = name; }
  

  
    inline const double& GetRating() const { return rating_; }
    inline double& GetRating() { return rating_; }
    inline void SetRating(const double& rating) { rating_ = rating; }
  

  
    inline const uint8_t& GetPostfix() const { return postfix_; }
    inline uint8_t& GetPostfix() { return postfix_; }
    inline void SetPostfix(const uint8_t& postfix) { postfix_ = postfix; }
  

  

static void WriteDirectTo(bufobjects::BufferBuilder& bb,const /* this comment seems to fix a jtwig bug "" */
    
      benchbo::Foo& foo,const std::string& name,const double& rating,const uint8_t& postfix);
static void WriteDirectIdentifiedTo(bufobjects::BufferBuilder& bb,const /* this comment seems to fix a jtwig bug "" */
    
      benchbo::Foo& foo,const std::string& name,const double& rating,const uint8_t& postfix);
};




  
    }
  

  


  

  
  
    

  
      namespace benchbo {
  

  


class Cat
: public bufobjects::BufferObject{
private:
  mutable uint32_t cached_size_;
protected:
std::vector</* this comment seems to fix a jtwig bug "[]" */
    
      benchbo::Bar> list_;bool initialized_;benchbo::Fruit fruit_;std::string location_;

public:



Cat();
Cat(std::vector</* this comment seems to fix a jtwig bug "[]" */
    
      benchbo::Bar> list,bool initialized,benchbo::Fruit fruit,std::string location);
void Init(std::vector</* this comment seems to fix a jtwig bug "[]" */
    
      benchbo::Bar> list,bool initialized,benchbo::Fruit fruit,std::string location);
Cat(const Cat& from);
Cat& operator=(const Cat& from);
~Cat();
uint16_t BufferObjectId() const override;
void Clear() override;
void CopyTo(bufobjects::BufferObject& obj) const override;
uint32_t Size() const override;
void WriteTo(bufobjects::BufferBuilder& bb) const override;
void ReadFrom(bufobjects::BufferBuilder& bb) override;
void WriteJsonTo(std::ostream &os) const override;
    inline const std::vector</* this comment seems to fix a jtwig bug "[]" */
    
      benchbo::Bar>& GetList() const { return list_; }
    inline std::vector</* this comment seems to fix a jtwig bug "[]" */
    
      benchbo::Bar>& GetList() { return list_; }
    inline void SetList(const std::vector</* this comment seems to fix a jtwig bug "[]" */
    
      benchbo::Bar>& list) { list_ = list; }
  

  
    
      inline const /* this comment seems to fix a jtwig bug "[]" */
    
      benchbo::Bar GetList(int index) const { return list_[index]; }
      inline /* this comment seems to fix a jtwig bug "[]" */
    
      benchbo::Bar GetList(int index) { return list_[index]; cached_size_ = 0; }
      inline void SetList(int index, /* this comment seems to fix a jtwig bug "[]" */
    
      benchbo::Bar value) { list_[index] = value; cached_size_ = 0; }
    
  
    inline const bool& GetInitialized() const { return initialized_; }
    inline bool& GetInitialized() { return initialized_; }
    inline void SetInitialized(const bool& initialized) { initialized_ = initialized; }
  

  
    inline const benchbo::Fruit& GetFruit() const { return fruit_; }
    inline benchbo::Fruit& GetFruit() { return fruit_; }
    inline void SetFruit(const benchbo::Fruit& fruit) { fruit_ = fruit; }
  

  
    inline const std::string& GetLocation() const { return location_; }
    inline std::string& GetLocation() { return location_; }
    inline void SetLocation(const std::string& location) { location_ = location; }
  

  

static void WriteDirectTo(bufobjects::BufferBuilder& bb,const std::vector</* this comment seems to fix a jtwig bug "[]" */
    
      benchbo::Bar>& list,const bool& initialized,const /* this comment seems to fix a jtwig bug "" */
    
      benchbo::Fruit& fruit,const std::string& location);
static void WriteDirectIdentifiedTo(bufobjects::BufferBuilder& bb,const std::vector</* this comment seems to fix a jtwig bug "[]" */
    
      benchbo::Bar>& list,const bool& initialized,const /* this comment seems to fix a jtwig bug "" */
    
      benchbo::Fruit& fruit,const std::string& location);
};




  
    }
  

  


  


#endif