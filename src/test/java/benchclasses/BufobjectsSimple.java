package benchclasses;


// Generated with https://github.com/paidgeek/bufobjects


import benchclasses.BufferObject;
import benchclasses.BufferObjects;
import benchclasses.BufferObjectBuilder;

@SuppressWarnings("all")
public class BufobjectsSimple
extends BufferObject{

protected byte[] name;protected double value;protected java.util.List<Integer> arr;

public BufobjectsSimple() {
  reset();
}

public BufobjectsSimple(String name,double value,java.util.List<Integer> arr)
{this.name = BufferObjectBuilder.getStringBytes(name);
  this.value = value;this.arr = arr;}

public short bufferObjectId() {
  return 1;
}

public void reset() {
this.name = new byte[0];this.value = 0.0;this.arr = new java.util.ArrayList<Integer>();

}

public BufobjectsSimple copy() {
  
BufobjectsSimple newCopy = new BufobjectsSimple();
newCopy.name = new byte[this.name.length];
    System.arraycopy(this.name, 0, newCopy.name, 0, this.name.length);newCopy.value = this.value;for(int i = 0; i < this.arr.size(); i++) {newCopy.arr.add(this.arr.get(i));}
return newCopy;
}

public void copyTo(BufferObject obj) {
  BufobjectsSimple dst = (BufobjectsSimple) obj;
  
dst.name = new byte[this.name.length];
    System.arraycopy(this.name, 0, dst.name, 0, this.name.length);dst.value = this.value;for(int i = 0; i < this.arr.size(); i++) {dst.arr.add(this.arr.get(i));}
}

protected int size() {
  int size = 0;


    size += BufferObjectBuilder.getStringSize(this.name);
  size += 8; // size for "f64"
  size += BufferObjectBuilder.getVarUInt32Size(this.arr.size());
    size += this.arr.size() * 4; // size for "i32"
    
return size;
}

public void writeTo(BufferObjectBuilder bob) {
  int needed = size();
  if(bob.getRemaining() < needed) {
    bob.growBuffer(needed);
  }
{
    bob.writeString(this.name);
  
  }{
    bob.writeFloat64(this.value);
  
  }{int size = this.arr.size();
    bob.writeVarUInt32(size);
    for(int i = 0; i < size; i++) {
      int e = this.arr.get(i);
      bob.writeInt32(e);
    }
  
  }
}

public void readFrom(BufferObjectBuilder bob) {
{
    this.name = bob.readString();
  
  }{
    this.value = bob.readFloat64();
  
  }{int size = bob.readVarUInt32();
    this.arr = new java.util.ArrayList<Integer>(size);
    Integer e = null;
    for(int i = 0; i < size; i++) {
      e = bob.readInt32();
      this.arr.add(e);
    }
  
  }
}

public String
  getName() {

    return BufferObjectBuilder.getStringFromBytes(this.name);

  }

  public void setName(String name) {

    this.name = BufferObjectBuilder.getStringBytes(name);

  }

public double
  getValue() {

    return this.value;

  }

  public void setValue(double value) {

    this.value = value;

  }

public java.util.List<Integer>
  getArr() {

    return this.arr;

  }

  public void setArr(java.util.List<Integer> arr) {

    this.arr = arr;

  }


  public Integer getArrAt(int index) {
  
    return this.arr.get(index);
  
  }

  public void setArrAt(int index, Integer value) {
  
    this.arr.set(index, value);
  
  }



public static Builder newBuilder() {
return new Builder();
}


public static class Builder {

private String name;
private double value;
private java.util.List<Integer> arr;



  public Builder setName(String name) {
    this.name = name;
    return this;
  }
  
  public Builder setValue(double value) {
    this.value = value;
    return this;
  }
  
  public Builder setArr(java.util.List<Integer> arr) {
    this.arr = arr;
    return this;
  }
  public Builder setArr(Integer ...arr) {
    this.arr = new java.util.ArrayList<Integer>();
    for(int i = 0; i < arr.length; i++) {
      this.arr.add(arr[i]);
    }
    return this;
  }
  public Builder addArr(Integer ...arr) {
    if(this.arr == null) {
      this.arr = new java.util.ArrayList<Integer>();
      for(int i = 0; i < arr.length; i++) {
        this.arr.add(arr[i]);
      }
    } else {
      for(int i = 0; i < arr.length; i++) {
        this.arr.add(arr[i]);
      }
    }
    return this;
  }
  public Builder addArr(java.util.List<Integer> arr) {
    if(this.arr == null) {
      this.arr = new java.util.ArrayList<Integer>(arr);
    } else {
      this.arr.addAll(new java.util.ArrayList<Integer>(arr));
    }
    return this;
  }
  

  public BufobjectsSimple build() {
    return new BufobjectsSimple(
this.name,this.value,this.arr);
  }

}


}