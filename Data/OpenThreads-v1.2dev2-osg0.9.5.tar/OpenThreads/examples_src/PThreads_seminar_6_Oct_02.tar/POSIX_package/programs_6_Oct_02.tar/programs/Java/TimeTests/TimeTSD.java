import java.io.*;
import Extensions.*;


public class TimeTSD extends Thread implements TimedObject {
  static SingleBarrier barrier = new SingleBarrier(1);
  static int n = 1000;
  int j = 0;

 
public void run() {
  for (int i=0; i<n; i++)
    {((TimeTSD)Thread.currentThread()).j++;}
  barrier.barrierPost();
}

  

public  void test (int n)  {

  this.n = n; 
  Thread t = new TimeTSD();
  t.start();
  barrier.barrierWait(); 
}
 

}
