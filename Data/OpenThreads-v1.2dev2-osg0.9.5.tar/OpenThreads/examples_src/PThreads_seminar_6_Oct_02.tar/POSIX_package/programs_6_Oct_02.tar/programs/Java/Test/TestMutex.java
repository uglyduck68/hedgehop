//              Extensions/TestMutex.java

package Extensions;

import java.io.*;


// This class in NOT cancellation-safe.

public class TestMutex implements Runnable {
  static Mutex          m = new Mutex();
  boolean               writer;


public TestMutex(boolean w)
    {writer = w;}

public static void main(String argv[]) {
  Thread t;

  for (int i=0; i<5; i++)
    {t = new Thread(new TestMutex(false), ("T@" + (i + 10)));
    t.start();
    }
}
  

public void run() {
  Thread self = Thread.currentThread();

  for (int i=0; i<10; i++) {
    System.out.println(self.getName() + " Locking: " + m);
    m.lock();
    System.out.println(self.getName() + " Got   lock: " + m);
    InterruptibleThread.sleep(50);
    System.out.println(self.getName() + " Releasing   lock: " + m);
    m.unlock();
    InterruptibleThread.sleep(10);
    }
  System.out.println(self.getName() + " done!");
}

}
