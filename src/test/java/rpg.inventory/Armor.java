package rpg.inventory;


// Generated with https://github.com/paidgeek/bufobjects


import rpg.BufferObject;
import rpg.BufferObjects;

@SuppressWarnings("all")
public class Armor
extends rpg.inventory.Item{


protected long defense;




  
    
      
    
  
    
  
    
  
public Armor() {
  reset();
}

public Armor(long defense,String name,byte quality,long cost)
{this.defense = defense;this.name = name;this.quality = quality;this.cost = cost;}

public int getBufferObjectId() {
  return 3;
}

public void reset() {
super.reset();this.defense = 0;

}

public Armor copy() {
Armor newCopy = new Armor();

newCopy.defense = this.defense;newCopy.name = this.name;newCopy.quality = this.quality;newCopy.cost = this.cost;
return newCopy;

}

public long
  getDefense() {
    return this.defense;
  }

  public void setDefense(long defense) {
    this.defense = defense;
  }




public int writeTo(byte[] b, int off) {
{
    b[off++] = (byte)this.defense;
b[off++] = (byte)(this.defense >> 8);
b[off++] = (byte)(this.defense >> 16);
b[off++] = (byte)(this.defense >> 24);
b[off++] = (byte)(this.defense >> 32);
b[off++] = (byte)(this.defense >> 40);
b[off++] = (byte)(this.defense >> 48);
b[off++] = (byte)(this.defense >> 56);
  
  }
return off;
}

public int readFrom(byte[] b, int off) {
{
    this.defense =
(((long)b[off++] & 0xFF)         |
(((long)b[off++] & 0xFF) << 8)   |
(((long)b[off++] & 0xFF) << 16)  |
(((long)b[off++] & 0xFF) << 24)  |
(((long)b[off++] & 0xFF) << 32)  |
(((long)b[off++] & 0xFF) << 40)  |
(((long)b[off++] & 0xFF) << 48)  |
(((long)b[off++] & 0xFF) << 56));
  
  }
return off;
}

public static Builder newBuilder() {
return new Builder();
}


public static class Builder {

private long defense;
private String name;
private byte quality;
private long cost;



  public Builder setDefense(long defense) {
    this.defense = defense;
    return this;
  }
  
  public Builder setName(String name) {
    this.name = name;
    return this;
  }
  
  public Builder setQuality(byte quality) {
    this.quality = quality;
    return this;
  }
  
  public Builder setCost(long cost) {
    this.cost = cost;
    return this;
  }
  

  public Armor build() {
    return new Armor(
this.defense,this.name,this.quality,this.cost);
  }

}


}