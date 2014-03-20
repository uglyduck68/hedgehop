/*                ThreadWin.c                */

/*
  Simple window program that inverts the colour of each button for
  6 seconds.

  In the non-threaded version, it hangs for 6 seconds with the GUI
  inactive (tho events are queued).  In the MT version, it spawns off
  a new thread to do that long "calculation", hence the GUI remains 
  active.  Upon completion, the thread writes to a pipe.  The X
  notifier reads from that pipe and inverts the colour back to the
  original colour.
*/
/*
cc -o ThreadWin ThreadWin.c -L. -R. -g -lpthread -lthread -pthread_extensions -lposix4 -I/usr/dt/include -I/usr/openwin/include -L/usr/openwin/lib -L/usr/dt/lib -R/usr/openwin/lib -R/usr/dt/lib -lXm -lXt -lX11 -lm

*/

#define _POSIX_C_SOURCE 199506L
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <X11/Intrinsic.h>
#include <X11/X.h>
#include <X11/StringDefs.h>
#include <Xm/Xm.h>
#include <Xm/RowColumn.h>
#include <Xm/PushB.h>
#include <pthread.h>
#include "thread_extensions.h"

#define READ 0
#define WRITE 1


/* function prototypes */
int                     ButtonPushed(Widget, XtPointer);
void                    *DoWork(void *);
XtAppContext            _XtDefaultAppContext();
XtInputCallbackProc     WorkComplete();
static int              message[2];
pthread_attr_t          attr;


main(int argc, char **argv)
{Widget                 toplevel, base, button[200];
 Arg                    wargs[10];
 int                    i, MT=0, N_BUTTONS=25;
 char                   but_label[5];
 XEvent                 event, fake;
 Display                *disp;
 Window                 win;
 XtAppContext           app;
 pthread_t              tid;

 /* check arguments */
 if (argc > 2) 
   printf("Usage: %s [MT]\n", argv[0]), exit(0);

 if (argc == 2 && strcmp(argv[1], "MT") == 0) MT = 1;

 if (pipe(message) < 0) 
   {fprintf(stderr, "Can't open pipe\n");
    exit(1);
  }
 PTHREAD_ATTR_INIT(&attr);
 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
 pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
 PTHREAD_CREATE(&tid, &attr, killer, (void *) 60);

 /* setup our main window */
 toplevel=XtInitialize(argv[0], "ThreadWin", NULL, 0, &argc, argv);

 /* set some arguments for our Row/Column Widget */
 XtSetArg(wargs[0], XmNorientation, XmHORIZONTAL);
 XtSetArg(wargs[1], XmNentryAlignment, XmALIGNMENT_CENTER);
 XtSetArg(wargs[2], XmNisAligned, True);
 XtSetArg(wargs[3], XmNnumColumns, (int)floor(sqrt((double)N_BUTTONS)));
 XtSetArg(wargs[4], XmNpacking, XmPACK_COLUMN);

 /* create the Row/Column Widget */
 base=XtCreateManagedWidget("base", xmRowColumnWidgetClass,
                            toplevel, wargs, 5);


 /* create the button widgets with the button number as it label */
 for (i=0;i<N_BUTTONS;i++) 
   {sprintf(but_label, " %d ", i);
    XtSetArg(wargs[0], XmNlabelString,
             XmStringCreate(but_label, XmSTRING_DEFAULT_CHARSET));
    button[i] = XmCreatePushButton(base, "button", wargs, 1);

    /* tell the button to call ButtonPushed() when pushed */
    XtAddCallback(button[i], XmNactivateCallback,
                  (XtCallbackProc) ButtonPushed, (void *)MT);
  }

 /* manage the buttons and go into the X event loop */
 XtManageChildren(button, N_BUTTONS);
 XtRealizeWidget(toplevel);
 app = _XtDefaultAppContext();
 XtAppAddInput(app, message[READ], (void *)XtInputReadMask,
               (XtInputCallbackProc)WorkComplete, NULL);
 XtMainLoop();
}


XtInputCallbackProc WorkComplete() 
{Pixel          fg, bg;
 Arg            warg[2];
 Widget         w;

 if (read(message[READ], &w, sizeof(w)) != sizeof(w)) 
   {fprintf(stderr, "Read error\n");
   exit(1);
 }

 /* get the buttons foreground and background colors */
 XtSetArg(warg[0], XmNforeground, &fg);
 XtSetArg(warg[1], XmNbackground, &bg);
 XtGetValues(w, warg, 2);

 /* swap the buttons foreground and background colors */
 XtSetArg(warg[0], XmNforeground, bg);
 XtSetArg(warg[1], XmNbackground, fg);
 XtSetValues(w, warg, 2);

 XtSetSensitive(w, True);
 return((XtInputCallbackProc)0);
}

/* 
        Button callback routine -- Called when a button is pushed 
*/

int ButtonPushed(Widget w, XtPointer MT)
{int            mt = (int) MT;
 Pixel          fg, bg;
 Arg            warg[2];
 pthread_t      tid;

 XtSetSensitive(w, False);

 /* get the buttons foreground and background colors */
 XtSetArg(warg[0], XmNforeground, &fg);
 XtSetArg(warg[1], XmNbackground, &bg);
 XtGetValues(w, warg, 2);

 /* swap the buttons foreground and background colors */
 XtSetArg(warg[0], XmNforeground, bg);
 XtSetArg(warg[1], XmNbackground, fg);
 XtSetValues(w, warg, 2);

 if (MT) 
   PTHREAD_CREATE(&tid, &attr, DoWork, (void *)w);
 else 
   DoWork((void *)w);


 return(0);
}


void *DoWork(void *arg) 
{Widget                 w = (Widget) arg;
 pthread_t              tid = pthread_self();
 char                   *name = thread_name(tid);

 printf("Thread %s: Start Processing...\n", name);
 sleep(6);
 printf("Thread %s: Processing done...\n", name);

 if (write(message[WRITE], &w, sizeof(w)) != sizeof(w)) 
   {fprintf(stderr, "Write error\n");
    exit(1);
  }
 return((void *)0);
}
