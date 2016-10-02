// Generated with https://github.com/paidgeek/bufobjects

#ifndef BUFOBJECTS_TYPETEST_H
#define BUFOBJECTS_TYPETEST_H

#include <iostream>
#include "buffer_object.h"

// forward declarations

  
    
  
    
  
    namespace typetest {class SmallClass;}namespace typetest {class SmallClass;}namespace typetest {class SmallClass;}namespace typetest {class SmallClass;}namespace typetest {}namespace typetest {}namespace typetest {}namespace typetest {}
  




  
  
    

  
      namespace typetest {
  

  


class SmallClass
: public bufobjects::BufferObject{

protected:
int32_t value_;

public:



SmallClass();
SmallClass(int32_t value);
void Init(int32_t value);
SmallClass(const SmallClass& from);
SmallClass& operator=(const SmallClass& from);
~SmallClass();
uint16_t BufferObjectId() const override;
void Reset() override;
void CopyTo(bufobjects::BufferObject& obj) const override;
uint32_t Size() const override;
void WriteTo(bufobjects::BufferBuilder& bb) const override;
void ReadFrom(bufobjects::BufferBuilder& bb) override;
void WriteJsonTo(std::ostream &os);
    inline const int32_t& GetValue() const { return value_; }
    inline void SetValue(const int32_t& value) { value_ = value; }
  

  

static void WriteDirectTo(bufobjects::BufferBuilder& bb,const int32_t& value);
static void WriteDirectIdentifiedTo(bufobjects::BufferBuilder& bb,const int32_t& value);
};




  
    }
  

  


  

  
  
    
  
    namespace typetest {
  

  


struct SmallStruct {
int32_t value;

SmallStruct();
SmallStruct(int32_t value);
SmallStruct(const SmallStruct& from);
void Reset();
void WriteTo(bufobjects::BufferBuilder& bb) const;
void ReadFrom(bufobjects::BufferBuilder& bb);
void WriteJsonTo(std::ostream &os);
};


  
    }
  

  


  

  
  
    

  
      namespace typetest {
  

  


class TypeTest
: public bufobjects::BufferObject{

protected:
uint32_t u_int_;int32_t s_int_;std::string string_;std::array<int32_t, 3> int_array_;std::vector<int32_t> int_vector_;std::array<std::string, 3> string_array_;std::vector<std::string> string_vector_;std::map<int32_t, std::string> int_string_map_;typetest::SmallClass* f_class_ = nullptr;std::array<typetest::SmallClass*, 3> f_class_array_;std::vector<typetest::SmallClass*> f_class_vector_;std::map<std::string, typetest::SmallClass*> f_class_map_;typetest::SmallStruct f_struct_;std::array<typetest::SmallStruct, 3> f_struct_array_;std::vector<typetest::SmallStruct> f_struct_vector_;std::map<int32_t, typetest::SmallStruct> f_struct_map_;

public:

    static const uint32_t kIntArrayLength = 3;
  
    static const uint32_t kStringArrayLength = 3;
  
    static const uint32_t kFClassArrayLength = 3;
  
    static const uint32_t kFStructArrayLength = 3;
  


TypeTest();
TypeTest(uint32_t u_int,int32_t s_int,std::string string,std::array<int32_t, 3> int_array,std::vector<int32_t> int_vector,std::array<std::string, 3> string_array,std::vector<std::string> string_vector,std::map<int32_t, std::string> int_string_map,typetest::SmallClass* f_class,std::array<typetest::SmallClass*, 3> f_class_array,std::vector<typetest::SmallClass*> f_class_vector,std::map<std::string, typetest::SmallClass*> f_class_map,typetest::SmallStruct f_struct,std::array<typetest::SmallStruct, 3> f_struct_array,std::vector<typetest::SmallStruct> f_struct_vector,std::map<int32_t, typetest::SmallStruct> f_struct_map);
void Init(uint32_t u_int,int32_t s_int,std::string string,std::array<int32_t, 3> int_array,std::vector<int32_t> int_vector,std::array<std::string, 3> string_array,std::vector<std::string> string_vector,std::map<int32_t, std::string> int_string_map,typetest::SmallClass* f_class,std::array<typetest::SmallClass*, 3> f_class_array,std::vector<typetest::SmallClass*> f_class_vector,std::map<std::string, typetest::SmallClass*> f_class_map,typetest::SmallStruct f_struct,std::array<typetest::SmallStruct, 3> f_struct_array,std::vector<typetest::SmallStruct> f_struct_vector,std::map<int32_t, typetest::SmallStruct> f_struct_map);
TypeTest(const TypeTest& from);
TypeTest& operator=(const TypeTest& from);
~TypeTest();
uint16_t BufferObjectId() const override;
void Reset() override;
void CopyTo(bufobjects::BufferObject& obj) const override;
uint32_t Size() const override;
void WriteTo(bufobjects::BufferBuilder& bb) const override;
void ReadFrom(bufobjects::BufferBuilder& bb) override;
void WriteJsonTo(std::ostream &os);
    inline const uint32_t& GetUInt() const { return u_int_; }
    inline void SetUInt(const uint32_t& u_int) { u_int_ = u_int; }
  

  
    inline const int32_t& GetSInt() const { return s_int_; }
    inline void SetSInt(const int32_t& s_int) { s_int_ = s_int; }
  

  
    inline const std::string& GetString() const { return string_; }
    inline void SetString(const std::string& string) { string_ = string; }
  

  
    inline const std::array<int32_t, 3>& GetIntArray() const { return int_array_; }
    inline void SetIntArray(const std::array<int32_t, 3>& int_array) { int_array_ = int_array; }
  

  
    
      inline const int32_t& GetIntArray(int index) const { return int_array_[index]; }
      inline void SetIntArray(int index, const int32_t& value) { int_array_[index] = value; }
    
  
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
  

  
    
      inline typetest::SmallClass* GetFClassVector(int index) { return f_class_vector_[index]; }
      inline void SetFClassVector(int index, typetest::SmallClass* value) { f_class_vector_[index] = value; }
    
  
    inline const std::map<std::string, typetest::SmallClass*>& GetFClassMap() const { return f_class_map_; }
    inline void SetFClassMap(const std::map<std::string, typetest::SmallClass*>& f_class_map) { f_class_map_ = f_class_map; }
  

  
    
    inline typetest::SmallClass* GetFClassMap(const std::string& key) { return f_class_map_[key]; }
        inline void SetFClassMap(const std::string& key, typetest::SmallClass* value) { f_class_map_[key] = value; }
    inline const typetest::SmallStruct& GetFStruct() const { return f_struct_; }
    inline void SetFStruct(const typetest::SmallStruct& f_struct) { f_struct_ = f_struct; }
  

  
    inline const std::array<typetest::SmallStruct, 3>& GetFStructArray() const { return f_struct_array_; }
    inline void SetFStructArray(const std::array<typetest::SmallStruct, 3>& f_struct_array) { f_struct_array_ = f_struct_array; }
  

  
    
      inline const typetest::SmallStruct& GetFStructArray(int index) const { return f_struct_array_[index]; }
      inline void SetFStructArray(int index, const typetest::SmallStruct& value) { f_struct_array_[index] = value; }
    
  
    inline const std::vector<typetest::SmallStruct>& GetFStructVector() const { return f_struct_vector_; }
    inline void SetFStructVector(const std::vector<typetest::SmallStruct>& f_struct_vector) { f_struct_vector_ = f_struct_vector; }
  

  
    
      inline const typetest::SmallStruct& GetFStructVector(int index) const { return f_struct_vector_[index]; }
      inline void SetFStructVector(int index, const typetest::SmallStruct& value) { f_struct_vector_[index] = value; }
    
  
    inline const std::map<int32_t, typetest::SmallStruct>& GetFStructMap() const { return f_struct_map_; }
    inline void SetFStructMap(const std::map<int32_t, typetest::SmallStruct>& f_struct_map) { f_struct_map_ = f_struct_map; }
  

  
    
    inline const typetest::SmallStruct& GetFStructMap(const int32_t& key) { return f_struct_map_[key]; }
        inline void SetFStructMap(const int32_t& key, const typetest::SmallStruct& value) { f_struct_map_[key] = value; }

    inline bool HasFClass() { return f_class_ != nullptr; }
  
static void WriteDirectTo(bufobjects::BufferBuilder& bb,const uint32_t& u_int,const int32_t& s_int,const std::string& string,const std::array<int32_t, 3>& int_array,const std::vector<int32_t>& int_vector,const std::array<std::string, 3>& string_array,const std::vector<std::string>& string_vector,const std::map<int32_t, std::string>& int_string_map,const typetest::SmallClass& f_class,const std::array<typetest::SmallClass*, 3>& f_class_array,const std::vector<typetest::SmallClass*>& f_class_vector,const std::map<std::string, typetest::SmallClass*>& f_class_map,const typetest::SmallStruct& f_struct,const std::array<typetest::SmallStruct, 3>& f_struct_array,const std::vector<typetest::SmallStruct>& f_struct_vector,const std::map<int32_t, typetest::SmallStruct>& f_struct_map);
static void WriteDirectIdentifiedTo(bufobjects::BufferBuilder& bb,const uint32_t& u_int,const int32_t& s_int,const std::string& string,const std::array<int32_t, 3>& int_array,const std::vector<int32_t>& int_vector,const std::array<std::string, 3>& string_array,const std::vector<std::string>& string_vector,const std::map<int32_t, std::string>& int_string_map,const typetest::SmallClass& f_class,const std::array<typetest::SmallClass*, 3>& f_class_array,const std::vector<typetest::SmallClass*>& f_class_vector,const std::map<std::string, typetest::SmallClass*>& f_class_map,const typetest::SmallStruct& f_struct,const std::array<typetest::SmallStruct, 3>& f_struct_array,const std::vector<typetest::SmallStruct>& f_struct_vector,const std::map<int32_t, typetest::SmallStruct>& f_struct_map);
};




  
    }
  

  


  


#endif