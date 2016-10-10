// Generated with https://github.com/paidgeek/bufobjects


#include "./../benchbo/bench_bo.h"



  
  

  
  
    
  
    namespace benchbo {
  

  


Foo::Foo() { }

Foo::Foo(int32_t time,float ration,uint16_t size)
:time(time),ration(ration),size(size){}

Foo::Foo(const Foo& from) {
  memcpy(this, &from, sizeof(Foo));
}

void Foo::Clear() {
time = 0;ration = 0.0f;size = 0;

}

void Foo::WriteTo(bufobjects::BufferBuilder& _bb) const {
if(_bb.GetRemaining() < sizeof(Foo)) {
  _bb.GrowBuffer(sizeof(Foo));
}
#if defined(BUFOBJECTS_LITTLE_ENDIAN)

_bb.WriteData((void*) this, sizeof(Foo));

#else

{_bb.WriteInt32(time);}
{_bb.WriteFloat32(ration);}
{_bb.WriteUInt16(size);}


#endif

}

void Foo::ReadFrom(bufobjects::BufferBuilder& _bb) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)

_bb.ReadData((void*) this, sizeof(Foo));

#else

{time = _bb.ReadInt32();}{ration = _bb.ReadFloat32();}{size = _bb.ReadUInt16();}

#endif

}

