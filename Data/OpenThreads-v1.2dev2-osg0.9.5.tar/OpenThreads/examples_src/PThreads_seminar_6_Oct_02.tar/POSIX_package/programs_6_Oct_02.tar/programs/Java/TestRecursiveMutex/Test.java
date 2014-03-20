//              TestRecursiveMutex/Test.java

/*

  Test your recursive mutex.  Replace "RecursiveMutex" with
  "MyRecursiveMutex", then write it!

*/

import java.io.*;
import Extensions.*;


public class Test implements Runnable {
  static String                 s[] =
  {"", "*", "**", "***", "****", "*****"};
  static RecursiveMutex         mutex = new RecursiveMutex();
  static SingleBarrier          barrier;
  static boolean                KILL = false;

public static void main(String argv[]) {
  Thread                t;

  barrier = new SingleBarrier(3);
  if (System.getProperty("KILL") != null) KILL = true;
  if (KILL) new Thread(new Killer(120)).start();
  System.out.println("Starting recursive test...");
  
  for (int j=0; j<3; j++) {
    t = new Thread(new Test());
    t.start();
  }

  barrier.barrierWait();
  System.out.println("Done.");
  System.exit(0);    
}

public void run() {

  recursive(5);
  barrier.barrierPost();
}


public void recursive(int i) {
  String                name = Thread.currentThread().getName();
  int                   j = 6-i;

  if (i > 0) {
    System.out.println(name + " Trying to enter level " + j + "   \t" + s[j]);
    mutex.lock();
    System.out.println(name + " Entered         level " + j + "   \t" + s[j]); 
    InterruptibleThread.sleep(100);
    recursive(i-1);
    mutex.unlock();
    System.out.println(name + " Leaving         level " + j + "   \t" + s[j]);
  }
}

}
