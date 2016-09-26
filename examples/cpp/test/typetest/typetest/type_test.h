// Generated with https://github.com/paidgeek/bufobjects
    #ifndef TYPETEST_TYPETEST_H
#define TYPETEST_TYPETEST_H

#include "../buffer_object.h"


#include "../typetest/small_struct.h"
  #include "../typetest/small_struct.h"
  #include "../typetest/small_struct.h"
  



namespace typetest {}namespace typetest {}namespace typetest {class SmallClass;}namespace typetest {class SmallClass;}namespace typetest {class SmallClass;}namespace typetest {class SmallClass;}namespace typetest {}namespace typetest {}
  
      namespace typetest {
  

  


class TypeTest
: public bufobjects::BufferObject{

protected:
uint32_t u_int_;
int32_t s_int_;
std::array<int32_t, 3> int_array_;
typetest::SmallStruct f_struct_;
std::array<typetest::SmallStruct, 3> f_struct_array_;
std::string string_;
std::vector<int32_t> int_vector_;
std::array<std::string, 3> string_array_;
std::vector<std::string> string_vector_;
std::map<int32_t, std::string> int_string_map_;
typetest::SmallClass* f_class_;
std::array<typetest::SmallClass*, 3> f_class_array_;
std::vector<typetest::SmallClass*> f_class_vector_;
std::map<std::string, typetest::SmallClass*> f_class_map_;
std::vector<typetest::SmallStruct> f_struct_vector_;
std::map<int32_t, typetest::SmallStruct> f_struct_map_;


public:

  typedef typetest::TypeTest* Ptr;


    static const uint32_t kIntArrayLength = 3;
  
    static const uint32_t kFStructArrayLength = 3;
  
    static const uint32_t kStringArrayLength = 3;
  
    static const uint32_t kFClassArrayLength = 3;
  

  class Builder;


TypeTest();
TypeTest(uint32_t u_int,int32_t s_int,std::array<int32_t, 3> int_array,typetest::SmallStruct f_struct,std::array<typetest::SmallStruct, 3> f_struct_array,std::string string,std::vector<int32_t> int_vector,std::array<std::string, 3> string_array,std::vector<std::string> string_vector,std::map<int32_t, std::string> int_string_map,typetest::SmallClass* f_class,std::array<typetest::SmallClass*, 3> f_class_array,std::vector<typetest::SmallClass*> f_class_vector,std::map<std::string, typetest::SmallClass*> f_class_map,std::vector<typetest::SmallStruct> f_struct_vector,std::map<int32_t, typetest::SmallStruct> f_struct_map);

~TypeTest();

void Init(uint32_t u_int,int32_t s_int,std::array<int32_t, 3> int_array,typetest::SmallStruct f_struct,std::array<typetest::SmallStruct, 3> f_struct_array,std::string string,std::vector<int32_t> int_vector,std::array<std::string, 3> string_array,std::vector<std::string> string_vector,std::map<int32_t, std::string> int_string_map,typetest::SmallClass*& f_class,std::array<typetest::SmallClass*, 3> f_class_array,std::vector<typetest::SmallClass*> f_class_vector,std::map<std::string, typetest::SmallClass*> f_class_map,std::vector<typetest::SmallStruct> f_struct_vector,std::map<int32_t, typetest::SmallStruct> f_struct_map);
static Ptr New(uint32_t u_int,int32_t s_int,std::array<int32_t, 3> int_array,typetest::SmallStruct f_struct,std::array<typetest::SmallStruct, 3> f_struct_array,std::string string,std::vector<int32_t> int_vector,std::array<std::string, 3> string_array,std::vector<std::string> string_vector,std::map<int32_t, std::string> int_string_map,typetest::SmallClass*& f_class,std::array<typetest::SmallClass*, 3> f_class_array,std::vector<typetest::SmallClass*> f_class_vector,std::map<std::string, typetest::SmallClass*> f_class_map,std::vector<typetest::SmallStruct> f_struct_vector,std::map<int32_t, typetest::SmallStruct> f_struct_map);
TypeTest(const TypeTest& from);
TypeTest& operator=(const TypeTest& from);
explicit operator bufobjects::BufferObject::Ptr() {
  return static_cast< bufobjects::BufferObject::Ptr >(this);
}
uint16_t BufferObjectId() const;
void Reset();
void CopyTo(bufobjects::BufferObject& obj) const;
uint32_t Size() const;
void WriteTo(bufobjects::BufferObjectBuilder& bob) const;
void ReadFrom(bufobjects::BufferObjectBuilder& bob);
    inline const uint32_t& GetUInt() const { return u_int_; }
    inline void SetUInt(const uint32_t& u_int) { u_int_ = u_int; }
  

  
    inline const int32_t& GetSInt() const { return s_int_; }
    inline void SetSInt(const int32_t& s_int) { s_int_ = s_int; }
  

  
    inline const std::array<int32_t, 3>& GetIntArray() const { return int_array_; }
    inline void SetIntArray(const std::array<int32_t, 3>& int_array) { int_array_ = int_array; }
  

  
    
      inline const int32_t& GetIntArray(int index) const { return int_array_[index]; }
      inline void SetIntArray(int index, const int32_t& value) { int_array_[index] = value; }
    
  
    inline const typetest::SmallStruct& GetFStruct() const { return f_struct_; }
    inline void SetFStruct(const typetest::SmallStruct& f_struct) { f_struct_ = f_struct; }
  

  
    inline const std::array<typetest::SmallStruct, 3>& GetFStructArray() const { return f_struct_array_; }
    inline void SetFStructArray(const std::array<typetest::SmallStruct, 3>& f_struct_array) { f_struct_array_ = f_struct_array; }
  

  
    
      inline const typetest::SmallStruct& GetFStructArray(int index) const { return f_struct_array_[index]; }
      inline void SetFStructArray(int index, const typetest::SmallStruct& value) { f_struct_array_[index] = value; }
    
  
    inline const std::string& GetString() const { return string_; }
    inline void SetString(const std::string& string) { string_ = string; }
  

  
    inline const std::vector<int32_t>& GetIntVector() const { return int_vector_; }
    inline void SetIntVector(const std::vector<int32_t>& int_vector) { int_vector_ = int_vector; }
  

  
    
      inline const int32_t& GetIntVector(int index) const { return int_vector_[index]; }
      inline void SetIntVector(int index, const int32_t& value) { int_vector_[index] = value; }
    
  
    inline const std::array<std::string, 3>& GetStringArray() const { return string_array_; }
    inline void SetStringArray(const std::array<std::string, 3>& string_array) { string_array_ = string_array; }
  

  
    
      inline const std::string& GetStringArray(int index) const { return string_array_[index]; }
      inline void SetStringArray(int index, const std::string& value) { string_array_[index] = value; }
    
  
    inline const std::vector<std::string>& GetStringVector() const { return string_vector_; }
    inline void SetStringVector(const std::vector<std::string>& string_vector) { string_vector_ = string_vector; }
  

  
    
      inline const std::string& GetStringVector(int index) const { return string_vector_[index]; }
      inline void SetStringVector(int index, const std::string& value) { string_vector_[index] = value; }
    
  
    inline const std::map<int32_t, std::string>& GetIntStringMap() const { return int_string_map_; }
    inline void SetIntStringMap(const std::map<int32_t, std::string>& int_string_map) { int_string_map_ = int_string_map; }
  

  
    
    inline const std::string& GetIntStringMap(const int32_t& key) { return int_string_map_[key]; }
    inline void SetIntStringMap(const int32_t& key, const std::string& value) { int_string_map_[key] = value; }

  
    inline typetest::SmallClass* GetFClass() { return f_class_; }
    inline void SetFClass(typetest::SmallClass* f_class) { f_class_ = f_class; }
  

  
    inline const std::array<typetest::SmallClass*, 3>& GetFClassArray() const { return f_class_array_; }
    inline void SetFClassArray(const std::array<typetest::SmallClass*, 3>& f_class_array) { f_class_array_ = f_class_array; }
  

  
    
      inline typetest::SmallClass* GetFClassArray(int index) { return f_class_array_[index]; }
      inline void SetFClassArray(int index, typetest::SmallClass* value) { f_class_array_[index] = value; }
    
  
    inline const std::vector<typetest::SmallClass*>& GetFClassVector() const { return f_class_vector_; }
    inline void SetFClassVector(const std::vector<typetest::SmallClass*>& f_class_vector) { f_class_vector_ = f_class_vector; }
  

  
    
      inline typetest::SmallClass* GetFClassVector(int index) const { return f_class_vector_[index]; }
      inline void SetFClassVector(int index, typetest::SmallClass* value) { f_class_vector_[index] = value; }
    
  
    inline const std::map<std::string, typetest::SmallClass*>& GetFClassMap() const { return f_class_map_; }
    inline void SetFClassMap(const std::map<std::string, typetest::SmallClass*>& f_class_map) { f_class_map_ = f_class_map; }
  

  
    
    inline typetest::SmallClass* GetFClassMap(const std::string& key) { return f_class_map_[key]; }
    inline void SetFClassMap(const std::string& key, typetest::SmallClass* value) { f_class_map_[key] = value; }

  
    inline const std::vector<typetest::SmallStruct>& GetFStructVector() const { return f_struct_vector_; }
    inline void SetFStructVector(const std::vector<typetest::SmallStruct>& f_struct_vector) { f_struct_vector_ = f_struct_vector; }
  

  
    
      inline const typetest::SmallStruct& GetFStructVector(int index) const { return f_struct_vector_[index]; }
      inline void SetFStructVector(int index, const typetest::SmallStruct& value) { f_struct_vector_[index] = value; }
    
  
    inline const std::map<int32_t, typetest::SmallStruct>& GetFStructMap() const { return f_struct_map_; }
    inline void SetFStructMap(const std::map<int32_t, typetest::SmallStruct>& f_struct_map) { f_struct_map_ = f_struct_map; }
  

  
    
    inline const typetest::SmallStruct& GetFStructMap(const int32_t& key) { return f_struct_map_[key]; }
    inline void SetFStructMap(const int32_t& key, const typetest::SmallStruct& value) { f_struct_map_[key] = value; }

  
static void WriteDirectTo(bufobjects::BufferObjectBuilder& bob,uint32_t u_int,int32_t s_int,std::array<int32_t, 3> int_array,typetest::SmallStruct f_struct,std::array<typetest::SmallStruct, 3> f_struct_array,std::string string,std::vector<int32_t> int_vector,std::array<std::string, 3> string_array,std::vector<std::string> string_vector,std::map<int32_t, std::string> int_string_map,typetest::SmallClass* f_class,std::array<typetest::SmallClass*, 3> f_class_array,std::vector<typetest::SmallClass*> f_class_vector,std::map<std::string, typetest::SmallClass*> f_class_map,std::vector<typetest::SmallStruct> f_struct_vector,std::map<int32_t, typetest::SmallStruct> f_struct_map);
static void WriteDirectIdentifiedTo(bufobjects::BufferObjectBuilder& bob,uint32_t u_int,int32_t s_int,std::array<int32_t, 3> int_array,typetest::SmallStruct f_struct,std::array<typetest::SmallStruct, 3> f_struct_array,std::string string,std::vector<int32_t> int_vector,std::array<std::string, 3> string_array,std::vector<std::string> string_vector,std::map<int32_t, std::string> int_string_map,typetest::SmallClass* f_class,std::array<typetest::SmallClass*, 3> f_class_array,std::vector<typetest::SmallClass*> f_class_vector,std::map<std::string, typetest::SmallClass*> f_class_map,std::vector<typetest::SmallStruct> f_struct_vector,std::map<int32_t, typetest::SmallStruct> f_struct_map);
};


  class TypeTest::Builder {
private:
uint32_t u_int_;
int32_t s_int_;
std::array<int32_t, 3> int_array_;
typetest::SmallStruct f_struct_;
std::array<typetest::SmallStruct, 3> f_struct_array_;
std::string string_;
std::vector<int32_t> int_vector_;
std::array<std::string, 3> string_array_;
std::vector<std::string> string_vector_;
std::map<int32_t, std::string> int_string_map_;
typetest::SmallClass* f_class_;
std::array<typetest::SmallClass*, 3> f_class_array_;
std::vector<typetest::SmallClass*> f_class_vector_;
std::map<std::string, typetest::SmallClass*> f_class_map_;
std::vector<typetest::SmallStruct> f_struct_vector_;
std::map<int32_t, typetest::SmallStruct> f_struct_map_;

public:
  Builder();

    Builder& UInt(const uint32_t& u_int);
  

  
    Builder& SInt(const int32_t& s_int);
  

  
    Builder& IntArray(const std::array<int32_t, 3>& int_array);
  

  
    
      Builder& IntArray(int index, const int32_t& value);
    
  
    Builder& FStruct(const typetest::SmallStruct& f_struct);
  

  
    Builder& FStructArray(const std::array<typetest::SmallStruct, 3>& f_struct_array);
  

  
    
      Builder& FStructArray(int index, const typetest::SmallStruct& value);
    
  
    Builder& String(const std::string& string);
  

  
    Builder& IntVector(const std::vector<int32_t>& int_vector);
  

  
    
      Builder& IntVector(int index, const int32_t& value);
      Builder& AddIntVector(const int32_t& value);
      Builder& AddIntVector(const std::vector<int32_t>& values);
    
  
    Builder& StringArray(const std::array<std::string, 3>& string_array);
  

  
    
      Builder& StringArray(int index, const std::string& value);
    
  
    Builder& StringVector(const std::vector<std::string>& string_vector);
  

  
    
      Builder& StringVector(int index, const std::string& value);
      Builder& AddStringVector(const std::string& value);
      Builder& AddStringVector(const std::vector<std::string>& values);
    
  
    Builder& IntStringMap(const std::map<int32_t, std::string>& int_string_map);
  

  
    
    Builder& IntStringMap(const int32_t& key, const std::string& value);

  
    Builder& FClass(typetest::SmallClass* f_class);
  

  
    Builder& FClassArray(const std::array<typetest::SmallClass*, 3>& f_class_array);
  

  
    
      Builder& FClassArray(int index, typetest::SmallClass* value);
    
  
    Builder& FClassVector(const std::vector<typetest::SmallClass*>& f_class_vector);
  

  
    
      Builder& FClassVector(int index, typetest::SmallClass* value);
      Builder& AddFClassVector(typetest::SmallClass* value);
      Builder& AddFClassVector(std::vector<typetest::SmallClass*> values);
    
  
    Builder& FClassMap(const std::map<std::string, typetest::SmallClass*>& f_class_map);
  

  
    
    Builder& FClassMap(const std::string& key, typetest::SmallClass* value);

  
    Builder& FStructVector(const std::vector<typetest::SmallStruct>& f_struct_vector);
  

  
    
      Builder& FStructVector(int index, const typetest::SmallStruct& value);
      Builder& AddFStructVector(const typetest::SmallStruct& value);
      Builder& AddFStructVector(const std::vector<typetest::SmallStruct>& values);
    
  
    Builder& FStructMap(const std::map<int32_t, typetest::SmallStruct>& f_struct_map);
  

  
    
    Builder& FStructMap(const int32_t& key, const typetest::SmallStruct& value);

  
TypeTest::Ptr Build();
void WriteTo(bufobjects::BufferObjectBuilder& bob);
void WriteIdentifiedTo(bufobjects::BufferObjectBuilder& bob);
};



  
    }
  

  


#endif
