package rpg;

// Generated with https://github.com/paidgeek/bufobjects

@SuppressWarnings("all")
public final class BufferObjects {
  public static final int RPG_CHARACTER_ID = 1;
  public static final int RPG_INVENTORY_WEAPON_ID = 2;
  public static final int RPG_INVENTORY_ARMOR_ID = 3;
  public static final int RPG_INVENTORY_INVENTORY_ID = 4;

  public static int writeTo(byte[] b, int off, BufferObject obj) {
    int id = obj.getBufferObjectId();
    {int value = id;
do {
  int bits = value & 0x7F;
  value >>>= 7;
  b[off++] = (byte) (bits + ((value != 0) ? 0x80 : 0));
} while (value != 0);}
    if(obj == null) {
      b[off++] = (byte) 0x80;
    } else {
      b[off++] = (byte) 0x81;
      off = obj.writeTo(b, off);
    }
    return off;
  }

  public static BufferObject readFrom(byte[] b, int off) {
    int id = 0;
    {
      int tmp = b[off++];
int value = 0;
if (tmp >= 0) {
value = tmp;
} else {
value = tmp & 0x7f;
if ((tmp = b[off++]) >= 0) {
value |= tmp << 7;
} else {
value |= (tmp & 0x7f) << 7;
if ((tmp = b[off++]) >= 0) {
value |= tmp << 14;
} else {
value |= (tmp & 0x7f) << 14;
if ((tmp = b[off++]) >= 0) {
value |= tmp << 21;
} else {
value |= (tmp & 0x7f) << 21;
value |= (tmp = b[off++]) << 28;
while (tmp < 0) {
tmp = b[off++];
}
}
}
}
}
id = value;
    }
    BufferObject obj = null;
    switch(id) {case RPG_CHARACTER_ID:
          obj = new rpg.Character();
          obj.readFrom(b, off);
          break;
        case RPG_INVENTORY_WEAPON_ID:
          obj = new rpg.inventory.Weapon();
          obj.readFrom(b, off);
          break;
        case RPG_INVENTORY_ARMOR_ID:
          obj = new rpg.inventory.Armor();
          obj.readFrom(b, off);
          break;
        case RPG_INVENTORY_INVENTORY_ID:
          obj = new rpg.inventory.Inventory();
          obj.readFrom(b, off);
          break;
        }
    return obj;
  }

}