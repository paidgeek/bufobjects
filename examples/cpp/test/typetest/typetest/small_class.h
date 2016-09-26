// Generated with https://github.com/paidgeek/bufobjects
    #ifndef TYPETEST_SMALLCLASS_H
#define TYPETEST_SMALLCLASS_H

#include "../buffer_object.h"







  
      namespace typetest {
  

  


class SmallClass
: public bufobjects::BufferObject{

protected:
int32_t value_;


public:

  typedef typetest::SmallClass* Ptr;




SmallClass();
SmallClass(int32_t value);

~SmallClass();

void Init(int32_t value);
static Ptr New(int32_t value);
SmallClass(const SmallClass& from);
SmallClass& operator=(const SmallClass& from);
explicit operator bufobjects::BufferObject::Ptr() {
  return static_cast< bufobjects::BufferObject::Ptr >(this);
}
uint16_t BufferObjectId() const;
void Reset();
void CopyTo(bufobjects::BufferObject& obj) const;
uint32_t Size() const;
void WriteTo(bufobjects::BufferObjectBuilder& bob) const;
void ReadFrom(bufobjects::BufferObjectBuilder& bob);
    inline const int32_t& GetValue() const { return value_; }
    inline void SetValue(const int32_t& value) { value_ = value; }
  

  
static void WriteDirectTo(bufobjects::BufferObjectBuilder& bob,int32_t value);
static void WriteDirectIdentifiedTo(bufobjects::BufferObjectBuilder& bob,int32_t value);
};




  
    }
  

  


#endif
