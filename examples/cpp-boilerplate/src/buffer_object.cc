// Generated with https://github.com/paidgeek/bufobjects

#include "buffer_object.h"
#include "rpg/character.h"
    #include "rpg/inventory/weapon.h"
    #include "rpg/inventory/armor.h"
    #include "rpg/inventory/inventory.h"
    

namespace bufobjects {
  void BufferObject::WriteIdentifiedTo(BufferObjectBuilder& bob, BufferObject& obj) {
    bob.WriteUInt16(obj.BufferObjectId());
    obj.WriteTo(bob);
  }

  BufferObject::Ptr BufferObject::ReadIdentifiedFrom(BufferObjectBuilder& bob) {
    uint16_t id = bob.ReadUInt16();
    BufferObject::Ptr obj;

    switch(id) {
case kRpgCharacterId:
      obj = new rpg::Character();
      break;
    case kRpgInventoryWeaponId:
      obj = new rpg::inventory::Weapon();
      break;
    case kRpgInventoryArmorId:
      obj = new rpg::inventory::Armor();
      break;
    case kRpgInventoryInventoryId:
      obj = new rpg::inventory::Inventory();
      break;
    }
    if(obj) {
      obj->ReadFrom(bob);
    }
    return obj;
  }
}
