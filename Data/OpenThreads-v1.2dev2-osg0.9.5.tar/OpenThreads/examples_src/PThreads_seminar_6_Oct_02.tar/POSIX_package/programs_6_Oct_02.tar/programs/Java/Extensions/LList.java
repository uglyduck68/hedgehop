//              Extensions/LList.java

/*
  Lisp style lists of objects.
  */


package Extensions;


public class LList {
public Object                   first;
public LList                    next;
public static LList             nil = new LList(null, null);


public LList cons (Object f) {
  LList newlist = new LList(f, this);
  return newlist;
}


public LList(Object f, LList l) {
  first = f; next = l;
}


public LList(Object f) {
  first = f; next = LList.nil;
}


public LList() {
  first = LList.nil; next = LList.nil;
}


public boolean empty() {
  return (this == LList.nil);
}

 
public Object[] makeArray() {
  int           length = this.length();
  LList         list = this;
  int           i = 0;
  Object[]      a = new Object[length];

  while (!list.empty()) {
    a[i] = list.first;
    i++;
    list = list.next;
  }
  return a;
}


public int length() {
  LList         list = this;
  int           i = 0;

  while (!list.empty()) {
    i++;
    list = list.next;
  }
  return i;
}


public void print() {
  LList          list = this;

  System.out.println("(");
  while (!list.empty()) {
    if (list.first == LList.nil)
      System.out.println("()");
    else
      System.out.println(" " + list.first.toString());
    list = list.next;
  }
  System.out.println(")");
}


public String toString() {
  LList          list = this;

  String s  = "\n(";
  while (!list.empty()) {
    s = s + " " + list.first.toString();
    list = list.next;
  }
  s = s + ")\n";
  return(s);
}

}
