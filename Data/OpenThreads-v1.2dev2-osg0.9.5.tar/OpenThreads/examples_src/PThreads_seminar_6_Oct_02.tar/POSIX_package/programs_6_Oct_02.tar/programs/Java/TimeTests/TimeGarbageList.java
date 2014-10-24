
import java.util.*;
import java.io.*;
import Extensions.*;


public class TimeGarbageList implements TimedObject {
  static TimeGarbageList list = null;

  static {
  for (int i=0; i<100; i++) {
    TimeGarbageList p =  new TimeGarbageList();
    p.next=list;
    list=p;
  }}

  TimeGarbageList next;

  
public   void test(int n) { 
  
  for (int i=0; i<n; i++) 
    {
      TimeGarbageList g = getGP();
      putGP(g);
    } 
}


  
public synchronized TimeGarbageList getGP() {
 TimeGarbageList g = null;

 g=list;
 list=list.next;
 return(g);
}

public synchronized void putGP(TimeGarbageList g) {

 g.next=list;
 list=g;
}

}
