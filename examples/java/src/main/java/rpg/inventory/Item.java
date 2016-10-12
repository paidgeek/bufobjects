

  
    
      
    
  

  
    
      
    
  

  


  package rpg.inventory;


// Generated with https://github.com/paidgeek/bufobjects

import rpg.BufferObject;
import rpg.BufferBuilder;

@SuppressWarnings("all")
public abstract class Item
extends BufferObject{

protected String name;protected byte quality;protected long cost;
private int _cachedSize;

public int size() {
  if(_cachedSize != 0) {
    return _cachedSize;
  }
  _cachedSize = 0;


    _cachedSize += BufferBuilder.getStringSize(this.name);
  _cachedSize += 1; // size for "u8"
  _cachedSize += 8; // size for "u64"
  
return _cachedSize;
}

public void clear() {
this.name = "";this.quality = 0;this.cost = 0;

_cachedSize = 0;
}

public String getName() {
    _cachedSize = 0;
    return this.name;
  }

  public void setName(String name) {
    this.name = name;
    _cachedSize = 0;
  }

public byte getQuality() {
    _cachedSize = 0;
    return this.quality;
  }

  public void setQuality(byte quality) {
    this.quality = quality;
    _cachedSize = 0;
  }

public long getCost() {
    _cachedSize = 0;
    return this.cost;
  }

  public void setCost(long cost) {
    this.cost = cost;
    _cachedSize = 0;
  }







}
