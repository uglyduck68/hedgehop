import java.io.*;
import Extensions.*;

 

public class TimeSem implements TimedObject {
  static Semaphore sem = new Semaphore();

public void test(int n) { 

  for (int i=0; i<n; i++) {
    sem.semPost();
    sem.semWait(); 
  }
}
}
