//              MatrixProblem/Adder.java

import java.io.*;
import Extensions.*;


public class Adder implements Runnable {
  int                   i, j;
  Matrix                a, b, c;
  SingleBarrier         barrier;


public Adder(Matrix a1, Matrix b1, Matrix c1, SingleBarrier barrier1) {
  a = a1;
  b = b1;
  c = c1;
  barrier = barrier1;
}


public void run() {
  InterruptibleThread.sleep(50);
  c.array[i] [j] = a.array[i] [j] + b.array[i] [j];
  barrier.barrierPost();
}

}



