package rpg;

// Generated with https://github.com/paidgeek/bufobjects

@SuppressWarnings("all")
public final class BufferObjects {
  public static final short RPG_CHARACTER_ID = 1;
  public static final short RPG_INVENTORY_WEAPON_ID = 2;
  public static final short RPG_INVENTORY_ARMOR_ID = 3;
  public static final short RPG_INVENTORY_INVENTORY_ID = 4;

  public static void writeTo(BufferObjectBuilder bob, BufferObject obj) {
    bob.writeUInt16(obj.bufferObjectId());
    obj.writeTo(bob);
  }

  public static BufferObject readFrom(BufferObjectBuilder bob) {
    short id = bob.readUInt16();
    BufferObject obj = null;
    switch(id) {case RPG_CHARACTER_ID:
          obj = new rpg.Character();
          obj.readFrom(bob);
          break;
        case RPG_INVENTORY_WEAPON_ID:
          obj = new rpg.inventory.Weapon();
          obj.readFrom(bob);
          break;
        case RPG_INVENTORY_ARMOR_ID:
          obj = new rpg.inventory.Armor();
          obj.readFrom(bob);
          break;
        case RPG_INVENTORY_INVENTORY_ID:
          obj = new rpg.inventory.Inventory();
          obj.readFrom(bob);
          break;
        }
    return obj;
  }

}