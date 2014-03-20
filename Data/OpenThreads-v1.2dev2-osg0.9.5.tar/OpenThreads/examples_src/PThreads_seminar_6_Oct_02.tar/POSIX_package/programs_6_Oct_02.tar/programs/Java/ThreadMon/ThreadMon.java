/**
 * ThreadMon is a thread monitor applet for Java virtual machines.
 *
 */

import java.applet.Applet;
import java.util.Vector;
import java.awt.List;
import java.awt.GridLayout;

public class ThreadMon extends Applet implements Runnable {

  private static String sccsid = null;
  private static String version = null;

  private static int threadMonCount = 0;  // # of ThreadMons ever instantiated 

  long sampleInterval;     // delay between thread state samples
  Thread thr = null;
  TMFrame tmFrame;
  Vector thrState;
  boolean shutdown;

  public void init() {
    if (sccsid == null) {
      sccsid = "@(#)  ThreadMon.java  1.3  96/02/29  18:14:59 ThreadMon";
      version = "1.3";
    }

    shutdown = false;
    sampleInterval = 1000;
    thrState = new Vector(10);

    tmFrame = new TMFrame("Fusion ThreadMon: Thread Monitor for Java " + version, this);
    setLayout(new GridLayout(1, 0));
    LaunchButton b = new LaunchButton(tmFrame, "Press to Start ThreadMon");
    add(b);

    thr = new Thread(this,
                     "ThreadMonitor"
                     + (((++threadMonCount) > 1) ? ("-" + threadMonCount):""));
    thr.start();

  }

  public void run() {

    while (!shutdown) {
      updateThreadStates();
      try { 
        Thread.sleep(sampleInterval);
      } catch (InterruptedException e) {
            return;
          };
    }
  }

  public void stop() {
    statusMsg("ThreadMon.stop called.");
  }

  public void shutdown() {
    statusMsg("Shutting down Thread Monitor");
    shutdown = true;
    if (thr != null) {
      thr.stop();
      thr = null;
    }
  }

  public void destroy() {
      super.stop();
    }

  private void statusMsg(String s) {
    try {
      showStatus(s);
    } catch (NullPointerException e) {  // handle exception if not Applet
      System.out.println(s);
    }
  }

    /**
     * Gets the root ThreadGroup of the Java Virtual Machine. This
     * method assumes that the current Thread is a member of a ThreadGroup
     * which is a descendant of the root ThreadGroup. 
     */
   
    public ThreadGroup rootThreadGroup()
    {
      ThreadGroup parent;
      ThreadGroup rootGroup;

      parent = Thread.currentThread().getThreadGroup();
      do
        {
          rootGroup = parent;
          parent = parent.getParent();
        } while (parent != null);

      return rootGroup;
    }

/**
 * Print a list of all ThreadGroups that currently exist in the 
 * Java virtual machine and are descendants of the root ThreadGroup.
 * The list is printed on the System out stream.
 */

