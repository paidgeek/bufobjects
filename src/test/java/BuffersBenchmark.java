import com.google.flatbuffers.FlatBufferBuilder;

import org.junit.Test;

public class BuffersBenchmark {

  private static final int N = 1000;

  private interface ExperimentMethod {
    int doExperiment();
  }

  @Test
  public void benchmark() {
    String[] names = new String[]{"Flat Buffers", "Buffer Objects"};
    ExperimentMethod[] experiments = new ExperimentMethod[]{
      new ExperimentMethod() {
        @Override
        public int doExperiment() {
          return doFlatBuffers();
        }
      }, new ExperimentMethod() {
      @Override
      public int doExperiment() {
        return doBufferObjects();
      }
    }
    };

    for (int i = 0; i < names.length; i++) {
      long startTime = 0;
      long duration = 0;
      long totalTime = 0;
      long minTime = Long.MAX_VALUE, maxTime = 0;
      int size = 0;

      for (int _ = 0; _ < N; _++) {
        startTime = System.nanoTime();

        size = experiments[i].doExperiment();

        duration = System.nanoTime() - startTime;
        totalTime += duration;
        minTime = Math.min(minTime, duration);
        maxTime = Math.max(maxTime, duration);
      }

      System.out.printf("-- %s --\n", names[i]);
      System.out.printf("avg: %dns\n", totalTime / N);
      System.out.printf("max: %dns, min: %dns\n", maxTime, minTime);
      System.out.printf("size: %d\n", size);
    }
  }

  private int doBufferObjects() {
    BufSimple simple = BufSimple.newBuilder()
      .setName("Simple")
      .setValue(42.0)
      .setArr(1, 1, 2, 3, 5)
      .build();
    byte[] b = new byte[1024];
    return simple.writeTo(b, 0);
  }

  private int doFlatBuffers() {
    FlatBufferBuilder fbb = new FlatBufferBuilder();
    return FlatSimple.createFlatSimple(fbb,
      fbb.createString("Simple"),
      42.0,
      FlatSimple.createArrVector(fbb, new int[]{1, 1, 2, 3, 5}));
  }

}
