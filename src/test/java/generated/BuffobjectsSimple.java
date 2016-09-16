package generated;


// Generated with https://github.com/paidgeek/bufobjects


public class BuffobjectsSimple
{


protected String name;
    
  
protected double value;
protected java.util.List<Integer> arr;



protected static java.nio.charset.Charset CHARSET_UTF8 = java.nio.charset.Charset.forName("UTF-8");public BuffobjectsSimple() {
reset();
}

public BuffobjectsSimple(String name,double value,java.util.List<Integer> arr)
{this.name = name;this.value = value;this.arr = arr;}

public void reset() {
this.name = "";this.value = 0.0;this.arr = new java.util.ArrayList<Integer>();

}

public BuffobjectsSimple copy() {
BuffobjectsSimple newCopy = new BuffobjectsSimple();

newCopy.name = this.name;newCopy.value = this.value;for(int i = 0; i < this.arr.size(); i++) {newCopy.arr.add(this.arr.get(i));}
return newCopy;

}

public String
  getName() {
    return this.name;
  }

  public void setName(String name) {
    this.name = name;
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
    long bitValue = Double.doubleToRawLongBits(this.value);
b[off++] = (byte)bitValue;
b[off++] = (byte)(bitValue >> 8);
b[off++] = (byte)(bitValue >> 16);
b[off++] = (byte)(bitValue >> 24);
b[off++] = (byte)(bitValue >> 32);
b[off++] = (byte)(bitValue >> 40);
b[off++] = (byte)(bitValue >> 48);
b[off++] = (byte)(bitValue >> 56);
  
  }{int size = this.arr.size();
    {
    b[off++] = (byte)size;
b[off++] = (byte)(size >> 8);
b[off++] = (byte)(size >> 16);
b[off++] = (byte)(size >> 24);
    }
    for(int i = 0; i < size; i++) {
      int e = this.arr.get(i);
      b[off++] = (byte)e;
b[off++] = (byte)(e >> 8);
b[off++] = (byte)(e >> 16);
b[off++] = (byte)(e >> 24);
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
    long bitValue =
(((long)b[off++] & 0xFF)         |
(((long)b[off++] & 0xFF) << 8)   |
(((long)b[off++] & 0xFF) << 16)  |
(((long)b[off++] & 0xFF) << 24)  |
(((long)b[off++] & 0xFF) << 32)  |
(((long)b[off++] & 0xFF) << 40)  |
(((long)b[off++] & 0xFF) << 48)  |
(((long)b[off++] & 0xFF) << 56));
this.value = Double.longBitsToDouble(bitValue);
  
  }{int size = 0;
    {
    size = (int)(
(b[off++] & 0xFF) |
((b[off++] & 0xFF) << 8)   |
((b[off++] & 0xFF) << 16)  |
(b[off++] << 24)
);
    }
    this.arr = new java.util.ArrayList<>(size);
    Integer e = null;
    for(int i = 0; i < size; i++) {
    e = (int)(
(b[off++] & 0xFF) |
((b[off++] & 0xFF) << 8)   |
((b[off++] & 0xFF) << 16)  |
(b[off++] << 24)
);
    this.arr.add(e);
    }
  
  }
return off;
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
  

  public BuffobjectsSimple build() {
    return new BuffobjectsSimple(
this.name,this.value,this.arr);
  }

}


}