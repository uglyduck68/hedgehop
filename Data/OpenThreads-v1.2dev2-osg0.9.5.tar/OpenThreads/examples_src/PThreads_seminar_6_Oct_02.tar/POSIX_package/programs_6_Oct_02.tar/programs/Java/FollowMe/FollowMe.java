//              FollowMe/FollowMe.java

/*
This is a simple little game which flashes up a series of colours which
you, the player, must then repeat. The threading trick here is that the
repaint() method needs the caller to go to sleep so that it can run. In
a different thread. Which you need to create.

Loosely adapted with permission from Jackson/McClellan "Java by Example".
*/


import java.applet.*;
import java.awt.*;
import Extensions.*;



public class FollowMe extends Applet implements Runnable {
  static final int      resetSleepTime = 1500;
  static final int      repaintSleepTime = 30;
  static final int      rotateSleepTime = 300;
  static final int      minimumSleepTime = 150;
  static final int      sleepTimeDecrement = 100;
  static final int      initialPatternLength = 4;
  static Semaphore      sem = new Semaphore();
  static Cell           chosenCell;
  int                   numCellsOnSide = 4;
  Thread                thread;         // For displaying patterns.
  int                   sleepTime;      // Sleep while flashing a square.
  int                   next;           // Index into the pattern.
  Cell[]                pattern;        // The current pattern.
  int                   patternLength;  // Length of the current pattern.
  boolean               singleCell;     // Paint a single cell?
  boolean               checkMove;      // Has a mouse_down has occurred?
  boolean               gameOver;               // 
  boolean               won;           
  boolean               resetting;      // Is the pattern is being reset?
  int                   cellWidth=100;  // The pixel width of a cell.
  int                   cellHeight=100; // The pixel height of a cell.
  static boolean        KILL = true;

  
public void init() {
  getReallyEasy();
  Cell.init();
  resize(400, 100);
}


  // Create a thread for the pattern display.  We start the game by
  // immediately displaying a pattern so call Thread.start() right
  // away.

public void start() {
  thread = new Thread(this);
  thread.start();
  new Thread(new Killer(120)).start();
}


  // Stop the display thread.  This is only called when the applet
  // is exited.

public void stop() {
  thread.stop();
  this.destroy();
}


public void run() {
  while (true) {
    reset();
    sem.semWait();      // Don't use thread.suspend() here.
  }
}

public void update(Graphics g) {// g is only available from callback
  paint(g);
}


  // In this paint method we optimize for the painting of single cells.
  // When a method makes a change to a single cell, it sets "singleCell" 
  // to true and sets chosenCell before calling repaint. 

public void paint(Graphics g) {
  if (gameOver) {
    if (won)
      g.setColor(Color.blue);
    else 
      g.setColor(Color.black);
    g.fillRect(0, 0, 400, 100);
    return;
  }
  if (singleCell)
    chosenCell.paint(g);
  else {
    for (int i = 0; i < numCellsOnSide; i++) Cell.cells[i].paint(g);
  }
}



  // When the user presses a button down in a square we highlight the
  // square and begin watch mouse movement.  If she then releases the
  // button in the same square we consider the square selected and
  // process her move.  If the mouse leaves the square we just 
  // unhighlight the square and proceed as if nothing had happened.

public boolean mouseDown(Event evt, int x, int y) {

  // If a new pattern is being displayed, do nothing.
  if (resetting) return true;

  // Scale the pixel coordinates to cell coordinates.
  int cellX  = x / cellWidth;

  // Set chosenCell to correct color.
  chosenCell = Cell.cells[cellX];
  chosenCell.brighten();
  singleCell  = true;

  // Schedule an update.
  repaint();

  // Set the checkMove flag so that we pay attention to drag 
  // and mouseUp events.
  checkMove = true;
  return true;
}

    
  // When a mouse drag occurs, we check if a mouse down has occurred and
  // if the mouse is now in the same square.  If the mouse has left
  // the square in which the mouse down occurred we unhighlight the
  // mouse down square and return to our default state.

public boolean mouseDrag(Event evt, int x, int y) {

  // If we're currently displaying the pattern or no mouse down
  // occurred within the applet, do nothing.
    
  if (resetting || !checkMove) return true;

  // Scale the pixel coordinates to cell coordinates.
    
  int cellX  = x / cellWidth;

  // If the mouse has not left the mouse down square, do nothing.
    
  if (chosenCell.equals(Cell.cells[cellX])) return true;

  // Set chosenCell so the paint method 
  // will know which square to redraw and what color to paint it.
  // Note that we don't repaint the square the mouse is now in
  // but, instead, the square the mouse just left.

  chosenCell.darken();
  singleCell  = true;
  repaint();

  // Return to the default state.

  checkMove = false;
  return true;
}



