package benchclasses;

// Generated with https://github.com/paidgeek/bufobjects

@SuppressWarnings("all")
public final class BufferObjects {
  public static final short BENCHCLASSES_BUFOBJECTSSIMPLE_ID = 1;

  public static void writeTo(BufferObjectBuilder bob, BufferObject obj) {
    bob.writeUInt16(obj.bufferObjectId());
    obj.writeTo(bob);
  }

  public static BufferObject readFrom(BufferObjectBuilder bob) {
    short id = bob.readUInt16();
    BufferObject obj = null;
    switch(id) {case BENCHCLASSES_BUFOBJECTSSIMPLE_ID:
          obj = new benchclasses.BufobjectsSimple();
          obj.readFrom(bob);
          break;
        }
    return obj;
  }

}