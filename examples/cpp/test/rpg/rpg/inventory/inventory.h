// Generated with https://github.com/paidgeek/bufobjects

#ifndef BUFOBJECTS_RPG_INVENTORY_H
#define BUFOBJECTS_RPG_INVENTORY_H

#include <iostream>
#include "../bufobjects.h"

// forward declarations

  
    
  
    namespace rpg {}namespace rpg {namespace inventory {class Inventory;}}namespace rpg {namespace inventory {class Item;}}
  

  
    
  
    namespace rpg {namespace inventory {}}
  
    
  
    
  
    namespace rpg {namespace inventory {class Item;}}
  




  
  
    
  
    namespace rpg {
  

  
    namespace inventory {
  

  


enum class Quality : uint8_t {
kCommon = 1,kRare = 2,kEpic = 3
};


  
    }
  

  
    }
  

  


  

  
  
    

  
    namespace rpg {
  

  
    namespace inventory {
  

  



class Item
: public bufobjects::BufferObject{
public:

Item();
Item(std::string name,rpg::inventory::Quality quality,uint64_t cost);
virtual ~Item(){};
virtual uint32_t Size() const override;
virtual void Clear() override;
virtual void WriteJsonTo(std::ostream &os) const = 0;


    inline const std::string& name() const { return name_; }
    inline std::string& name() { return name_; }
    inline void set_name(const std::string& name) { name_ = name_; }
  

  
    inline const rpg::inventory::Quality& quality() const { return quality_; }
    inline rpg::inventory::Quality& quality() { return quality_; }
    inline void set_quality(const rpg::inventory::Quality& quality) { quality_ = quality_; }
  

  
    inline const uint64_t& cost() const { return cost_; }
    inline uint64_t& cost() { return cost_; }
    inline void set_cost(const uint64_t& cost) { cost_ = cost_; }
  

  




protected:
std::string name_;
rpg::inventory::Quality quality_= static_cast< rpg::inventory::Quality >(0);
uint64_t cost_= 0;

private:
  mutable uint32_t _cached_size_;
};


  
    }
  

  
    }
  

  


  

  
  
    

  
      namespace rpg {
  

  
      namespace inventory {
  

  


class Weapon
: public /* this comment seems to fix a jtwig bug "" */
    
      rpg::inventory::Item{
public:



Weapon();
Weapon(uint64_t damage,std::string name,rpg::inventory::Quality quality,uint64_t cost);
void Init(uint64_t damage,std::string name,rpg::inventory::Quality quality,uint64_t cost);
Weapon(const Weapon& from);
Weapon& operator=(const Weapon& from);
~Weapon();
uint16_t BufferObjectId() const override;
void Clear() override;
void CopyTo(bufobjects::BufferObject& obj) const override;
uint32_t Size() const override;
void WriteTo(bufobjects::BufferBuilder& bb) const override;
void ReadFrom(bufobjects::BufferBuilder& bb) override;
void WriteJsonTo(std::ostream &os) const override;
    inline const uint64_t& damage() const { return damage_; }
    inline uint64_t& damage() { return damage_; }
    inline void set_damage(const uint64_t& damage) { damage_ = damage_; }
  

  

static void WriteDirectTo(bufobjects::BufferBuilder& bb,const uint64_t& damage,const std::string& name,const /* this comment seems to fix a jtwig bug "" */
    
      rpg::inventory::Quality& quality,const uint64_t& cost);
static void WriteDirectIdentifiedTo(bufobjects::BufferBuilder& bb,const uint64_t& damage,const std::string& name,const /* this comment seems to fix a jtwig bug "" */
    
      rpg::inventory::Quality& quality,const uint64_t& cost);
protected:
uint64_t damage_= 0;

private:
  mutable uint32_t _cached_size_;
};




  
    }
  

  
    }
  

  


  

  
  
    

  
      namespace rpg {
  

  
      namespace inventory {
  

  


class Armor
: public /* this comment seems to fix a jtwig bug "" */
    
      rpg::inventory::Item{
public:



Armor();
Armor(uint64_t defense,std::string name,rpg::inventory::Quality quality,uint64_t cost);
void Init(uint64_t defense,std::string name,rpg::inventory::Quality quality,uint64_t cost);
Armor(const Armor& from);
Armor& operator=(const Armor& from);
~Armor();
uint16_t BufferObjectId() const override;
void Clear() override;
void CopyTo(bufobjects::BufferObject& obj) const override;
uint32_t Size() const override;
void WriteTo(bufobjects::BufferBuilder& bb) const override;
void ReadFrom(bufobjects::BufferBuilder& bb) override;
void WriteJsonTo(std::ostream &os) const override;
    inline const uint64_t& defense() const { return defense_; }
    inline uint64_t& defense() { return defense_; }
    inline void set_defense(const uint64_t& defense) { defense_ = defense_; }
  

  

static void WriteDirectTo(bufobjects::BufferBuilder& bb,const uint64_t& defense,const std::string& name,const /* this comment seems to fix a jtwig bug "" */
    
      rpg::inventory::Quality& quality,const uint64_t& cost);
static void WriteDirectIdentifiedTo(bufobjects::BufferBuilder& bb,const uint64_t& defense,const std::string& name,const /* this comment seems to fix a jtwig bug "" */
    
      rpg::inventory::Quality& quality,const uint64_t& cost);
protected:
uint64_t defense_= 0;

private:
  mutable uint32_t _cached_size_;
};




  
    }
  

  
    }
  

  


  

  
  
    

  
      namespace rpg {
  

  
      namespace inventory {
  

  


class Inventory
: public bufobjects::BufferObject{
public:


  class Builder;


Inventory();
Inventory(uint32_t capacity,std::vector</* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item*> items);
void Init(uint32_t capacity,std::vector</* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item*> items);
Inventory(const Inventory& from);
Inventory& operator=(const Inventory& from);
~Inventory();
uint16_t BufferObjectId() const override;
void Clear() override;
void CopyTo(bufobjects::BufferObject& obj) const override;
uint32_t Size() const override;
void WriteTo(bufobjects::BufferBuilder& bb) const override;
void ReadFrom(bufobjects::BufferBuilder& bb) override;
void WriteJsonTo(std::ostream &os) const override;
    inline const uint32_t& capacity() const { return capacity_; }
    inline uint32_t& capacity() { return capacity_; }
    inline void set_capacity(const uint32_t& capacity) { capacity_ = capacity_; }
  

  
    inline const std::vector</* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item*>& items() const { return items_; }
    inline std::vector</* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item*>& items() { return items_; }
    inline void set_items(const std::vector</* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item*>& items) { items_ = items_; }
  

  
    
      inline /* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item* items(int index) { return items_[index]; _cached_size_ = 0; }
      inline void set_items(int index, /* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item* value) { items_[index] = value; _cached_size_ = 0; }
    
  

static void WriteDirectTo(bufobjects::BufferBuilder& bb,const uint32_t& capacity,const std::vector</* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item*>& items);
static void WriteDirectIdentifiedTo(bufobjects::BufferBuilder& bb,const uint32_t& capacity,const std::vector</* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item*>& items);
protected:
uint32_t capacity_= 0;
std::vector</* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item*> items_;

private:
  mutable uint32_t _cached_size_;
};


  class Inventory::Builder {
public:
Builder();

    Builder& SetCapacity(const uint32_t& capacity);
  

  
    Builder& SetItems(const std::vector</* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item*>& items);
  

  
    
      Builder& SetItems(int index, rpg::inventory::Item* value);
      Builder& AddItems(rpg::inventory::Item* value);
      Builder& AddItems(std::vector</* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item*> values);
    
  
Inventory* Build();
private:

  uint32_t capacity_= 0;

  std::vector</* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item*> items_;

};



  
    }
  

  
    }
  

  


  


#endif