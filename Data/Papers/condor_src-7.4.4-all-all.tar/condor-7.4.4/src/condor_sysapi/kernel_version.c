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
#include "condor_config.h"
#include "condor_debug.h"
#include "sysapi.h"
#include "sysapi_externs.h"

char *_sysapi_kernel_version = NULL;

/* the raw version */
/* Do not free the returned pointer */
const char *
sysapi_kernel_version_raw(void)
{
#if !defined(WIN32)
	struct utsname buf;

	if( uname(&buf) < 0 ) {
		_sysapi_kernel_version = strdup("N/A");
		return _sysapi_kernel_version;
	}
#endif

#if defined(LINUX)
	if (strncmp(buf.release, "2.2.", 4) == MATCH) {
		_sysapi_kernel_version = strdup("2.2.x");
	} else if (strncmp(buf.release, "2.3.", 4) == MATCH) {
		_sysapi_kernel_version = strdup("2.3.x");
	} else if (strncmp(buf.release, "2.4.", 4) == MATCH) {
		_sysapi_kernel_version = strdup("2.4.x");
	} else if (strncmp(buf.release, "2.5.", 4) == MATCH) {
		_sysapi_kernel_version = strdup("2.5.x");
	} else if (strncmp(buf.release, "2.6.", 4) == MATCH) {
		_sysapi_kernel_version = strdup("2.6.x");
	} else if (strncmp(buf.release, "2.7.", 4) == MATCH) {
		_sysapi_kernel_version = strdup("2.7.x");
	} else if (strncmp(buf.release, "2.8.", 4) == MATCH) {
		_sysapi_kernel_version = strdup("2.8.x");
	} else {
		_sysapi_kernel_version = strdup(buf.release);
	}
#elif defined(Solaris)
	if (strcmp(buf.release, "2.10") == MATCH ||
		strcmp(buf.release, "5.10") == MATCH)
	{
		_sysapi_kernel_version = strdup("2.10");

	} else if (strcmp(buf.release, "2.9") == MATCH ||
			strcmp(buf.release, "5.9") == MATCH)
	{
		_sysapi_kernel_version = strdup("2.9");

	} else if (strcmp(buf.release, "2.8") == MATCH ||
				strcmp(buf.release, "5.8") == MATCH)
	{
		_sysapi_kernel_version = strdup("2.8");

	} else if (strcmp(buf.release, "2.7") == MATCH ||
				strcmp(buf.release, "5.7") == MATCH)
	{
		_sysapi_kernel_version = strdup("2.7");

	} else if(strcmp(buf.release, "5.6") == MATCH ||
				strcmp(buf.release, "2.6") == MATCH)
	{
		_sysapi_kernel_version = strdup("2.6");

	} else if (strcmp(buf.release, "5.5.1") == MATCH ||
				strcmp(buf.release, "2.5.1") == MATCH)
	{
		_sysapi_kernel_version = strdup("2.5.1");

	} else if (strcmp(buf.release, "5.5") == MATCH ||
				strcmp(buf.release, "2.5") == MATCH)
	{
		_sysapi_kernel_version = strdup("2.5");

	} else {
		_sysapi_kernel_version = strdup(buf.release);

	}

#elif defined(IRIX)
	_sysapi_kernel_version = strdup(buf.release);
#elif defined(OSF1)
	_sysapi_kernel_version = strdup(buf.release);
#elif defined(Darwin) || defined(CONDOR_FREEBSD)
	_sysapi_kernel_version = strdup(buf.release);
#elif defined(AIX)
	_sysapi_kernel_version = strdup(buf.release);
#elif defined(HPUX)
	_sysapi_kernel_version = strdup(buf.release);
#elif defined(WIN32)
	_sysapi_kernel_version = strdup("Unknown");
#else
#	error Please port sysapi_kernel_version_raw() to this platform!
#endif
	
	return _sysapi_kernel_version;
}

/* the cooked version */
/* Do not free the returned pointer */
const char *
sysapi_kernel_version(void)
{	
	sysapi_internal_reconfig();

	if( _sysapi_kernel_version != NULL ) {
		return _sysapi_kernel_version;
	} else {
		return sysapi_kernel_version_raw();
	}
}


