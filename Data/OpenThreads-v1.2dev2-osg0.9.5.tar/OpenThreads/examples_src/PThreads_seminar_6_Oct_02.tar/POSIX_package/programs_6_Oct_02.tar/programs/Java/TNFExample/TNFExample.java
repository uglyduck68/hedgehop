//              TNFExample

/*
  Show how to use TNF from Java.  (Only a bit messy.)
  */


import java.io.*;
import java.util.*;
import Extensions.*;

class ProbedObject {
  public native void objectCreateStart();
  public native void objectCreateEnd();


  static {System.loadLibrary("javaProbe");}

}




class TNFExample implements Runnable {
  static SingleBarrier barrier = new SingleBarrier(1);

public static void main (String[] arg) throws Throwable {
  long startTime = System.currentTimeMillis();
  long endTime;

  if (arg.length == 0) {
    System.out.println("Running single-threaded");
    new TNFExample().run();     // Non-threaded
  }
  else {
    System.out.println("Running multi-threaded");
    for (int i=0; i<10; i++) {
      new Thread(new TNFExample()).start();
    }
    barrier.barrierWait();
  }
  endTime = System.currentTimeMillis();
  System.out.println("Done after " + (endTime - startTime) + "ms");
  System.exit(0);
}


public void run() {
  ProbedObject obj = new ProbedObject();

  for (int i=0; i<100; i++) {
    obj.objectCreateStart();
    obj = new ProbedObject();
    obj.objectCreateEnd();
  }
  barrier.barrierPost();
}

}
