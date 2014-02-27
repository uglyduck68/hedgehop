/***************************************************************
 *
 * Copyright (C) 1990-2007, Condor Team, Computer Sciences Department,
 * University of Wisconsin-Madison, WI.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License.  You may
 * obtain a copy of the License at
 * 
 *    http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ***************************************************************/


 

#include "condor_common.h"
#include "image.h"
#include <sys/procfs.h>		// for /proc calls
#include <sys/mman.h>		// for mmap() test
#include "condor_debug.h"
#include "condor_syscalls.h"

/* a few notes:
 * this is a pretty rough port
 *
 * data_start_addr() is basically an educated guess based on dump(1)
 * it is probably not entirely correct, but does seem to work!
 *
 * stack_end_addr() is generally well known for sparc machines
 * however it doesn't seem to appear in solaris header files
 * 
 * JmpBufSP_Index() was derived by dumping the jmp_buf, allocating a
 * large chunk of memory on the stack, and dumping the jmp_buf again
 * whichever value changed by about sizeof(chuck) is the stack pointer
 *
 */

/*
  Return starting address of the data segment
*/
#if defined(X86)
#include <sys/elf_386.h>
#else
#include <sys/elf_SPARC.h>
#endif
extern int _etext;
long
data_start_addr()
{
#if defined(X86)
	return (  (((long)&_etext) + ELF_386_MAXPGSZ) + 0x8 - 1 ) & ~(0x8-1);
#else
	return (  (((long)&_etext) + ELF_SPARC_MAXPGSZ) + 0x8 - 1 ) & ~(0x8-1);
#endif
}

/*
  Return ending address of the data segment
*/
long
data_end_addr()
{
	return (long)sbrk(0);
}

/*
  Return TRUE if the stack grows toward lower addresses, and FALSE
  otherwise.
*/
BOOL StackGrowsDown()
{
	return TRUE;
}

/*
  Return the index into the jmp_buf where the stack pointer is stored.
  Expect that the jmp_buf will be viewed as an array of integers for
  this.
*/
int JmpBufSP_Index()
{
#if defined(X86)
	return 4;
#else
	return 1;	
#endif
}

/*
  Return starting address of stack segment.
*/
long
stack_start_addr()
{
	long	answer;

	jmp_buf env;
	(void)SETJMP( env );
	return JMP_BUF_SP(env) & ~1023; // Curr sp, rounded down
}

/*
  Return ending address of stack segment.
*/
long
stack_end_addr()
{
	/* return 0xF8000000; -- for sun4[c] */
#if defined(X86)
	return 0x8048000; /* -- for x86 */
#else
	#if defined(Solaris27) || defined(Solaris28) 
		return 0xFFBF0000;
	#elif defined(Solaris29)
		return 0xFFC00000; /* XXX educated guess */
	#else
		/* Solaris 2.5.1, Solaris 2.6 */
		return 0xF0000000;
	#endif
#endif
}

/*
  Patch any registers whose values should be different at restart
  time than they were at checkpoint time.
*/
void
patch_registers( void *generic_ptr )
{
	// Nothing needed
}

// static prmap_t *my_map = NULL;
static prmap_t my_map[ MAX_SEGS ];
static int	prmap_count = 0;
static int	text_loc = -1, stack_loc = -1, heap_loc = -1;
// static int      mmap_loc = -1;

/*
  Find the segment in my_map which contains the address in addr.
  Used to find the text segment.
*/
int
find_map_for_addr(caddr_t addr)
{
	int		i;

	for (i = 0; i < prmap_count; i++) {
		if (addr >= my_map[i].pr_vaddr &&
			addr <= my_map[i].pr_vaddr + my_map[i].pr_size){
			return i;
		}
	}
	return -1;
}

/*
  Return the number of segments to be checkpointed.  Note that this
  number includes the text segment, which should be ignored.  On error,
  returns -1.
*/
extern "C"   int SYSCALL(int ...);