void Foo::WriteJsonTo(std::ostream &_os) const {
_os << '{';

uint32_t _i = 0;
_os << "\"" << "time" << "\":";
    _os << time;
  

  
    _os << ',';
  

_os << "\"" << "ration" << "\":";
    _os << ration;
  

  
    _os << ',';
  

_os << "\"" << "size" << "\":";
    _os << size;
  

  


_os << '}';

}


  
    }
  

  


  

  
  
    

  
    namespace benchbo {
  

  


Bar::Bar() {
  cached_size_ = 0;
}

Bar::Bar(benchbo::Foo foo,std::string name,double rating,uint8_t postfix)
:foo_(foo),name_(name),rating_(rating),postfix_(postfix){
  cached_size_ = 0;
}

Bar::~Bar() {


}

void Bar::Init(benchbo::Foo foo,std::string name,double rating,uint8_t postfix) {foo_ = foo;name_ = name;rating_ = rating;postfix_ = postfix;
cached_size_ = 0;
}

Bar::Bar(const Bar& from) {
  from.CopyTo(*this);
  cached_size_ = 0;
}

Bar& Bar::operator=(const Bar& from) {
  from.CopyTo(*this);
  cached_size_ = from.cached_size_;
  return *this;
}

uint16_t Bar::BufferObjectId() const {
  return bufobjects::kBenchBoBarId;
}

void Bar::Clear() {
foo_.Clear();name_.clear();rating_ = 0.0;postfix_ = 0;

cached_size_ = 0;
}

void Bar::CopyTo(bufobjects::BufferObject& _obj) const {
Bar& _dst = static_cast< Bar& >(_obj);
_dst.cached_size_ = cached_size_;


      _dst.foo_ = foo_;
    _dst.name_ = name_;_dst.rating_ = rating_;_dst.postfix_ = postfix_;

}

uint32_t Bar::Size() const {
if (cached_size_ != 0) {
  return cached_size_;
}
cached_size_ = 0;


    
      cached_size_ += sizeof(benchbo::Foo);
    
  
    cached_size_ += bufobjects::BufferBuilder::GetStringSize(name_);
  cached_size_ += 8; // size for "f64"
  cached_size_ += 1; // size for "u8"
  

return cached_size_;
}

void Bar::WriteTo(bufobjects::BufferBuilder& _bb) const {
uint32_t _needed = this->Size();
if(_bb.GetRemaining() < _needed) {
  _bb.GrowBuffer(_needed);
}
{
    foo_.WriteTo(_bb);
  
  }
{
    _bb.WriteString(name_);
  
  }
{
    _bb.WriteFloat64(rating_);
  
  }
{
    _bb.WriteUInt8(postfix_);
  
  }


}

void Bar::ReadFrom(bufobjects::BufferBuilder& _bb) {
{
    foo_.ReadFrom(_bb);
  
  }
{
    name_ = _bb.ReadString();
  
  }
{
    rating_ = _bb.ReadFloat64();
  
  }
{
    postfix_ = _bb.ReadUInt8();
  
  }


cached_size_ = 0;
}

void Bar::WriteJsonTo(std::ostream &_os) const {
  _os << '{';



uint32_t _i = 0;
_os << "\"foo\":";
    foo_.WriteJsonTo(_os);
  

  
    _os << ',';
  

_os << "\"name\":";
    _os << "\"" << name_ << "\"";
  

  
    _os << ',';
  

_os << "\"rating\":";
    _os << rating_;
  

  
    _os << ',';
  

_os << "\"postfix\":";
    _os << static_cast< uint16_t >(postfix_);
  

  


_os << '}';

}

void Bar::WriteDirectTo(bufobjects::BufferBuilder& _bb,const /* this comment seems to fix a jtwig bug "" */
    
      benchbo::Foo& foo,const std::string& name,const double& rating,const uint8_t& postfix) {
{
    foo.WriteTo(_bb);
  
  }{
    _bb.WriteString(name);
  
  }{
    _bb.WriteFloat64(rating);
  
  }{
    _bb.WriteUInt8(postfix);
  
  }
};
void Bar::WriteDirectIdentifiedTo(bufobjects::BufferBuilder& _bb,const /* this comment seems to fix a jtwig bug "" */
    
      benchbo::Foo& foo,const std::string& name,const double& rating,const uint8_t& postfix) {
_bb.WriteUInt16(bufobjects::kBenchBoBarId);
Bar::WriteDirectTo(_bb,foo,name,rating,postfix);
};




  
    }
  

  


  

  
  
    

  
    namespace benchbo {
  

  


Cat::Cat() {
  cached_size_ = 0;
}

Cat::Cat(std::vector</* this comment seems to fix a jtwig bug "[]" */
    
      benchbo::Bar> list,bool initialized,benchbo::Fruit fruit,std::string location)
:list_(list),initialized_(initialized),fruit_(fruit),location_(location){
  cached_size_ = 0;
}

Cat::~Cat() {


}

void Cat::Init(std::vector</* this comment seems to fix a jtwig bug "[]" */
    
      benchbo::Bar> list,bool initialized,benchbo::Fruit fruit,std::string location) {list_ = list;initialized_ = initialized;fruit_ = fruit;location_ = location;
cached_size_ = 0;
}

Cat::Cat(const Cat& from) {
  from.CopyTo(*this);
  cached_size_ = 0;
}

Cat& Cat::operator=(const Cat& from) {
  from.CopyTo(*this);
  cached_size_ = from.cached_size_;
  return *this;
}

uint16_t Cat::BufferObjectId() const {
  return bufobjects::kBenchBoCatId;
}

void Cat::Clear() {

    list_.clear();
  initialized_ = false;fruit_ = static_cast< benchbo::Fruit >(0);location_.clear();

cached_size_ = 0;
}

void Cat::CopyTo(bufobjects::BufferObject& _obj) const {
Cat& _dst = static_cast< Cat& >(_obj);
_dst.cached_size_ = cached_size_;

_dst.list_ = std::vector< /* this comment seems to fix a jtwig bug "[]" */
    
      benchbo::Bar >(list_);_dst.initialized_ = initialized_;_dst.fruit_ = fruit_;_dst.location_ = location_;

}

uint32_t Cat::Size() const {
if (cached_size_ != 0) {
  return cached_size_;
}
cached_size_ = 0;

cached_size_ += bufobjects::BufferBuilder::GetVarUInt32Size(static_cast< uint32_t >(list_.size()));
    
        for(const auto& _e : list_) {
        // this comment seems to fix a jtwig bug "[]"
        
          cached_size_ += _e.Size();
        
        }
      
    cached_size_ += 1; // size for "b"
  cached_size_ += 2; // size for "i16"
  
    cached_size_ += bufobjects::BufferBuilder::GetStringSize(location_);
  

return cached_size_;
}

void Cat::WriteTo(bufobjects::BufferBuilder& _bb) const {
uint32_t _needed = this->Size();
if(_bb.GetRemaining() < _needed) {
  _bb.GrowBuffer(_needed);
}
{_bb.WriteVarUInt32(static_cast< uint32_t >(list_.size()));
    for(const auto& _e : list_) {
    // this comment seems to fix a jtwig bug "[]"
      
        _e.WriteTo(_bb);
    }
  }
{
    _bb.WriteBool(initialized_);
  
  }
{
    _bb.WriteInt16(static_cast< int16_t >(fruit_));
  
  }
{
    _bb.WriteString(location_);
  
  }


}

void Cat::ReadFrom(bufobjects::BufferBuilder& _bb) {
{uint32_t _size = _bb.ReadVarUInt32();
    list_.clear();
    list_.reserve(_size);
    /* this comment seems to fix a jtwig bug "[]" */
    
      benchbo::Bar _e;
    for(uint32_t i = 0; i < _size; i++) {
      // this comment seems to fix a jtwig bug "[]"
      
        _e.ReadFrom(_bb);
      list_.push_back(_e);
    }
  }
{
    initialized_ = _bb.ReadBool();
  
  }
{
    fruit_ = static_cast< /* this comment seems to fix a jtwig bug "" */
    
      benchbo::Fruit >(_bb.ReadInt16());
  
  }
{
    location_ = _bb.ReadString();
  
  }


cached_size_ = 0;
}

void Cat::WriteJsonTo(std::ostream &_os) const {
  _os << '{';



uint32_t _i = 0;
_os << "\"list\":";_os << '[';
    _i = 0;
    for(const auto& _e : list_) {
      /* this comment seems to fix a jtwig bug "[]" */
    
      _e.WriteJsonTo(_os);
      if(++_i < list_.size()) {
        _os << ',';
      }
    }
    _os << ']';

  
    _os << ',';
  

_os << "\"initialized\":";
    
  

  
    _os << ',';
  

_os << "\"fruit\":";
    _os << static_cast< int16_t >(fruit_);
  

  
    _os << ',';
  

_os << "\"location\":";
    _os << "\"" << location_ << "\"";
  

  


_os << '}';

}

void Cat::WriteDirectTo(bufobjects::BufferBuilder& _bb,const std::vector</* this comment seems to fix a jtwig bug "[]" */
    
      benchbo::Bar>& list,const bool& initialized,const /* this comment seems to fix a jtwig bug "" */
    
      benchbo::Fruit& fruit,const std::string& location) {
{_bb.WriteVarUInt32(static_cast< uint32_t >(list.size()));
    for(const auto& _e : list) {
      // this comment seems to fix a jtwig bug "[]"
      
        _e.WriteTo(_bb);
    }
  }{
    _bb.WriteBool(initialized);
  
  }{
    _bb.WriteInt16(static_cast< int16_t >(fruit));
  
  }{
    _bb.WriteString(location);
  
  }
};
void Cat::WriteDirectIdentifiedTo(bufobjects::BufferBuilder& _bb,const std::vector</* this comment seems to fix a jtwig bug "[]" */
    
      benchbo::Bar>& list,const bool& initialized,const /* this comment seems to fix a jtwig bug "" */
    
      benchbo::Fruit& fruit,const std::string& location) {
_bb.WriteUInt16(bufobjects::kBenchBoCatId);
Cat::WriteDirectTo(_bb,list,initialized,fruit,location);
};




  
    }