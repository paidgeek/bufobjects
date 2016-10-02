

  
    
      
    
  

  
    
      
    
  

  


  package rpg.inventory;


// Generated with https://github.com/paidgeek/bufobjects


import rpg.BufferObject;
import rpg.BufferBuilder;

@SuppressWarnings("all")
public class Weapon
extends rpg.inventory.Item{

protected long damage;

public Weapon() {
  reset();
}

public Weapon(long damage,String name,byte quality,long cost)
{this.damage = damage;this.name = name;this.quality = quality;this.cost = cost;}

public void init(long damage,String name,byte quality,long cost)
{this.damage = damage;this.name = name;this.quality = quality;this.cost = cost;}

public short bufferObjectId() {
  return RPG_INVENTORY_WEAPON_ID;
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

public int size() {
  int size = super.size();

size += 8; // size for "u64"
  
return size;
}

public void writeTo(BufferBuilder bb) {
  int needed = size();
  if(bb.getRemaining() < needed) {
    bb.growBuffer(needed);
  }
{
    bb.writeUInt64(this.damage);
  
  }{
    bb.writeString(this.name);
  
  }{
    bb.writeUInt8(this.quality);
  
  }{
    bb.writeUInt64(this.cost);
  
  }
}

public void readFrom(BufferBuilder bb) {
{
    this.damage = bb.readUInt64();
  
  }{
    this.name = bb.readString();
  
  }{
    this.quality = bb.readUInt8();
  
  }{
    this.cost = bb.readUInt64();
  
  }
}

public long getDamage() {
    return this.damage;
  }

  public void setDamage(long damage) {
    this.damage = damage;
  }







public void writeJsonTo(java.io.OutputStream os) throws java.io.IOException {
  os.write('{');


  os.write(BufferBuilder.getStringBytes("\"_id\":"));os.write(BufferBuilder.getStringBytes(String.valueOf(this.bufferObjectId())));
    os.write(',');
  


int i = 0;
final java.math.BigInteger two = java.math.BigInteger.valueOf(2);
os.write(BufferBuilder.getStringBytes("\"damage\":"));
    if(this.damage >= 0) {
      os.write( BufferBuilder.getStringBytes("\"" + String.valueOf(this.damage) + "\"") );
    } else {
      os.write(BufferBuilder.getStringBytes("\"" + two.multiply(java.math.BigInteger.valueOf(Long.MAX_VALUE)).add(two).add(java.math.BigInteger.valueOf(this.damage)).toString() + "\""));
    }
  

  
    os.write(',');
  

os.write(BufferBuilder.getStringBytes("\"name\":"));
    os.write( BufferBuilder.getStringBytes("\"" + this.name + "\"") );
  

  
    os.write(',');
  

os.write(BufferBuilder.getStringBytes("\"quality\":"));
    os.write( BufferBuilder.getStringBytes( String.valueOf((short)(this.quality & 0xFF) )) );
  

  
    os.write(',');
  

os.write(BufferBuilder.getStringBytes("\"cost\":"));
    if(this.cost >= 0) {
      os.write( BufferBuilder.getStringBytes("\"" + String.valueOf(this.cost) + "\"") );
    } else {
      os.write(BufferBuilder.getStringBytes("\"" + two.multiply(java.math.BigInteger.valueOf(Long.MAX_VALUE)).add(two).add(java.math.BigInteger.valueOf(this.cost)).toString() + "\""));
    }
  

  


os.write('}');

}

public static void writeDirectTo(BufferBuilder bb,long damage,String name,byte quality,long cost) {
  {
    bb.writeUInt64(damage);
  
  }{
    bb.writeString(name);
  
  }{
    bb.writeUInt8(quality);
  
  }{
    bb.writeUInt64(cost);
  
  }
}

public static void writeDirectIdentifiedTo(BufferBuilder bb,long damage,String name,byte quality,long cost) {
  bb.writeUInt16(RPG_INVENTORY_WEAPON_ID);
  writeDirectTo(bb,damage,name,quality,cost);
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
