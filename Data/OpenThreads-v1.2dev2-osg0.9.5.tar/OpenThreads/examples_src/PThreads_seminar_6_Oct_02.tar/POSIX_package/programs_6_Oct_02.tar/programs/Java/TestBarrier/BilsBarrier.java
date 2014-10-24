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

  /*
public synchronized void barrierWait() {
  try {
    currentCount++;
    while (currentCount < initialCount) {wait(); wait(40);}
    notifyAll();
  }
  catch (InterruptedException ie) {System.exit(10);}
}

*/

public synchronized void barrierWait() {
  boolean lastIn = false;

  try {
    while (leavingCount>0) {wait();}
    currentCount++;
    if (currentCount == initialCount) {lastIn = true;}
    while (currentCount < initialCount) {wait(); wait(40);}
    leavingCount++;
    if (lastIn) notifyAll();
    if (leavingCount==initialCount) {
      currentCount=0;
      leavingCount=0;
      notifyAll();
    }
  }
  catch (InterruptedException ie) {System.exit(10);}
}

}
