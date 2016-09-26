// Generated with https://github.com/paidgeek/bufobjects
    #ifndef TYPETEST_SMALLSTRUCT_H
#define TYPETEST_SMALLSTRUCT_H

#include "../buffer_object.h"
  
    namespace typetest {
  

  


struct SmallStruct {
int32_t value_;

SmallStruct();
SmallStruct(int32_t value);
SmallStruct(const SmallStruct& from);
void Reset();
void WriteTo(bufobjects::BufferObjectBuilder& bob) const;
void ReadFrom(bufobjects::BufferObjectBuilder& bob);
};


  
    }
  

  


#endif
