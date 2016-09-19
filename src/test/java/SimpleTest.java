import com.moybl.bufobjects.BufferUtil;

import org.junit.Test;

import java.util.Arrays;

import benchclasses.BuffobjectsSimple;

public class SimpleTest {

  @Test
  public void testSimple() {
    BuffobjectsSimple simple = new BuffobjectsSimple("Bobby", 42.0, Arrays.asList(1, 1, 2, 3, 5));
    byte[] b = new byte[48];

    simple.writeTo(b, 0);

    for (int i = 0; i < b.length; i++) {
      System.out.print(b[i]);
      if (i < b.length - 1) {
        System.out.print(", ");
      }
    }
    System.out.println();
  }

  @Test
  public void testVarInt() {
    byte[] b = new byte[32];
    int off = 0;

    off = BufferUtil.writeUnsignedVarLong(43286, b, off);
    System.out.println(off);

    for (int i = 0; i < b.length; i++) {
      System.out.print(b[i]);
      if (i < b.length - 1) {
        System.out.print(", ");
      }
    }
    System.out.println();
  }

}
