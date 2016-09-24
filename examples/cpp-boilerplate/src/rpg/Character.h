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
std::string name_;
rpg::Position position_;
float speed_;
std::shared_ptr<rpg::inventory::Inventory> bag_;
std::shared_ptr<rpg::inventory::Item> main_hand_;
std::array<double, 8> buffs_;


public:

    static const uint32_t kBuffsLength = 8;
  
  class Builder;

Character();
Character(std::string name,rpg::Position position,float speed,std::shared_ptr<rpg::inventory::Inventory> bag,std::shared_ptr<rpg::inventory::Item> main_hand,std::array<double, 8> buffs);
void Init(std::string name,rpg::Position position,float speed,std::shared_ptr<rpg::inventory::Inventory>& bag,std::shared_ptr<rpg::inventory::Item> main_hand,std::array<double, 8> buffs);
Character(const Character& from);
Character& operator=(const Character& from);
uint16_t BufferObjectId() const;
void Reset();
void CopyTo(bufobjects::BufferObject& obj) const;
uint32_t Size() const;
void WriteTo(bufobjects::BufferObjectBuilder& bob) const;
void ReadFrom(bufobjects::BufferObjectBuilder& bob);const std::string& GetName() const;
  void SetName(const std::string& name);
  const rpg::Position& GetPosition() const;
  void SetPosition(const rpg::Position& position);
  const float& GetSpeed() const;
  void SetSpeed(const float& speed);
  const std::shared_ptr<rpg::inventory::Inventory>& GetBag() const;
  void SetBag(const std::shared_ptr<rpg::inventory::Inventory>& bag);
  const std::shared_ptr<rpg::inventory::Item>& GetMainHand() const;
  void SetMainHand(const std::shared_ptr<rpg::inventory::Item>& main_hand);
  const std::array<double, 8>& GetBuffs() const;
  void SetBuffs(const std::array<double, 8>& buffs);
  
    const double& GetBuffsAt(int index) const;
    void SetBuffsAt(int index, const double& value);
  
};

class Character::Builder {
private:
std::string name_;
rpg::Position position_;
float speed_;
std::shared_ptr<rpg::inventory::Inventory> bag_;
std::shared_ptr<rpg::inventory::Item> main_hand_;
std::array<double, 8> buffs_;

public:
  Builder();
Builder& SetName(const std::string& name);
  Builder& SetPosition(const rpg::Position& position);
  Builder& SetSpeed(const float& speed);
  Builder& SetBag(const std::shared_ptr<rpg::inventory::Inventory>& bag);
  Builder& SetMainHand(const std::shared_ptr<rpg::inventory::Item>& main_hand);
  Builder& SetBuffs(const std::array<double, 8>& buffs);
  
  Builder& SetBuffsAt(int index, const double& value);
  
std::shared_ptr< Character > Build();
};


  
    }
  

  


#endif