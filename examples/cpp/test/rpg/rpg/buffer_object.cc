// Generated with https://github.com/paidgeek/bufobjects

#include "buffer_object.h"
#include "rpg.h"
#include "rpg_inventory.h"


namespace bufobjects {

BufferObject* ReadIdentifiedFrom(BufferBuilder& _bb) {
  uint16_t id = _bb.ReadUInt16();
  BufferObject* obj = nullptr;

  switch(id) {
case kRpgCharacterId:
      obj = new rpg::Character{};
    break;
  case kRpgInventoryWeaponId:
      obj = new rpg::inventory::Weapon{};
    break;
  case kRpgInventoryArmorId:
      obj = new rpg::inventory::Armor{};
    break;
  case kRpgInventoryInventoryId:
      obj = new rpg::inventory::Inventory{};
    break;
  }
  if(obj != nullptr) {
    obj->ReadFrom(_bb);
  }
  return obj;
}

}
