import java.io.*;
import Extensions.*;


public class TimeEnableDisableInterruption
        extends InterruptibleThread implements TimedObject {
  static SingleBarrier barrier = new SingleBarrier(1);
  static int n = 1000;
 
public void run() {
  for (int i=0; i<n; i++) {
    InterruptibleThread.disableInterrupts();
    InterruptibleThread.enableInterrupts();
  }
  barrier.barrierPost();
}

  

public  void test (int n)  {

  this.n = n; 
  Thread t = new TimeEnableDisableInterruption();
  t.start();
  barrier.barrierWait(); 
}
 

}
