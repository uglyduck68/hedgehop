//              StopQueueSolution/Workpile.java

import java.io.*;
import java.util.*;
import Extensions.*;


public class Workpile {
  LinkedList list = new LinkedList();
  int length = 0;
  public int max = 1000;
  Mutex mutex = new Mutex();
  ConditionVar producerCV = new  ConditionVar();
  ConditionVar consumerCV = new  ConditionVar();
public boolean stop = false;
  
public void Workpile(int i) {
  max = i;
}

  
public void add(Item item) {

  list.add(item);
  length++;
}

  
public Item removeFirst() {
  Item item = (Item) list.removeFirst();
 
  length--;
  return(item);
}

  
public boolean empty() {

  return(length == 0);
}

  
public int size() {

  return(length);
}

  
public boolean full() {

  return(length == max);
}

}
