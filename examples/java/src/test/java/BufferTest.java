import org.junit.Assert;
import org.junit.Test;

import java.math.BigInteger;

public class BufferTest {

  @Test
  public void testOutputStream() {
    long startTime = System.nanoTime();

    long duration = System.nanoTime() - startTime;
    System.out.println(duration);
  }

  @Test
  public void testStringBuilder() {
    long startTime = System.nanoTime();

    long duration = System.nanoTime() - startTime;
    System.out.println(duration);
  }

}
