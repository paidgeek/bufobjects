import com.google.flatbuffers.FlatBufferBuilder;

import org.junit.Test;

import java.io.ByteArrayOutputStream;
import java.nio.ByteBuffer;
import java.util.Arrays;

import benchclasses.BuffobjectsSimple;
import benchclasses.FlatBuffersSimple;
import benchclasses.ProtobufSimpleOuterClass.ProtobufSimple;

public class BuffersBenchmark {

  private static final int N = 1000;
  private static final int M = 1000;

  private interface ExperimentMethod {
    int doExperiment();
  }

  @Test
  public void benchmark() {
    String[] names = new String[]{"Protocol Buffers", "Flat Buffers", "Buffer Objects"};
    ExperimentMethod[] experiments = new ExperimentMethod[]{
      this::doProtocolBuffers,
      this::doFlatBuffers,
      this::doBufferObjects
    };

    long startTime = 0;
    long duration = 0;
    long[] totalTime = new long[names.length];
    long[] minTime = new long[names.length];
    long[] maxTime = new long[names.length];
    int[] size = new int[names.length];

    for (int i = 0; i < names.length; i++) {
      minTime[i] = Long.MAX_VALUE;
    }

    for (int _ = 0; _ < N; _++) {
      for (int i = 0; i < names.length; i++) {
        startTime = System.nanoTime();
        size[i] = experiments[i].doExperiment();

        duration = System.nanoTime() - startTime;
        totalTime[i] += duration;
        minTime[i] = Math.min(minTime[i], duration);
        maxTime[i] = Math.max(maxTime[i], duration);
      }
    }

    for (int i = 0; i < names.length; i++) {
      System.out.printf("-- %s --\n", names[i]);
      System.out.printf("avg: %fs\n", (totalTime[i] / N) * 1E-9);
      System.out.printf("max: %fs, min: %fs\n", maxTime[i] * 1E-9, minTime[i] * 1E-9);
      System.out.printf("size: %d\n", size[i]);
    }
  }

  private int doBufferObjects() {
    int off = 0;
    for (int i = 0; i < M; i++) {
      BuffobjectsSimple simple = BuffobjectsSimple.newBuilder()
        .setName("Simple")
        .setValue(42.0)
        .setArr(1, 1, 2, 3, 5)
        .build();
      byte[] b = new byte[1024];
      off = simple.writeTo(b, 0);
      simple.reset();
      simple.readFrom(b, 0);
    }
    return off;
  }

  private int doFlatBuffers() {
    int off = 0;
    for (int i = 0; i < M; i++) {
      FlatBufferBuilder fbb = new FlatBufferBuilder();
      off = FlatBuffersSimple.createFlatSimple(fbb,
        fbb.createString("Simple"),
        42.0,
        FlatBuffersSimple.createArrVector(fbb, new int[]{1, 1, 2, 3, 5}));
      FlatBuffersSimple.finishFlatSimpleBuffer(fbb, off);

      ByteBuffer db = fbb.dataBuffer();
      ByteBuffer bb = ByteBuffer.wrap(db.array(), db.position(), db.capacity() - db.position());

      FlatBuffersSimple simple = FlatBuffersSimple.getRootAsFlatSimple(bb);
    }
    return off;
  }

  private int doProtocolBuffers() {
    try {
      for (int i = 0; i < M; i++) {
        ProtobufSimple simple = ProtobufSimple.newBuilder()
          .setName("Simple")
          .setValue(42.0)
          .addAllArr(Arrays.asList(1, 1, 2, 3, 5))
          .build();
        ByteArrayOutputStream os = new ByteArrayOutputStream(1024);

        simple.writeTo(os);

        ProtobufSimple.parseFrom(os.toByteArray());
      }
    } catch (Exception e) {
      e.printStackTrace();
    }

    return ProtobufSimple.newBuilder()
      .setName("Simple")
      .setValue(42.0)
      .addAllArr(Arrays.asList(1, 1, 2, 3, 5))
      .build().getSerializedSize();
  }

}