int
num_segments( )
{
	int	fd;
	char	buf[100];

	int scm = SetSyscalls( SYS_LOCAL | SYS_UNMAPPED );
	sprintf(buf, "/proc/%d", SYSCALL(SYS_getpid));
	fd = SYSCALL(SYS_open, buf, O_RDWR, 0);
	if (fd < 0) {
		SetSyscalls(scm);
		return -1;
	}
	SYSCALL(SYS_ioctl, fd, PIOCNMAP, &prmap_count);
	if (prmap_count > MAX_SEGS) {
		dprintf( D_ALWAYS, "Don't know how to grow segment map yet!\n" );
		Suicide();
	}		
/*	if (my_map != NULL) {
		free(my_map);
	}
	my_map = (prmap_t *) malloc(sizeof(prmap_t) * (prmap_count + 1));  */

	SYSCALL(SYS_ioctl, fd, PIOCMAP, my_map);
	/* find the text segment by finding where this function is
	   located */
	text_loc = find_map_for_addr((caddr_t) num_segments);
	/* identify the stack segment by looking for the bottom of the stack,
	   because the top of the stack may be in the data area, often the
	   case for programs which utilize threads or co-routine packages. */
	if ( StackGrowsDown() )
		stack_loc = find_map_for_addr((caddr_t) stack_end_addr());
	else
		stack_loc = find_map_for_addr((caddr_t) stack_start_addr());
	heap_loc = find_map_for_addr((caddr_t) data_start_addr());
//	mmap_loc = find_map_for_addr((caddr_t) mmap);
	if (SYSCALL(SYS_close, fd) < 0) {
		dprintf(D_ALWAYS, "close: %s", strerror(errno));
	}
	SetSyscalls( scm );
	return prmap_count;
}

/*
  Assigns the bounds of the segment specified by seg_num to start
  and long, and the protections to prot.  Returns -1 on error, 1 if
  this segment is the text segment, 2 if this segment is the stack
  segment, 3 if this segment is in the data segment, and 0 otherwise.
*/
int
segment_bounds( int seg_num, RAW_ADDR &start, RAW_ADDR &end, int &prot )
{
	if (my_map == NULL)
		return -1;
	start = (long) my_map[seg_num].pr_vaddr;
	end = start + my_map[seg_num].pr_size;

	prot = 0;
	if (my_map[seg_num].pr_mflags & MA_READ) {
		prot |= PROT_READ;
	}
	if (my_map[seg_num].pr_mflags & MA_WRITE) {
		prot |= PROT_WRITE;
	}
	if (my_map[seg_num].pr_mflags & MA_EXEC) {
		prot |= PROT_EXEC;
	}

	if (seg_num == text_loc)
		return 1;
	else if (seg_num == stack_loc)
		return 2;
	else if (seg_num == heap_loc ||
		 ((unsigned)my_map[seg_num].pr_vaddr >= (unsigned)data_start_addr() &&
		  (unsigned)my_map[seg_num].pr_vaddr <= (unsigned)data_end_addr()))
	        return 3;
	return 0;
}

struct ma_flags {
	int	flag_val;
	char	*flag_name;
} MA_FLAGS[] = {{MA_READ, "MA_READ"},
				{MA_WRITE, "MA_WRITE"},
				{MA_EXEC, "MA_EXEC"},
				{MA_SHARED, "MA_SHARED"},
				{MA_BREAK, "MA_BREAK"},
				{MA_STACK, "MA_STACK"}};

/*
  For use in debugging only.  Displays the segment map of the current
  process.
*/
void
display_prmap()
{
	int		i, j;

	num_segments();
	for (i = 0; i < prmap_count; i++) {
	  dprintf( D_ALWAYS, "addr = 0x%p, size = 0x%x, offset = 0x%x",
		 my_map[i].pr_vaddr, my_map[i].pr_size, my_map[i].pr_off);
	  for (j = 0; j < sizeof(MA_FLAGS) / sizeof(MA_FLAGS[0]); j++) {
	    if (my_map[i].pr_mflags & MA_FLAGS[j].flag_val) {
	      dprintf( D_ALWAYS, " %s", MA_FLAGS[j].flag_name);
	    }
	  }
	  dprintf( D_ALWAYS, "\n");
	}
}
