//              Extensions/TestCV.java

import java.io.*;
import Extensions.*;


// This class in NOT cancellation-safe.

public class TestCV implements Runnable {
  static Mutex m = new Mutex();
  static ConditionVar cv1 = new ConditionVar();
  static boolean ready = false;
  boolean writer;
  static Thread thr;


public TestCV(boolean w) {
  writer = w;
}

public static void main(String argv[]) {
  Thread t;

  for (int i=0; i<1; i++) {
    t = new Thread(new TestCV(false), ("T@" + (i + 10)));
    t.start();
  }

  for (int i=0; i<1; i++) {
    t = new Thread(new TestCV(true), ("T@" + (i + 0)));
    t.start();
  }
}

public void run() {
  Thread self = Thread.currentThread();
 
  if (writer) {thr=self;
    for (int i=0; i<2; i++) {
      System.out.println(self.getName() + " Locking: " + m);
      m.lock();
      System.out.println(self.getName() + " Got   lock: " + m);
      InterruptibleThread.sleep(50);
      while (!ready) {
        System.out.println(self.getName() + " waiting: " );
        cv1.condWait(m);
      }
      System.out.println(self.getName() + " Releasing   lock: " + m);
      ready = false;
      m.unlock();
      InterruptibleThread.sleep(10);
    }
  }

  if (!writer) {
    for (int i=0; i<2; i++) {
      System.out.println(self.getName() + " Locking: " + m);
      InterruptibleThread.sleep(500);
      m.lock();
      System.out.println(self.getName() + " Got   lock: " + m);
      thr.interrupt();
      System.out.println(self.getName() + " Interrupted thr ");
      cv1.condSignal();
      System.out.println(self.getName() + " Signaled thr ");
      ready = true;
      //         ready = false;
      m.unlock();
      System.out.println(self.getName() + " Releasing   lock: " + m);
      System.out.println(self.getName() + " Signaling: " + m);
      //cv1.condBroadcast();
      InterruptibleThread.sleep(10);
    }
  }
  System.out.println(self.getName() + " done!");

}

}
