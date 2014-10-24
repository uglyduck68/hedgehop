import java.io.*;
import java.util.*;
import Extensions.*;


public class TimeContext  implements TimedObject, Runnable {
  static SingleBarrier barrier = new SingleBarrier(2);
  static int n = 1000;
  static Object obj = new Object();
  TimeContext him;
  boolean myTurn;


public void run() {
  Thread self = Thread.currentThread();
       
  for (int i=0; i<n; i++) {
    try {
      synchronized (obj) {
	while (!myTurn) obj.wait();
	//	System.out.println(self.getName());
	myTurn = false;
	him.myTurn = true;
	obj.notify();
      }
    }
    catch (InterruptedException ie) {}
  }
  barrier.barrierPost();  
}


/*
public void run() {
  Thread self = Thread.currentThread();
       
  for (int i=0; i<n; i++) {
    Thread.yield();
  }
  barrier.barrierPost();  
}
*/


public void test(int n) { 

  TimeContext.n = n;
  TimeContext timecontext1 = new TimeContext();
  TimeContext timecontext2 = new TimeContext();
  timecontext1.him = timecontext2;
  timecontext2.him = timecontext1;
  timecontext1.myTurn = false;
  timecontext2.myTurn = true;
  Thread t1 = new Thread(timecontext1);
  Thread t2 = new Thread(timecontext2);
  
  t2.start();
  t1.start();
  barrier.barrierWait();  
}
 
}
