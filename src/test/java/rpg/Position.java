package rpg;

// Generated with https://github.com/paidgeek/bufobjects

@SuppressWarnings("all")
public class Position {

  public static final int SIZE = 0 + 4 + 4;

  public float x;
  public float y;

  public Position() {
    reset();
  }

  public Position(float x, float y) {
    this.x = x;
    this.y = y;
  }

  public void init(float x, float y) {
    this.x = x;
    this.y = y;
  }

  public void reset() {
    this.x = 0.0f;
    this.y = 0.0f;

  }

  public Position copy() {
    Position newCopy = new Position();
    newCopy.x = this.x;
    newCopy.y = this.y;
    return newCopy;
  }

  public void copyTo(Position dst) {
    dst.x = this.x;
    dst.y = this.y;
  }

  public void writeTo(BufferObjectBuilder bob) {
    if (bob.getRemaining() < SIZE) {
      bob.growBuffer(SIZE);
    }
    {
      bob.writeFloat32(this.x);
    }
    {
      bob.writeFloat32(this.y);
    }
  }

  public void readFrom(BufferObjectBuilder bob) {
    {
      this.x = bob.readFloat32();
    }
    {
      this.y = bob.readFloat32();
    }
  }

}