package rpg;

// Generated with https://github.com/paidgeek/bufobjects

public abstract class BufferObject {

  public abstract short bufferObjectId();

  public abstract void reset();

  public abstract BufferObject copy();

  public abstract void copyTo(BufferObject dst);

  public abstract void writeTo(BufferObjectBuilder bob);

  public abstract void readFrom(BufferObjectBuilder bob);

  public int size() {
    return 0;
  }

}