//              Extensions/PushBackTokenStreamIgnoreComments.java

package Extensions;

import java.io.*;


public class PushBackTokenStreamIgnoreComments extends PushBackTokenStream {


  
public PushBackTokenStreamIgnoreComments(String name) {
  super(name);
}
  
private boolean eolp(char c) {
  return((c == '\n') || (c == '\n'));
}


private void skipToEOL() throws IOException {
  char c1 = ' ';

  while (!eolp(c1)) {
    c1 = (char) pis.read();
  }
  pis.unread(c1);
}
   

   
public void skipWhiteSpace() throws IOException {
  char c1;
  while (true) {
    c1 = (char) pis.read();
      
    if (eolp(c1)) {
      c1 = (char) pis.read();
      if ((c1 == 'C') || (c1 == 'c')) {
        skipToEOL();
        continue;
      }
      else {
        pis.unread(c1);
        continue;
      }}
      
    if (whiteSpace(c1) || (c1 == ','))
      continue;
    else {
      pis.unread(c1);
      break;
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
        if (token.equals("=") || token.equals("=3D"))
          continue;
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
  if (token.equals("=") || token.equals("=3D"))
    token = readObject();
  if (token.equals("'N'")) return 13.0;
  if (token.equals("'Z'")) return 26.0;
  throw new IOException(token + " is not 'N' or 'Z'");
}


public double readNextNumber() throws IOException {
  Object token, token1;
 
 
  token = readObject();
  while (token.equals("=") || token.equals("=3D"))
    token = readObject();
  if (!numberp(token))   throw new IOException(token + " is not a number.");
  return( ((Double) token).doubleValue());
}

}
