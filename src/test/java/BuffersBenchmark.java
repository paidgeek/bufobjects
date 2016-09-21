import com.google.flatbuffers.FlatBufferBuilder;

import org.junit.Test;

import java.io.ByteArrayOutputStream;
import java.nio.ByteBuffer;
import java.util.*;

import benchclasses.*;
import benchclasses.ProtobufSimpleOuterClass.ProtobufSimple;

public class BuffersBenchmark {

  private static final int N = 1000;
  private static final int M = 1000;

  private static String name;
  private static double value;
  private static int[] arr;
  private static List<Integer> arrAsList;

  static {
    Random random = new Random(1337);

    for (int i = 0; i < 10; i++) {
      name += (char)(random.nextInt(25) + 65);
    }
    
    value = random.nextDouble();

    arr = new int[10];
    arrAsList = new ArrayList<>();
    for (int i = 0; i < arr.length; i++) {
      arr[i] = random.nextInt();
      arrAsList.add(arr[i]);
    }
  }

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
      BufferObjectBuilder bob = new BufferObjectBuilder(1024, 100000);
      BufobjectsSimple simple = BufobjectsSimple.newBuilder()
        .setName(name)
        .setValue(value)
        .setArr(arrAsList)
        .build();
      simple.writeTo(bob);
      off = bob.getOffset();
      simple.reset();
      simple.readFrom(bob);
    }
    return off;
  }

  private int doFlatBuffers() {
    int off = 0;
    for (int i = 0; i < M; i++) {
      FlatBufferBuilder fbb = new FlatBufferBuilder();
      off = FlatBuffersSimple.createFlatSimple(fbb,
        fbb.createString(name),
        value,
        FlatBuffersSimple.createArrVector(fbb, arr));
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
          .setName(name)
          .setValue(value)
          .addAllArr(arrAsList)
          .build();
        ByteArrayOutputStream os = new ByteArrayOutputStream(1024);

        simple.writeTo(os);

        ProtobufSimple.parseFrom(os.toByteArray());
      }
    } catch (Exception e) {
      e.printStackTrace();
    }

    return ProtobufSimple.newBuilder()
      .setName(name)
      .setValue(value)
      .addAllArr(arrAsList)
      .build().getSerializedSize();
  }

}
