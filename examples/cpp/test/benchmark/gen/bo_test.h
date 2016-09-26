// Generated with https://github.com/paidgeek/bufobjects
    #ifndef GEN_BOTEST_H
#define GEN_BOTEST_H

#include "../buffer_object.h"






namespace gen {class BoTestSub;}
  
      namespace gen {
  

  


class BoTest
: public bufobjects::BufferObject{

protected:
std::string str_value_;
std::vector<int32_t> int_array_;
gen::BoTestSub* sub_;


public:

  typedef gen::BoTest* Ptr;



  class Builder;


BoTest();
BoTest(std::string str_value,std::vector<int32_t> int_array,gen::BoTestSub* sub);

~BoTest();

void Init(std::string str_value,std::vector<int32_t> int_array,gen::BoTestSub*& sub);
static Ptr New(std::string str_value,std::vector<int32_t> int_array,gen::BoTestSub*& sub);
BoTest(const BoTest& from);
BoTest& operator=(const BoTest& from);
explicit operator bufobjects::BufferObject::Ptr() {
  return bufobjects::PointerCast< BufferObject >(this);
}
uint16_t BufferObjectId() const;
void Reset();
void CopyTo(bufobjects::BufferObject& obj) const;
uint32_t Size() const;
void WriteTo(bufobjects::BufferObjectBuilder& bob) const;
void ReadFrom(bufobjects::BufferObjectBuilder& bob);
    inline const std::string& GetStrValue() const { return str_value_; }
    inline void SetStrValue(const std::string& str_value) { str_value_ = str_value; }
  

  
    inline const std::vector<int32_t>& GetIntArray() const { return int_array_; }
    inline void SetIntArray(const std::vector<int32_t>& int_array) { int_array_ = int_array; }
  

  
    
      inline const int32_t& GetIntArrayAt(int index) const { return int_array_[index]; }
      inline void SetIntArrayAt(int index, const int32_t& value) { int_array_[index] = value; }
    
  
    gen::BoTestSub* GetSub() { return sub_; }
    inline void SetSub(gen::BoTestSub* sub) { sub_ = sub; }
  

  
static void WriteDirectTo(bufobjects::BufferObjectBuilder& bob,std::string str_value,std::vector<int32_t> int_array,gen::BoTestSub* sub);
static void WriteDirectIdentifiedTo(bufobjects::BufferObjectBuilder& bob,std::string str_value,std::vector<int32_t> int_array,gen::BoTestSub* sub);
};


  class BoTest::Builder {
private:
std::string str_value_;
std::vector<int32_t> int_array_;
gen::BoTestSub* sub_;

public:
  Builder();

    Builder& StrValue(const std::string& str_value);
  

  
    Builder& IntArray(const std::vector<int32_t>& int_array);
  

  
    
      Builder& IntArray(int index, const int32_t& value);
      Builder& AddIntArray(const int32_t& value);
      Builder& AddIntArray(const std::vector<int32_t>& values);
    
  
    Builder& Sub(gen::BoTestSub* sub);
  

  
BoTest::Ptr Build();
void WriteTo(bufobjects::BufferObjectBuilder& bob);
void WriteIdentifiedTo(bufobjects::BufferObjectBuilder& bob);
};



  
    }
  

  


#endif
