//              HeatFlow2/Worker.java

import java.io.*;
import Extensions.*;

public class Worker implements Runnable {
  int                   delay;
  SingleBarrier         barrier;
  State oldState,       newState;
  int                   centerStart, centerEnd, nIterations;


public Worker(State s,  SingleBarrier b, int d, int cs, int ce, int n) {
  delay = d;
  barrier= b;
  centerStart = cs;
  centerEnd = ce;
  newState = s;
  nIterations = n;
}


public void run() {
  String                selfName = Thread.currentThread().getName();

  newState.barrier.barrierPost();       // This state complete.
   
  for (int i = 0; i < nIterations; i++) {
    oldState = newState;
    newState = newState.next;

    for (int j = centerStart+1; j < centerEnd-1; j++) {
      oldState.transform(newState, j);
    }
      
    oldState.barrier.barrierWait(); // Wait till complete.
    oldState.transform(newState, centerStart);
    oldState.transform(newState, centerEnd-1);
    newState.barrier.barrierPost(); // Done using oldState?
      
    if (Test.DEBUG) {
      System.out.println(selfName + " completed interation " + i);
      if (centerStart == 0) newState.print(i+1);
    }
  }   
  barrier.barrierPost();
}
  
}
