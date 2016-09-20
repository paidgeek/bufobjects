package rpg.inventory;


// Generated with https://github.com/paidgeek/bufobjects


import rpg.BufferObject;
import rpg.BufferObjects;
import rpg.BufferObjectBuilder;

@SuppressWarnings("all")
public class Weapon
extends rpg.inventory.Item{


protected long damage;


public Weapon() {
  reset();
}

public Weapon(long damage,String name,byte quality,long cost)
{this.damage = damage;this.name = name;this.quality = quality;this.cost = cost;}

public short bufferObjectId() {
  return 2;
}

public int size() {
  int size = super.size();

size += 8; // size for "u64"
  
return size;
}

public void reset() {
super.reset();this.damage = 0;

}

public Weapon copy() {
  
Weapon newCopy = new Weapon();
newCopy.damage = this.damage;newCopy.name = this.name;newCopy.quality = this.quality;newCopy.cost = this.cost;
return newCopy;
}

public void copyTo(BufferObject obj) {
  Weapon dst = (Weapon) obj;
  
dst.damage = this.damage;dst.name = this.name;dst.quality = this.quality;dst.cost = this.cost;
}

public long
  getDamage() {
    return this.damage;
  }

  public void setDamage(long damage) {
    this.damage = damage;
  }




public void writeTo(BufferObjectBuilder bob) {
{
    bob.writeUInt64(this.damage);
  
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
    this.damage = bob.readUInt64();
  
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

private long damage;
private String name;
private byte quality;
private long cost;



  public Builder setDamage(long damage) {
    this.damage = damage;
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
  

  public Weapon build() {
    return new Weapon(
this.damage,this.name,this.quality,this.cost);
  }

}


}