// Generated with https://github.com/paidgeek/bufobjects
    #ifndef GEN_BOTESTSUB_H
#define GEN_BOTESTSUB_H

#include "../buffer_object.h"







  
      namespace gen {
  

  


class BoTestSub
: public bufobjects::BufferObject{

protected:
float x_;
double y_;


public:

  typedef gen::BoTestSub* Ptr;


  class Builder;

BoTestSub();
BoTestSub(float x,double y);
void Init(float x,double y);
BoTestSub(const BoTestSub& from);
BoTestSub& operator=(const BoTestSub& from);
uint16_t BufferObjectId() const;
void Reset();
void CopyTo(bufobjects::BufferObject& obj) const;
uint32_t Size() const;
void WriteTo(bufobjects::BufferObjectBuilder& bob) const;
void ReadFrom(bufobjects::BufferObjectBuilder& bob);
    const float& GetX() const;
    void SetX(const float& x);
  

  
    const double& GetY() const;
    void SetY(const double& y);
  

  
static void WriteDirectTo(bufobjects::BufferObjectBuilder& bob,float x,double y);
static void WriteDirectIdentifiedTo(bufobjects::BufferObjectBuilder& bob,float x,double y);
};

class BoTestSub::Builder {
private:
float x_;
double y_;

public:
  Builder();

    Builder& SetX(const float& x);
  

  
    Builder& SetY(const double& y);
  

  
BoTestSub::Ptr Build();
};


  
    }
  

  


#endif
