//             ThreadedSwing/NumericButtonListener.java

/*
  This classes listens only for button pushes on the numbered buttons.
*/


import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import Extensions.*;



public class NumericButtonListener implements ActionListener  {


public void actionPerformed(ActionEvent event) {
  ThreadedJButton currentButton = (ThreadedJButton)event.getSource();

  System.out.println("Pressed " + currentButton);
  currentButton.setEnabled(false);
  System.out.println(currentButton + " disabled.");
  DoWorker w = new DoWorker(currentButton);

  if (ThreadedSwing.useThreads) 
    new Thread(w).start();
  else 
    w.run();
}

}



class DoWorker implements Runnable {
  ThreadedJButton       button;

  
public DoWorker(ThreadedJButton b) {
  button = b;
}



public void run() {
  Thread selfName = Thread.currentThread();

  System.out.println(button + " sleeping... " + selfName);
  InterruptibleThread.sleep(6000);
  System.out.println(button + " done. " + selfName);

  // This will run workComplete() in Swing main thread.
  // This is the main point of the whole example.
  SwingUtilities.invokeLater(new DidWorker(button));
}

}


class DidWorker implements Runnable {
  ThreadedJButton       button;

  
public DidWorker(ThreadedJButton b) {
  button = b;
}

public void run() {    // Run only in Swing main thread.
  Thread selfName = Thread.currentThread();

  button.setEnabled(true);
  System.out.println(button + " reenabled. " + selfName);
}
}
