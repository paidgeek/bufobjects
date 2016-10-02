

  
    
      
    
  

  
    
      
    
  

  


  package rpg.inventory;


// Generated with https://github.com/paidgeek/bufobjects

import rpg.BufferObject;
import rpg.BufferBuilder;

@SuppressWarnings("all")
public abstract class Item
extends BufferObject{

protected String name;protected byte quality;protected long cost;

public int size() {
  int size = 0;


    size += BufferBuilder.getStringSize(this.name);
  size += 1; // size for "u8"
  size += 8; // size for "u64"
  
return size;
}

public void reset() {
this.name = "";this.quality = 0;this.cost = 0;

}

public String getName() {
    return this.name;
  }

  public void setName(String name) {
    this.name = name;
  }

public byte getQuality() {
    return this.quality;
  }

  public void setQuality(byte quality) {
    this.quality = quality;
  }

public long getCost() {
    return this.cost;
  }

  public void setCost(long cost) {
    this.cost = cost;
  }







public abstract void writeJsonTo(java.io.OutputStream os) throws java.io.IOException;

}
