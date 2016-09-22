package rpg;

// Generated with https://github.com/paidgeek/bufobjects

@SuppressWarnings("all")
public abstract class BufferObject {

  public abstract short bufferObjectId();

  public abstract void reset();

  public abstract BufferObject copy();

  public abstract void copyTo(BufferObject dst);

  public abstract void writeTo(BufferObjectBuilder bob);

  public abstract void readFrom(BufferObjectBuilder bob);

  public int size() {
    return 0;
  }

  public static final short RPG_CHARACTER_ID = 1;
  public static final short RPG_INVENTORY_WEAPON_ID = 2;
  public static final short RPG_INVENTORY_ARMOR_ID = 3;
  public static final short RPG_INVENTORY_INVENTORY_ID = 4;

  public static void writeIdentifiedTo(BufferObjectBuilder bob, BufferObject obj) {
    bob.writeUInt16(obj.bufferObjectId());
    obj.writeTo(bob);
  }

  public static BufferObject readIdentifiedFrom(BufferObjectBuilder bob) {
    short id = bob.readUInt16();
    BufferObject obj = null;
    switch (id) {
      case RPG_CHARACTER_ID:
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