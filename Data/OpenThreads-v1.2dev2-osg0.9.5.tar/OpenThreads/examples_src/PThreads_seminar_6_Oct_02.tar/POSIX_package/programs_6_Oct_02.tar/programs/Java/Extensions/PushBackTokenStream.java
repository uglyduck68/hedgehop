//              Extensions/PushBackTokenStream.java

package Extensions;

import java.io.*;


public class PushBackTokenStream {
  static     Double d = new Double(0.0);

public boolean trace = false;
  static int TT_NUMBER = StreamTokenizer.TT_NUMBER;
  static int TT_WORD = StreamTokenizer.TT_WORD;

  File f;
public  FileInputStream fis;
public ThrowingPushbackInputStream  pis;
  int token;
  String sval;
  double nval;
  boolean buffered = false;

public PushBackTokenStream(String name) {

  try {
    f = new File(name);
    fis = new FileInputStream(f);
    pis = new ThrowingPushbackInputStream(fis);
  }
  catch (java.io.FileNotFoundException e) {
    System.out.println(e + " in PushBackTokenStream");
  }
}

private static boolean numberPrefix(char c1) {

  return  ((c1 == '.') || (c1 == '-') || (c1 == '+'));
}
private static boolean digit(char c1) {

  return  ((c1 >= '0') && (c1 <= '9'));
}

protected static boolean whiteSpace(char c1) {

  return  ((c1 == ' ') || (c1 == '\t') || (c1 == '\n') || (c1 == '\r'));
}


public void skipWhiteSpace() throws IOException {
  char c1;
  while (true) {
    c1 = (char) pis.read();
    if (whiteSpace(c1)) 
      continue;
    else {
      pis.unread(c1);
      break;
    }
  }
}

private String readString(char c1) throws IOException {
  StringBuffer b = new StringBuffer();

  while (!whiteSpace(c1)) {
    b.append(c1);
    c1 = (char) pis.read();
  }
  pis.unread(c1);
  return(new String(b));
}


public int nextToken() throws IOException {
  pis.endOfToken = -1;
  return(nextTokenInternal());
}

public int nextToken(int i) throws IOException {
  pis.endOfToken = i;
  i = nextTokenInternal();
  pis.endOfToken = -1;
  return(i);
}


public int nextTokenInternal() throws IOException {
  char c1, c2;
  {
    if (buffered) {
      buffered = false;
      return token;
    }
    skipWhiteSpace();
    c1 = (char) pis.read();

    if (numberPrefix(c1)) {
      c2 = (char) pis.read();
      if (digit(c2) || numberPrefix(c2)) {
        pis.unread(c2);
        nval = readNumberInternal(c1);
        token = TT_NUMBER;
        //System.out.println("nextToken: " + nval); 
        return token;
      }
      else {
        pis.unread(c2);
        sval = readString(c1);
        token = TT_WORD;
        //System.out.println("nextToken: " + sval); 
        return token;
      }
    }
    else
      if (digit(c1)) {
        nval = readNumberInternal(c1);
        token = TT_NUMBER;
        //System.out.println("nextToken: " + nval); 
        return token;
      }
      else {
        sval = readString(c1);
        token = TT_WORD;
        //System.out.println("nextToken: " + sval); 
        return token;
      }
  }
 
}   


private double readNumberInternal(char c1) throws IOException {
  char c2;
  double n = 0.0, exp = 0.0;
  int sign=1, psign = 1;

  if (c1 == '-') {
    sign =-1;
    c1 = (char) pis.read();
  }

  if (digit(c1)) {
    n = readInt(c1);
    c1 = (char) pis.read();
  }
       
  if (c1 == '.') {
    c1 = (char) pis.read();
    if (digit(c1)) {
      n = n + readFraction(c1);
      c1 = (char) pis.read();
    }}

  if ((c1 == 'E') || (c1 == 'e')) {
    c1 = (char) pis.read();
    if (c1 == '-') {
      psign =-1;
      c1 = (char) pis.read();
    }
    else
      if (c1 == '+') c1 = (char) pis.read();
    if (digit(c1)) {
      exp = psign * readInt(c1);
      n = n * Math.pow(10.0, exp);
    }
    else pis.unread(c1);        // "3E+" or "3e-" are legal == 3
  }
  else pis.unread(c1);
  return (sign * n);
}

private double readInt(char c1) throws IOException {
  double n = 0.0;
  {
    while (digit(c1)) {
      n = (n * 10) + (c1 - '0');
      c1 = (char) pis.read();
    }
    pis.unread(c1);
    return n;
  }

}

private double readFraction(char c1) throws IOException {
  double n = 0.0;
  double div = 10.0;
  {
    while (digit(c1)) {
      n = n + ((c1 - '0')/div);
      div = div*10.0;
      c1 = (char) pis.read();
    }
    pis.unread(c1);
    return n;
  }

}

public void pushBack() throws IOException {

  if (buffered)         System.out.println("PB error");
  buffered = true;
}

public double readNumber() throws NotANumberException, IOException {
  pis.endOfToken = -1;
  return(readNumberInternal1());
}
public double readNumber(int i) throws NotANumberException, IOException {
  pis.endOfToken = i;
  double d = readNumberInternal1();
  pis.endOfToken = -1;
  return(d);
}


public double readNumberInternal1() throws NotANumberException, IOException {
  int token;

  //  try
    {
    token = nextTokenInternal();
    if (token == TT_NUMBER) {
      // System.out.println("number: " + nval); 
    }
    else {
      pushBack();
      //            System.out.println("read number pushback: " + sval); 
      //         throw new NotANumberException("in PushBackTokenStream.readNumber()");
      throw new NotANumberException();
    }
    return nval;
  }
  //     catch (java.io.IOException fnf) {
  // System.out.println("Bug");
  //             return 10.0;
  //             }
}


public void skipTo(String s) throws IOException {
  int token;

  while (true) {
    token = nextTokenInternal();
    if (token == TT_WORD) {

      // System.out.println("word: " + sval); 
      if (sval.equals(s)) {

        break;
      }
    }}
}

public void skipTo(double n) throws IOException {
  int token;

  while (true) {
    token = nextTokenInternal();
    if (token == TT_NUMBER) {

      // System.out.println("word: " + sval); 
      if (nval == n) {

        break;
      }
    }}
}


public Object readObject() throws IOException {
  int token;
  {
    token = nextTokenInternal(); 
    if (token == TT_NUMBER) {

      if (trace) System.out.println(nval + " ");
      return(new Double(nval));
    }
    else {

      if (trace) System.out.println(sval + " ");
      return(sval);
    }
  }
}


public LList readListOfNumbers() throws IOException {


  Object token = LList.nil;      // something!
  LList list = LList.nil;
  {

    while (true) {
      token = readObject();
      if (numberp(token))
        list = list.cons(token);
      else
        break;
    }
    pushBack();
    return list;
  }
}



public double readNextLetter() throws IOException {
  Object token;
 
  token = readObject();
  if (token.equals("'N'")) return 13.0;
  if (token.equals("'Z'")) return 26.0;
  throw new IOException(token + " is not 'N' or 'Z'");
}


public double readNextNumber() throws IOException {
  Object token, token1;
 
  token = readObject();
  if (!numberp(token))   throw new IOException(token + " is not a number.");
  return( ((Double) token).doubleValue());
}

public boolean numberp(Object o) {
  return(o.getClass().equals(d.getClass()));
}



}
