
import java.util.*;
import java.io.*;
import Extensions.*;


public class TimeGarbagePool implements TimedObject {
  static TimeGarbagePool p[] = new TimeGarbagePool[100];

  static {
  for (int i=0; i<100; i++) {
    p[i] =  new TimeGarbagePool();
  }}

  
public   void test(int n) { 
  
  for (int i=0; i<n; i++) 
    {
      TimeGarbagePool g = getGP();
    } 
}


  
public synchronized TimeGarbagePool getGP() {
 TimeGarbagePool g = null;

  for (int i=0; i<100; i++) {
    g = p[i];
    if (i == 50) break;
  }

  return(g);
}

}
