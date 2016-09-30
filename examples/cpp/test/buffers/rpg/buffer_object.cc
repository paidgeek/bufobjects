// Generated with https://github.com/paidgeek/bufobjects

#include "buffer_object.h"
#include "buffer_builder.h"
#include "rpg.h"
#include "rpg_inventory.h"


namespace bufobjects {
  void WriteIdentifiedTo(BufferBuilder& _bb, BufferObject::Ptr obj) {
    _bb.WriteUInt16(obj->BufferObjectId());
    obj->WriteTo(_bb);
  }

  BufferObject::Ptr ReadIdentifiedFrom(BufferBuilder& _bb) {
    uint16_t id = _bb.ReadUInt16();
    BufferObject::Ptr obj;

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
      obj->ReadFrom(_bb);
    }
    return obj;
  }
}
