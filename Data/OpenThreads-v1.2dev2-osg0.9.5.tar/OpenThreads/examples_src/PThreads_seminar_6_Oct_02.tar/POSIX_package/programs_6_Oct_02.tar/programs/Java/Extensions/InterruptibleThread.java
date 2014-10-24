//              Extensions/InterruptibleThread.java

/*
  This class implements a non-interruptable sleep() and wait().
  
  It implements a enable/disable mechanism for both interrupt() and stop()
  and implements a exit() method as syntatic sugar.
  */



package Extensions;


import java.io.*;
import java.util.*;


public class InterruptibleThread extends Thread {
  boolean       interruptsEnabled = false;
  boolean       interruptPending = false;
  boolean       stopPending = false;
  boolean       stopEnabled = false;
  static int    INTERATIONS_PER_US = 1;


public InterruptibleThread(Runnable r) {
  super(r);
}
    
public InterruptibleThread() {
  super();
}
    

public static void sleep(long time)  {
  boolean interrupted = false;

  if (time == 0L) return;
  try {Thread.sleep(time);}
  catch (InterruptedException ie) {interrupted=true;} // Don't worry about time.
  if (interrupted) Thread.currentThread().interrupt();
}


public static void calibrateSpin() {
  long start = new Date().getTime();
  spin(1000000);
  long end = new Date().getTime();
  double duration = end-start;
  INTERATIONS_PER_US = (int) (INTERATIONS_PER_US * (1000/duration));
  //  System.out.println("new INTERATIONS_PER_US " + INTERATIONS_PER_US
  //                 + " duration " + duration);
}


public static int spin(int time) {
  int           j=0;    // Dummy to prevent compiler optimizations
 
  for (int i=0;i<time*INTERATIONS_PER_US;i++) j++;
  return j;
}



public void wait(boolean t) {
  boolean       interrupted = false;

  try {super.wait();}
  catch (InterruptedException ie) {interrupted=true;}
  if (interrupted) Thread.currentThread().interrupt();
}


public static void impossible(Object o) {
  InterruptibleThread self = (InterruptibleThread)Thread.currentThread();

  System.out.println(self + " at " + o +
		     " in an impossible state. Fix your code!");
  System.exit(1);
}


public static void enableInterrupts() {
  InterruptibleThread self = (InterruptibleThread)Thread.currentThread();

  synchronized (self) {
    self.interruptsEnabled = true;
    if (self.interruptPending) self.interrupt();
    self.interruptPending = false;
  }
}


public static void disableInterrupts() {
  InterruptibleThread self = (InterruptibleThread) Thread.currentThread();

  synchronized (self) {
    if (interrupted()) self.interruptPending = true; 
    self.interruptsEnabled = false;
  }
}


public synchronized void interrupt() {
  if (interruptsEnabled)
    super.interrupt();          // Really send the interrupt now
  else
    interruptPending = true;
}


  // Yes, stop() is deprecated. This is an example of possibilities only.
public static void enableStop() { 
  InterruptibleThread self = (InterruptibleThread) Thread.currentThread();

  synchronized (self) {
    if (self.stopPending) Thread.currentThread().stop();
    self.stopEnabled = true;
    self.stopPending = false;
  }
}

public static void disableStop() {
  InterruptibleThread self = (InterruptibleThread) Thread.currentThread();

  synchronized (self) {
    if (self.stopPending)
      InterruptibleThread.exit();       // If already stopped, exit.
    self.stopEnabled = false;
  }
}


public synchronized void stop(boolean t) {
  stopPending = true;
  if (stopEnabled) {Thread.currentThread().stop();}
}


public static void exit() {
  Thread.currentThread().stop();
}


public void join(boolean t) {
  boolean       interrupted = false;

  while (true) {
    try {super.join(); break;}
    catch (InterruptedException ie) {interrupted=true;}
  }
  if (interrupted) Thread.currentThread().interrupt();  
}

}
