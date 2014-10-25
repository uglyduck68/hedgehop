//              Extensions/ConditionVar.java

/*
  A Pthreads style condition variable.

  Note that if you use these, you must handle InterruptedException
  carefully. condWait() will return as if from a spurious wakeup
  if interrupted. If your code allows interrupts to be sent, you
  MUST look at InterruptedException inside of the while() loop:

  while (!condition) {
    condWait(m);
    if (Thread.interrupted()) {throw something/do something!}
    }

*/



package Extensions;

import java.io.*;

public class ConditionVar {


public void condWait(Mutex mutex) {
  boolean       interrupted = false;

  if (Thread.interrupted()) interrupted=true;

  synchronized (this) {
    mutex.unlock();
    try {
      wait();
    }
    catch (InterruptedException ie) {interrupted=true;}
  }

  mutex.lock();
  if (interrupted) Thread.currentThread().interrupt();
}



public void condWait(Mutex mutex, long timeout) {
  boolean       interrupted = false;

  if (Thread.interrupted()) interrupted=true;

  synchronized (this) {
    mutex.unlock();
    try {
      wait(timeout);
    }
    catch (InterruptedException ie) {interrupted=true;}
  }

  mutex.lock();
  if (interrupted) Thread.currentThread().interrupt();
}



public synchronized void condSignal() {
  notify();
}

public synchronized void condBroadcast() {
  notifyAll();
}

}
