
import java.util.*;
import java.io.*;
import Extensions.*;


public class TimeGarbagePool2 implements TimedObject {
  static TimeGarbagePool2 p[] = new TimeGarbagePool2[100];
  TimeGarbagePool2 q[] = new TimeGarbagePool2[100];

  static {
  for (int i=0; i<100; i++) {
    p[i] =  new TimeGarbagePool2();
  }}

  
public   void test(int n) { 
  
  for (int i=0; i<n; i++) 
    {
      TimeGarbagePool2 g = getGP();
    } 
}


  
public synchronized TimeGarbagePool2 getGP() {
 TimeGarbagePool2 g = null;

  for (int i=0; i<100; i++) {
    g = p[i];
    if (i == 50) break;
  }

  for (int i=0; i<100; i++) {
    g.q[i] = null;
  }

  return(g);
}

}
