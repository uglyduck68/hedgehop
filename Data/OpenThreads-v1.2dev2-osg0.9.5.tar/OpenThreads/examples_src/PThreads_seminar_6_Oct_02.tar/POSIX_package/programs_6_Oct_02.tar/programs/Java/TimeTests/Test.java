//              TimeDisk/Test.java

/*
  Run a pile of timing tests and do statistics. No real surprises
  here. A few things are somewhat different than in native threads,
  but nothing that would cause me to radically alter a program design.

  Probably the biggest thing is relative speed of VOLATILE vs.
  synchronized sections, implying that Dekker's algorithm is a viable
  alternative in some circumstances.  (I'd still avoid it and stick with
  locks.)

  Note that many factors affect the runtime of a program. Placement
  of the JVM in core will cause times vary by upwards of 20%(!). So
  don't put too much stock in the Std. Dev. numbers you get.

  On my 110MHz SS4, Java 1.2:

Test(seconds/test: 1 iterations: 10)

Test                    Mean(uS)        Std. Dev.
Volatile set            0.076           0.004
Global accessed         0.075           0.004
Threads created         1560.           91.73
Context switched        74.57           2.590
Interrupt               21.46           2.124
Interrupted             21.90           1.421
Disable Intrs           47.99           3.848
Fake TSD                3.372           0.259
Local sync'd            3.266           0.222
Fun sync'd              3.476           0.224
Notify                  6.175           0.240
Semaphore               22.65           5.225
RWLock                  77.67           5.228
Mutex                   28.72           1.759


*/


import java.io.*;
import java.util.*;
import Extensions.*;


public class Test { 
  static int           mult=1, iterations=1;
  static boolean       DEBUG; 

public static void main(String argv[]) {
 
  if (argv.length > 0) mult = Integer.parseInt(argv[0]); 
  if (argv.length > 1) iterations = Integer.parseInt(argv[1]); 
  if (System.getProperty("DEBUG") != null) DEBUG = true;
  System.out.println("Test(seconds/test: " + mult
                     + " iterations: " + iterations + ")");
  if (iterations > 1)
    System.out.println("\nTest\t\t\tMean(uS)\tStd. Dev.");
  else
    System.out.print("\nTest\t\t\tMean(uS)");


  test(new TimeCreate(),              150*mult, "Threads created  ");
  test(new TimeContext(),            3000*mult, "Context switched ");
  test(new GetProperty(),          180000*mult, "GetProperty      ");
  test(new TimeMillisecs(),        250000*mult, "Millisecs        ");
  test(new TimeDateMs(),           160000*mult, "DateMs           ");
  test(new TimeVolatile(),        9000000*mult, "Volatile set     ");
  test(new TimeGlobal(),          9000000*mult, "Global accessed  ");
  test(new TimeInterrupt(),        150000*mult, "Interrupt        ");
  test(new TimeInterrupted(),      150000*mult, "Interrupted      ");
  test(new TimeEnableDisableInterruption(),
                                    80000*mult, "Disable Intrs    ");
  test(new TimeFakeTSD(),          400000*mult, "Fake TSD         ");
  //  test(new TimeTSDget(),        10000*mult, "TSD get          ");
  //  test(new TimeTSDset(),        10000*mult, "TSD set          ");
  test(new TimeSyncLocal(),        700000*mult, "Local sync'd     ");
  test(new TimeSyncFun(),          700000*mult, "Fun sync'd       ");
  test(new TimeNotify(),           180000*mult, "Notify           ");
  test(new TimeCondSignal(),       130000*mult, "Cond Signal      ");
  test(new TimeSem(),              100000*mult, "Semaphore        ");
  test(new TimeRWLock(),            25000*mult, "RWLock           ");
  test(new TimeMutex(),             70000*mult, "Mutex            ");
  test(new DiscriminationNet(),   8000000*mult, "DiscriminationNet");
  test(new DiscriminationNet2(),  5000000*mult, "DiscriminationNet2");
  test(new TimeGarbage(),          100000*mult, "Garbage          ");
  test(new TimeGarbage2(),         100000*mult, "Garbage2         ");
  test(new TimeGarbage3(),         100000*mult, "Garbage3         ");
  test(new TimeGarbagePool(),      100000*mult, "GarbagePool      ");
  test(new TimeGarbageList(),      100000*mult, "GarbageList      ");
  test(new TimeGarbagePool2(),      20000*mult, "GarbagePool2     ");
  System.out.println("\nDone.");
  System.exit(0);
}


public static void test(TimedObject o, int n, String s) {
  long                  end, start;
  double                time, runTime_sum=0.0, mean, S=0.0;
  double[]              runTimes = new double[iterations];

  o.test(n/10);
  o.test(n/10);

  if (iterations == 1) System.out.println();
  System.out.print(s);
  if (DEBUG) System.out.println();

  for (int i=0; i<iterations; i++) {
    start = new Date().getTime();

    o.test(n);

    end = new Date().getTime();
    time = ((double) (end-start))/n;

    if (DEBUG)
      System.out.print(n + " times in "
                       + (end-start) + " mS.");

    if (iterations==1 || DEBUG) {
      System.out.print("\t" + new String((time*1000)+"  ").substring(0, 5));
    }
    if (DEBUG) System.out.println();
    runTimes[i] =  time;
    runTime_sum += time;
  }
  
  
  if (iterations>1) {
    mean = runTime_sum/iterations;

    for (int i=0; i<iterations; i++) S+=(mean-runTimes[i])*(mean-runTimes[i]);
    S = Math.sqrt(S/(iterations-1));
    if (S<0.000001) S = 0.000001;
    System.out.println("\t" + new String((mean*1000)+"  ").substring(0, 5)
                       + "\t\t"
                       + new String((S*1000)+"  ").substring(0, 5));
  }
}

}


