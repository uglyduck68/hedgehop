//              ThreadedAWT/ThreadedAWT.java



/*
  When the user pushes a button, disable it and sleep for 6 seconds.
  If "Threaded", then do the sleeping in a new thread, allowing the
  other buttons to remain active. If "Non-Threaded" then do the sleeping
  in the SWING thread, effectively disabling the other buttons.

  After sleeping, reenable the button in the same thread.
  (AWT is thread-safe.)

  CF: Same program in Swing: ThreadedSwing and in PThreads: ThreadWin.c

*/


import java.applet.*;
import java.awt.*;
import Extensions.*;



public class ThreadedAWT extends Applet {
  static boolean        useThreads = false;
  static boolean        KILL = true;

  
public void init() {
  ThreadedButton button;


  button = new ThreadedButton("Non-Threaded");
  add(button);
  for (int i=1; i<5; i++) {
    button = new ThreadedButton(""+i);
    add(button);
  }
  if (KILL) new Thread(new Killer(120)).start();
  resize(600, 100);
}


  // This method listens for all button pushes.

public boolean action(Event event, Object arg) {
  ThreadedButton currentButton = (ThreadedButton)event.target;

  if (!(currentButton instanceof ThreadedButton)) return(false);

  System.out.println("Pressed " + currentButton);

  // For the "Threaded" button.
  if (currentButton.getLabel() == "Non-Threaded") {
    currentButton.setLabel("Threaded");
    useThreads = true;
    return(true);
  }
  if (currentButton.getLabel() == "Threaded") {
    currentButton.setLabel("Non-Threaded");
    useThreads = false;
    return(true);
  }

  // For the numeric buttons.
  currentButton.setEnabled(false);
  System.out.println(currentButton + " disabled.");
  Worker w = new DoWork(currentButton);

  if (useThreads) 
    new Thread(w).start();
  else 
    w.run();
  return true;
}

}
