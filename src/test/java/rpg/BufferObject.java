package rpg;

// Generated with https://github.com/paidgeek/bufobjects

public abstract class BufferObject {
  public abstract int getBufferObjectId();
  public abstract void reset();
  public abstract BufferObject copy();
  public abstract int writeTo(byte[] b, int off);
  public abstract int readFrom(byte[] b, int off);
}
