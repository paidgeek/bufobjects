

  
    
      
    
  

  
    
      
    
  

  


  package rpg.inventory;


// Generated with https://github.com/paidgeek/bufobjects


import rpg.BufferObject;
import rpg.BufferBuilder;

@SuppressWarnings("all")
public class Inventory
extends BufferObject{

protected int capacity;protected java.util.List<rpg.inventory.Item> items;

private int _cachedSize;

public Inventory() {
  clear();
}

public Inventory(int capacity,java.util.List<rpg.inventory.Item> items)
{this.capacity = capacity;this.items = items;}

public void init(int capacity,java.util.List<rpg.inventory.Item> items)
{this.capacity = capacity;this.items = items;
_cachedSize = 0;
}

public short bufferObjectId() {
  return RPG_INVENTORY_INVENTORY_ID;
}

public void clear() {
this.capacity = 0;if(this.items != null) {
      this.items.clear();
    }

_cachedSize = 0;
}

public Inventory copy() {
  
Inventory newCopy = new Inventory();
newCopy.capacity = this.capacity;for(int i = 0; i < this.items.size(); i++) {rpg.inventory.Item e = this.items.get(i);
        if(e != null) {
          newCopy.items.add((rpg.inventory.Item)e.copy());
        }}
newCopy._cachedSize = _cachedSize;
return newCopy;
}

public void copyTo(BufferObject obj) {
  Inventory dst = (Inventory) obj;
  
dst.capacity = this.capacity;for(int i = 0; i < this.items.size(); i++) {rpg.inventory.Item e = this.items.get(i);
      if(e != null) {
        ((rpg.inventory.Item)e).copyTo(e);
      }}
  dst._cachedSize = _cachedSize;
}

public int size() {
  if(_cachedSize != 0) {
    return _cachedSize;
  }
  _cachedSize = 0;

_cachedSize += 4; // size for "u32"
  if (this.items == null) {
    _cachedSize += 1; // BufferBuilder.getVarUInt32Size(0)
    } else {
    _cachedSize += BufferBuilder.getVarUInt32Size(this.items.size());
      
          for(int i = 0; i < this.items.size(); i++) {
          if(this.items.get(i) != null) {
          _cachedSize += this.items.get(i).size();
          // this comment seems to fix a jtwig bug ""
          
            
              _cachedSize += 2; // size of bufferObjectId
            
          
          }
          }
        
      }


  
return _cachedSize;
}

public void writeTo(BufferBuilder bb) {
  int needed = size();
  if(bb.getRemaining() < needed) {
    bb.growBuffer(needed);
  }
{
    bb.writeUInt32(this.capacity);
  
  }{if(this.items == null) {
      bb.writeVarUInt32(0);
    } else {
      int size = this.items.size();
      bb.writeVarUInt32(size);
      for(int i = 0; i < size; i++) {
        rpg.inventory.Item e = this.items.get(i);
        if(e == null) {
        throw new java.lang.NullPointerException("Collection elements cannot be null");
      }
      // this comment seems to fix a jtwig bug [com.moybl.sidl.ast.ClassDefinition@4edde6e5, com.moybl.sidl.ast.ClassDefinition@70177ecd]
      
        bb.writeUInt16(e.bufferObjectId());
      
      e.writeTo(bb);
      }
    }
  }
}

public void readFrom(BufferBuilder bb) {
{
    this.capacity = bb.readUInt32();
  
  }{int size = bb.readVarUInt32();
    if(this.items == null) {
      this.items = new java.util.ArrayList<rpg.inventory.Item>(size);
    } else {
      this.items.clear();
    }
    rpg.inventory.Item e = null;
    for(int i = 0; i < size; i++) {
      // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.ClassDefinition@4edde6e5, com.moybl.sidl.ast.ClassDefinition@70177ecd]"
      
        short id = bb.readUInt16();
        switch(id) {
            case RPG_INVENTORY_WEAPON_ID:
            e = new rpg.inventory.Weapon();
            e.readFrom(bb);
            break;
            case RPG_INVENTORY_ARMOR_ID:
            e = new rpg.inventory.Armor();
            e.readFrom(bb);
            break;}
      this.items.add(e);
    }
  }
_cachedSize = 0;
}

public int getCapacity() {
    _cachedSize = 0;
    return this.capacity;
  }

  public void setCapacity(int capacity) {
    this.capacity = capacity;
    _cachedSize = 0;
  }

public java.util.List<rpg.inventory.Item> getItems() {
    _cachedSize = 0;
    return this.items;
  }

  public void setItems(java.util.List<rpg.inventory.Item> items) {
    this.items = items;
    _cachedSize = 0;
  }


  public rpg.inventory.Item getItems(int index) {
    _cachedSize = 0;
    return this.items.get(index);
  }

  public void setItems(int index, rpg.inventory.Item value) {
    _cachedSize = 0;
    this.items.set(index, value);
  }






public void writeJsonTo(java.io.OutputStream os) throws java.io.IOException {
  os.write('{');



int i = 0;
final java.math.BigInteger two = java.math.BigInteger.valueOf(2);
os.write(BufferBuilder.getStringBytes("\"capacity\":"));
    os.write( BufferBuilder.getStringBytes( String.valueOf((short)(this.capacity & 0xFFFFFFFFL)) ) );
  

  
    os.write(',');
  

os.write(BufferBuilder.getStringBytes("\"items\":"));os.write('[');
    if(this.items != null) {
      int size = this.items.size();
      for(i = 0; i < size; i++) {
        rpg.inventory.Item e = this.items.get(i);
        if(e == null) {
        os.write(BufferBuilder.getStringBytes("null"));
      } else {
        e.writeJsonTo(os);
      }
        if(i < size - 1) {
          os.write(',');
        }
      }
    }
    os.write(']');

  


os.write('}');

}

public static void writeDirectTo(BufferBuilder bb,int capacity,java.util.List<rpg.inventory.Item> items) {
  {
    bb.writeUInt32(capacity);
  
  }{if(items == null) {
      bb.writeVarUInt32(0);
    } else {
      int size = items.size();
      bb.writeVarUInt32(size);
      for(int i = 0; i < size; i++) {
        rpg.inventory.Item e = items.get(i);
        if(e == null) {
        bb.writeUInt8((byte) 0x80);
      } else {
        bb.writeUInt8((byte) 0x81);
        // this comment seems to fix a jtwig bug [com.moybl.sidl.ast.ClassDefinition@4edde6e5, com.moybl.sidl.ast.ClassDefinition@70177ecd]
        
          bb.writeUInt16(e.bufferObjectId());
        
        e.writeTo(bb);
      }
      }
    }
  }
}

public static void writeDirectIdentifiedTo(BufferBuilder bb,int capacity,java.util.List<rpg.inventory.Item> items) {
  bb.writeUInt16(RPG_INVENTORY_INVENTORY_ID);
  writeDirectTo(bb,capacity,items);
}

public static Builder newBuilder() {
  return new Builder();
}


public static class Builder {

private int capacity;
private java.util.List<rpg.inventory.Item> items;



  public Builder setCapacity(int capacity) {
    this.capacity = capacity;
    return this;
  }
  
  public Builder setItems(java.util.List<rpg.inventory.Item> items) {
    this.items = items;
    return this;
  }
  public Builder setItems(rpg.inventory.Item ...items) {
    this.items = new java.util.ArrayList<rpg.inventory.Item>();
    for(int i = 0; i < items.length; i++) {
      this.items.add(items[i]);
    }
    return this;
  }
  public Builder setItems(int index, rpg.inventory.Item value) {
    if(this.items == null) {
      this.items = new java.util.ArrayList<rpg.inventory.Item>();
    }
    this.items.set(0, value);
    return this;
  }
  public Builder addItems(rpg.inventory.Item ...items) {
    if(this.items == null) {
      this.items = new java.util.ArrayList<rpg.inventory.Item>();
      for(int i = 0; i < items.length; i++) {
        this.items.add(items[i]);
      }
    } else {
      for(int i = 0; i < items.length; i++) {
        this.items.add(items[i]);
      }
    }
    return this;
  }
  public Builder addItems(java.util.List<rpg.inventory.Item> items) {
    if(this.items == null) {
      this.items = new java.util.ArrayList<rpg.inventory.Item>(items);
    } else {
      this.items.addAll(new java.util.ArrayList<rpg.inventory.Item>(items));
    }
    return this;
  }
  

  public Inventory build() {
    return new Inventory(
this.capacity,this.items);
  }

}


}
