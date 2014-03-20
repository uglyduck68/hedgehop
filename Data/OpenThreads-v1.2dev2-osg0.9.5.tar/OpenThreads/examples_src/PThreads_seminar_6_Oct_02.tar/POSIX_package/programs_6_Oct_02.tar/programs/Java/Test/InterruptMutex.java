//              Extensions/InterruptMutex.java

import Extensions.*;
import java.io.*;


// This class in NOT cancellation-safe.

public class InterruptMutex implements Runnable {
  static Mutex m = new Mutex();
  boolean sleep;


public InterruptMutex(boolean w)
    {sleep = w;}

public static void main(String argv[]) {
  Thread t[] = new Thread[10];

  for (int i=0; i<5; i++)
    {t[i] = new Thread(new InterruptMutex(false), ("T@" + (i + 10)));
    t[i].start();
    }
  for (int i=5; i<10; i++)
    {t[i] = new Thread(new InterruptMutex(true), ("T@" + (i + 10)));
    t[i].start();
    }
  try {
    Thread.sleep(250);
  }
  catch (InterruptedException ie) {System.out.println(ie + " impossible");}
  for (int i=5; i<10; i++) {
    System.out.println("Interrupting " + t[i].getName());
    t[i].interrupt();
    try {
      Thread.sleep(500);
    }
    catch (InterruptedException ie) {System.out.println(ie + " impossible");}
  }
  System.out.println("Main exiting");
}
  

public void run() 
    {
      interruptMutex(sleep);
    }


public void interruptMutex(boolean sleep)  {
  Thread self = Thread.currentThread();

  try {
    for (int i=0; i<10; i++) {
      System.out.println(self.getName() + " Locking: " + m);
      m.lock();
      System.out.println(self.getName() + " Got   lock: " + m);
      if (sleep) Thread.sleep(250);
      System.out.println(self.getName() + " Releasing   lock: " + m);
      m.unlock();
      if (sleep) Thread.sleep(250);
    }
  }
  catch (InterruptedException ie) {
    System.out.println(self.getName() + " interrupted.");
  }
  System.out.println(self.getName() + " done!");
}

}
