// Generated with https://github.com/paidgeek/bufobjects

#include "buffer_object.h"

  #include "./../rpg/rpg.h"

  #include "./../rpg/inventory/inventory.h"


namespace bufobjects {

BufferObject* ReadIdentifiedFrom(BufferBuilder& _bb) {
  uint16_t id = _bb.ReadUInt16();
  BufferObject* obj = nullptr;

  switch(id) {
case kRpgCharacterId:
      obj = new rpg::Character{};
      obj->ReadFrom(_bb);
    break;
  case kRpgInventoryWeaponId:
      obj = new rpg::inventory::Weapon{};
      obj->ReadFrom(_bb);
    break;
  case kRpgInventoryArmorId:
      obj = new rpg::inventory::Armor{};
      obj->ReadFrom(_bb);
    break;
  case kRpgInventoryInventoryId:
      obj = new rpg::inventory::Inventory{};
      obj->ReadFrom(_bb);
    break;
  }
  return obj;
}

}
