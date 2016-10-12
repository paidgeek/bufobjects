package rpg;

// Generated with https://github.com/paidgeek/bufobjects

@SuppressWarnings("all")
public abstract class BufferObject {

  public abstract short bufferObjectId();
  public abstract void clear();
  public abstract BufferObject copy();
  public abstract void copyTo(BufferObject dst);
  public abstract void writeTo(BufferBuilder bb);
  public abstract void readFrom(BufferBuilder bb);
  public abstract void writeJsonTo(java.io.OutputStream os) throws java.io.IOException;

  public int size() {
    return 0;
  }
      public static final short RPG_CHARACTER_ID = 1;
      public static final short RPG_INVENTORY_WEAPON_ID = 2;
      public static final short RPG_INVENTORY_ARMOR_ID = 3;
      public static final short RPG_INVENTORY_INVENTORY_ID = 4;

  public static void writeIdentifiedTo(BufferBuilder bb, BufferObject obj) {
    bb.writeUInt16(obj.bufferObjectId());
    obj.writeTo(bb);
  }

  public static BufferObject readIdentifiedFrom(BufferBuilder bb) {
    short id = bb.readUInt16();
    BufferObject obj = null;
    switch(id) {case RPG_CHARACTER_ID:
          obj = new rpg.Character();
          obj.readFrom(bb);
          break;
        case RPG_INVENTORY_WEAPON_ID:
          obj = new rpg.inventory.Weapon();
          obj.readFrom(bb);
          break;
        case RPG_INVENTORY_ARMOR_ID:
          obj = new rpg.inventory.Armor();
          obj.readFrom(bb);
          break;
        case RPG_INVENTORY_INVENTORY_ID:
          obj = new rpg.inventory.Inventory();
          obj.readFrom(bb);
          break;
        }
    return obj;
  }

}
