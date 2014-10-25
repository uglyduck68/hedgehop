//              MatrixProblem/TestMatrix.java

/*

This program illustrates the dangers of inadvertantly using shared
data, and the problems which result.

What is particularly interesting about this program, is that the
thread start times must be considered as random, making this into
a big race condition.  It is possible that you will get the correct
answer.  It is possible that all the threads will get the same values
for {i,j}, it is possible for any combination of values! A very nice
program indeed.

*/


import java.io.*;
import Extensions.*;
import java.util.*;


public class TestMatrix {


public static void main(String argv[]) {
  Matrix a = new Matrix(5, 5);
  Matrix b = new Matrix(5, 5);
  Matrix c = new Matrix(5, 5);
  SingleBarrier barrier = new SingleBarrier();
  Random r = new Random(10);
 
  barrier.init(25);
  System.out.print("\n\n                 A is");
  a.fill();
  a.print();
  System.out.print("\n                 B is");
  b.fill();
  b.print();
  Adder e = new Adder(a, b, c, barrier);

  for (int i=0; i<5; i++) {
    for (int j=0; j<5; j++) {
      e.i = i;
      e.j = j;
      Thread t = new Thread(e);
      t.start();
      InterruptibleThread.sleep(Math.abs(r.nextInt() % 100));
    }
  }

  barrier.barrierWait();
  System.out.print("\n                 Sum is");
  c.print();
  System.exit(0);
}

}
