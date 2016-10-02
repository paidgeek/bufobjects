

  
    
      
    
  

  
    
      
    
  

  


  package rpg.inventory;


// Generated with https://github.com/paidgeek/bufobjects


import rpg.BufferObject;
import rpg.BufferBuilder;

@SuppressWarnings("all")
public class Inventory
extends BufferObject{

protected int capacity;protected java.util.List<rpg.inventory.Item> items;

public Inventory() {
  reset();
}

public Inventory(int capacity,java.util.List<rpg.inventory.Item> items)
{this.capacity = capacity;this.items = items;}

public void init(int capacity,java.util.List<rpg.inventory.Item> items)
{this.capacity = capacity;this.items = items;}

public short bufferObjectId() {
  return RPG_INVENTORY_INVENTORY_ID;
}

public void reset() {
this.capacity = 0;if(this.items != null) {
      this.items.clear();
    }

}

public Inventory copy() {
  
Inventory newCopy = new Inventory();
newCopy.capacity = this.capacity;for(int i = 0; i < this.items.size(); i++) {rpg.inventory.Item e = this.items.get(i);
        if(e != null) {
          newCopy.items.add((rpg.inventory.Item)e.copy());
        }}
return newCopy;
}

public void copyTo(BufferObject obj) {
  Inventory dst = (Inventory) obj;
  
dst.capacity = this.capacity;for(int i = 0; i < this.items.size(); i++) {rpg.inventory.Item e = this.items.get(i);
      if(e != null) {
        ((rpg.inventory.Item)e).copyTo(e);
      }}
}

public int size() {
  int size = 0;

size += 4; // size for "u32"
  if (this.items == null) {
      size += 1; // BufferBuilder.getVarUInt32Size(0)
    } else {
      size += BufferBuilder.getVarUInt32Size(this.items.size());
      
          for(int i = 0; i < this.items.size(); i++) {
          if(this.items.get(i) != null) {
          size += this.items.get(i).size();
          // this comment seems to fix a jtwig bug ""
          
            
              size += 2; // size of bufferObjectId
            
          
          }
          }
          size += this.items.size(); // for "is null" byte
        
      }

    
  
return size;
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
        bb.writeUInt8((byte) 0x80);
      } else {
        bb.writeUInt8((byte) 0x81);
        // this comment seems to fix a jtwig bug true
        
          bb.writeUInt16(e.bufferObjectId());
        
        e.writeTo(bb);
      }
      }
    }
  }
}

public void readFrom(BufferBuilder bb) {
{
    this.capacity = bb.readUInt32();
  
  }{int size = bb.readVarUInt32();
    this.items = new java.util.ArrayList<rpg.inventory.Item>(size);
    rpg.inventory.Item e = null;
    for(int i = 0; i < size; i++) {
      // this comment seems to fix a jtwig bug "true"
      
        if (bb.readUInt8() == (byte) 0x81) {
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
        } else {
          e = null;
        }
      this.items.add(e);
    }
  }
}

public int getCapacity() {
    return this.capacity;
  }

  public void setCapacity(int capacity) {
    this.capacity = capacity;
  }

public java.util.List<rpg.inventory.Item> getItems() {
    return this.items;
  }

  public void setItems(java.util.List<rpg.inventory.Item> items) {
    this.items = items;
  }


  public rpg.inventory.Item getItems(int index) {
    return this.items.get(index);
  }

  public void setItems(int index, rpg.inventory.Item value) {
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
        // this comment seems to fix a jtwig bug true
        
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
