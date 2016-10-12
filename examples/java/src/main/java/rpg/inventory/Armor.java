

  
    
      
    
  

  
    
      
    
  

  


  package rpg.inventory;


// Generated with https://github.com/paidgeek/bufobjects


import rpg.BufferObject;
import rpg.BufferBuilder;

@SuppressWarnings("all")
public class Armor
extends rpg.inventory.Item{

protected long defense;

private int _cachedSize;

public Armor() {
  clear();
}

public Armor(long defense,String name,byte quality,long cost)
{this.defense = defense;this.name = name;this.quality = quality;this.cost = cost;}

public void init(long defense,String name,byte quality,long cost)
{this.defense = defense;this.name = name;this.quality = quality;this.cost = cost;
_cachedSize = 0;
}

public short bufferObjectId() {
  return RPG_INVENTORY_ARMOR_ID;
}

public void clear() {
super.clear();this.defense = 0;

_cachedSize = 0;
}

public Armor copy() {
  
Armor newCopy = new Armor();
newCopy.defense = this.defense;newCopy.name = this.name;newCopy.quality = this.quality;newCopy.cost = this.cost;
newCopy._cachedSize = _cachedSize;
return newCopy;
}

public void copyTo(BufferObject obj) {
  Armor dst = (Armor) obj;
  
dst.defense = this.defense;dst.name = this.name;dst.quality = this.quality;dst.cost = this.cost;
  dst._cachedSize = _cachedSize;
}

public int size() {
  if(_cachedSize != 0) {
    return _cachedSize;
  }
  _cachedSize = super.size();

_cachedSize += 8; // size for "u64"
  
return _cachedSize;
}

public void writeTo(BufferBuilder bb) {
  int needed = size();
  if(bb.getRemaining() < needed) {
    bb.growBuffer(needed);
  }
{
    bb.writeUInt64(this.defense);
  
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
    this.defense = bb.readUInt64();
  
  }{
    this.name = bb.readString();
  
  }{
    this.quality = bb.readUInt8();
  
  }{
    this.cost = bb.readUInt64();
  
  }
_cachedSize = 0;
}

public long getDefense() {
    _cachedSize = 0;
    return this.defense;
  }

  public void setDefense(long defense) {
    this.defense = defense;
    _cachedSize = 0;
  }







public void writeJsonTo(java.io.OutputStream os) throws java.io.IOException {
  os.write('{');


  os.write(BufferBuilder.getStringBytes("\"_id\":"));os.write(BufferBuilder.getStringBytes(String.valueOf(this.bufferObjectId())));
    os.write(',');
  


int i = 0;
final java.math.BigInteger two = java.math.BigInteger.valueOf(2);
os.write(BufferBuilder.getStringBytes("\"defense\":"));
    if(this.defense >= 0) {
      os.write( BufferBuilder.getStringBytes("\"" + String.valueOf(this.defense) + "\"") );
    } else {
      os.write(BufferBuilder.getStringBytes("\"" + two.multiply(java.math.BigInteger.valueOf(Long.MAX_VALUE)).add(two).add(java.math.BigInteger.valueOf(this.defense)).toString() + "\""));
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

public static void writeDirectTo(BufferBuilder bb,long defense,String name,byte quality,long cost) {
  {
    bb.writeUInt64(defense);
  
  }{
    bb.writeString(name);
  
  }{
    bb.writeUInt8(quality);
  
  }{
    bb.writeUInt64(cost);
  
  }
}

public static void writeDirectIdentifiedTo(BufferBuilder bb,long defense,String name,byte quality,long cost) {
  bb.writeUInt16(RPG_INVENTORY_ARMOR_ID);
  writeDirectTo(bb,defense,name,quality,cost);
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
