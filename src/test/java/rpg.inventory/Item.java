package rpg.inventory;

// Generated with https://github.com/paidgeek/bufobjects

import rpg.BufferObject;

public abstract class Item
  extends BufferObject {

  protected String name;
  protected byte quality;
  protected long cost;

  public void reset() {
    this.name = "";
    this.quality = 0;
    this.cost = 0;

  }

  public String
  getName() {
    return this.name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public byte
  getQuality() {
    return this.quality;
  }

  public void setQuality(byte quality) {
    this.quality = quality;
  }

  public long
  getCost() {
    return this.cost;
  }

  public void setCost(long cost) {
    this.cost = cost;
  }

}