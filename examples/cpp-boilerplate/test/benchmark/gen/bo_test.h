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
BoTest(const BoTest& from);
BoTest& operator=(const BoTest& from);
uint16_t BufferObjectId() const;
void Reset();
void CopyTo(bufobjects::BufferObject& obj) const;
uint32_t Size() const;
void WriteTo(bufobjects::BufferObjectBuilder& bob) const;
void ReadFrom(bufobjects::BufferObjectBuilder& bob);
    const std::string& GetStrValue() const;
    void SetStrValue(const std::string& str_value);
  

  
    const std::vector<int32_t>& GetIntArray() const;
    void SetIntArray(const std::vector<int32_t>& int_array);
  

  
    
      const int32_t& GetIntArrayAt(int index) const;
      void SetIntArrayAt(int index, const int32_t& value);
    
  
    gen::BoTestSub* GetSub();
    void SetSub(gen::BoTestSub* sub);
  

  
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

    Builder& SetStrValue(const std::string& str_value);
  

  
    Builder& SetIntArray(const std::vector<int32_t>& int_array);
  

  
    
      Builder& SetIntArrayAt(int index, const int32_t& value);
      Builder& AddIntArray(const int32_t& value);
      Builder& AddIntArray(const std::vector<int32_t>& values);
    
  
    Builder& SetSub(gen::BoTestSub* sub);
  

  
BoTest::Ptr Build();
};


  
    }
  

  


#endif
