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

}
