//              OneQueueProblem/Producer.java

import java.io.*;
import Extensions.*;

public class Producer implements Runnable {
  Workpile      workpile;
  SingleBarrier barrier;
  Client        client;


public Producer(Workpile w,  Client c, SingleBarrier b) {
  workpile = w;
  client = c;
  barrier= b;
}


public void run() {
  Request request;

  while (true) {
    request = client.read();
    synchronized(workpile) {
      workpile.add(request);
      workpile.notify();
    }
  }
}
}
