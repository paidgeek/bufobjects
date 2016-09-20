package rpg.inventory;


// Generated with https://github.com/paidgeek/bufobjects


import rpg.BufferObject;
import rpg.BufferObjects;
import rpg.BufferObjectBuilder;

@SuppressWarnings("all")
public class Armor
extends rpg.inventory.Item{


protected long defense;


public Armor() {
  reset();
}

public Armor(long defense,String name,byte quality,long cost)
{this.defense = defense;this.name = name;this.quality = quality;this.cost = cost;}

public short bufferObjectId() {
  return 3;
}

public int size() {
  int size = super.size();

size += 8; // size for "u64"
  
return size;
}

public void reset() {
super.reset();this.defense = 0;

}

public Armor copy() {
  
Armor newCopy = new Armor();
newCopy.defense = this.defense;newCopy.name = this.name;newCopy.quality = this.quality;newCopy.cost = this.cost;
return newCopy;
}

public void copyTo(BufferObject obj) {
  Armor dst = (Armor) obj;
  
dst.defense = this.defense;dst.name = this.name;dst.quality = this.quality;dst.cost = this.cost;
}

public long
  getDefense() {
    return this.defense;
  }

  public void setDefense(long defense) {
    this.defense = defense;
  }




public void writeTo(BufferObjectBuilder bob) {
{
    bob.writeUInt64(this.defense);
  
  }{
    bob.writeString(this.name);
  
  }{
    bob.writeUInt8(this.quality);
  
  }{
    bob.writeUInt64(this.cost);
  
  }
}

public void readFrom(BufferObjectBuilder bob) {
{
    this.defense = bob.readUInt64();
  
  }{
    this.name = bob.readString();
  
  }{
    this.quality = bob.readUInt8();
  
  }{
    this.cost = bob.readUInt64();
  
  }
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