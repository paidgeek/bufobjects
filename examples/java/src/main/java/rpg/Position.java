

  
    
      
    
  

  


  package rpg;


// Generated with https://github.com/paidgeek/bufobjects

import rpg.BufferBuilder;

@SuppressWarnings("all")
public class Position {

public float x;public float y;
public static final int SIZE = 0+ 4+ 4;

  public Position() { }

public Position(float x,float y)
{this.x = x;this.y = y;}

public void clear() {
this.x = 0.0f;this.y = 0.0f;

}

public Position copy() {
Position newCopy = new Position();
newCopy.x = this.x;newCopy.y = this.y;
return newCopy;
}

public void copyTo(Position dst) {
dst.x = this.x;dst.y = this.y;
}

public void writeTo(BufferBuilder bb) {
  {
    bb.writeFloat32(this.x);
  
  }{
    bb.writeFloat32(this.y);
  
  }
}

public void readFrom(BufferBuilder bb) {
  {
    this.x = bb.readFloat32();
  
  }{
    this.y = bb.readFloat32();
  
  }
}

public void writeJsonTo(java.io.OutputStream os) throws java.io.IOException {
os.write('{');

int i = 0;
final java.math.BigInteger two = java.math.BigInteger.valueOf(2);
os.write(BufferBuilder.getStringBytes("\"x\":"));
    os.write(BufferBuilder.getStringBytes(String.valueOf(this.x).replaceAll("\\.0+$", "")));
  

  
    os.write(',');
  

os.write(BufferBuilder.getStringBytes("\"y\":"));
    os.write(BufferBuilder.getStringBytes(String.valueOf(this.y).replaceAll("\\.0+$", "")));
  

  


os.write('}');

}

}
