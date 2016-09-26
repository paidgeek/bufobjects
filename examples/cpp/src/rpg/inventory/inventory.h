// Generated with https://github.com/paidgeek/bufobjects
    #ifndef RPG_INVENTORY_INVENTORY_H
#define RPG_INVENTORY_INVENTORY_H

#include "../../buffer_object.h"






namespace rpg {namespace inventory {class Item;}}
  
      namespace rpg {
  

  
      namespace inventory {
  

  


class Inventory
: public bufobjects::BufferObject{

protected:
uint32_t capacity_;
std::vector<rpg::inventory::Item*> items_;


public:

  typedef rpg::inventory::Inventory* Ptr;



  class Builder;


Inventory();
Inventory(uint32_t capacity,std::vector<rpg::inventory::Item*> items);

~Inventory();

void Init(uint32_t capacity,std::vector<rpg::inventory::Item*> items);
static Ptr New(uint32_t capacity,std::vector<rpg::inventory::Item*> items);
Inventory(const Inventory& from);
Inventory& operator=(const Inventory& from);
explicit operator bufobjects::BufferObject::Ptr() {
  return bufobjects::PointerCast< BufferObject >(this);
}
uint16_t BufferObjectId() const;
void Reset();
void CopyTo(bufobjects::BufferObject& obj) const;
uint32_t Size() const;
void WriteTo(bufobjects::BufferObjectBuilder& bob) const;
void ReadFrom(bufobjects::BufferObjectBuilder& bob);
    const uint32_t& GetCapacity() const;
    void SetCapacity(const uint32_t& capacity);
  

  
    const std::vector<rpg::inventory::Item*>& GetItems() const;
    void SetItems(const std::vector<rpg::inventory::Item*>& items);
  

  
    
      rpg::inventory::Item* GetItemsAt(int index) const;
      void SetItemsAt(int index, rpg::inventory::Item* value);
    
  
static void WriteDirectTo(bufobjects::BufferObjectBuilder& bob,uint32_t capacity,std::vector<rpg::inventory::Item*> items);
static void WriteDirectIdentifiedTo(bufobjects::BufferObjectBuilder& bob,uint32_t capacity,std::vector<rpg::inventory::Item*> items);
};


  class Inventory::Builder {
private:
uint32_t capacity_;
std::vector<rpg::inventory::Item*> items_;

public:
  Builder();

    Builder& Capacity(const uint32_t& capacity);
  

  
    Builder& Items(const std::vector<rpg::inventory::Item*>& items);
  

  
    
      Builder& Items(int index, rpg::inventory::Item* value);
      Builder& AddItems(rpg::inventory::Item* value);
      Builder& AddItems(std::vector<rpg::inventory::Item*> values);
    
  
Inventory::Ptr Build();
};



  
    }
  

  
    }
  

  


#endif
