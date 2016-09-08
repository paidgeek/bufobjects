package rpg.inventory;

public class Inventory {

  private int capacity;
  private java.util.List<rpg.inventory.Item> items;

  public Inventory() {
    reset();
  }

  public Inventory(int capacity, java.util.List<rpg.inventory.Item> items) {
    this.capacity = capacity;
    this.items = items;
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
        newCopy.items.add(e.copy());
      }
    }
    return newCopy;
  }

  public int getCapacity() {
    return this.capacity;
  }

  public void setCapacity(int capacity) {
    this.capacity = capacity;
  }

  public java.util.List<rpg.inventory.Item> getItems() {
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
      return new Inventory(this.capacity, this.items);
    }
  }
}