    public void printThreadGroups()
      {

      ThreadGroup rootGroup = rootThreadGroup();

      System.out.println("ThreadGroups: "
                         + (rootGroup.activeGroupCount() + 1));

      System.out.println(rootGroup.toString());
      ThreadGroup threadGroups[]
        = new ThreadGroup[rootGroup.activeGroupCount()];
      rootGroup.enumerate(threadGroups);

      for (int i = 0; i < threadGroups.length; i++)
        {
          System.out.println(threadGroups[i].toString());
        }
    }

/**
 * Print a list of all Threads that currently exist in the 
 * Java virtual machine and who are members of ThreadGroups which
 * are descendants of the root ThreadGroup. The list is printed on
 * the System out stream.
 */
    public void printThreads()
      {
        ThreadGroup rootGroup = rootThreadGroup();

        System.out.println("Threads: " + rootGroup.activeCount());

        Thread threads[]= new Thread[rootGroup.activeCount()];
        rootGroup.enumerate(threads);

        System.out.println(ThreadState.getHeader());

        for (int i = 0; i < threads.length; i++ )
        {
          System.out.println(new ThreadState(threads[i]).dispString);
        }
          
      }

/**
 * (Re)Build the threadState vector, clear the display widget, 
 * 
 */
    public synchronized void refreshThreadDisplay() {
        tmFrame.getThreadDisplay().clear();
        thrState.removeAllElements();
        updateThreadStates();
      }

/**
 * Creates and maintains Vector of ThreadState objects that represents
 * the state of all Threads that this applet has access to in the Java
 * virtual machine. The ThreadState vector is maintained for the sole
 * purpose of minimizing the number of display updates ThreadMon initiates.
 *
 * ThreadMon assumes that all Threads are in ThreadGroups that
 * are reachable from one tree of ThreadGroups, and it assumes that
 * it's own ThreadGroup is a leaf on that tree.
 *
 * Once the ThreadState vector has been created, updateThreadStates checks
 * each Thread for state changes, adds a a new ThreadState for any newly
 * created Threads, and gets rid of any ThreadState objects that correspond
 * to Threads that no longer exist.
 *
 * Finally, it calls another method to actually update the display of the
 * Threads and their states.
 *
 * This method doesn't create any new objects unless it has to,
 * so that the thread monitor doesn't become a drain on the virtual machine.
 * As a result, the code is not as simple as one might expect.
 *
 * A mark-sweep scheme is employed to ensure that ThreadStates aren't
 * maintained for Threads that have disappeared since the last update.
 *
 */

    public synchronized void updateThreadStates()
      {
        ThreadGroup rootGroup = rootThreadGroup();

        Thread threads[]= new Thread[rootGroup.activeCount()];
        rootGroup.enumerate(threads);

        boolean changed = false; 

        clearMarksAndUpdated();

        for (int i = 0; i < threads.length; i++ ) {
          Thread t = threads[i];

          String name = t.getName();
          ThreadGroup g = t.getThreadGroup();
          int pri = t.getPriority();
          boolean d = t.isDaemon();
          boolean a = t.isAlive();

          if (thrState.size() == 0) {
            thrState.addElement(new ThreadState(t, name, g, pri, d, a));
            changed = true;
          } 
          else {
            int s = thrState.size();
            boolean found = false;
            for (int j = 0; j < s; j++) {
              ThreadState el = (ThreadState) thrState.elementAt(j);
              if (el.thr.equals(t)) {
                found = true;
                el.setMark(); //mark so we don't kill off later
                if (!el.equals(t, name, g, pri, d, a)) {
                  el.update(t, name, g, pri, d, a);
                  changed = true;
                }
                break;
              }
                
            } // for j
            if (!found) {
              thrState.addElement(new ThreadState(t, name, g, pri, d, a));
              changed = true;
            }
          } // else
        } // for i

        if (changed)
          updateThreadDisplay();

        reapUnmarked();

  } // updateThreadState() 

 synchronized void clearMarksAndUpdated() {
    int s = thrState.size();
    if (s == 0) return;
    for (int i = 0; i < s; i++) {
      ThreadState el = ((ThreadState) thrState.elementAt(i));
      el.clearMark();
      el.clearUpdated();
    }
 }

/*
 * Deletes dead Threads from the ThreadState vector and from the
 * display widget.
 */
 
  synchronized boolean reapUnmarked() {
    boolean changed = false;
    int s = thrState.size();
    List dl = tmFrame.getThreadDisplay();
    for (int i = 0; i < s; i++) {
      if (((ThreadState) thrState.elementAt(i)).markFlag == false) {
        thrState.removeElementAt(i);
        dl.delItem(i);
        i--;
        s--;
        changed = true;
      }
    }
    return changed;
 }

/**
 * Perform the actual update of the thread display widget.
 * This merely sweeps through the ThreadState vector, and
 * updates the list widget's element corresponding to Threads
 * that need to be updated. New threads are added onto the end
 * of the list. Dead threads are deleted elsewhere.
 *
 * The use of List.replace() to update the display can cause
 * temporary blanks to appear in the display when things are
 * changing rapidly, since Java 1.0 Beta 2 implements replace()
 * as a delete()/add().
 */

