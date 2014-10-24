//              OneQueueProblem/Consumer.java

import java.io.*;
import Extensions.*;

public class Consumer implements Runnable {
  Workpile              workpile;
  SingleBarrier         barrier;

public Consumer(Workpile w, SingleBarrier b) {
  workpile = w;
  barrier= b;
}


public void run() {
  Request               request;
 
  while (true) { 
    request = workpile.removeFirst(); 
    request.process();
  } 
}
}
