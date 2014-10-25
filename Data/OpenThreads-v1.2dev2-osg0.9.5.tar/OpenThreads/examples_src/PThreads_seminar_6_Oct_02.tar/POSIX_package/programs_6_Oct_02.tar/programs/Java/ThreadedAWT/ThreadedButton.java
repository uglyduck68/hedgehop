//              ThreadedAWT/ThreadedButton.java

/*
  Once this did something useful...
*/


import java.applet.*;
import java.awt.*;
import Extensions.*;



public class ThreadedButton extends Button {

public ThreadedButton(String s) {
  super(s);
}

public String toString() {
  return("ThreadedButton_" + getLabel());
}

}
