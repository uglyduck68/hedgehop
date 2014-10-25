//              /Test.java


import java.io.*;
import Extensions.*;



public class Test extends Thread {
  static final int limit = 4096;
  static int nThreads=1;
  static Object o = new Object();
  static SingleBarrier barrier, barrier1;
  static boolean startFlag=false;
  static Flag[] flags = new Flag[limit];
  int count;
  static int totalCS = 40960;


public static void main(String[] argv) throws Exception {
  long startTime, endTime, time;
  float CStime;
  long initialTime=0;


  //if (argv.length > 0) nThreads = Integer.parseInt(argv[0]);
  System.out.println("PTE Thrasher");

  for (nThreads=1; nThreads<=limit; nThreads = (nThreads * 2)) {
    startFlag=false;
    barrier = new SingleBarrier(nThreads);
    barrier1 = new SingleBarrier(nThreads);

    for (int i=0; i<nThreads; i++) {
      flags[i] = new Flag();
      new Test(i).start();
    }
    barrier1.barrierWait();
    startTime = System.currentTimeMillis();
    //    startEm();
      flags[0].setTrue();
    barrier.barrierWait();
    endTime = System.currentTimeMillis();
    if (nThreads == 1) {
      initialTime =  (endTime-startTime);
      time = (endTime-startTime);
    }
    else {time = (endTime-startTime)-initialTime;}
    CStime = time/(float) totalCS;
    System.out.println("Completed " + nThreads+  " in "
		       + time + " ms. Average CS " + CStime + " ms");
  }
}


  static void startEm() {
    synchronized (o) {
      startFlag=true;
      flags[0].setTrue();
      o.notifyAll();
    }
  }

  static void waitStart() {
    synchronized (o) {
      try {
	while (!startFlag) {o.wait();}
      }
      catch (InterruptedException ie) {} //Never happen!
    }
  }

public void run () {

  int iterations = totalCS/nThreads;

  barrier1.barrierPost();
  //waitStart();
  //System.out.println(count);
  for (int i = 0; i<iterations; i++) {
    flags[count].waitTrue();
    //    System.out.println(count);
    flags[count].setFalse();
    flags[(count+1)%nThreads].setTrue();
  }
  barrier.barrierPost();
}

public Test (int i) {
  super();
  count = i;
}



}


class Flag {
  boolean go = false;

  synchronized void setTrue() {
    go = true;
    notify();
  }

  synchronized void setFalse() {
    go = false;
  }

  synchronized void waitTrue() {
    try {
      while (!go) {wait();}
    }
    catch (InterruptedException ie) {} // Never happen
    
  }
}
