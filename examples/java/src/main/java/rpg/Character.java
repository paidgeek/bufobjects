

  
    
      
    
  

  


  package rpg;


// Generated with https://github.com/paidgeek/bufobjects


import rpg.BufferObject;
import rpg.BufferBuilder;

@SuppressWarnings("all")
public class Character
extends BufferObject{

protected String name;protected rpg.Position position;protected float speed;protected rpg.inventory.Inventory bag;protected java.util.Map<String, rpg.inventory.Item> equipment;protected double[] buffs;
    public static final int BUFFS_LENGTH = 8;
  

private int _cachedSize;

public Character() {
  clear();
}

public Character(String name,rpg.Position position,float speed,rpg.inventory.Inventory bag,java.util.Map<String, rpg.inventory.Item> equipment,double[] buffs)
{this.name = name;this.position = position;this.speed = speed;this.bag = bag;this.equipment = equipment;this.buffs = buffs;}

public void init(String name,rpg.Position position,float speed,rpg.inventory.Inventory bag,java.util.Map<String, rpg.inventory.Item> equipment,double[] buffs)
{this.name = name;this.position = position;this.speed = speed;this.bag = bag;this.equipment = equipment;this.buffs = buffs;
_cachedSize = 0;
}

public short bufferObjectId() {
  return RPG_CHARACTER_ID;
}

public void clear() {
this.name = "";if (this.position != null) {
      this.position.clear();
    }this.speed = 0.0f;this.bag = null;if(this.equipment != null) {
      this.equipment.clear();
    }this.buffs = new double[BUFFS_LENGTH];
    

_cachedSize = 0;
}

public Character copy() {
  
Character newCopy = new Character();
newCopy.name = this.name;if(this.position != null) {
      newCopy.position = (rpg.Position)this.position.copy();
    }newCopy.speed = this.speed;if(this.bag != null) {
      newCopy.bag = (rpg.inventory.Inventory)this.bag.copy();
    }newCopy.equipment = this.equipment;for(int i = 0; i < BUFFS_LENGTH; i++) {newCopy.buffs[i] = this.buffs[i];}
newCopy._cachedSize = _cachedSize;
return newCopy;
}

public void copyTo(BufferObject obj) {
  Character dst = (Character) obj;
  
dst.name = this.name;if(this.position != null) {
      this.position.copyTo(dst.position);
    }dst.speed = this.speed;if(this.bag != null) {
      this.bag.copyTo(dst.bag);
    }dst.equipment = this.equipment;for(int i = 0; i < BUFFS_LENGTH; i++) {dst.buffs[i] = this.buffs[i];}
  dst._cachedSize = _cachedSize;
}

public int size() {
  if(_cachedSize != 0) {
    return _cachedSize;
  }
  _cachedSize = 0;


    _cachedSize += BufferBuilder.getStringSize(this.name);
  
    
      _cachedSize += rpg.Position.SIZE;
    
  _cachedSize += 4; // size for "f32"
  
    
      _cachedSize += 1; // +1 for "is null" byte
      if(this.bag != null) {
      _cachedSize += this.bag.size();
      // this comment seems to fix a jtwig bug "[]"
      
      }
    
  _cachedSize += BufferBuilder.getVarUInt32Size(this.equipment.size());

    

    
        for(java.util.Map.Entry<String, rpg.inventory.Item> e : this.equipment.entrySet()) {
        
          _cachedSize += BufferBuilder.getStringSize(e.getKey());
        
          if(e.getValue() != null) {
        _cachedSize += e.getValue().size();
            // this comment seems to fix a jtwig bug ""
            
              
                _cachedSize += 2; // size of bufferObjectId
              
            
          }
        }
      
    if(this.buffs == null) {
    
      this.buffs = new double[BUFFS_LENGTH];
    
    }
    _cachedSize += BUFFS_LENGTH * 8;
    
return _cachedSize;
}

public void writeTo(BufferBuilder bb) {
  int needed = size();
  if(bb.getRemaining() < needed) {
    bb.growBuffer(needed);
  }
{
    bb.writeString(this.name);
  
  }{
    if(this.position == null) {
        this.position = new rpg.Position();
      }
      this.position.writeTo(bb);
  
  }{
    bb.writeFloat32(this.speed);
  
  }{
    if(this.bag == null) {
        bb.writeUInt8((byte) 0x80);
      } else {
        bb.writeUInt8((byte) 0x81);
        // this comment seems to fix a jtwig bug []
        
        this.bag.writeTo(bb);
      }
  
  }{if(this.equipment == null) {
      bb.writeVarUInt32(0);
    } else {
      int size = this.equipment.size();
      bb.writeVarUInt32(size);
      String key;
      rpg.inventory.Item value;
      for(java.util.Map.Entry<String, rpg.inventory.Item> e : this.equipment.entrySet()) {
        key = e.getKey();
        value = e.getValue();
        bb.writeString(key);
        if(value == null) {
        throw new java.lang.NullPointerException("Collection elements cannot be null");
      }
      // this comment seems to fix a jtwig bug [com.moybl.sidl.ast.ClassDefinition@4edde6e5, com.moybl.sidl.ast.ClassDefinition@70177ecd]
      
        bb.writeUInt16(value.bufferObjectId());
      
      value.writeTo(bb);
      }
    }
  
  }{
    if(this.buffs == null) {
      this.buffs = new double[BUFFS_LENGTH];
    }
    for(int i = 0; i < BUFFS_LENGTH; i++) {
      bb.writeFloat64(this.buffs[i]);
    }
  }
}

public void readFrom(BufferBuilder bb) {
{
    this.name = bb.readString();
  
  }{
    if (this.position == null) {
        this.position = new rpg.Position();
      }
      this.position.readFrom(bb);
  
  }{
    this.speed = bb.readFloat32();
  
  }{
    // this comment seems to fix a jtwig bug "[]"
      
        if (bb.readUInt8() == (byte) 0x81) {
          if (this.bag == null) {
            this.bag = new rpg.inventory.Inventory();
          }
          this.bag.readFrom(bb);
        } else {
          this.bag = null;
        }
  
  }{int size = bb.readVarUInt32();
    if(this.equipment == null) {
      this.equipment = new java.util.HashMap<String, rpg.inventory.Item>(size);
    } else {
      this.equipment.clear();
    }
    String key;
    rpg.inventory.Item value = null;
    for(int i = 0; i < size; i++) {
      key = bb.readString();
      // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@4edde6e5, com.moybl.sidl.ast.ClassDefinition@70177ecd]"
      
        short id = bb.readUInt16();
        switch(id) {
            case RPG_INVENTORY_WEAPON_ID:
            value = new rpg.inventory.Weapon();
            value.readFrom(bb);
            break;
            case RPG_INVENTORY_ARMOR_ID:
            value = new rpg.inventory.Armor();
            value.readFrom(bb);
            break;}
      this.equipment.put(key, value);
    }
  
  }{
    if(this.buffs == null) {
      this.buffs = new double[BUFFS_LENGTH];
    }
    for(int i = 0; i < BUFFS_LENGTH; i++) {
      this.buffs[i] = bb.readFloat64();
    }
  }
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

public rpg.Position getPosition() {
    _cachedSize = 0;
    return this.position;
  }

  public void setPosition(rpg.Position position) {
    this.position = position;
    _cachedSize = 0;
  }

public float getSpeed() {
    _cachedSize = 0;
    return this.speed;
  }

  public void setSpeed(float speed) {
    this.speed = speed;
    _cachedSize = 0;
  }

public rpg.inventory.Inventory getBag() {
    _cachedSize = 0;
    return this.bag;
  }

  public void setBag(rpg.inventory.Inventory bag) {
    this.bag = bag;
    _cachedSize = 0;
  }

public java.util.Map<String, rpg.inventory.Item> getEquipment() {
    _cachedSize = 0;
    return this.equipment;
  }

  public void setEquipment(java.util.Map<String, rpg.inventory.Item> equipment) {
    this.equipment = equipment;
    _cachedSize = 0;
  }


  public rpg.inventory.Item getEquipment(String key) {
    _cachedSize = 0;
    return this.equipment.get(key);
  }

  public void setEquipment(String key, rpg.inventory.Item value) {
    _cachedSize = 0;
    this.equipment.put(key, value);
  }
public double[] getBuffs() {
    _cachedSize = 0;
    return this.buffs;
  }

  public void setBuffs(double[] buffs) {
    this.buffs = buffs;
    _cachedSize = 0;
  }


  public double getBuffs(int index) {
    _cachedSize = 0;
    return this.buffs[index];
  }

  public void setBuffs(int index, double value) {
    _cachedSize = 0;
    this.buffs[index] = value;
  }




    public boolean hasBag() { return bag != null; }
  


public void writeJsonTo(java.io.OutputStream os) throws java.io.IOException {
  os.write('{');



int i = 0;
final java.math.BigInteger two = java.math.BigInteger.valueOf(2);
os.write(BufferBuilder.getStringBytes("\"name\":"));
    os.write( BufferBuilder.getStringBytes("\"" + this.name + "\"") );
  

  
    os.write(',');
  

os.write(BufferBuilder.getStringBytes("\"position\":"));
    this.position.writeJsonTo(os);
  

  
    os.write(',');
  

os.write(BufferBuilder.getStringBytes("\"speed\":"));
    os.write(BufferBuilder.getStringBytes(String.valueOf(this.speed).replaceAll("\\.0+$", "")));
  

  
    os.write(',');
  

os.write(BufferBuilder.getStringBytes("\"bag\":"));
    if(this.bag == null) {
        os.write(BufferBuilder.getStringBytes("null"));
      } else {
        this.bag.writeJsonTo(os);
      }
  

  
    os.write(',');
  

os.write(BufferBuilder.getStringBytes("\"equipment\":"));os.write('{');
    if(this.equipment != null) {
      int size = this.equipment.size();
      i = 0;
      String key;
      rpg.inventory.Item value;
      for(java.util.Map.Entry<String, rpg.inventory.Item> e : this.equipment.entrySet()) {
        key = e.getKey();
        value = e.getValue();
        
        os.write( BufferBuilder.getStringBytes("\"" + key + "\"") );
        
        os.write(':');
        if(value == null) {
        os.write(BufferBuilder.getStringBytes("null"));
      } else {
        value.writeJsonTo(os);
      }
        if(++i < size) {
          os.write(',');
        }
      }
    }
    os.write('}');
  

  
    os.write(',');
  

os.write(BufferBuilder.getStringBytes("\"buffs\":"));
    if(this.buffs == null) {
      this.buffs = new double[BUFFS_LENGTH];
    }
    os.write('[');
    for(i = 0; i < BUFFS_LENGTH; i++) {
      os.write(BufferBuilder.getStringBytes(String.valueOf(this.buffs[i]).replaceAll("\\.0+$", "")));
      if(i < BUFFS_LENGTH - 1) {
        os.write(',');
      }
    }
    os.write(']');

  


os.write('}');

}

public static void writeDirectTo(BufferBuilder bb,String name,rpg.Position position,float speed,rpg.inventory.Inventory bag,java.util.Map<String, rpg.inventory.Item> equipment,double[] buffs) {
  {
    bb.writeString(name);
  
  }{
    if(position == null) {
        position = new rpg.Position();
      }
      position.writeTo(bb);
  
  }{
    bb.writeFloat32(speed);
  
  }{
    if(bag == null) {
        bb.writeUInt8((byte) 0x80);
      } else {
        bb.writeUInt8((byte) 0x81);
        // this comment seems to fix a jtwig bug []
        
        bag.writeTo(bb);
      }
  
  }{if(equipment == null) {
      bb.writeVarUInt32(0);
    } else {
      int size = equipment.size();
      bb.writeVarUInt32(size);
      String key;
      rpg.inventory.Item value;
      for(java.util.Map.Entry<String, rpg.inventory.Item> e : equipment.entrySet()) {
        key = e.getKey();
        value = e.getValue();
        bb.writeString(key);
        if(value == null) {
        bb.writeUInt8((byte) 0x80);
      } else {
        bb.writeUInt8((byte) 0x81);
        // this comment seems to fix a jtwig bug [com.moybl.sidl.ast.ClassDefinition@4edde6e5, com.moybl.sidl.ast.ClassDefinition@70177ecd]
        
          bb.writeUInt16(value.bufferObjectId());
        
        value.writeTo(bb);
      }
      }
    }
  
  }{
    if(buffs == null) {
      buffs = new double[BUFFS_LENGTH];
    }
    for(int i = 0; i < BUFFS_LENGTH; i++) {
      bb.writeFloat64(buffs[i]);
    }
  }
}

public static void writeDirectIdentifiedTo(BufferBuilder bb,String name,rpg.Position position,float speed,rpg.inventory.Inventory bag,java.util.Map<String, rpg.inventory.Item> equipment,double[] buffs) {
  bb.writeUInt16(RPG_CHARACTER_ID);
  writeDirectTo(bb,name,position,speed,bag,equipment,buffs);
}

public static Builder newBuilder() {
  return new Builder();
}


public static class Builder {

private String name;
private rpg.Position position;
private float speed;
private rpg.inventory.Inventory bag;
private java.util.Map<String, rpg.inventory.Item> equipment;
private double[] buffs;



  public Builder setName(String name) {
    this.name = name;
    return this;
  }
  
  public Builder setPosition(rpg.Position position) {
    this.position = position;
    return this;
  }
  
  public Builder setSpeed(float speed) {
    this.speed = speed;
    return this;
  }
  
  public Builder setBag(rpg.inventory.Inventory bag) {
    this.bag = bag;
    return this;
  }
  
  public Builder setEquipment(java.util.Map<String, rpg.inventory.Item> equipment) {
    this.equipment = equipment;
    return this;
  }
  public Builder setEquipment(String key, rpg.inventory.Item value) {
    if(this.equipment == null) {
      this.equipment = new java.util.HashMap<String, rpg.inventory.Item>();
    }
    this.equipment.put(key, value);
    return this;
  }
  
  public Builder setBuffs(double ...buffs) {
    if(buffs.length == BUFFS_LENGTH) {
      this.buffs = buffs;
    } else if(buffs.length < BUFFS_LENGTH) {
      this.buffs = new double[BUFFS_LENGTH];
      System.arraycopy(buffs, 0, this.buffs, 0, buffs.length);
    } else {
      throw new IndexOutOfBoundsException();
    }
    return this;
  }
  public Builder setBuffs(int index, double value) {
    if(this.buffs == null) {
      this.buffs = new double[BUFFS_LENGTH];
    }
    this.buffs[0] = value;
    return this;
  }
  

  public Character build() {
    return new Character(
this.name,this.position,this.speed,this.bag,this.equipment,this.buffs);
  }

}


}
