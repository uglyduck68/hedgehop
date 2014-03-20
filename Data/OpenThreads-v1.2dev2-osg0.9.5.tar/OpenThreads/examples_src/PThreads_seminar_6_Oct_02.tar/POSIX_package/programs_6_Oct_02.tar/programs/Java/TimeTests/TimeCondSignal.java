import java.io.*;
import Extensions.*;


public class TimeCondSignal
        extends InterruptibleThread implements TimedObject {
  static SingleBarrier barrier = new SingleBarrier(1);
  static int n = 1000;
	  ConditionVar v = new ConditionVar();
 
public void run() {
  for (int i=0; i<n; i++) {
    v.condSignal();
      }
  barrier.barrierPost();
}

  

public  void test (int n)  {

  this.n = n; 
  Thread t = new TimeCondSignal();
  t.start();
  barrier.barrierWait(); 
}
 

}
