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


#ifndef SELECTOR_H
#define SELECTOR_H

#include "condor_common.h"

class Selector {
public:
	Selector();
	~Selector();
	static int fd_select_size();

	enum IO_FUNC {
		IO_READ, IO_WRITE, IO_EXCEPT
	};

	enum SELECTOR_STATE {
		VIRGIN, FDS_READY, TIMED_OUT, SIGNALLED, FAILED
	};

	void reset();
	void add_fd( int fd, IO_FUNC interest );
	void delete_fd( int fd, IO_FUNC interest );
	void set_timeout( time_t sec, long usec = 0 );
	void set_timeout( timeval tv );
	void unset_timeout();
	void execute();
	int select_retval();
	int select_errno();
	BOOLEAN	has_ready();
	BOOLEAN	timed_out();
	BOOLEAN	signalled();
	BOOLEAN failed();
	BOOLEAN fd_ready( int fd, IO_FUNC interest );
	void display();

private:
	static int _fd_select_size;
	static fd_set *cached_read_fds, *cached_save_read_fds;
	static fd_set *cached_write_fds, *cached_save_write_fds;
	static fd_set *cached_except_fds, *cached_save_except_fds;
	fd_set	*read_fds, *save_read_fds;
	fd_set	*write_fds, *save_write_fds;
	fd_set	*except_fds, *save_except_fds;
	int		fd_set_size;
	int		max_fd;
	BOOLEAN			timeout_wanted;
	struct timeval	timeout;
	SELECTOR_STATE	state;
	int		_select_retval;
	int		_select_errno;
};

void display_fd_set( char *msg, fd_set *set, int max, bool try_dup = false);

#endif
