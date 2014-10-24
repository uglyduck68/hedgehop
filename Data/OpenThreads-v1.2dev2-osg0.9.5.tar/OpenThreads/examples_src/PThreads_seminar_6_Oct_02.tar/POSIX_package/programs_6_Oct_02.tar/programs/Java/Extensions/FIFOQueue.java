//              Extensions/FIFOQueue.java

/*
  Nice idea, but Vector is horribly inefficent for this purpose.
  */

package Extensions;
import java.util.*;


public class FIFOQueue {
  LinkedList list = new LinkedList();
 

public void add(Object object) {
  list.add(object);
}

  
public Object removeFirst() {
  Object        object = (Object) list.removeFirst();
  return(object);
}

  
public boolean empty() {
  return(list.size() == 0);
}

  
public int size() {
  return(list.size());
}

}
 
