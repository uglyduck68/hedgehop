//              TimeDisk/Test.java

/*

  This program runs a set of read() calls against one large file.
  It runs with one or more threads so you can see the performance
  effect of MT.  Each read() gets one byte from a random location.
  You can run it for a number of iterations & get mean & SD.

  Make sure that there are links in /tmp pointing to wherever you
  can find room. The file must be smaller than MAX_INT (ie <2g
  for 32-bit OS).

  grep "avail mem" /var/adm/messages.* | head -1

  /usr/sbin/mkfile 1g  /disk2/6/temp_disk_test
  ln -s /disk2/6/temp_disk_test /tmp/time_disk0.tmp

  lrwxrwxrwx   1 bil other ... time_disk0.tmp -> /disk2/6/temp_disk_test

  The file must be much larger than physical memory.  10x would be great,
  but 2x will do.  Expect "performance" to improve as the mbufs get
  loaded.  For a file 2x Physical, initial 100/s will improve to 200/s
  (as 50% of the file will become cached).  To populate the cache, you
  can run this program for a while. If your file is too small, and the
  read rate exceeds 200/s, the program will abort and tell you.

  runtime    = (Physical Memory / PAGE_SIZE)   / READS_PER_SECOND
  eg:
  160seconds = (128MB          / (8KB/PAGE))  / 100

  
  NB: This only runs under Java 2.
  CF: Same program in C: time_disk.c

*/


import java.io.*;
import java.util.*;
import Extensions.*;


public class Test implements Runnable {
  static int            MAX_FILE_SIZE=1024*1024*1024; // for 32-bit OS
  static int            PAGE_SIZE=8192;
  static int            MAX_PAGES=(MAX_FILE_SIZE/PAGE_SIZE);
  static int            MAX_THREADS=512;
  static int            MAX_DENSITY=100;
  static int            MAX_READS;
  static int[]          hits = new int[MAX_PAGES];
  static int[]          density = new int[MAX_DENSITY];
  static String         path="/tmp/time_disk0.tmp";
  static int            spinTime = 0, runtime=10, nThreads = 1;
  static int            iterations=1;
  static boolean        setConcurrency=false;
  static int[]          nProcessed;
  static boolean        DEBUG=false;
  static Thread[]       threads;
  static boolean        stop=false;

  static native void pthread_setconcurrency(int i);
  static {System.loadLibrary("PThreadsInterface");}
  // System.out.println("Loaded");}

  Random                ran;
  int                   me;






public void run() {
  int                   err;
  long                  length;
  byte[]                b = new byte[2];
  RandomAccessFile      fd=null;
  long                  fileOffset;
  Thread                self=Thread.currentThread();

  try {
    fd = new RandomAccessFile(path, "r");
    length = fd.length();
    if ((length < 0) || (length > MAX_FILE_SIZE))
      throw(new IOException("Tmp file too big!"));

    for (int i = 0; i < MAX_READS; i++) {
      if (stop) return;
      fileOffset =  Math.abs((ran.nextInt() * PAGE_SIZE) % length);
      hits[(int) fileOffset/PAGE_SIZE]++;
      //if (DEBUG)
      // System.out.println(t + " reading at " + fileOffset);

      fd.seek(fileOffset);
      err=fd.read(b, 0, 1);
      if (err == -1) {throw new IOException();} 
      InterruptibleThread.spin(spinTime*1000);
      nProcessed[me]++;

      // It's interesting to see the results of yield() here when
      // using >1 GREEN THREADS.  (The results are what you expect --
      // same performance only spread to all threads.)
      // You would never include this in a "real" program.
      if (!setConcurrency) Thread.yield();
      
    }
    stop = true; // If one thread completes MAX_READS, all quit.
    fd.close();  // This is probably because you're using GREEN THREADS.
    System.out.println("Read rate > 200/s. File is memory-resident?");
    System.exit(1);
  }
  catch (IOException e) {
    System.out.println("Is " + path + " correct? \n" +e);
    System.exit(1);
  }
}



public static void main(String argv[]) throws Exception {
  int           totalProcessed;
  double[]      rates = new double[MAX_THREADS];
  double        S=0.0, mean, rate_sum=0.0, realtime;
  Thread        t;

  if (argv.length > 0) nThreads = Integer.parseInt(argv[0]);
  if (argv.length > 1) spinTime = Integer.parseInt(argv[1]);
  if (argv.length > 2) runtime = Integer.parseInt(argv[2]);
  if (argv.length > 3) iterations = Integer.parseInt(argv[3]);
  if (argv.length > 4) setConcurrency = (Integer.parseInt(argv[4]) == 1);
  if (System.getProperty("DEBUG") != null) DEBUG = true;
  System.out.println("Test(nThreads: " + nThreads
		     + " spinTime: " + spinTime
                     + "ms runtime: " + runtime
                     + "s iterations " + iterations
                     + " setConcurrency: " + setConcurrency
                     + ")");

  if (spinTime>0) InterruptibleThread.calibrateSpin();

  MAX_READS = 200*runtime;              // About 2x fastest 1999 disk
  nProcessed=new int[nThreads];
  threads=new Thread[nThreads];
  if (setConcurrency) pthread_setconcurrency(nThreads+1);

  for (int j=0;j<iterations;j++) {

    for (int i=0;i<MAX_PAGES;i++) hits[i] = 0;
    for (int i=0;i<MAX_DENSITY;i++) density[i]=0;
    for (int i=0;i<nThreads;i++) nProcessed[i]=0;
    totalProcessed=0;
 
    long start = new Date().getTime();
    for (int i=0;i<nThreads;i++) {
      Random ran = new Random(start+i);
      t = new Thread(new Test(i, ran));
      t.start();
      threads[i] = t;
    }

    start = new Date().getTime();
    InterruptibleThread.sleep(runtime*1000);
    stop = true;   
    for (int i=0;i<nThreads;i++) {threads[i].join();}
    long end = new Date().getTime();
    realtime = ((end - start)/1000.0);

    for (int i=0;i<nThreads;i++) {
      if (DEBUG)
        System.out.println("Thread " + i + " processed \t"
			   + nProcessed[i]);
      totalProcessed +=nProcessed[i];
    }

    for (int i=0;i<MAX_PAGES;i++) {
      if (hits[i] < MAX_DENSITY)
        density[hits[i]]++;
      else
        if (DEBUG)
          System.out.println("Page " + i + " got " + hits[i] + " hits!");
    }

    if (DEBUG) {
      System.out.println("nHits \t nPages");
      for (int i=0;i<MAX_DENSITY;i++) {
        if (density[i]>0) System.out.println(i + "\t " + density[i]);
      }
    }

    if (iterations==1)
      System.out.println("Processed " + totalProcessed + " in " + realtime
                         + "s. Rate\t" + (totalProcessed/realtime) + "/s.");
    rates[j] =  totalProcessed / realtime;
    rate_sum += totalProcessed / realtime;
    stop=false;
  }

  if (iterations>1) {
    mean = rate_sum/iterations;

    for (int i=0; i<iterations; i++) S+=(mean-rates[i])*(mean-rates[i]);
    S = Math.sqrt(S/(iterations-1));
    System.out.println("Mean rate: " + mean
                       + "/sec, Standard Deviation: " + S);
  }
  System.exit(0);
}



public Test(int i, Random r) {
  ran = r;
  me = i;
}

}
