// Generated with https://github.com/paidgeek/bufobjects

#include "buffer_object.h"
#include "rpg.h"
#include "rpg_inventory.h"


namespace bufobjects {
  void WriteIdentifiedTo(BufferObjectBuilder& _bob, BufferObject::Ptr obj) {
    _bob.WriteUInt16(obj->BufferObjectId());
    obj->WriteTo(_bob);
  }

  BufferObject::Ptr ReadIdentifiedFrom(BufferObjectBuilder& _bob) {
    uint16_t id = _bob.ReadUInt16();
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
      obj->ReadFrom(_bob);
    }
    return obj;
  }
}
