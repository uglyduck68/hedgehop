//              StopQueueSolution/Item.java

import java.io.*;

public class Item extends Object {
  int count;

public Item() {
  count = 0;
}

public Item(int i) {
  count = i;
}

public String toString() {

  return("<Item " + count + ">");
}
 
}
