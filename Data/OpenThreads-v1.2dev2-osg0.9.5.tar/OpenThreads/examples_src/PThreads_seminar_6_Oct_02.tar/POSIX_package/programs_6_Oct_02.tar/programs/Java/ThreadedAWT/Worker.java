//             ThreadedAWT/Worker.java

import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import Extensions.*;



public class Worker implements Runnable {
  ThreadedButton        button;

public void run() {}
}



class DoWork extends Worker {
  
public DoWork(ThreadedButton b) {
  button = b;
}


public void run() {
  doWork();
}

public void doWork() {          // Run in any thread.
  Thread selfName = Thread.currentThread();

  System.out.println(button + " sleeping... " + selfName);
  InterruptibleThread.sleep(6000);
  System.out.println(button + " done. " + selfName);

  // This will run workComplete() in the current thread. A bit awkward
  // for AWT, this makes a nice contrast to the Swing code.
  new WorkComplete(button).run();
}

}


class WorkComplete extends Worker {
  
public WorkComplete(ThreadedButton b) {
  button = b;
}


public void run() {
  workComplete();
}

public void workComplete() {
  Thread selfName = Thread.currentThread();

  button.setEnabled(true);
  System.out.println(button + " reenabled. " + selfName);
}
}
