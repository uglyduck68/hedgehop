//             ThreadedSwing/ThreadedSwing.java

/*
  When the user pushes a button, disable it and sleep for 6 seconds.
  If "Threaded", then do the sleeping in a new thread, allowing the
  other buttons to remain active. If "Non-Threaded" then do the sleeping
  in the SWING thread, effectively disabling the other buttons.

  After sleeping, reenable the button by calling invokeLater().
  (Swing is NOT thread-safe.)

  CF: Same program in AWT: ThreadedAWT and in PThreads: ThreadWin.c

*/


import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import Extensions.*;



public class ThreadedSwing extends JFrame {
  static boolean        useThreads = false;
  static boolean        KILL = true;



public ThreadedSwing() {
  ThreadedJButton       button;

  setTitle("ThreadedSwing");
  JPanel topPanel = new JPanel();
  getContentPane().add(topPanel);

  ThreadButtonListener tbl = new ThreadButtonListener();
  NumericButtonListener nbl = new NumericButtonListener();

  button = new ThreadedJButton("Non-Threaded");
  topPanel.add(button);
  button.addActionListener(tbl);

  for (int i=1; i<5; i++) {
    button = new ThreadedJButton(""+i);
    topPanel.add(button);
    button.addActionListener(nbl);
  }
}


public static void main(String args[]) {
  ThreadedSwing         mainFrame = new ThreadedSwing();

  mainFrame.pack();
  mainFrame.setVisible(true);
  // Killer MUST be in another thread.
  if (KILL) new Thread(new Killer(120)).start();
}
 
}
