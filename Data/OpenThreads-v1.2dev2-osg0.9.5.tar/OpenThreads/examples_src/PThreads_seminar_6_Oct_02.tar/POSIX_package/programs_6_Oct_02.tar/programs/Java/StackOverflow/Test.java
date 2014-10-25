//              /Test.java

/*
 
*/



public class Test extends Thread {
  static int i = 0;
  static int sum = 0;
  static int localVars=0;


public static void main(String[] argv) throws Exception {


  if (argv.length > 0) localVars = Integer.parseInt(argv[0]);
  System.out.println("Stack Overflow with " + localVars + " local variables");

  Test t = new Test();
  t.start();
}

public void run () {

  try {
    switch (localVars) {
    case   0:	recursive0();   break;
    case  10:   recursive10();  break;
    case  20:	recursive20();  break;
    case 100:	recursive100(); break;
    default:	System.out.println("Usage Test [0|10|20|100]");
    }
  } 
  //finally {
   catch (java.lang.StackOverflowError e) {
        System.out.println("Stack Overflow at: " + i + " ");
    //    System.out.println("Stack Overflow at: " + i + " " + e);
  }
}

  void recursive0 () { 
    i++;
    recursive0();
  }


  void recursive10 () {
    int i0=0, i1=0, i2=0, i3=0, i4=0, i5=0, i6=0, i7=0, i8=0, i9=0;
    //summ(i0, i1, i2, i3, i4, i5, i6, i7, i8, i9);
 
    i++;
    recursive10();
  }

  void recursive20 () { 
    int i0=0, i1=0, i2=0, i3=0, i4=0, i5=0, i6=0, i7=0, i8=0, i9=0;
    int j0=0, j1=0, j2=0, j3=0, j4=0, j5=0, j6=0, j7=0, j8=0, j9=0;
 
    i++;
    recursive20();
  }

  void recursive100 () { 
    int i0=0, i1=0, i2=0, i3=0, i4=0, i5=0, i6=0, i7=0, i8=0, i9=0;
    int j0=0, j1=0, j2=0, j3=0, j4=0, j5=0, j6=0, j7=0, j8=0, j9=0;
    int k0=0, k1=0, k2=0, k3=0, k4=0, k5=0, k6=0, k7=0, k8=0, k9=0;
    int l0=0, l1=0, l2=0, l3=0, l4=0, l5=0, l6=0, l7=0, l8=0, l9=0;
    int m0=0, m1=0, m2=0, m3=0, m4=0, m5=0, m6=0, m7=0, m8=0, m9=0; 
    int n0=0, n1=0, n2=0, n3=0, n4=0, n5=0, n6=0, n7=0, n8=0, n9=0;
    int o0=0, o1=0, o2=0, o3=0, o4=0, o5=0, o6=0, o7=0, o8=0, o9=0;
    int p0=0, p1=0, p2=0, p3=0, p4=0, p5=0, p6=0, p7=0, p8=0, p9=0;
    int q0=0, q1=0, q2=0, q3=0, q4=0, q5=0, q6=0, q7=0, q8=0, q9=0;
    int r0=0, r1=0, r2=0, r3=0, r4=0, r5=0, r6=0, r7=0, r8=0, r9=0;
 

summ(i0, i1, i2, i3, i4, i5, i6, i7, i8, i9);
summ(j0, j1, j2, j3, j4, j5, j6, j7, j8, j9);
summ(k0, k1, k2, k3, k4, k5, k6, k7, k8, k9);
summ(l0, l1, l2, l3, l4, l5, l6, l7, l8, l9);
summ(m0, m1, m2, m3, m4, m5, m6, m7, m8, m9);
summ(n0, n1, n2, n3, n4, n5, n6, n7, n8, n9);
summ(o0, o1, o2, o3, o4, o5, o6, o7, o8, o9);
summ(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
summ(q0, q1, q2, q3, q4, q5, q6, q7, q8, q9);
summ(r0, r1, r2, r3, r4, r5, r6, r7, r8, r9);

    i++;
    recursive100();


summ(i0, i1, i2, i3, i4, i5, i6, i7, i8, i9);
summ(j0, j1, j2, j3, j4, j5, j6, j7, j8, j9);
summ(k0, k1, k2, k3, k4, k5, k6, k7, k8, k9);
summ(l0, l1, l2, l3, l4, l5, l6, l7, l8, l9);
summ(m0, m1, m2, m3, m4, m5, m6, m7, m8, m9);
summ(n0, n1, n2, n3, n4, n5, n6, n7, n8, n9);
summ(o0, o1, o2, o3, o4, o5, o6, o7, o8, o9);
summ(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
summ(q0, q1, q2, q3, q4, q5, q6, q7, q8, q9);
summ(r0, r1, r2, r3, r4, r5, r6, r7, r8, r9);
  }

 void summ(int i0,int i1,int i2,int i3,int i4,int i5,int i6,int i7,int i8,int i9) {
    sum = i0+i1+i2+i3+i4+i5+i6+i7+i8+i9;
  }
}
