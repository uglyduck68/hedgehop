//             ThreadedSwing/ThreadButtonListener.java

/*
  This classes listens only for button pushes on the
  "Threaded" / "Non-Threaded" button.

*/

import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import Extensions.*;



public class ThreadButtonListener implements ActionListener  {


public void actionPerformed(ActionEvent event) {
  ThreadedJButton currentButton = (ThreadedJButton)event.getSource();

  System.out.println("Pressed " + currentButton);
  ThreadedSwing.useThreads = !ThreadedSwing.useThreads;
  if (ThreadedSwing.useThreads)
    currentButton.setText("Threaded");
  else
    currentButton.setText("Non-Threaded");
}

}
