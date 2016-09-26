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
rpg::inventory::Item* main_hand_;


public:

  typedef rpg::Character* Ptr;


    static const uint32_t kBuffsLength = 8;
  

  class Builder;


Character();
Character(rpg::Position position,float speed,std::array<double, 8> buffs,std::string name,rpg::inventory::Inventory* bag,rpg::inventory::Item* main_hand);

~Character();

void Init(rpg::Position position,float speed,std::array<double, 8> buffs,std::string name,rpg::inventory::Inventory*& bag,rpg::inventory::Item* main_hand);
static Ptr New(rpg::Position position,float speed,std::array<double, 8> buffs,std::string name,rpg::inventory::Inventory*& bag,rpg::inventory::Item* main_hand);
Character(const Character& from);
Character& operator=(const Character& from);
explicit operator bufobjects::BufferObject::Ptr() {
  return bufobjects::PointerCast< BufferObject >(this);
}
uint16_t BufferObjectId() const;
void Reset();
void CopyTo(bufobjects::BufferObject& obj) const;
uint32_t Size() const;
void WriteTo(bufobjects::BufferObjectBuilder& bob) const;
void ReadFrom(bufobjects::BufferObjectBuilder& bob);
    const rpg::Position& GetPosition() const;
    void SetPosition(const rpg::Position& position);
  

  
    const float& GetSpeed() const;
    void SetSpeed(const float& speed);
  

  
    const std::array<double, 8>& GetBuffs() const;
    void SetBuffs(const std::array<double, 8>& buffs);
  

  
    
      const double& GetBuffsAt(int index) const;
      void SetBuffsAt(int index, const double& value);
    
  
    const std::string& GetName() const;
    void SetName(const std::string& name);
  

  
    rpg::inventory::Inventory* GetBag();
    void SetBag(rpg::inventory::Inventory* bag);
  

  
    rpg::inventory::Item* GetMainHand();
    void SetMainHand(rpg::inventory::Item* main_hand);
  

  
static void WriteDirectTo(bufobjects::BufferObjectBuilder& bob,rpg::Position position,float speed,std::array<double, 8> buffs,std::string name,rpg::inventory::Inventory* bag,rpg::inventory::Item* main_hand);
static void WriteDirectIdentifiedTo(bufobjects::BufferObjectBuilder& bob,rpg::Position position,float speed,std::array<double, 8> buffs,std::string name,rpg::inventory::Inventory* bag,rpg::inventory::Item* main_hand);
};


  class Character::Builder {
private:
rpg::Position position_;
float speed_;
std::array<double, 8> buffs_;
std::string name_;
rpg::inventory::Inventory* bag_;
rpg::inventory::Item* main_hand_;

public:
  Builder();

    Builder& Position(const rpg::Position& position);
  

  
    Builder& Speed(const float& speed);
  

  
    Builder& Buffs(const std::array<double, 8>& buffs);
  

  
    
      Builder& Buffs(int index, const double& value);
    
  
    Builder& Name(const std::string& name);
  

  
    Builder& Bag(rpg::inventory::Inventory* bag);
  

  
    Builder& MainHand(rpg::inventory::Item* main_hand);
  

  
Character::Ptr Build();
};



  
    }
  

  


#endif
