package rpg.inventory;

// Generated with https://github.com/paidgeek/bufobjects

import rpg.BufferObject;
import rpg.BufferObjectBuilder;

@SuppressWarnings("all")
public class Inventory
  extends BufferObject {

  protected int capacity;
  protected java.util.List<rpg.inventory.Item> items;

  public Inventory() {
    reset();
  }

  public Inventory(int capacity, java.util.List<rpg.inventory.Item> items) {
    this.capacity = capacity;
    this.items = items;
  }

  public short bufferObjectId() {
    return RPG_INVENTORY_INVENTORY_ID;
  }

  public void reset() {
    this.capacity = 0;
    this.items = new java.util.ArrayList<>();

  }

  public Inventory copy() {

    Inventory newCopy = new Inventory();
    newCopy.capacity = this.capacity;
    for (int i = 0; i < this.items.size(); i++) {
      rpg.inventory.Item e = this.items.get(i);
      if (e != null) {
        newCopy.items.add((rpg.inventory.Item) e.copy());
      }
    }
    return newCopy;
  }

  public void copyTo(BufferObject obj) {
    Inventory dst = (Inventory) obj;

    dst.capacity = this.capacity;
    for (int i = 0; i < this.items.size(); i++) {
      rpg.inventory.Item e = this.items.get(i);
      if (e != null) {
        ((rpg.inventory.Item) e).copyTo(e);
      }
    }
  }

  public int size() {
    int size = 0;

    size += 4; // size for "u32"
    size += BufferObjectBuilder.getVarUInt32Size(this.items.size());
    for (int i = 0; i < this.items.size(); i++) {
      if (this.items.get(i) != null) {
        size += this.items.get(i).size();
        // this comment seems to fix a jtwig bug ""

        size += 2; // size of bufferObjectId

      }
    }
    size += this.items.size(); // for "is null" byte

    return size;
  }

  public void writeTo(BufferObjectBuilder bob) {
    int needed = size();
    if (bob.getRemaining() < needed) {
      bob.growBuffer(needed);
    }
    {
      bob.writeUInt32(this.capacity);

    }
    {
      int size = this.items.size();
      bob.writeVarUInt32(size);
      for (int i = 0; i < size; i++) {
        rpg.inventory.Item e = this.items.get(i);
        if (e == null) {
          bob.writeUInt8((byte) 0x80);
        } else {
          bob.writeUInt8((byte) 0x81);
          // this comment seems to fix a jtwig bug [com.moybl.sidl.ast.TypeDefinition@30dae81, com.moybl.sidl.ast.TypeDefinition@1b2c6ec2]

          bob.writeUInt16(e.bufferObjectId());

          e.writeTo(bob);
        }
      }

    }
  }

  public void readFrom(BufferObjectBuilder bob) {
    {
      this.capacity = bob.readUInt32();

    }
    {
      int size = bob.readVarUInt32();
      this.items = new java.util.ArrayList<rpg.inventory.Item>(size);
      rpg.inventory.Item e = null;
      for (int i = 0; i < size; i++) {
        // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.TypeDefinition@30dae81, com.moybl.sidl.ast.TypeDefinition@1b2c6ec2]"

        if (bob.readUInt8() == (byte) 0x81) {
          short id = bob.readUInt16();
          switch (id) {
            case RPG_INVENTORY_WEAPON_ID:
              e = new rpg.inventory.Weapon();
              break;
            case RPG_INVENTORY_ARMOR_ID:
              e = new rpg.inventory.Armor();
              break;
          }
          e.readFrom(bob);
        } else {
          e = null;
        }
        this.items.add(e);
      }

    }
  }

  public int
  getCapacity() {

    return this.capacity;

  }

  public void setCapacity(int capacity) {

    this.capacity = capacity;

  }

  public java.util.List<rpg.inventory.Item>
  getItems() {

    return this.items;

  }

  public void setItems(java.util.List<rpg.inventory.Item> items) {

    this.items = items;

  }

  public rpg.inventory.Item getItemsAt(int index) {

    return this.items.get(index);

  }

  public void setItemsAt(int index, rpg.inventory.Item value) {

    this.items.set(index, value);

  }

  public static Builder newBuilder() {
    return new Builder();
  }

  public static class Builder {

    private int capacity;
    private java.util.List<rpg.inventory.Item> items;

    public Builder setCapacity(int capacity) {
      this.capacity = capacity;
      return this;
    }

    public Builder setItems(java.util.List<rpg.inventory.Item> items) {
      this.items = items;
      return this;
    }

    public Builder setItems(rpg.inventory.Item... items) {
      this.items = new java.util.ArrayList<rpg.inventory.Item>();
      for (int i = 0; i < items.length; i++) {
        this.items.add(items[i]);
      }
      return this;
    }

    public Builder addItems(rpg.inventory.Item... items) {
      if (this.items == null) {
        this.items = new java.util.ArrayList<rpg.inventory.Item>();
        for (int i = 0; i < items.length; i++) {
          this.items.add(items[i]);
        }
      } else {
        for (int i = 0; i < items.length; i++) {
          this.items.add(items[i]);
        }
      }
      return this;
    }

    public Builder addItems(java.util.List<rpg.inventory.Item> items) {
      if (this.items == null) {
        this.items = new java.util.ArrayList<rpg.inventory.Item>(items);
      } else {
        this.items.addAll(new java.util.ArrayList<rpg.inventory.Item>(items));
      }
      return this;
    }

    public Inventory build() {
      return new Inventory(
        this.capacity, this.items);
    }

  }

}