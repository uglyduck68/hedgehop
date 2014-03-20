//              OneQueueSolution/Workpile.java

/*
  A Workpile consists of a list of Requests plus the
  synchronization variables required to protect that list.
  The List is a simple linked list. (Vectors are too slow!)

  Notice that the synchronization variables are provided,
  but not USED in any of the methods here. The callers of
  these methods are responsible for the synchronization
  (as it should be!).

*/



import java.io.*;
import java.util.*;
import Extensions.*;


public class Workpile {
  LinkedList	list = new LinkedList();
  int           max = 10;
  boolean       stop = false;


public synchronized void add(Request request) {
  try {
    while (full()) {wait();}
    list.add(request);
    notify();
  }
  catch (InterruptedException ie) {System.out.println("Impossible!");}
}
  

public synchronized Request removeFirst() {
  Request request=null;

  try {
    while (empty()) {wait();}
    request = (Request) list.removeFirst();
    notify();
  }
  catch (InterruptedException ie) {System.out.println("Impossible!");}
  return(request);
}

  
public boolean empty() {
  return(list.size() == 0);
}


public boolean full() {
  return(list.size() == max);
}


public int size() {
  return(list.size());
}
}
