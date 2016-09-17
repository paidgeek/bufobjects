package rpg;


// Generated with https://github.com/paidgeek/bufobjects


import rpg.BufferObject;
import rpg.BufferObjects;

@SuppressWarnings("all")
public class Character
extends BufferObject{


protected String name;
    
  
protected float speed;
protected rpg.inventory.Inventory bag;
protected rpg.inventory.Item mainHand;
protected double[] buffs;
    public static final int BUFFS_LENGTH = 8;
  



protected static java.nio.charset.Charset CHARSET_UTF8 = java.nio.charset.Charset.forName("UTF-8");public Character() {
  reset();
}

public Character(String name,float speed,rpg.inventory.Inventory bag,rpg.inventory.Item mainHand,double[] buffs)
{this.name = name;this.speed = speed;this.bag = bag;this.mainHand = mainHand;this.buffs = buffs;}

public int getBufferObjectId() {
  return 1;
}

public void reset() {
this.name = "";this.speed = 0.0f;this.bag = null;this.mainHand = null;this.buffs = new double[BUFFS_LENGTH];

}

public Character copy() {
Character newCopy = new Character();

newCopy.name = this.name;newCopy.speed = this.speed;if(this.bag != null) {
      newCopy.bag = (rpg.inventory.Inventory)this.bag.copy();
    }if(this.mainHand != null) {
      newCopy.mainHand = (rpg.inventory.Item)this.mainHand.copy();
    }for(int i = 0; i < BUFFS_LENGTH; i++) {newCopy.buffs[i] = this.buffs[i];}
return newCopy;

}

public String
  getName() {
    return this.name;
  }

  public void setName(String name) {
    this.name = name;
  }

public float
  getSpeed() {
    return this.speed;
  }

  public void setSpeed(float speed) {
    this.speed = speed;
  }

public rpg.inventory.Inventory
  getBag() {
    return this.bag;
  }

  public void setBag(rpg.inventory.Inventory bag) {
    this.bag = bag;
  }

public rpg.inventory.Item
  getMainHand() {
    return this.mainHand;
  }

  public void setMainHand(rpg.inventory.Item mainHand) {
    this.mainHand = mainHand;
  }

public double[]
  getBuffs() {
    return this.buffs;
  }

  public void setBuffs(double[] buffs) {
    this.buffs = buffs;
  }


  public double getBuffsAt(int index) {
    return this.buffs[index];
  }

  public void setBuffsAt(int index, double value) {
    this.buffs[index] = value;
  }



public int writeTo(byte[] b, int off) {
{
    if(this.name == null) {
  this.name = "";
}
byte[] utf8 = this.name.getBytes(CHARSET_UTF8);
int length = utf8.length;
do {
  int bits = length & 0x7F;
  length >>>= 7;
  b[off++] = (byte) (bits + ((length != 0) ? 0x80 : 0));
} while (length != 0);
if(utf8.length != 0) {
  System.arraycopy(utf8, 0, b, off, utf8.length);
  off += utf8.length;
}
  
  }{
    int bitValue = Float.floatToRawIntBits(this.speed);
b[off++] = (byte)bitValue;
b[off++] = (byte)(bitValue >> 8);
b[off++] = (byte)(bitValue >> 16);
b[off++] = (byte)(bitValue >> 24);
  
  }{
    int id = getBufferObjectId();
    {int value = id;
do {
  int bits = value & 0x7F;
  value >>>= 7;
  b[off++] = (byte) (bits + ((value != 0) ? 0x80 : 0));
} while (value != 0);}
    if(this.bag == null) {
      b[off++] = (byte) 0x80;
    } else {
      b[off++] = (byte) 0x81;
      this.bag.writeTo(b, off);
    }
  
  }{
    int id = getBufferObjectId();
    {int value = id;
do {
  int bits = value & 0x7F;
  value >>>= 7;
  b[off++] = (byte) (bits + ((value != 0) ? 0x80 : 0));
} while (value != 0);}
    if(this.mainHand == null) {
      b[off++] = (byte) 0x80;
    } else {
      b[off++] = (byte) 0x81;
      this.mainHand.writeTo(b, off);
    }
  
  }{
    for(int i = 0; i < BUFFS_LENGTH; i++) {
    long bitValue = Double.doubleToRawLongBits(this.buffs[i]);
b[off++] = (byte)bitValue;
b[off++] = (byte)(bitValue >> 8);
b[off++] = (byte)(bitValue >> 16);
b[off++] = (byte)(bitValue >> 24);
b[off++] = (byte)(bitValue >> 32);
b[off++] = (byte)(bitValue >> 40);
b[off++] = (byte)(bitValue >> 48);
b[off++] = (byte)(bitValue >> 56);
    }
  }
return off;
}

public int readFrom(byte[] b, int off) {
{
    int length = 0;
int tmp = b[off++];
if (tmp >= 0) {
  length = tmp;
} else {
  length = tmp & 0x7f;
  if ((tmp = b[off++]) >= 0) {
  length |= tmp << 7;
  } else {
  length |= (tmp & 0x7f) << 7;
  if ((tmp = b[off++]) >= 0) {
  length |= tmp << 14;
  } else {
  length |= (tmp & 0x7f) << 14;
  if ((tmp = b[off++]) >= 0) {
  length |= tmp << 21;
  } else {
  length |= (tmp & 0x7f) << 21;
  length |= (tmp = b[off++]) << 28;
  while (tmp < 0) {
  tmp = b[off++];
  }
  }
  }
  }
}
byte[] bytes = new byte[length];
System.arraycopy(b, off, bytes, 0, length);
off += length;
this.name = new String(bytes, CHARSET_UTF8);
  
  }{
    int bitValue = (int)(
(b[off++] & 0xFF) |
((b[off++] & 0xFF) << 8)   |
((b[off++] & 0xFF) << 16)  |
(b[off++] << 24)
);
this.speed = Float.intBitsToFloat(bitValue);
  
  }{
    int id = 0;
    {
      int tmp = b[off++];
int value = 0;
if (tmp >= 0) {
value = tmp;
} else {
value = tmp & 0x7f;
if ((tmp = b[off++]) >= 0) {
value |= tmp << 7;
} else {
value |= (tmp & 0x7f) << 7;
if ((tmp = b[off++]) >= 0) {
value |= tmp << 14;
} else {
value |= (tmp & 0x7f) << 14;
if ((tmp = b[off++]) >= 0) {
value |= tmp << 21;
} else {
value |= (tmp & 0x7f) << 21;
value |= (tmp = b[off++]) << 28;
while (tmp < 0) {
tmp = b[off++];
}
}
}
}
}
id = value;
    }
    if (b[off++] == (byte) 0x81) {
      switch(id) {}
      off = this.bag.readFrom(b, off);
    } else {
      this.bag = null;
    }
  
  }{
    int id = 0;
    {
      int tmp = b[off++];
int value = 0;
if (tmp >= 0) {
value = tmp;
} else {
value = tmp & 0x7f;
if ((tmp = b[off++]) >= 0) {
value |= tmp << 7;
} else {
value |= (tmp & 0x7f) << 7;
if ((tmp = b[off++]) >= 0) {
value |= tmp << 14;
} else {
value |= (tmp & 0x7f) << 14;
if ((tmp = b[off++]) >= 0) {
value |= tmp << 21;
} else {
value |= (tmp & 0x7f) << 21;
value |= (tmp = b[off++]) << 28;
while (tmp < 0) {
tmp = b[off++];
}
}
}
}
}
id = value;
    }
    if (b[off++] == (byte) 0x81) {
      switch(id) {}
      off = this.mainHand.readFrom(b, off);
    } else {
      this.mainHand = null;
    }
  
  }{
    if(this.buffs == null) {
    this.buffs = new double[BUFFS_LENGTH];
    }
    for(int i = 0; i < BUFFS_LENGTH; i++) {
    long bitValue =
(((long)b[off++] & 0xFF)         |
(((long)b[off++] & 0xFF) << 8)   |
(((long)b[off++] & 0xFF) << 16)  |
(((long)b[off++] & 0xFF) << 24)  |
(((long)b[off++] & 0xFF) << 32)  |
(((long)b[off++] & 0xFF) << 40)  |
(((long)b[off++] & 0xFF) << 48)  |
(((long)b[off++] & 0xFF) << 56));
this.buffs[i] = Double.longBitsToDouble(bitValue);
    }
  }
return off;
}

public static Builder newBuilder() {
return new Builder();
}


public static class Builder {

private String name;
private float speed;
private rpg.inventory.Inventory bag;
private rpg.inventory.Item mainHand;
private double[] buffs;



  public Builder setName(String name) {
    this.name = name;
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
  
  public Builder setMainHand(rpg.inventory.Item mainHand) {
    this.mainHand = mainHand;
    return this;
  }
  
  public Builder setBuffs(double ...buffs) {
    this.buffs = buffs;
    return this;
  }
  

  public Character build() {
    return new Character(
this.name,this.speed,this.bag,this.mainHand,this.buffs);
  }

}


}