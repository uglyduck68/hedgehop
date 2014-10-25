//              TestRecursiveMutex/MyRecursiveMutex.java

/*
  A very simple implementation of a barrier. Too bad it doesn't work...

			  Fix it!!
*/

import java.io.*;
import Extensions.*;


public class MyBarrier {
  int currentCount=0, initialCount=0, leavingCount=0;


public MyBarrier(int i) {
  initialCount = i;
}


public synchronized void barrierWait() {
  try {
    currentCount++;
    while (currentCount < initialCount) {wait(); wait(40);} // Leave in extra!
    notifyAll();
  }
  catch (InterruptedException ie) {System.exit(10);}
}

}
