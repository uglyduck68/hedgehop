/**
 * threadpool_test.c, copyright 2001 Steve Gribble
 *
 * Just a regression test for the threadpool code.
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdarg.h>
#include "threadpool_org.h"

#include "spthread.h"

#include "Threadpool.h"

#include "timeval.h"

extern int errno;

using namespace X1;

void mylog( FILE * fp, const  char  *format,  /*args*/ ...)
{
	va_list ltVaList;
	va_start( ltVaList, format );
	vprintf( format, ltVaList );
	va_end( ltVaList );

	fflush( stdout );
}

void dispatch_threadpool_to_me(void *arg) 
{
  int seconds = (int) arg;

  fprintf(stdout, "  in dispatch_threadpool %d\n", seconds);
  fprintf(stdout, "  thread#%ld\n", sp_thread_self() );
  sp_sleep(seconds);
  fprintf(stdout, "  done dispatch_threadpool %d\n", seconds);
}

/**
* @function	dispatch_threadpool_to_me_2
* @return	sp_thread_result_t is meaningless because @function is executed as thread
*			in the threadpool. user can't get the return value from this @function.
* @brief	this function is for function dispatch test using Threadpool class.
*/
sp_thread_result_t dispatch_threadpool_to_me_2(void *arg) 
{
  int seconds = (int) arg;

  fprintf(stdout, "  in dispatch_threadpool %d\n", seconds);
  fprintf(stdout, "  thread#%ld\n", sp_thread_self() );
  sp_sleep(seconds);
  fprintf(stdout, "  done dispatch_threadpool %d\n", seconds);

  return 0;
}

/**
* @class	Worker
* @brief	this class is for Thread dispatch test using Threadpool class.
*/
class Worker :public Thread
{
public:
	Worker() : m_nSecond(0)
	{
	}

	~Worker()
	{
	}

	Worker(int n) : m_nSecond(n)
	{
	}

	sp_thread_result_t	Run(Thread* pArg)
	{
		int seconds = static_cast<Worker*>(pArg)->m_nSecond;

		fprintf(stdout, "  in dispatch_threadpool %d\n", seconds);
		fprintf(stdout, "  thread#: %ld\n", GetId());
		sp_sleep(seconds);
		fprintf(stdout, "  done dispatch_threadpool %d\n", seconds);

		return 0;
	}

protected:
	int		m_nSecond;
};

int TestThreadpool_1()
{
	Threadpool		Thdpool(2);
	Worker			Three(3);
	Worker			Six(6);
	Worker			Seven(7);
	Worker			Three2(3);
	Worker			Six2(6);
	Worker			Seven2(7);

	fprintf(stdout, "**main** dispatch_threadpool 3\n");

	Thdpool.Assign(&Three);

	fprintf(stdout, "**main** dispatch_threadpool 6\n");
	
	Thdpool.Assign(&Six);
	
	fprintf(stdout, "**main** dispatch_threadpool 7\n");
	
	Thdpool.Assign(&Seven);

	fprintf(stdout, "**main** done first\n");
	
	sp_sleep(10);

	fprintf(stdout, "\n\n");

	fprintf(stdout, "**main** dispatch_threadpool 3\n");
	Thdpool.Assign(&Three2);
	fprintf(stdout, "**main** dispatch_threadpool 6\n");
	Thdpool.Assign(&Six2);
	fprintf(stdout, "**main** dispatch_threadpool 7\n");
	Thdpool.Assign(&Seven2);

	fprintf(stdout, "**main done second\n");

	Thdpool.Destroy();

	return 0;
}

int TestThreadpool_2()
{
	Threadpool		Thdpool(2);

	fprintf(stdout, "**main** dispatch_threadpool 3\n");

	Thdpool.Assign(dispatch_threadpool_to_me_2, (void*)3);

	fprintf(stdout, "**main** dispatch_threadpool 6\n");
	
	Thdpool.Assign(dispatch_threadpool_to_me_2, (void*)6);
	
	fprintf(stdout, "**main** dispatch_threadpool 7\n");
	
	Thdpool.Assign(dispatch_threadpool_to_me_2, (void*)7);

	fprintf(stdout, "**main** done first\n");
	
	sp_sleep(10);

	fprintf(stdout, "\n\n");

	fprintf(stdout, "**main** dispatch_threadpool 3\n");
	Thdpool.Assign(dispatch_threadpool_to_me_2, (void*)3);
	fprintf(stdout, "**main** dispatch_threadpool 6\n");
	Thdpool.Assign(dispatch_threadpool_to_me_2, (void*)6);
	fprintf(stdout, "**main** dispatch_threadpool 7\n");
	Thdpool.Assign(dispatch_threadpool_to_me_2, (void*)7);

	fprintf(stdout, "**main done second\n");

	Thdpool.Destroy();

	return 0;
}
int	TestThreadpool()
{
	int		n1	= 0;
	int		n2	= 0;

	n2	= TestThreadpool_2();

	n1	= TestThreadpool_1();

	return ((n1 == 0&& n2 == 0)? 0: 1);
}


int main(int argc, char **argv) 
{
#if	0
	int year, month, day, hour, min, sec, msec;

	TimeVal::Now(year, month, day, hour, min, sec, msec);

	printf("%04d/%02d/%02d %02d:%02d:%02d.%04d\n", year, month, day, hour, min, sec, msec);
#endif

#if	0
	return TestThreadpool();
#endif

  threadpool tp;

  tp = create_threadpool(2);

  fprintf(stdout, "**main** dispatch_threadpool 3\n");
  dispatch_threadpool(tp, dispatch_threadpool_to_me, (void *) 3);
  fprintf(stdout, "**main** dispatch_threadpool 6\n");
  dispatch_threadpool(tp, dispatch_threadpool_to_me, (void *) 6);
  fprintf(stdout, "**main** dispatch_threadpool 7\n");
  dispatch_threadpool(tp, dispatch_threadpool_to_me, (void *) 7);

  fprintf(stdout, "**main** done first\n");
  sp_sleep(20);
  fprintf(stdout, "\n\n");

  fprintf(stdout, "**main** dispatch_threadpool 3\n");
  dispatch_threadpool(tp, dispatch_threadpool_to_me, (void *) 3);
  fprintf(stdout, "**main** dispatch_threadpool 6\n");
  dispatch_threadpool(tp, dispatch_threadpool_to_me, (void *) 6);
  fprintf(stdout, "**main** dispatch_threadpool 7\n");
  dispatch_threadpool(tp, dispatch_threadpool_to_me, (void *) 7);

  fprintf(stdout, "**main done second\n");

  destroy_threadpool( tp );

  //sp_sleep(20);
  return -1;
}

