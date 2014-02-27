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
#include "io_proxy_handler.h"

#include "NTsenders.h"
#include "../condor_chirp/chirp_protocol.h"

#include "condor_event.h"
#include <errno.h>

static int sscanf_chirp( char const *input,char const *fmt,... );

IOProxyHandler::IOProxyHandler()
{
	cookie = 0;
	got_cookie = false;
}

IOProxyHandler::~IOProxyHandler()
{
	free(cookie);
}

/*
Initialize this handler on the given stream.
The process at the other side of the stream must present
the cookie passed in as an argument.  This r
Returns true on success, false otherwise.
*/

bool IOProxyHandler::init( Stream *s, const char *c )
{
	cookie = strdup(c);
	if(!cookie) return false;

	daemonCore->Register_Socket( s, "IOProxy client", (SocketHandlercpp) &IOProxyHandler::handle_request, "IOProxyHandler::handle_request", this );

	return true;
}

/*
This callback is invoked any time new data arrive on the socket.
If a valid cookie has been received, then decode and execute the request.
Otherwise, only accept cookie attempts.
Returns KEEP_STREAM if the stream is still valid, ~KEEP_STREAM otherwise.
*/

int IOProxyHandler::handle_request( Stream *s )
{
	char line[CHIRP_LINE_MAX];
	ReliSock *r = (ReliSock *) s;

	if(r->get_line_raw(line,CHIRP_LINE_MAX)>0)  {
		if( got_cookie ) {
			handle_standard_request(r,line);
		} else {
			handle_cookie_request(r,line);
		}
		return KEEP_STREAM;
	} else {
		dprintf(D_ALWAYS,"IOProxyHandler: closing connection to %s\n",r->peer_ip_str());
		delete this;
		return ~KEEP_STREAM;
	}
}

/*
Handle an incoming line from the client.
If it is a valid cookie request, then authenticate.
Otherwise, return a not-authenticated-error.
*/

void IOProxyHandler::handle_cookie_request( ReliSock *r, char *line )
{
	char check_cookie[CHIRP_LINE_MAX];

	if(sscanf(line,"cookie %s",check_cookie)==1) {
		if(!strcmp(check_cookie,cookie)) {
			dprintf( D_FULLDEBUG, 
					 "IOProxyHandler: client presented correct cookie.\n" );
			got_cookie = true;
		} else {
			dprintf( D_ALWAYS, "IOProxyHandler: client presented "
					 "*WRONG* cookie.\n" );
			sleep(1);
		}
	} else {
		dprintf( D_ALWAYS, "IOProxyHandler: client started with "
				 "'%s' instead of a cookie\n", line );
	}

	if(got_cookie) {
		sprintf(line,"0");
	} else {
		sprintf(line,"%d",CHIRP_ERROR_NOT_AUTHENTICATED);
	}

	r->put_line_raw(line);
}


/*
sscanf_chirp -- A simplified version of sscanf that handles escapes.

Format tokens recognized:

%d  --  decimal
%s  --  word, possibly containing escaped characters
%%  --  match %
*/

int
sscanf_chirp( char const *input,char const *fmt,... )
{
  va_list args;
  int args_parsed = 0;
  va_start(args,fmt);

  while(*input && *fmt) {
    if(*fmt == '%') { //parse an argument
      switch(*(++fmt)) {
      case 'd': { //read a decimal
	long d;
	char *end;
	fmt++;
	d = strtol(input,&end,10);
	if(end > input) {
	  args_parsed++;
	  *(va_arg(args,int *)) = d;
	  input = end;
	}
	else goto parse_failed;
	break;
      }
      case 's': { //read a word
	//assume provided buffer is big enough
	char *word = va_arg(args,char *);
	fmt++;
	while(*input && !isspace(*input)) {
	  if(*input == '\\') {
	    input++;
	    if(!*input) break;
	  }
	  *(word++) = *(input++);
	}
	*word = '\0';
	args_parsed++;
	break;
      }
      case '%':
	if(*input != *fmt) goto parse_failed;
	input++;
	fmt++;
	break;
      default: //unexpected fmt token!?
	goto parse_failed;
      }
    } else if(isspace(*fmt)) { //match whitespace
      while(isspace(*input)) input++;
      while(isspace(*fmt)) fmt++;
    } else { //normal character match
      if(*input != *fmt) goto parse_failed;
      input++;
      fmt++;
    }
  }

 parse_failed:
  //like sscanf, we just return number of parsed args when something fails

  va_end(args);
  return args_parsed;
}

/*
Handle an incoming line from the client.
A valid cookie is assumed to have been received, so decode and execute any request.
*/

