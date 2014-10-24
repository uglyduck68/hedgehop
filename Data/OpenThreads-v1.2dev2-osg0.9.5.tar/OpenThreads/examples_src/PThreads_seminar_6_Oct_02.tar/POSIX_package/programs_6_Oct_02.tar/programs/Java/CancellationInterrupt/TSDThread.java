//              CancellationInterrupt/TSDThread.java

/*
  Add a bit of Thread-Specific Data.
  */

import java.io.*;
import java.util.*;
import Extensions.*;


public class TSDThread extends Thread {
 boolean inCriticalSection = true;

  
public TSDThread(Searcher o) {
  super(o); 
}

}
