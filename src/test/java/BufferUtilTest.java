import com.moybl.bufobjects.BufferUtil;

import org.junit.Assert;
import org.junit.Test;

import java.util.Random;

public class BufferUtilTest {

  @Test
  public void testVarInt() {
    Random random = new Random(1337);
    byte[] b = new byte[128];
    int off = 0;
    int[] dst = new int[1];

    for (int i = 0; i < 20; i++) {
      int value = random.nextInt();

      off = BufferUtil.writeVarInt(value, b, 0);
      BufferUtil.readVarInt(b, 0, dst);

      Assert.assertEquals(value, dst[0]);
    }
  }

  @Test
  public void testUnsignedVarInt() {
    Random random = new Random(1337);
    byte[] b = new byte[128];
    int off = 0;
    int[] dst = new int[1];

    for (int i = 0; i < 20; i++) {
      int value = random.nextInt(Integer.MAX_VALUE);

      off = BufferUtil.writeUnsignedVarInt(value, b, 0);
      BufferUtil.readUnsignedVarInt(b, 0, dst);

      Assert.assertEquals(value, dst[0]);
    }
  }

  @Test
  public void testVarLong() {
    Random random = new Random(1337);
    byte[] b = new byte[128];
    int off = 0;
    long[] dst = new long[1];

    for (int i = 0; i < 20; i++) {
      long value = random.nextLong();

      off = BufferUtil.writeVarLong(value, b, 0);
      BufferUtil.readVarLong(b, 0, dst);

      Assert.assertEquals(value, dst[0]);
    }
  }

  @Test
  public void testUnsignedVarLong() {
    Random random = new Random(1337);
    byte[] b = new byte[128];
    int off = 0;
    long[] dst = new long[1];

    for (int i = 0; i < 20; i++) {
      long value = Math.abs(random.nextLong());

      off = BufferUtil.writeUnsignedVarLong(value, b, 0);
      BufferUtil.readUnsignedVarLong(b, 0, dst);

      Assert.assertEquals(value, dst[0]);
    }
  }

}
