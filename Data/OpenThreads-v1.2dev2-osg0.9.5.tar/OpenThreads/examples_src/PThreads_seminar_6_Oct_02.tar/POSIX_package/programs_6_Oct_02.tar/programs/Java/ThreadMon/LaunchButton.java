import java.awt.*;

/////////////////////////////////////////////////////////////////////////
// A button which displays a frame when pressed.
// This is suitable for launching an applet.
/////////////////////////////////////////////////////////////////////////
public class LaunchButton extends Button {

  Frame frame;

  LaunchButton(Frame f, String s) {

    frame = f;
    setLabel(s);

  }

  public boolean action(Event event, Object obj) {
 
    frame.show();
    return true;
 
  }
}
