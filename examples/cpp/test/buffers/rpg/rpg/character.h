// Generated with https://github.com/paidgeek/bufobjects
    #ifndef RPG_CHARACTER_H
#define RPG_CHARACTER_H

#include "../buffer_object.h"


#include "../rpg/position.h"
  



namespace rpg {}namespace rpg {namespace inventory {class Inventory;}}namespace rpg {namespace inventory {class Item;}}
  
      namespace rpg {
  

  


class Character
: public bufobjects::BufferObject{

protected:
rpg::Position position_;
float speed_;
std::array<double, 8> buffs_;
std::string name_;
rpg::inventory::Inventory* bag_;
std::map<std::string, rpg::inventory::Item*> equipment_;


public:

  typedef rpg::Character* Ptr;


    static const uint32_t kBuffsLength = 8;
  

  class Builder;


Character();
Character(rpg::Position position,float speed,std::array<double, 8> buffs,std::string name,rpg::inventory::Inventory* bag,std::map<std::string, rpg::inventory::Item*> equipment);

~Character();

void Init(rpg::Position position,float speed,std::array<double, 8> buffs,std::string name,rpg::inventory::Inventory*& bag,std::map<std::string, rpg::inventory::Item*> equipment);
static Ptr New(rpg::Position position,float speed,std::array<double, 8> buffs,std::string name,rpg::inventory::Inventory*& bag,std::map<std::string, rpg::inventory::Item*> equipment);
Character(const Character& from);
Character& operator=(const Character& from);
explicit operator bufobjects::BufferObject::Ptr() {
  return static_cast< bufobjects::BufferObject::Ptr >(this);
}
uint16_t BufferObjectId() const;
void Reset();
void CopyTo(bufobjects::BufferObject& obj) const;
uint32_t Size() const;
void WriteTo(bufobjects::BufferObjectBuilder& bob) const;
void ReadFrom(bufobjects::BufferObjectBuilder& bob);
    inline const rpg::Position& GetPosition() const { return position_; }
    inline void SetPosition(const rpg::Position& position) { position_ = position; }
  

  
    inline const float& GetSpeed() const { return speed_; }
    inline void SetSpeed(const float& speed) { speed_ = speed; }
  

  
    inline const std::array<double, 8>& GetBuffs() const { return buffs_; }
    inline void SetBuffs(const std::array<double, 8>& buffs) { buffs_ = buffs; }
  

  
    
      inline const double& GetBuffs(int index) const { return buffs_[index]; }
      inline void SetBuffs(int index, const double& value) { buffs_[index] = value; }
    
  
    inline const std::string& GetName() const { return name_; }
    inline void SetName(const std::string& name) { name_ = name; }
  

  
    inline rpg::inventory::Inventory* GetBag() { return bag_; }
    inline void SetBag(rpg::inventory::Inventory* bag) { bag_ = bag; }
  

  
    inline const std::map<std::string, rpg::inventory::Item*>& GetEquipment() const { return equipment_; }
    inline void SetEquipment(const std::map<std::string, rpg::inventory::Item*>& equipment) { equipment_ = equipment; }
  

  
    
    inline rpg::inventory::Item* GetEquipment(const std::string& key) { return equipment_[key]; }
    inline void SetEquipment(const std::string& key, rpg::inventory::Item* value) { equipment_[key] = value; }

  
static void WriteDirectTo(bufobjects::BufferObjectBuilder& bob,rpg::Position position,float speed,std::array<double, 8> buffs,std::string name,rpg::inventory::Inventory* bag,std::map<std::string, rpg::inventory::Item*> equipment);
static void WriteDirectIdentifiedTo(bufobjects::BufferObjectBuilder& bob,rpg::Position position,float speed,std::array<double, 8> buffs,std::string name,rpg::inventory::Inventory* bag,std::map<std::string, rpg::inventory::Item*> equipment);
};


  class Character::Builder {
private:
rpg::Position position_;
float speed_;
std::array<double, 8> buffs_;
std::string name_;
rpg::inventory::Inventory* bag_;
std::map<std::string, rpg::inventory::Item*> equipment_;

public:
  Builder();

    Builder& Position(const rpg::Position& position);
  

  
    Builder& Speed(const float& speed);
  

  
    Builder& Buffs(const std::array<double, 8>& buffs);
  

  
    
      Builder& Buffs(int index, const double& value);
    
  
    Builder& Name(const std::string& name);
  

  
    Builder& Bag(rpg::inventory::Inventory* bag);
  

  
    Builder& Equipment(const std::map<std::string, rpg::inventory::Item*>& equipment);
  

  
    
    Builder& Equipment(const std::string& key, rpg::inventory::Item* value);

  
Character::Ptr Build();
void WriteTo(bufobjects::BufferObjectBuilder& bob);
void WriteIdentifiedTo(bufobjects::BufferObjectBuilder& bob);
};



  
    }
  

  


#endif
