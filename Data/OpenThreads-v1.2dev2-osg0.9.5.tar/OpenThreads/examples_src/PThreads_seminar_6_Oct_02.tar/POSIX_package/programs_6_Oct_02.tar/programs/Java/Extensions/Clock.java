//              Extensions/Clock.java

/*
  */


package Extensions;

import java.io.*;


public class Clock implements Runnable {
  static long startTime = 0, time = 0;
  static boolean DEBUG = false;


  static void start() {
    new Thread(new Clock(), "Clock Thread").start();
    reset();
  }


  static void reset() {
    startTime = System.currentTimeMillis();
  }


  static long time() {
    return time;
  }


  public void run() {
    while (true) {
      try {
	Thread.sleep(1);
      }
      catch (InterruptedException ie) {}
      time = System.currentTimeMillis() - startTime;
      if (DEBUG) System.out.println("Time: " + time);
    }
  }


public static void main(String[] args) throws Exception {

  DEBUG = true;
  Clock.start();
  try {
    Thread.sleep(1000);
  }
  catch (InterruptedException ie) {}
  System.exit(0);
}

}