  public void updateThreadDisplay() {
    int s = thrState.size();
    if (s == 0) return;

    List dl = tmFrame.getThreadDisplay();

    for (int i = 0; i < s; i++) {
      ThreadState ts = ((ThreadState) thrState.elementAt(i));
      if (ts.updated == true) {
        if (ts.displayed == true) {
          dl.replaceItem(ts.dispString, i);
        } else {
          dl.addItem(ts.dispString);
          ts.setDisplayed();
        }
        ts.clearUpdated();
      }
    }
 }

  public synchronized void stopThread(int s) {
    if ((s > thrState.size() - 1) || (s < 0)) return;
    ThreadState ts = ((ThreadState) thrState.elementAt(s));
    try {
      if (ts.thr.isAlive()) {
        ts.thr.stop();
        ts.updateAlive(ts.thr.isAlive());
      }
    } catch (SecurityException e) {
      statusMsg("Security exception stopping thread " + ts.thr.getName());
    }
    updateThreadDisplay();
  }

  public synchronized void suspendThread(int s) {
    if ((s > thrState.size() - 1) || (s < 0)) return;
    ThreadState ts = ((ThreadState) thrState.elementAt(s));
    try {
      ts.thr.suspend();
    } catch (SecurityException e) {
      statusMsg("Security exception suspending thread " + ts.thr.getName());
    }
  }

  public synchronized void resumeThread(int s) {
    if ((s > thrState.size() - 1) || (s < 0)) return;
    ThreadState ts = ((ThreadState) thrState.elementAt(s));
    try {
      ts.thr.resume();
    } catch (SecurityException e) {
      statusMsg("Security exception resuming thread " + ts.thr.getName());
    }
  }

  public synchronized void incrementThreadPriority(int s) {
    if ((s > thrState.size() - 1) || (s < 0)) return;
    ThreadState ts = ((ThreadState) thrState.elementAt(s));
    int pri;
    try {
      pri = ts.thr.getPriority();
    } catch (SecurityException e) {
      statusMsg("Security exception getting priority for " + ts.thr.getName());
      return;
    }
    setThrPri(ts, pri + 1);
  }

  public synchronized void decrementThreadPriority(int s) {
    if ((s > thrState.size() - 1) || (s < 0)) return;
    ThreadState ts = ((ThreadState) thrState.elementAt(s));
    int pri;
    try {
      pri = ts.thr.getPriority();
    } catch (SecurityException e) {
      statusMsg("Security exception getting priority for " + ts.thr.getName());
      return;
    }
    setThrPri(ts, pri - 1);
  }

  public synchronized void setThreadPriority(int s, int pri) {
    if ((s > thrState.size() - 1) || (s < 0)) return;
    ThreadState ts = ((ThreadState) thrState.elementAt(s));
    setThrPri(ts, pri);
  }

  private synchronized void setThrPri(ThreadState ts, int pri) {
    if ((pri < Thread.MIN_PRIORITY) || (pri > Thread.MAX_PRIORITY))
      return;
    try {
      ts.thr.setPriority(pri);
      ts.updatePriority(ts.thr.getPriority());
    } catch (SecurityException e) {
      statusMsg("Security exception setting priority for " + ts.thr.getName());
      return;
    }
    updateThreadDisplay();
  }

  public synchronized int getThreadPriority(int s) {
    if ((s > thrState.size() - 1) || (s < 0)) return -1;
    ThreadState ts = ((ThreadState) thrState.elementAt(s));
    int pri;
    try {
      pri = ts.thr.getPriority();
    } catch (SecurityException e) {
      statusMsg("Security exception getting priority for " + ts.thr.getName());
      return -1;
    }
    return pri;
  }

  public static void main(String args[]) {
    ThreadMon tm = new ThreadMon();
    tm.init();
    tm.start();
   }
}

