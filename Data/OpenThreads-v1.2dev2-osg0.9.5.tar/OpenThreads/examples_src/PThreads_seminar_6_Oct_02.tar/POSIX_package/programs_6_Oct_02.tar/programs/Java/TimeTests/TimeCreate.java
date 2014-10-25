
import java.util.*;
import java.io.*;
import Extensions.*;


public class TimeCreate implements Runnable, TimedObject {
  static SingleBarrier barrier = new SingleBarrier(1);

public void run()
    {barrier.barrierPost();  }

  

public   void test(int n) { 

  for (int i=0; i<n; i++) {
    Thread t = new Thread(new TimeCreate());
    t.start();
    //Thread.currentThread().yield();         This has no effect.
    barrier.barrierWait(); 
  } 
}

  /*


public   void test(int n) { 

  for (int i=0; i<n/10; i++) 
    {
      for (int ii=0; ii<10; ii++) {
	Thread t = new Thread(new TimeCreate());
	t.start();
      }
      //Thread.currentThread().yield();         This has no effect.
      barrier.barrierWait(); 
    } 
}
*/
}
