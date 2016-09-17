package rpg.inventory;

// Generated with https://github.com/paidgeek/bufobjects

import rpg.BufferObject;
import rpg.BufferObjects;

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

  public int getBufferObjectId() {
    return 4;
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

  public int writeTo(byte[] b, int off) {
    {
      b[off++] = (byte) this.capacity;
      b[off++] = (byte) (this.capacity >> 8);
      b[off++] = (byte) (this.capacity >> 16);
      b[off++] = (byte) (this.capacity >> 24);

    }
    {
      int size = this.items.size();
      {
        b[off++] = (byte) size;
        b[off++] = (byte) (size >> 8);
        b[off++] = (byte) (size >> 16);
        b[off++] = (byte) (size >> 24);
      }
      for (int i = 0; i < size; i++) {
        rpg.inventory.Item e = this.items.get(i);
        BufferObjects.writeTo(b, off, e);
      }

    }
    return off;
  }

  public int readFrom(byte[] b, int off) {
    {
      this.capacity = (int) (
        (b[off++] & 0xFF) |
          ((b[off++] & 0xFF) << 8) |
          ((b[off++] & 0xFF) << 16) |
          (b[off++] << 24)
      );

    }
    {
      int size = 0;
      {
        size = (int) (
          (b[off++] & 0xFF) |
            ((b[off++] & 0xFF) << 8) |
            ((b[off++] & 0xFF) << 16) |
            (b[off++] << 24)
        );
      }
      this.items = new java.util.ArrayList<>(size);
      rpg.inventory.Item e = null;
      for (int i = 0; i < size; i++) {
        e = (rpg.inventory.Item) BufferObjects.readFrom(b, off);
        this.items.add(e);
      }

    }
    return off;
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