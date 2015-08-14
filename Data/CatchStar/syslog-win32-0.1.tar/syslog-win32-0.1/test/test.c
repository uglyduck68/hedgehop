/*
 * This test is based on logger.c.
 *
 * Copyright (c) 1983, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * 1999-02-22 Arkadiusz Mi¶kiewicz <misiek@pld.ORG.PL>
 * - added Native Language Support
 * Sun Mar 21 1999 - Arnaldo Carvalho de Melo <acme@conectiva.com.br>
 * - fixed strerr(errno) in gettext calls
 * 2005-06-17 Alexander Yaworsky <yaworsky@mail.ru>
 * - modified for native win32
 */

#include <errno.h>
#include <getopt.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <windows.h>

#define	SYSLOG_NAMES
#include <syslog.h>

#define _(s) s

int	decode (char *, CODE *);
int	pencode (char *);
void	usage (void);

int
main(int argc, char **argv) {
	int ch;
	int pri = LOG_NOTICE;
	int burst = 1, sleep = 1;
	int max_identical = 0;
	int iterations = 1;
	char *tag = NULL;
	FILETIME current_time, max_time;
	unsigned long long max_time_64;
	int msg_index, total_sent;

	while ((ch = getopt(argc, argv, "p:t:b:s:i:n:")) != -1)
		switch((char)ch) {
		case 'p':		/* priority */
			pri = pencode(optarg);
			break;
		case 't':		/* tag */
			tag = optarg;
			break;
		case 'b':		/* message burst time in seconds */
			burst = strtoul( optarg, NULL, 0 );
			break;
		case 's':		/* sleep time in seconds */
			sleep = strtoul( optarg, NULL, 0 );
			break;
		case 'i':		/* max number of identical messages */
			max_identical = strtoul( optarg, NULL, 0 );
			break;
		case 'n':		/* number of test iterations */
			iterations = strtoul( optarg, NULL, 0 );
			break;
		case '?':
		default:
			usage();
		}

	openlog(tag ? tag : "test", 0, 0);

	msg_index = 1;
	total_sent = 0;
	for(;;) {
		int messages_sent = 0;
		int identic_count = 0, identic_index = 0;

		GetSystemTimeAsFileTime( &current_time );
		max_time = current_time;
		max_time_64 = (((long long) max_time.dwHighDateTime) << 32) + (long long) max_time.dwLowDateTime;
		max_time_64 += ((long long) burst) * (long long) 10000000;
		max_time.dwHighDateTime = max_time_64 >> 32;
		max_time.dwLowDateTime = max_time_64;
		for(;;) {
			int i;
			for( i = 0; i < 100; i++ ) {
				syslog(pri, "test message %d", msg_index );
				messages_sent++;
				total_sent++;
				if( identic_index < identic_count )
					identic_index++;
				else {
				        msg_index++;
					identic_index = 0;
					if( identic_count < max_identical )
						identic_count++;
					else
						identic_count = 0;
				}
			}
			GetSystemTimeAsFileTime( &current_time );
			if( CompareFileTime( &current_time, &max_time ) >= 0 )
				break;
		}
		printf( "%d messages sent in burst, total %d messages sent\n", messages_sent, total_sent );
		if( --iterations == 0 )
			break;
		printf( "%d iteration(s) remain; sleeping %d sec.\n", iterations, sleep );
		Sleep( sleep * 1000 );
	}
	closelog();
	exit(0);
}

/*
 *  Decode a symbolic name to a numeric value
 */
int
pencode(s)
	register char *s;
{
	char *save;
	int fac, lev;

	for (save = s; *s && *s != '.'; ++s);
	if (*s) {
		*s = '\0';
		fac = decode(save, facilitynames);
		if (fac < 0) {
			(void)fprintf(stderr,
			    _("logger: unknown facility name: %s.\n"), save);
			exit(1);
		}
		*s++ = '.';
	}
	else {
		fac = LOG_USER;
		s = save;
	}
	lev = decode(s, prioritynames);
	if (lev < 0) {
		(void)fprintf(stderr,
		    _("logger: unknown priority name: %s.\n"), save);
		exit(1);
	}
	return ((lev & LOG_PRIMASK) | (fac & LOG_FACMASK));
}

int
decode(name, codetab)
	char *name;
	CODE *codetab;
{
	register CODE *c;

	if (isdigit(*name))
		return (atoi(name));

	for (c = codetab; c->c_name; c++)
		if (!strcasecmp(name, c->c_name))
			return (c->c_val);

	return (-1);
}

void
usage()
{
	(void)fprintf(stderr,
	    _("usage: test [-i] [-p pri] [-t tag] [-b burst time] [-s sleep time] [-i max identical] [-n iterations]\n"));
	exit(1);
}
