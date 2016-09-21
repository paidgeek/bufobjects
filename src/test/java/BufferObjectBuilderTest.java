import org.junit.Assert;
import org.junit.Test;

import benchclasses.BufferObjectBuilder;

public class BufferObjectBuilderTest {

  @Test
  public void testSizes() {
    BufferObjectBuilder bob = new BufferObjectBuilder();

    bob.writeVarInt32(-500);
    System.out.println(bob.getOffset());

    System.out.println(BufferObjectBuilder.getVarInt32Size(-500));
  }

  @Test
  public void testFloats() {
    BufferObjectBuilder bob = new BufferObjectBuilder();

    float x1 = 0.0001f, x2 = 324893.3153461f;
    double x3 = 0.000000001, x4 = 23948329853456.43295834;

    bob.writeFloat32(x1);
    bob.writeFloat64(x3);
    bob.writeFloat32(x2);
    bob.writeFloat64(x4);

    bob.rewind();

    Assert.assertEquals(x1, bob.readFloat32(), 0.0000001f);
    Assert.assertEquals(x3, bob.readFloat64(), 0.0000001);
    Assert.assertEquals(x2, bob.readFloat32(), 0.0000001f);
    Assert.assertEquals(x4, bob.readFloat64(), 0.0000001);
  }

  @Test
  public void testTypes() {
    BufferObjectBuilder bob = new BufferObjectBuilder();

    bob.writeFloat32(2354.5345f);
    bob.writeString(BufferObjectBuilder.getStringBytes("ABC"));
    bob.writeFloat64(42.13);

    bob.rewind();

    Assert.assertEquals(2354.5345f, bob.readFloat32(), 0.00001f);
    Assert.assertEquals("ABC", BufferObjectBuilder.getStringFromBytes(bob.readString()));
    Assert.assertEquals(42.13, bob.readFloat64(), 0.001);
  }

}
