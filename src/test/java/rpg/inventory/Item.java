package rpg.inventory;


// Generated with https://github.com/paidgeek/bufobjects

import rpg.BufferObject;
import rpg.BufferObjectBuilder;

@SuppressWarnings("all")
public abstract class Item
extends BufferObject{

protected byte[] name;protected byte quality;protected long cost;

public int size() {
  int size = 0;


    size += BufferObjectBuilder.getStringSize(this.name);
  size += 1; // size for "u8"
  size += 8; // size for "u64"
  
return size;
}

public void reset() {
this.name = new byte[0];this.quality = 0;this.cost = 0;

}

public String
  getName() {

    return BufferObjectBuilder.getStringFromBytes(this.name);

  }

  public void setName(String name) {

    this.name = BufferObjectBuilder.getStringBytes(name);

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