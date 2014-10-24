/** 
 * Class TMFrame implements the user interface for ThreadMon.
 */

import java.awt.Frame;
import java.awt.List;
import java.awt.Button;
import java.awt.Panel;
import java.awt.Event;
import java.awt.Font;
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.Scrollbar;
import java.awt.TextField;
import java.awt.Label;
import java.applet.Applet;

public class TMFrame extends Frame {
  private static String sccsid = null;
  private static String version = null;

  ThreadMon tm;
  List threadDisplayList;
  TextField priorityValue;
  Scrollbar priScrollbar;

  TMFrame(String name, ThreadMon t) {
    super(name);

    if (sccsid == null) {
      sccsid = "@(#)  TMFrame.java  1.3  96/02/29  18:14:24 TMFrame";
      version = "1.3";
    }

    tm = t;

    setLayout(new BorderLayout());
    Font ffn = new Font("Courier", Font.BOLD, 14);

    Label listhead = new Label(ThreadState.getHeader(), Label.LEFT);
    listhead.setFont(ffn);
    add("North", listhead);

    threadDisplayList = new List(10, false);
    threadDisplayList.setFont(ffn);
    add("Center", threadDisplayList);

    Panel bottomPanel = new Panel();
    bottomPanel.setLayout(new FlowLayout());

    Panel leftSubPanel = new Panel();
    leftSubPanel.setLayout(new FlowLayout());

    leftSubPanel.add(new Label("Priority (1-10)", Label.LEFT));
    priorityValue = new TextField(2);
    leftSubPanel.add(priorityValue);
    priScrollbar = new Scrollbar(Scrollbar.HORIZONTAL, 0, 1, 1, 10);
    leftSubPanel.add(priScrollbar);

    leftSubPanel.add(new Button("Suspend"));
    leftSubPanel.add(new Button("Resume"));
    leftSubPanel.add(new Button("Stop"));

    bottomPanel.add(leftSubPanel);

    Panel rightSubPanel = new Panel();
    rightSubPanel.setLayout(new FlowLayout());
 
    rightSubPanel.add(new Button("Refresh"));
    rightSubPanel.add(new Button("Quit"));
    bottomPanel.add(rightSubPanel);

    add("South", bottomPanel);

    pack();

  }

  public List getThreadDisplay() {
    return threadDisplayList;
  }

  // note: since setting a Thread's priority can fail, never propagate
  // a priority value set by the user. Only propagate one that's been
  // retrieved from the Thread itself.

  // Priority value propagation code is replicated and optimized for each
  // case to avoid generating extraneous screen updates.

  // note: The event handling code below assumes that only one
  // Scrollbar, List, and TextField exists in the TMFrame.
 
  public boolean handleEvent(Event evt) {
    if (evt.id == Event.WINDOW_DESTROY) {
      bail();
      return true;
    }
    else if (evt.target instanceof Scrollbar) {
      int val = ((Scrollbar)evt.target).getValue();
      int sel = getThreadDisplay().getSelectedIndex();
      if (sel != -1) {
        tm.setThreadPriority(sel, val);
        int pri = tm.getThreadPriority(sel);
        if (pri != -1) {
          priorityValue.setText(Integer.toString(pri));
          ((Scrollbar) evt.target).setValue(pri);
        }
        getThreadDisplay().select(sel);
      }
      return true;
    }
    else {
      return super.handleEvent(evt);
    }
  }
      
  public boolean action(Event evt, Object arg) {
    if (evt.target instanceof TextField) {
      int val = Integer.valueOf((String) arg).intValue();
      int sel = getThreadDisplay().getSelectedIndex();
      if (sel != -1) {
        tm.setThreadPriority(sel, val);
        int pri = tm.getThreadPriority(sel);
        if (pri != -1) {
          priorityValue.setText(Integer.toString(pri));
          priScrollbar.setValue(pri);
        }
        getThreadDisplay().select(sel);
      }
      return true;
    }
    else if (evt.target instanceof List) {
      int sel = getThreadDisplay().getSelectedIndex();
      if (sel != -1) {
        tm.getThreadPriority(sel);
        int pri = tm.getThreadPriority(sel);
        if (pri != -1) {
          priorityValue.setText(Integer.toString(pri));
          priScrollbar.setValue(pri);
        }
        getThreadDisplay().select(sel);
      }
      return true;
    }
    else if (evt.target instanceof Button) {

      String lbl = ((Button) evt.target).getLabel();

      if (lbl.equals("Refresh")) {
        tm.refreshThreadDisplay();
        return true;
      }
      else if (lbl.equals("Suspend")) {
        int sel = getThreadDisplay().getSelectedIndex();
        if (sel != -1) {
          tm.suspendThread(sel);
        }
        return true;
      }
      else if (lbl.equals("Resume")) {
        int sel = getThreadDisplay().getSelectedIndex();
        if (sel != -1) {
          tm.resumeThread(sel);
        }
        return true;
      }
      else if (lbl.equals("Stop")) {
        int sel = getThreadDisplay().getSelectedIndex();
        if (sel != -1) {
          tm.stopThread(sel);
        }
        return true;
      }
      else if (lbl.equals("Quit")) {
        bail();
        return true;
      }
      else return false;
    }
    else return false;
  }

/* quit the thread monitor, get rid of the frame */

  private void bail() {
          hide();
          dispose();
          tm.shutdown();
  }

}
