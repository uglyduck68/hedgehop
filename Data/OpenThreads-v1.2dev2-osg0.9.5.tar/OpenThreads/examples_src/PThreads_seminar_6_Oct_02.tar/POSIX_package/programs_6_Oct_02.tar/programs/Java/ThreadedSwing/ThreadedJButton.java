//              ThreadedSwing/ThreadedJButton.java

/*
  Once upon a time this was an interesting class.  Now it
  provides a nice print string.
*/


import java.applet.*;
import java.awt.*;
import javax.swing.*;
import Extensions.*;



public class ThreadedJButton extends JButton {


public ThreadedJButton(String s) {
  super(s);
}


public String toString() {
  return("ThreadedJButton_" + getText());
}

}
