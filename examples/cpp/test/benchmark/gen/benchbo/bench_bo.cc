// Generated with https://github.com/paidgeek/bufobjects


#include "./../benchbo/bench_bo.h"



  
  

  
  
    
  
    namespace benchbo {
  

  


Foo::Foo() { }

Foo::Foo(uint64_t id,int16_t count,int8_t prefix,uint32_t length)
:id(id),count(count),prefix(prefix),length(length){}

Foo::Foo(const Foo& from) {
  memcpy(this, &from, sizeof(Foo));
}

void Foo::Reset() {
id = 0;count = 0;prefix = 0;length = 0;

}

void Foo::WriteTo(bufobjects::BufferBuilder& _bb) const {
if(_bb.GetRemaining() < sizeof(Foo)) {
  _bb.GrowBuffer(sizeof(Foo));
}
#if defined(BUFOBJECTS_LITTLE_ENDIAN)

_bb.WriteData((void*) this, sizeof(Foo));

#else

{_bb.WriteUInt64(id);}
{_bb.WriteInt16(count);}
{_bb.WriteInt8(prefix);}
{_bb.WriteUInt32(length);}


#endif

}

void Foo::ReadFrom(bufobjects::BufferBuilder& _bb) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)

_bb.ReadData((void*) this, sizeof(Foo));

#else

{id = _bb.ReadUInt64();}{count = _bb.ReadInt16();}{prefix = _bb.ReadInt8();}{length = _bb.ReadUInt32();}

#endif

}

void Foo::WriteJsonTo(std::ostream &_os) {
_os << '{';

uint32_t _i = 0;
_os << "\"" << "id" << "\":";
    _os << "\"" << id << "\"";
  

  
    _os << ',';
  

_os << "\"" << "count" << "\":";
    _os << count;
  

  
    _os << ',';
  

_os << "\"" << "prefix" << "\":";
    _os << static_cast< int16_t >(prefix);
  

  
    _os << ',';
  

_os << "\"" << "length" << "\":";
    _os << length;
  

  


_os << '}';

}


  
    }
  

  


  

  
  
    
  
    namespace benchbo {
  

  


Bar::Bar() { }

Bar::Bar(benchbo::Foo parent,int32_t time,float ratio,uint16_t size)
:parent(parent),time(time),ratio(ratio),size(size){}

Bar::Bar(const Bar& from) {
  memcpy(this, &from, sizeof(Bar));
}

void Bar::Reset() {
parent.Reset();time = 0;ratio = 0.0f;size = 0;

}

void Bar::WriteTo(bufobjects::BufferBuilder& _bb) const {
if(_bb.GetRemaining() < sizeof(Bar)) {
  _bb.GrowBuffer(sizeof(Bar));
}
#if defined(BUFOBJECTS_LITTLE_ENDIAN)

_bb.WriteData((void*) this, sizeof(Bar));

#else

{parent.WriteTo(_bb);}
{_bb.WriteInt32(time);}
{_bb.WriteFloat32(ratio);}
{_bb.WriteUInt16(size);}


#endif

}

void Bar::ReadFrom(bufobjects::BufferBuilder& _bb) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)

_bb.ReadData((void*) this, sizeof(Bar));

#else

{parent.ReadFrom(_bb);}{time = _bb.ReadInt32();}{ratio = _bb.ReadFloat32();}{size = _bb.ReadUInt16();}

#endif

}