void IOProxyHandler::handle_standard_request( ReliSock *r, char *line )
{
	char *url = NULL;
	char path[CHIRP_LINE_MAX];
	char newpath[CHIRP_LINE_MAX];
	char flags_string[CHIRP_LINE_MAX];
	char name[CHIRP_LINE_MAX];
	char expr[CHIRP_LINE_MAX];
	int result, offset, whence, length, flags, mode, fd;

	dprintf(D_SYSCALLS,"IOProxyHandler: request: %s\n",line);

	if(sscanf_chirp(line,"open %s %s %d",path,flags_string,&mode)==3) {

		/*
		Open is a rather special case.
		First, we attempt to look up the file name and
		convert it into a physical url.  Then, we make
		sure that we know how to open the url.
		Finally, we actually open it.
		*/

		dprintf(D_SYSCALLS,"Getting mapping for file %s\n",path);

		result = REMOTE_CONDOR_get_file_info_new(path,url);
		if(result==0) {
			dprintf(D_SYSCALLS,"Directed to use url %s\n",url);
			ASSERT( strlen(url) < CHIRP_LINE_MAX );
			if(!strncmp(url,"remote:",7)) {
				strncpy(path,url+7,CHIRP_LINE_MAX);
			} else if(!strncmp(url,"buffer:remote:",14)) {
				strncpy(path,url+14,CHIRP_LINE_MAX);
			} else {
				EXCEPT("File %s maps to url %s, which I don't know how to open.\n",path,url);
			}
		} else {
			EXCEPT("Unable to map file %s to a url: %s\n",path,strerror(errno));
		}

		dprintf(D_SYSCALLS,"Which simplifies to file %s\n",path);

		flags = 0;

		if( strchr(flags_string,'w') ) {
			if( strchr(flags_string,'r') ) {
				flags |= O_RDWR;
			} else {
				flags |= O_WRONLY;
			}
		} else {
			flags |= O_RDONLY;
		}

		if(strchr(flags_string,'c')) flags |= O_CREAT;
		if(strchr(flags_string,'t')) flags |= O_TRUNC;
		if(strchr(flags_string,'x')) flags |= O_EXCL;
		if(strchr(flags_string,'a')) flags |= O_APPEND;

		result = REMOTE_CONDOR_open(path,(open_flags_t)flags,mode);
		sprintf(line,"%d",convert(result,errno));
		r->put_line_raw(line);

		free( url );
		url = NULL;
	} else if(sscanf_chirp(line,"close %d",&fd)==1) {

		result = REMOTE_CONDOR_close(fd);
		sprintf(line,"%d",convert(result,errno));
		r->put_line_raw(line);

	} else if(sscanf_chirp(line,"lseek %d %d %d",&fd,&offset,&whence)) {

		int whence_valid = 1;

		switch(whence) {
			case 0:
				whence = SEEK_SET;
				break;
			case 1:
				whence = SEEK_CUR;
				break;
			case 2:
				whence = SEEK_END;
				break;
			default:
				whence_valid = 0;
				break;
		}

		if(whence_valid) {
			result = REMOTE_CONDOR_lseek(fd,offset,whence);
			result = convert(result,errno);
		} else {
			result = CHIRP_ERROR_INVALID_REQUEST;
		}

		sprintf(line,"%d",result);
		r->put_line_raw(line);

	} else if(sscanf_chirp(line,"unlink %s",path)==1) {

		result = REMOTE_CONDOR_unlink(path);
		sprintf(line,"%d",convert(result,errno));
		r->put_line_raw(line);

	} else if(sscanf_chirp(line,"rename %s %s",path,newpath)==2) {

		result = REMOTE_CONDOR_rename(path,newpath);
		sprintf(line,"%d",convert(result,errno));
		r->put_line_raw(line);

	} else if(sscanf_chirp(line,"mkdir %s %d",path,&mode)==2) {

		result = REMOTE_CONDOR_mkdir(path,mode);
		sprintf(line,"%d",convert(result,errno));
		r->put_line_raw(line);

	} else if(sscanf_chirp(line,"rmdir %s",path)==1) {

		result = REMOTE_CONDOR_rmdir(path);
		sprintf(line,"%d",convert(result,errno));
		r->put_line_raw(line);

	} else if(sscanf_chirp(line,"fsync %d",&fd)==1) {

		result = REMOTE_CONDOR_fsync(fd);
		sprintf(line,"%d",convert(result,errno));
		r->put_line_raw(line);

	} else if(sscanf_chirp(line,"lookup %s",path)==1) {

		result = REMOTE_CONDOR_get_file_info_new(path,url);
		if(result==0) {
			dprintf(D_SYSCALLS,"Filename %s maps to url %s\n",path,url);
			sprintf(line,"%u",(unsigned int)strlen(url));
			r->put_line_raw(line);
			r->put_bytes_raw(url,strlen(url));
		} else {
			sprintf(line,"%d",convert(result,errno));
			r->put_line_raw(line);
		}

		free( url );
		url = NULL;
	} else if(sscanf_chirp(line,"set_job_attr %s %s",name,expr)==2) {

		result = REMOTE_CONDOR_set_job_attr(name,expr);
		sprintf(line,"%d",convert(result,errno));
		r->put_line_raw(line);

	} else if(sscanf_chirp(line,"get_job_attr %s",name)==1) {

		char *recv_expr = NULL;
		result = REMOTE_CONDOR_get_job_attr(name,recv_expr);
		if(result==0) {
			sprintf(line,"%u",(unsigned int)strlen(recv_expr));
			r->put_line_raw(line);
			r->put_bytes_raw(recv_expr,strlen(recv_expr));
		} else {
			sprintf(line,"%d",convert(result,errno));
			r->put_line_raw(line);
		}	
		free( recv_expr );

	} else if(sscanf_chirp(line,"constrain %s",expr)==1) {

		result = REMOTE_CONDOR_constrain(expr);
		sprintf(line,"%d",convert(result,errno));
		r->put_line_raw(line);

	} else if(sscanf_chirp(line,"read %d %d",&fd,&length)==2) {

		char *buffer = (char*) malloc(length);
		if(buffer) {
			result = REMOTE_CONDOR_read(fd,buffer,length);
			sprintf(line,"%d",convert(result,errno));
			r->put_line_raw(line);
			if(result>0) {
				r->put_bytes_raw(buffer,result);
			}
			free(buffer);
		} else {
			sprintf(line,"%d",CHIRP_ERROR_NO_MEMORY);
		}
	
	} else if(sscanf_chirp(line,"write %d %d",&fd,&length)==2) {

		char *buffer = (char*) malloc(length);
		if(buffer) {
			result = r->get_bytes_raw(buffer,length);
			if(result==length) {
				result = REMOTE_CONDOR_write(fd,buffer,length);
				sprintf(line,"%d",convert(result,errno));
			} else {
				sprintf(line,"%d",CHIRP_ERROR_INVALID_REQUEST);
			}
			free(buffer);
		} else {
			sprintf(line,"%d",CHIRP_ERROR_NO_MEMORY);
		}
		r->put_line_raw(line);
		
	} else if(sscanf_chirp(line,"ulog %s", name)==1) {

		GenericEvent event;
		ClassAd *ad;

		// setInfoText truncates name to 128 bytes
		event.setInfoText( name );

		ad = event.toClassAd();
		ASSERT(ad);

		result = REMOTE_CONDOR_ulog( ad );
		sprintf(line, "%d", convert(result,errno));
		r->put_line_raw(line);

	} else if(strncmp(line,"version",7)==0) {
	    sprintf(line,"%d",CHIRP_VERSION);
	    r->put_line_raw(line);
	}
	else {
		sprintf(line,"%d",CHIRP_ERROR_INVALID_REQUEST);
		r->put_line_raw(line);
	}

	dprintf(D_SYSCALLS,"IOProxyHandler: response: %s\n",line);
}

