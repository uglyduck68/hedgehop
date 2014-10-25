/**
 *  ThreadState -- used by the ThreadMon class to maintain a representation
 *  of the runtime state of a Java Thread. This class also maintains instance
 *  variables which track various things involved in the updating and
 *  displaying activities undertaken by ThreadMon.
 */

public class ThreadState {
  private static String sccsid = null;
  private static String version = null;

 // Thread state variables   
 Thread thr;
 String name;
 ThreadGroup group;
 int priority;
 boolean isDaemon;
 boolean isAlive;

 // String representation of a Thread's state, for display purposes
 String dispString;

 // housekeeping variables
 boolean markFlag; // for mark-sweep algorithm; used to purge dead Threads 
 boolean updated;  // true is state updated since last display
 boolean displayed; // true if Thread's state has been displayed

 ThreadState(Thread t) {
   this(t, t.getName(), t.getThreadGroup(), t.getPriority(),
        t.isDaemon(), t.isAlive());
 } 

 ThreadState(Thread t, String n, ThreadGroup g, int p, boolean d, boolean a) {

    if (sccsid == null) {
      sccsid = "@(#)  ThreadState.java  1.2  96/01/17  17:26:26 ThreadState";
      version = "1.2";
    }

    update(t, n, g, p, d, a);
    displayed = false;
 }

/**
 * update a ThreadState object. This method is called when the update algorithm
 * discovers that the state of a Thread has changed.
 */

 void update(Thread t, String n, ThreadGroup g, int p, boolean d, boolean a) {
   thr = t;
   name = n;
   group = g;
   priority = p;
   isDaemon = d;
   isAlive = a;

   dispString = toThreadDesc();
   markFlag = true;
   updated = true;
 }

 /**
  * update the ThreadState object to reflect a Thread's new priority, and
  * indicate that the ThreadState has changed.
  */

 void updatePriority(int p) {
   priority = p;
   dispString = toThreadDesc();
   updated = true;
 }

 /**
  * update the ThreadState object to reflect whether the  Thread is alive, and
  * indicate that the ThreadState has changed.
  */

 void updateAlive(boolean a) {
   isAlive = a;
   dispString = toThreadDesc();
   updated = true;
 }

 /** 
  * compare the saved ThreadState with the argument values.
  * The thread monitor doesn't use anequals(ThreadState t) since that would
  * mean creating a new ThreadState object just to do the comparison, which
  * would generate lots of garbage in the update algorithm
  */

 boolean equals(Thread t, String n, ThreadGroup g,
                int pri, boolean d, boolean a) {
   return ((thr == t)
           && (name.equals(n))
           && (group == g)
           && (priority == pri)
           && (isDaemon == d)
           && (isAlive == a));
 }

 void clearMark() {
   markFlag = false;
 }

 void setMark() {
   markFlag = true;
 }

 void setDisplayed() {
   displayed = true;
 }

 void clearUpdated() {
   updated = false;
 }

/*
 * Returns a string that contains a formatted representation of argument
 * ThreadState t's public state. 
 */

 private String toThreadDesc() {
     try {

       String n = name;
       if (name == null)
         n = "unknown thread";

       String g;
       if ((group == null) || (group.getName() == null))
         g = "unknown group";
       else
         g = group.getName();

          return strFormat(n, 35) + " "
                 + strFormat(g, 20) + " "  
                 + strFormat(Integer.toString(priority), 3) + " "
                 + strFormat(new Boolean(isDaemon).toString(), 6) + " "
                 + strFormat(new Boolean(isAlive).toString(), 5);
      } catch (Exception e) {
        return strFormat("unknown thread with bad state",
                         getHeader().length() );
      }
        
   }

 /** Return a header string corresponding to the names of the fields in
  *  the strings maintained by the dispString property of this class
  */

 public static String getHeader() {
   return strFormat("Name", 35)
     + " " + strFormat("Group", 20) + " Pri Daemon Alive";
 }

/* helper method -- pads String out with spaces to width len
 */

 private static String strFormat(String s, int len) {
      if (s == null)
        s = " ";

      // pad string out to constant width
      int sl = s.length();

      if (sl < len) {
          for (int i = 0; i < len - sl; i++) {
            s = s + " ";
          }
      }
      else if (s.length() > len) {
        s = s.substring(0, len);
      }
     return s;
  }

}