  // If the mouse button is released and the button had been pressed
  // within the applet,  unhighlight the square and add the square
  // to the user's pattern.  Check if the user has completed the 
  // pattern or selected the wrong square.

public boolean mouseUp(Event evt, int x, int y) {


  // If we're currently redisplaying the pattern or no mouse down
  // occurred within the applet, do nothing.

  if (resetting || !checkMove) return true;

  // Scale the pixel coordinates to cell coordinates.

  int cellX  = x / cellWidth;

  // Set chosenCell so the paint method will know which square to redraw. 

  chosenCell = Cell.cells[cellX];
  chosenCell.darken();
  singleCell  = true;
  repaint();


  // testPattern() will try to match the user's selection with the
  // next cell in the pattern.  If it matches, the pattern index
  // is advanced and a check is made to see if the user has
  // completed the pattern.  If the selection doesn't match, the
  // current game ends and a new game starts. 

  testPattern(cellX);
  checkMove = false;
  return true;
}



  // This routine compares a cell with the next cell in the stored
  // pattern.  If it matches, a check is made for the pattern being
  // complete.  If it fails, the game ends and a new game is started.
  // Each time a pattern is completed, the pattern display is speeded
  // up or the pattern is lengthened.

private void testPattern(int x) {

    Cell nextMatch = pattern[next++];
    if (nextMatch.equals(Cell.cells[x])) {

      // If the current cell matched, check if we're at the
      // end of the pattern.

      if (next == patternLength) {

        // If the pattern is complete, play a winning sound and
        // make the next pattern harder.  Resume the pattern
        // display thread to display a new pattern.

        win();
        getHarder();
        sem.semPost();
      }

    }
    else {

      // If the user failed to match the current cell, play a losing
      // sound and make the next pattern really easy.  Resume the
      // pattern display thread to display a new pattern.

      lose();
      getReallyEasy();
      sem.semPost();
    }
  }



  // Play a "winning" sound.

private void win() {
    getAudioClip(getCodeBase(), "Audio/gong.au").play();
    won=true;
  }



  // Play a "losing" sound.

private void lose() {
    getAudioClip(getCodeBase(), "Audio/beep.au").play();
    won=false;
  }


  
  // Make the pattern harder.  Decrement the display time until it gets
  // too fast then slow it down and make the pattern longer.

private void getHarder() {

    if (sleepTime > minimumSleepTime) {

      sleepTime -= sleepTimeDecrement;
    }
    else {
      patternLength++;
      sleepTime = resetSleepTime / 2;
    }
  }



  // Make the pattern really easy.  Make the display time very long
  // and the pattern very short.  This is used to start a new game.

private void getReallyEasy() {

    sleepTime = resetSleepTime / 2;
    patternLength = initialPatternLength;
  }



  // reset() starts a new pattern.  It generates the pattern, and
  // displays it to the user.  The pattern sequence is generated
  // using the Math.random() method and each square in the pattern
  // is displayed as it is generated.  This must run is a seperate
  // thread so that repaint() will work!
    
private void reset() {

    // Set "resetting" to true so events will be ignored while the
    // pattern is displayed.

    resetting = true;
    checkMove = false;
    singleCell = false;
    gameOver = true;
    repaint();
    InterruptibleThread.sleep(sleepTime);
    gameOver = false;
    repaint();
    InterruptibleThread.sleep(sleepTime);


    // Initialize the current index into the pattern to 0.  This
    // is used to keep track of where the user is in duplicating
    // the pattern.

    next = 0;

    // Create a new pattern array.  Each element is a pair of
    // X and Y coordinates.  We could save space using chars or
    // shorts but this is always a small array so it doesn't
    // really matter.

    pattern = new Cell[patternLength];


    for (int i = 0; i < patternLength; i++) {


      // Select random X and Y coordinates.

      int randomX = (int)((Math.random() * 10) % numCellsOnSide);

      // Set the next pattern entry to the new coordinates.

      pattern[i] = Cell.cells[randomX];

      // Display the pattern square by redrawing it briefly in a
      // brighter version of its current color.


      chosenCell = Cell.cells[randomX];
      chosenCell.brighten();
      singleCell = true;
      repaint();

      // Sleep so the user can see the bright color before we
      // darken it again.  The sleep time decreases as patterns
      // are successfully duplicated.

      InterruptibleThread.sleep(sleepTime);

      // Redraw the square in its original color before going to
      // the next square.

      chosenCell.darken();
      singleCell = true;
      repaint();

      // Sleep between squares. 

      InterruptibleThread.sleep(repaintSleepTime);
    }

    // Allow mouse events to be processed.

    resetting = false;
  }

}
