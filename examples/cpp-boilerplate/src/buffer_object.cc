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

  std::shared_ptr< BufferObject > BufferObject::ReadIdentifiedFrom(BufferObjectBuilder& bob) {
    uint16_t id = bob.ReadUInt16();
    std::shared_ptr< BufferObject > obj;
    switch(id) {
case kRpgCharacterId:
      obj = std::make_shared< rpg::Character >();
      break;
    case kRpgInventoryWeaponId:
      obj = std::make_shared< rpg::inventory::Weapon >();
      break;
    case kRpgInventoryArmorId:
      obj = std::make_shared< rpg::inventory::Armor >();
      break;
    case kRpgInventoryInventoryId:
      obj = std::make_shared< rpg::inventory::Inventory >();
      break;
    }
    if(obj) {
      obj->ReadFrom(bob);
    }
    return obj;
  }
}
