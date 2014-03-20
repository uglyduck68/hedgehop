import java.io.*;
import Extensions.*;


public class TimeFakeTSD extends Thread implements TimedObject {
  static SingleBarrier barrier = new SingleBarrier(1);
  static int n = 1000;
  int j = 0;

 
public void run() {
  for (int i=0; i<n; i++)
    {((TimeFakeTSD)Thread.currentThread()).j++;}
  barrier.barrierPost();
}

  

public  void test (int n)  {

  this.n = n; 
  Thread t = new TimeFakeTSD();
  t.start();
  barrier.barrierWait(); 
}
 

}
