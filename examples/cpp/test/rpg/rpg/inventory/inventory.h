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
private:
  mutable uint32_t cached_size_;
protected:
std::string name_;rpg::inventory::Quality quality_;uint64_t cost_;

public:

Item();
Item(std::string name,rpg::inventory::Quality quality,uint64_t cost);
virtual ~Item(){};
virtual uint32_t Size() const override;
virtual void Clear() override;
virtual void WriteJsonTo(std::ostream &os) const = 0;


    inline const std::string& GetName() const { return name_; }
    inline std::string& GetName() { return name_; }
    inline void SetName(const std::string& name) { name_ = name; }
  

  
    inline const rpg::inventory::Quality& GetQuality() const { return quality_; }
    inline rpg::inventory::Quality& GetQuality() { return quality_; }
    inline void SetQuality(const rpg::inventory::Quality& quality) { quality_ = quality; }
  

  
    inline const uint64_t& GetCost() const { return cost_; }
    inline uint64_t& GetCost() { return cost_; }
    inline void SetCost(const uint64_t& cost) { cost_ = cost; }
  

  





};


  
    }
  

  
    }
  

  


  

  
  
    

  
      namespace rpg {
  

  
      namespace inventory {
  

  


class Weapon
: public /* this comment seems to fix a jtwig bug "" */
    
      rpg::inventory::Item{
private:
  mutable uint32_t cached_size_;
protected:
uint64_t damage_;

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
    inline const uint64_t& GetDamage() const { return damage_; }
    inline uint64_t& GetDamage() { return damage_; }
    inline void SetDamage(const uint64_t& damage) { damage_ = damage; }
  

  

static void WriteDirectTo(bufobjects::BufferBuilder& bb,const uint64_t& damage,const std::string& name,const /* this comment seems to fix a jtwig bug "" */
    
      rpg::inventory::Quality& quality,const uint64_t& cost);
static void WriteDirectIdentifiedTo(bufobjects::BufferBuilder& bb,const uint64_t& damage,const std::string& name,const /* this comment seems to fix a jtwig bug "" */
    
      rpg::inventory::Quality& quality,const uint64_t& cost);
};




  
    }
  

  
    }
  

  


  

  
  
    

  
      namespace rpg {
  

  
      namespace inventory {
  

  


class Armor
: public /* this comment seems to fix a jtwig bug "" */
    
      rpg::inventory::Item{
private:
  mutable uint32_t cached_size_;
protected:
uint64_t defense_;

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
    inline const uint64_t& GetDefense() const { return defense_; }
    inline uint64_t& GetDefense() { return defense_; }
    inline void SetDefense(const uint64_t& defense) { defense_ = defense; }
  

  

static void WriteDirectTo(bufobjects::BufferBuilder& bb,const uint64_t& defense,const std::string& name,const /* this comment seems to fix a jtwig bug "" */
    
      rpg::inventory::Quality& quality,const uint64_t& cost);
static void WriteDirectIdentifiedTo(bufobjects::BufferBuilder& bb,const uint64_t& defense,const std::string& name,const /* this comment seems to fix a jtwig bug "" */
    
      rpg::inventory::Quality& quality,const uint64_t& cost);
};




  
    }
  

  
    }
  

  


  

  
  
    

  
      namespace rpg {
  

  
      namespace inventory {
  

  


class Inventory
: public bufobjects::BufferObject{
private:
  mutable uint32_t cached_size_;
protected:
uint32_t capacity_;std::vector</* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item*> items_;

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
    inline const uint32_t& GetCapacity() const { return capacity_; }
    inline uint32_t& GetCapacity() { return capacity_; }
    inline void SetCapacity(const uint32_t& capacity) { capacity_ = capacity; }
  

  
    inline const std::vector</* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item*>& GetItems() const { return items_; }
    inline std::vector</* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item*>& GetItems() { return items_; }
    inline void SetItems(const std::vector</* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item*>& items) { items_ = items; }
  

  
    
      inline /* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item* GetItems(int index) { return items_[index]; cached_size_ = 0; }
      inline void SetItems(int index, /* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item* value) { items_[index] = value; cached_size_ = 0; }
    
  

static void WriteDirectTo(bufobjects::BufferBuilder& bb,const uint32_t& capacity,const std::vector</* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item*>& items);
static void WriteDirectIdentifiedTo(bufobjects::BufferBuilder& bb,const uint32_t& capacity,const std::vector</* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item*>& items);
};


  class Inventory::Builder {
private:
uint32_t capacity_;
std::vector</* this comment seems to fix a jtwig bug "true" */
    
      rpg::inventory::Item*> items_;

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
};



  
    }
  

  
    }
  

  


  


#endif