void Bar::WriteJsonTo(std::ostream &_os) {
_os << '{';

uint32_t _i = 0;
_os << "\"" << "parent" << "\":";
    parent.WriteJsonTo(_os);
  

  
    _os << ',';
  

_os << "\"" << "time" << "\":";
    _os << time;
  

  
    _os << ',';
  

_os << "\"" << "ratio" << "\":";
    _os << ratio;
  

  
    _os << ',';
  

_os << "\"" << "size" << "\":";
    _os << size;
  

  


_os << '}';

}


  
    }
  

  


  

  
  
    

  
    namespace benchbo {
  

  


FooBar::FooBar() { }

FooBar::FooBar(benchbo::Bar sibling,std::string name,double rating,uint8_t postfix)
:sibling_(sibling),name_(name),rating_(rating),postfix_(postfix){}

FooBar::~FooBar() {

    
  
    
  
    
  
    
  
}

void FooBar::Init(benchbo::Bar sibling,std::string name,double rating,uint8_t postfix) {sibling_ = sibling;name_ = name;rating_ = rating;postfix_ = postfix;}

FooBar::FooBar(const FooBar& from) {
  from.CopyTo(*this);
}

FooBar& FooBar::operator=(const FooBar& from) {
  from.CopyTo(*this);
  return *this;
}

uint16_t FooBar::BufferObjectId() const {
  return bufobjects::kBenchBoFooBarId;
}

void FooBar::Reset() {
sibling_.Reset();name_.clear();rating_ = 0.0;postfix_ = 0;

}

void FooBar::CopyTo(bufobjects::BufferObject& _obj) const {
FooBar& _dst = static_cast< FooBar& >(_obj);


      _dst.sibling_ = sibling_;
    _dst.name_ = name_;_dst.rating_ = rating_;_dst.postfix_ = postfix_;

}

uint32_t FooBar::Size() const {
uint32_t _size = 0;


    
      _size += sizeof(benchbo::Bar);
    
  
    _size += bufobjects::BufferBuilder::GetStringSize(name_);
  _size += 8; // size for "f64"
  _size += 1; // size for "u8"
  
return _size;
}

void FooBar::WriteTo(bufobjects::BufferBuilder& _bb) const {
uint32_t _needed = this->Size();
if(_bb.GetRemaining() < _needed) {
  _bb.GrowBuffer(_needed);
}
{
    sibling_.WriteTo(_bb);
  
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

void FooBar::ReadFrom(bufobjects::BufferBuilder& _bb) {
{
    sibling_.ReadFrom(_bb);
  
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


}

void FooBar::WriteJsonTo(std::ostream &_os) {
  _os << '{';



uint32_t _i = 0;
_os << "\"sibling\":";
    sibling_.WriteJsonTo(_os);
  

  
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

void FooBar::WriteDirectTo(bufobjects::BufferBuilder& _bb,const benchbo::Bar& sibling,const std::string& name,const double& rating,const uint8_t& postfix) {
{
    sibling.WriteTo(_bb);
  
  }{
    _bb.WriteString(name);
  
  }{
    _bb.WriteFloat64(rating);
  
  }{
    _bb.WriteUInt8(postfix);
  
  }
};
void FooBar::WriteDirectIdentifiedTo(bufobjects::BufferBuilder& _bb,const benchbo::Bar& sibling,const std::string& name,const double& rating,const uint8_t& postfix) {
_bb.WriteUInt16(bufobjects::kBenchBoFooBarId);
FooBar::WriteDirectTo(_bb,sibling,name,rating,postfix);
};




  
    }
  

  


  

  
  
    

  
    namespace benchbo {
  

  


FooBarContainer::FooBarContainer() { }

FooBarContainer::FooBarContainer(std::vector<benchbo::FooBar*> list,bool initialized,benchbo::Fruit fruit,std::string location)
:list_(list),initialized_(initialized),fruit_(fruit),location_(location){}

FooBarContainer::~FooBarContainer() {

    
      for(auto e : list_) {
        delete(e);
      }
      list_.clear();
    
  
    
  
    
  
    
  
}

void FooBarContainer::Init(std::vector<benchbo::FooBar*> list,bool initialized,benchbo::Fruit fruit,std::string location) {list_ = list;initialized_ = initialized;fruit_ = fruit;location_ = location;}

FooBarContainer::FooBarContainer(const FooBarContainer& from) {
  from.CopyTo(*this);
}

FooBarContainer& FooBarContainer::operator=(const FooBarContainer& from) {
  from.CopyTo(*this);
  return *this;
}

uint16_t FooBarContainer::BufferObjectId() const {
  return bufobjects::kBenchBoFooBarContainerId;
}

void FooBarContainer::Reset() {

    
      for(auto e : list_) {
        delete(e);
      }
    
    list_.clear();
  initialized_ = false;fruit_ = static_cast< benchbo::Fruit >(0);location_.clear();

}

void FooBarContainer::CopyTo(bufobjects::BufferObject& _obj) const {
FooBarContainer& _dst = static_cast< FooBarContainer& >(_obj);

_dst.list_ = std::vector< benchbo::FooBar* >(list_);_dst.initialized_ = initialized_;_dst.fruit_ = fruit_;_dst.location_ = location_;

}

uint32_t FooBarContainer::Size() const {
uint32_t _size = 0;

_size += bufobjects::BufferBuilder::GetVarUInt32Size(static_cast< uint32_t >(list_.size()));
    
        for(const auto& _e : list_) {
          if(_e != nullptr) {
            _size += _e->Size();
            // this comment seems to fix a jtwig bug ""
            
          }
        }
        _size += list_.size(); // for "is null" byte
      
    _size += 1; // size for "b"
  _size += 2; // size for "i16"
  
    _size += bufobjects::BufferBuilder::GetStringSize(location_);
  
return _size;
}

void FooBarContainer::WriteTo(bufobjects::BufferBuilder& _bb) const {
uint32_t _needed = this->Size();
if(_bb.GetRemaining() < _needed) {
  _bb.GrowBuffer(_needed);
}
{_bb.WriteVarUInt32(static_cast< uint32_t >(list_.size()));
    for(const auto& _e : list_) {
    if(_e == nullptr) {
        _bb.WriteUInt8(0x80);
      } else {
        _bb.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        _e->WriteTo(_bb);
      }
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

void FooBarContainer::ReadFrom(bufobjects::BufferBuilder& _bb) {
{uint32_t _size = _bb.ReadVarUInt32();
    list_.clear();
    list_.reserve(_size);
    for(uint32_t i = 0; i < _size; i++) {
      
        benchbo::FooBar* e = nullptr;
      
      // this comment seems to fix a jtwig bug "[]"
      
        if (_bb.ReadUInt8() == 0x81) {
          if (e == nullptr) {
            e = new benchbo::FooBar{};
          }
          e->ReadFrom(_bb);
        } else {
          e = nullptr;
        }
      list_.push_back(e);
    }
  }
{
    initialized_ = _bb.ReadBool();
  
  }
{
    fruit_ = static_cast< benchbo::Fruit >(_bb.ReadInt16());
  
  }
{
    location_ = _bb.ReadString();
  
  }


}

void FooBarContainer::WriteJsonTo(std::ostream &_os) {
  _os << '{';



uint32_t _i = 0;
_os << "\"list\":";_os << '[';
    _i = 0;
    for(const auto& _e : list_) {
      if(_e == nullptr) {
        _os << "null";
      } else {
        _e->WriteJsonTo(_os);
      }
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

void FooBarContainer::WriteDirectTo(bufobjects::BufferBuilder& _bb,const std::vector<benchbo::FooBar*>& list,const bool& initialized,const benchbo::Fruit& fruit,const std::string& location) {
{_bb.WriteVarUInt32(static_cast< uint32_t >(list.size()));
    for(const auto& _e : list) {
      if(_e == nullptr) {
        _bb.WriteUInt8(0x80);
      } else {
        _bb.WriteUInt8(0x81);
        // this comment seems to fix a jtwig bug "[]"
        
        _e->WriteTo(_bb);
      }
    }
  }{
    _bb.WriteBool(initialized);
  
  }{
    _bb.WriteInt16(static_cast< int16_t >(fruit));
  
  }{
    _bb.WriteString(location);
  
  }
};
void FooBarContainer::WriteDirectIdentifiedTo(bufobjects::BufferBuilder& _bb,const std::vector<benchbo::FooBar*>& list,const bool& initialized,const benchbo::Fruit& fruit,const std::string& location) {
_bb.WriteUInt16(bufobjects::kBenchBoFooBarContainerId);
FooBarContainer::WriteDirectTo(_bb,list,initialized,fruit,location);
};




  
    }