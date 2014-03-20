//              Extensions/Killer.java

/*
  Kill the program after a while.
*/


package Extensions;



public class Killer implements Runnable {
  int           delay;


public Killer(int d) {
  delay = d;
}

public void run() {
  InterruptibleThread.sleep(delay*1000);
  System.out.println("Timed out! (Hung?)  Die! Die! Die!");
  System.exit(-1);
}

}