int IOProxyHandler::convert( int result, int unix_errno )
{
	if(result>=0) return result;

	switch(unix_errno) {
		case EPERM:
		case EACCES:
			return CHIRP_ERROR_NOT_AUTHORIZED;
		case ENOENT:
			return CHIRP_ERROR_DOESNT_EXIST;
		case EEXIST:
			return CHIRP_ERROR_ALREADY_EXISTS;
		case EFBIG:
			return CHIRP_ERROR_TOO_BIG;
		case ENOSPC:
			return CHIRP_ERROR_NO_SPACE;
		case ENOMEM:
			return CHIRP_ERROR_NO_MEMORY;
		case EBADF:
		case E2BIG:
		case EINVAL:
			return CHIRP_ERROR_INVALID_REQUEST;
		case ENFILE:
		case EMFILE:
			return CHIRP_ERROR_TOO_MANY_OPEN;
		case EBUSY:
#ifndef WIN32
		case ETXTBSY:
#endif
			return CHIRP_ERROR_BUSY;
		case EAGAIN:
		case EINTR:
			return CHIRP_ERROR_TRY_AGAIN;
		default:
			dprintf(D_ALWAYS, "Starter ioproxy server got unknown unix errno:%d\n", unix_errno);
			return CHIRP_ERROR_UNKNOWN;
	}
}
