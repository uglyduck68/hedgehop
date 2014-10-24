//              TestTimeout/TestTimeout.java


import java.io.*;
import Extensions.*;



public class TestTimeout implements Runnable { 
  long                  initialTimeout;
  static long           testStartTime;
  static boolean        condition = false;



public TestTimeout(int i) {initialTimeout = i;}


public synchronized void run() {
  String                selfName = Thread.currentThread().getName();
  long                  timeRemaining, now=0;
  long                  time = initialTimeout;

  while (!condition) {
    timeRemaining = NIWait(time);
    now = System.currentTimeMillis();
    System.out.println(now-testStartTime + "\t" + selfName
                       + "\t[" + initialTimeout + ", " + timeRemaining
                       + "]  \t\t" + condition
                       + "\t  " + Thread.interrupted());
    if (timeRemaining==0) break;
    time = timeRemaining;
  }
  System.out.println(now-testStartTime + "\t" + selfName + " \texiting");
}



public void test() {
  TestTimeout           t1, t2, t3;
  Thread                T1, T2, T3;
  long                  now;
  Thread                self = Thread.currentThread();

  testStartTime = System.currentTimeMillis();
  T1=new Thread(t1 = new TestTimeout(0));
  T1.start();
  T2=new Thread(t2 = new TestTimeout(500));
  T2.start();
  T3=new Thread(t3 = new TestTimeout(1500));
  T3.start();
  for (int i = 0; i <10; i++) {
    InterruptibleThread.sleep(100);
    now = System.currentTimeMillis();
    System.out.println("\n" + (now-testStartTime) + "\tmain \tpinging...");
    synchronized (t1) {t1.notify();}
    synchronized (t2) {t2.notify();}
    synchronized (t3) {t3.notify();}
    now = System.currentTimeMillis();
    Thread.yield();
    System.out.println((now-testStartTime) + "\tmain \tfinished pinging.\n");
    if (i == 2) {T1.interrupt(); T2.interrupt(); T3.interrupt();}
    if (i == 5) {condition = true;}
  }
  System.out.println("Exiting.");
}

  
public long NIWait(long timeout) {
  Thread        self = Thread.currentThread();
  long          now, timeSoFar, startTime, timeRemaining, maxWaitTime;

  timeRemaining = maxWaitTime = timeout;
  startTime = System.currentTimeMillis();

  try {wait(timeout);}
  catch (InterruptedException ie) {
    now = System.currentTimeMillis();
    timeSoFar = now - testStartTime;
    System.out.println(timeSoFar + "\t" + self.getName()
                       + "\tinterrupted. (Reinterrupting...)");
    self.interrupt();
  }

  now = System.currentTimeMillis();
  timeSoFar = now - startTime;
  timeRemaining =  (maxWaitTime - timeSoFar);
  System.out.println(now - testStartTime + "\t" + self.getName()
                     + "\t[" + initialTimeout + ", " + timeRemaining
                     + "] woken.");
  if (timeSoFar > maxWaitTime) {
    System.out.println(now-testStartTime + "\t" + self.getName()
                       + "\t[" + initialTimeout + ", " + timeRemaining
                       + "] timed out.");
    return 0;
  }
  return timeRemaining;
}


public static void main(String[] args) throws Exception {

  System.out.println(
   "\n\nTime  Thread  \t[requested, remaining]  Condition Interrupted?");
  System.out.println(
   "======================================================================");
  TestTimeout t = new TestTimeout(0);
  t.test();   
}
  
}
