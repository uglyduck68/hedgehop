//              Extensions/List.java

/*
  Lisp style lists of objects.
  */


package Extensions;


public class List {
public Object                   first;
public List                     next;
public static List              nil = new List(null, null);


public List cons (Object f) {
  List newlist = new List(f, this);
  return newlist;
}


public List(Object f, List l) {
  first = f; next = l;
}


public List(Object f) {
  first = f; next = List.nil;
}


public List() {
  first = List.nil; next = List.nil;
}


public boolean empty() {
  return (this == List.nil);
}

 
public Object[] makeArray() {
  int           length = this.length();
  List          list = this;
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
  List          list = this;
  int           i = 0;

  while (!list.empty()) {
    i++;
    list = list.next;
  }
  return i;
}


public void print() {
  List          list = this;

  System.out.println("(");
  while (!list.empty()) {
    if (list.first == List.nil)
      System.out.println("()");
    else
      System.out.println(" " + list.first.toString());
    list = list.next;
  }
  System.out.println(")");
}


public String toString() {
  List          list = this;

  String s  = "\n(";
  while (!list.empty()) {
    s = s + " " + list.first.toString();
    list = list.next;
  }
  s = s + ")\n";
  return(s);
}

}
