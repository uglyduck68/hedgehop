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



/* 
   This file contains implementations of functions we need in the
   regular libcedar.a that we do NOT want to link into standard
   universe jobs with libcondorsyscall.a.  Any functions implemented
   here need to be added to condor_syscall_lib/cedar_no_ckpt_stubs.C
   that calls EXCEPT() or whatever is appropriate.  This way, we can
   add functionality to CEDAR that we need/use outside of the syscall
   library without causing trouble inside the standard universe code.
*/


#include "condor_common.h"
#include "condor_debug.h"
#include "condor_io.h"
#include "directory.h"
#include "globus_utils.h"
#include "condor_auth_x509.h"
#include "condor_config.h"
#include "ccb_client.h"
#include "condor_sinful.h"
#include "condor_netdb.h"
#include "internet.h"

#ifdef WIN32
#include <mswsock.h>	// For TransmitFile()
#endif

const unsigned int PUT_FILE_EOM_NUM = 666;

// This special file descriptor number must not be a valid fd number.
// It is used to make get_file() consume transferred data without writing it.
const int GET_FILE_NULL_FD = -10;

int
ReliSock::get_file( filesize_t *size, const char *destination, bool flush_buffers)
{
	int fd;
	int result;

	// Open the file
	errno = 0;
	fd = ::safe_open_wrapper( destination,
				 O_WRONLY | O_CREAT | O_TRUNC |
				 _O_BINARY | _O_SEQUENTIAL | O_LARGEFILE,
				 0600 );

	// Handle open failure; it's bad....
	if ( fd < 0 )
	{
		int saved_errno = errno;
#ifndef WIN32 /* Unix */
		if ( errno == EMFILE ) {
			_condor_fd_panic( __LINE__, __FILE__ ); /* This calls dprintf_exit! */
		}
#endif
		dprintf(D_ALWAYS,
				"get_file(): Failed to open file %s, errno = %d: %s.\n",
				destination, saved_errno, strerror(saved_errno) );

			// In order to remain in a well-defined state on the wire
			// protocol, read and throw away the file data.
		result = get_file( size, GET_FILE_NULL_FD, flush_buffers );
		if( result<0 ) {
				// Failure to read (and throw away) data indicates that
				// we are in an undefined state on the wire protocol
				// now, so return that type of failure, rather than
				// the well-defined failure code for OPEN_FAILED.
			return result;
		}

		errno = saved_errno;
		return GET_FILE_OPEN_FAILED;
	} 

	dprintf(D_FULLDEBUG,"get_file(): going to write to filename %s\n",
		destination);

	result = get_file( size, fd,flush_buffers);

	if(::close(fd)!=0) {
		dprintf(D_ALWAYS, "ReliSock: get_file: close failed, errno = %d (%s)\n", errno, strerror(errno));
		return -1;
	}

	if(result<0) unlink(destination);
	
	return result;
}

int
ReliSock::get_file( filesize_t *size, int fd, bool flush_buffers )
{
	char buf[65536];
	filesize_t filesize;
	unsigned int eom_num;
	filesize_t total = 0;
	int retval = 0;
	int saved_errno = 0;

		// NOTE: the caller may pass fd=GET_FILE_NULL_FD, in which
		// case we just read but do not write the data.

	// Read the filesize from the other end of the wire
	if ( !get(filesize) || !end_of_message() ) {
		dprintf(D_ALWAYS, 
			"Failed to receive filesize in ReliSock::get_file\n");
		return -1;
	}


	// Log what's going on
	dprintf(D_FULLDEBUG,
			"get_file: Receiving " FILESIZE_T_FORMAT " bytes\n", filesize );

		/*
		  the code used to check for filesize == -1 here, but that's
		  totally wrong.  we're storing the size as an unsigned int,
		  so we can't check it against a negative value.  furthermore,
		  ReliSock::put_file() never puts a -1 on the wire for the
		  size.  that's legacy code from the pseudo_put_file_stream()
		  RSC in the syscall library.  this code isn't like that.
		*/

	// Now, read it all in & save it
	while( total < filesize ) {
		int	iosize = (int) MIN( (filesize_t) sizeof(buf),
									filesize - total );
		int	nbytes = get_bytes_nobuffer( buf, iosize, 0 );
		if ( nbytes <= 0 ) {
			break;
		}

		if( fd == GET_FILE_NULL_FD ) {
				// Do not write the data, because we are just
				// fast-forwarding and throwing it away, due to errors
				// already encountered.
			total += nbytes;
			continue;
		}

		int rval;
		int written;
		for( written=0; written<nbytes; ) {
			rval = ::write( fd, &buf[written], (nbytes-written) );
			if( rval < 0 ) {
				saved_errno = errno;
				dprintf( D_ALWAYS,
						 "ReliSock::get_file: write() returned %d: %s "
						 "(errno=%d)\n", rval, strerror(errno), errno );


					// Continue reading data, but throw it all away.
					// In this way, we keep the wire protocol in a
					// well defined state.
				fd = GET_FILE_NULL_FD;
				retval = GET_FILE_WRITE_FAILED;
				written = nbytes;
				break;
			} else if( rval == 0 ) {
					/*
					  write() shouldn't really return 0 at all.
					  apparently it can do so if we asked it to write
					  0 bytes (which we're not going to do) or if the
					  file is closed (which we're also not going to
					  do).  so, for now, if we see it, we want to just
					  break out of this loop.  in the future, we might
					  do more fancy stuff to handle this case, but
					  we're probably never going to see this anyway.
					*/
				dprintf( D_ALWAYS, "ReliSock::get_file: write() returned 0: "
						 "wrote %d out of %d bytes (errno=%d %s)\n",
						 written, nbytes, errno, strerror(errno) );
				break;
			} else {
				written += rval;
			}
		}
		total += written;
	}

	if ( filesize == 0 ) {
		if ( !get(eom_num) || eom_num != PUT_FILE_EOM_NUM ) {
			dprintf(D_ALWAYS,"get_file: Zero-length file check failed!\n");
			return -1;
		}			
	}

	if (flush_buffers && fd != GET_FILE_NULL_FD ) {
		fsync(fd);
	}

	if( fd == GET_FILE_NULL_FD ) {
		dprintf( D_ALWAYS,
				 "get_file(): consumed " FILESIZE_T_FORMAT
				 " bytes of file transmission\n",
				 total );
	}
	else {
		dprintf( D_FULLDEBUG,
				 "get_file: wrote " FILESIZE_T_FORMAT " bytes to file\n",
				 total );
	}

	if ( total < filesize ) {
		dprintf( D_ALWAYS,
				 "get_file(): ERROR: received " FILESIZE_T_FORMAT " bytes, "
				 "expected " FILESIZE_T_FORMAT "!\n",
				 total, filesize);
		return -1;
	}

	*size = total;
	errno = saved_errno;
	return retval;
}

int
ReliSock::put_empty_file( filesize_t *size )
{
	*size = 0;
	if(!put(*size) || !end_of_message()) {
		dprintf(D_ALWAYS,"ReliSock: put_file: failed to send dummy file size\n");
		return -1;
	}
	put(PUT_FILE_EOM_NUM); //end the zero-length file
	return 0;
}

int
ReliSock::put_file( filesize_t *size, const char *source)
{
	int fd;
	int result;

	// Open the file, handle failure
	fd = safe_open_wrapper(source, O_RDONLY | O_LARGEFILE | _O_BINARY | _O_SEQUENTIAL, 0);
	if ( fd < 0 )
	{
		dprintf(D_ALWAYS,
				"ReliSock: put_file: Failed to open file %s, errno = %d.\n",
				source, errno);
			// Give the receiver an empty file so that this message is
			// complete.  The receiver _must_ detect failure through
			// some additional communication that is not part of
			// the put_file() message.

		int rc = put_empty_file( size );
		if(rc < 0) {
			return rc;
		}

		return PUT_FILE_OPEN_FAILED;
	}

	dprintf(D_FULLDEBUG,"put_file: going to send from filename %s\n",
		source);

	result = put_file( size, fd);

	if (::close(fd) < 0) {
		dprintf(D_ALWAYS, "ReliSock: put_file: close failed, errno = %d (%s)\n", errno, strerror(errno));
		return -1;
	}

	return result;
}

int
ReliSock::put_file( filesize_t *size, int fd )
{
	filesize_t	filesize;
	filesize_t	total = 0;


	StatInfo filestat( fd );
	if ( filestat.Error() ) {
		int		staterr = filestat.Errno( );
		dprintf(D_ALWAYS, "ReliSock: put_file: StatBuf failed: %d %s\n",
				staterr, strerror( staterr ) );
		return -1;
	}

	if ( filestat.IsDirectory() ) {
		dprintf(D_ALWAYS,
				"ReliSock: put_file: Failed because directories are not supported.\n" );
			// Give the receiver an empty file so that this message is
			// complete.  The receiver _must_ detect failure through
			// some additional communication that is not part of
			// the put_file() message.

		int rc = put_empty_file( size );
		if(rc < 0) {
			return rc;
		}

#ifdef EISDIR
		errno = EISDIR;
#else
		errno = EINVAL;
#endif
		return PUT_FILE_OPEN_FAILED;
	}

	filesize = filestat.GetFileSize( );
	dprintf( D_FULLDEBUG, "put_file: Found file size %lld\n", filesize );

	// Send the file size to the reciever
	if ( !put(filesize) || !end_of_message() ) {
		dprintf(D_ALWAYS, "ReliSock: put_file: Failed to send filesize.\n");
		return -1;
	}

	// Log what's going on
	dprintf(D_FULLDEBUG,
			"put_file: sending " FILESIZE_T_FORMAT " bytes\n", filesize);

	// If the file has a non-zero size, send it
	if ( filesize > 0 ) {

#if defined(WIN32)
		// On Win32, if we don't need encryption, use the super-efficient Win32
		// TransmitFile system call. Also, TransmitFile does not support
		// file sizes over 2GB, so we avoid that case as well.
		if ( !get_encryption() && filesize < INT_MAX ) {

			// First drain outgoing buffers
			if ( !prepare_for_nobuffering(stream_encode) ) {
				dprintf(D_ALWAYS,
						"ReliSock: put_file: failed to drain buffers!\n");
				return -1;
			}

			// Now transmit file using special optimized Winsock call
			if ( TransmitFile(_sock,(HANDLE)_get_osfhandle(fd),
							  filesize,0,NULL,NULL,0) == FALSE ) {
				dprintf(D_ALWAYS,
						"ReliSock: put_file: TransmitFile() failed, errno=%d\n",
						GetLastError() );
				return -1;
			} else {
				// Note that it's been sent, so that we don't try to below
				total = filesize;
			}
		}
#endif

		char buf[65536];
		int nbytes, nrd;

		// On Unix, always send the file using put_bytes_nobuffer().
		// Note that on Win32, we use this method as well if encryption 
		// is required.
		while (total < filesize &&
			   (nrd = ::read(fd, buf, sizeof(buf))) > 0) {
			if ((nbytes = put_bytes_nobuffer(buf, nrd, 0)) < nrd) {
					// put_bytes_nobuffer() does the appropriate
					// looping for us already, the only way this could
					// return less than we asked for is if it returned
					// -1 on failure.
				ASSERT( nbytes == -1 );
				dprintf( D_ALWAYS, "ReliSock::put_file: failed to put %d "
						 "bytes (put_bytes_nobuffer() returned %d)\n",
						 nrd, nbytes );
				return -1;
			}
			total += nbytes;
		}
	
	} // end of if filesize > 0

	if ( filesize == 0 ) {
		put(PUT_FILE_EOM_NUM);
	}

	dprintf(D_FULLDEBUG,
			"ReliSock: put_file: sent " FILESIZE_T_FORMAT " bytes\n", total);

	if (total < filesize) {
		dprintf(D_ALWAYS,"ReliSock: put_file: only sent " FILESIZE_T_FORMAT 
					" bytes out of " FILESIZE_T_FORMAT "\n",
			total, filesize);
		return -1;
	}

	*size = filesize;
	return 0;
}

int
ReliSock::get_file_with_permissions( filesize_t *size, 
									 const char *destination,
									 bool flush_buffers )
{
	int result;
	condor_mode_t file_mode;

	// Read the permissions
	this->decode();
	if ( this->code( file_mode ) == FALSE ||
		 this->end_of_message() == FALSE ) {
		dprintf( D_ALWAYS, "ReliSock::get_file_with_permissions(): "
				 "Failed to read permissions from peer\n" );
		return -1;
	}

	result = get_file( size, destination, flush_buffers );

	if ( result < 0 ) {
		return result;
	}

		// If the other side told us to ignore its permissions, then we're
		// done.
	if ( file_mode == NULL_FILE_PERMISSIONS ) {
		dprintf( D_FULLDEBUG, "ReliSock::get_file_with_permissions(): "
				 "received null permissions from peer, not setting\n" );
		return result;
	}

		// We don't know how unix permissions translate to windows, so
		// ignore whatever permissions we received if we're on windows.
#ifndef WIN32
	dprintf( D_FULLDEBUG, "ReliSock::get_file_with_permissions(): "
			 "going to set permissions %o\n", file_mode );

	// chmod the file
	errno = 0;
	result = ::chmod( destination, (mode_t)file_mode );
	if ( result < 0 ) {
		dprintf( D_ALWAYS, "ReliSock::get_file_with_permissions(): "
				 "Failed to chmod file '%s': %s (errno: %d)\n",
				 destination, strerror(errno), errno );
		return -1;
	}
#endif

	return result;
}


int
ReliSock::put_file_with_permissions( filesize_t *size, const char *source )
{
	int result;
	condor_mode_t file_mode;

#ifndef WIN32
	// Stat the file
	StatInfo stat_info( source );

	if ( stat_info.Error() ) {
		dprintf( D_ALWAYS, "ReliSock::put_file_with_permissions(): "
				 "Failed to stat file '%s': %s (errno: %d, si_error: %d)\n",
				 source, strerror(stat_info.Errno()), stat_info.Errno(),
				 stat_info.Error() );

		// Now send an empty file in order to recover sanity on this
		// stream.
		file_mode = NULL_FILE_PERMISSIONS;
		this->encode();
		if( this->code( file_mode) == FALSE ||
			this->end_of_message() == FALSE ) {
			dprintf( D_ALWAYS, "ReliSock::put_file_with_permissions(): "
			         "Failed to send dummy permissions\n" );
			return -1;
		}
		int rc = put_empty_file( size );
		if(rc < 0) {
			return rc;
		}
		return PUT_FILE_OPEN_FAILED;
	}
	file_mode = (condor_mode_t)stat_info.GetMode();
#else
		// We don't know what unix permissions a windows file should have,
		// so tell the other side to ignore permissions from us (act like
		// get/put_file() ).
	file_mode = NULL_FILE_PERMISSIONS;
#endif

	dprintf( D_FULLDEBUG, "ReliSock::put_file_with_permissions(): "
			 "going to send permissions %o\n", file_mode );

	// Send the permissions
	this->encode();
	if ( this->code( file_mode ) == FALSE ||
		 this->end_of_message() == FALSE ) {
		dprintf( D_ALWAYS, "ReliSock::put_file_with_permissions(): "
				 "Failed to send permissions\n" );
		return -1;
	}

	result = put_file( size, source );

	return result;
}

int
ReliSock::get_x509_delegation( filesize_t *size, const char *destination,
							   bool flush_buffers )
{
	int in_encode_mode;

		// store if we are in encode or decode mode
	in_encode_mode = is_encode();

	if ( !prepare_for_nobuffering( stream_unknown ) ||
		 !end_of_message() ) {
		dprintf( D_ALWAYS, "ReliSock::get_x509_delegation(): failed to "
				 "flush buffers\n" );
		return -1;
	}

	if ( x509_receive_delegation( destination, relisock_gsi_get, (void *) this,
								  relisock_gsi_put, (void *) this ) != 0 ) {
		dprintf( D_ALWAYS, "ReliSock::get_x509_delegation(): "
				 "delegation failed: %s\n", x509_error_string() );
		return -1;
	}

		// restore stream mode (either encode or decode)
	if ( in_encode_mode && is_decode() ) {
		encode();
	} else if ( !in_encode_mode && is_encode() ) { 
		decode();
	}
	if ( !prepare_for_nobuffering( stream_unknown ) ) {
		dprintf( D_ALWAYS, "ReliSock::get_x509_delegation(): failed to "
				 "flush buffers afterwards\n" );
		return -1;
	}

	if ( flush_buffers ) {
		int rc = 0;
		int fd = safe_open_wrapper( destination, O_WRONLY, 0 );
		if ( fd < 0 ) {
			rc = fd;
		} else {
			rc = fsync( fd );
			::close( fd );
		}
		if ( rc < 0 ) {
			dprintf( D_ALWAYS, "ReliSock::get_x509_delegation(): open/fsync "
					 "failed, errno=%d (%s)\n", errno,
					 strerror( errno ) );
		}
	}

		// We should figure out how many bytes were sent
	*size = 0;

	return 0;
}

int
ReliSock::put_x509_delegation( filesize_t *size, const char *source )
{
	int in_encode_mode;

		// store if we are in encode or decode mode
	in_encode_mode = is_encode();

	if ( !prepare_for_nobuffering( stream_unknown ) ||
		 !end_of_message() ) {
		dprintf( D_ALWAYS, "ReliSock::put_x509_delegation(): failed to "
				 "flush buffers\n" );
		return -1;
	}

	if ( x509_send_delegation( source, relisock_gsi_get, (void *) this,
							   relisock_gsi_put, (void *) this ) != 0 ) {
		dprintf( D_ALWAYS, "ReliSock::put_x509_delegation(): delegation "
				 "failed: %s\n", x509_error_string() );
		return -1;
	}

		// restore stream mode (either encode or decode)
	if ( in_encode_mode && is_decode() ) {
		encode();
	} else if ( !in_encode_mode && is_encode() ) { 
		decode();
	}
	if ( !prepare_for_nobuffering( stream_unknown ) ) {
		dprintf( D_ALWAYS, "ReliSock::put_x509_delegation(): failed to "
				 "flush buffers afterwards\n" );
		return -1;
	}

		// We should figure out how many bytes were sent
	*size = 0;

	return 0;
}


int relisock_gsi_get(void *arg, void **bufp, size_t *sizep)
{
    /* globus code which calls this function expects 0/-1 return vals */
    
    ReliSock * sock = (ReliSock*) arg;
    size_t stat;
    
    sock->decode();
    
    //read size of data to read
    stat = sock->code( *((int *)sizep) );

	if( *((int *)sizep) == 0 ) {
			// We avoid calling malloc(0) here, because the zero-length
			// buffer is not being freed by globus.
		*bufp = NULL;
	}
	else {
		*bufp = malloc( *((int *)sizep) );
		if ( !*bufp ) {
			dprintf( D_ALWAYS, "malloc failure relisock_gsi_get\n" );
			stat = FALSE;
		}

			//if successfully read size and malloced, read data
		if ( stat ) {
			sock->code_bytes( *bufp, *((int *)sizep) );
		}
	}
    
    sock->end_of_message();
    
    //check to ensure comms were successful
    if ( stat == FALSE ) {
        dprintf( D_ALWAYS, "relisock_gsi_get (read from socket) failure\n" );
        return -1;
    }
    return 0;
}

int relisock_gsi_put(void *arg,  void *buf, size_t size)
{
    //param is just a ReliSock*
    ReliSock *sock = (ReliSock *) arg;
    int stat;
    
    sock->encode();
    
    //send size of data to send
    stat = sock->code( (int &)size );
    
    
    //if successful, send the data
    if ( stat ) {
        if ( !(stat = sock->code_bytes( buf, ((int) size )) ) ) {
            dprintf( D_ALWAYS, "failure sending data (%d bytes) over sock\n",size);
        }
    }
    else {
        dprintf( D_ALWAYS, "failure sending size (%d) over sock\n", size );
    }
    
    sock->end_of_message();
    
    //ensure data send was successful
    if ( stat == FALSE) {
        dprintf( D_ALWAYS, "relisock_gsi_put (write to socket) failure\n" );
        return -1;
    }
    return 0;
}

bool
Stream::prepare_crypto_for_secret_is_noop()
{
	CondorVersionInfo const *peer_ver = get_peer_version();
	if( !peer_ver || peer_ver->built_since_version(7,1,3) ) {
		if( !get_encryption() ) {
			if( crypto_ ) {
					// do turn on encryption before sending secret
				return false;
			}
		}
	}
	return true;
}

void
Stream::prepare_crypto_for_secret()
{
	m_crypto_state_before_secret = true;
	if( !prepare_crypto_for_secret_is_noop() ) {
		dprintf(D_NETWORK,"encrypting secret\n");
		m_crypto_state_before_secret = get_encryption(); // always false
		set_crypto_mode(true);
	}
}

void
Stream::restore_crypto_after_secret()
{
	if( !m_crypto_state_before_secret ) {
		set_crypto_mode(false); //restore crypto mode
	}
}

int Sock::reverse_connect(char const *host,int /*port*/,bool nonblocking)
{
	if( !host || *host != '<' ) {
		return CEDAR_ENOCCB;
	}

	Sinful sinful(host);
	if( !sinful.valid() ) {
		return CEDAR_ENOCCB;
	}

	char const *ccb_contact = sinful.getCCBContact();
	if( !ccb_contact || !*ccb_contact ) {
		return CEDAR_ENOCCB;
	}

	return do_reverse_connect(ccb_contact,nonblocking);
}

int
SafeSock::do_reverse_connect(char const *,bool)
{
	dprintf(D_ALWAYS,
			"CCBClient: WARNING: UDP not supported by CCB."
			"  Will therefore try to send packet directly to %s.\n",
			peer_description());

	return CEDAR_ENOCCB;
}

int
ReliSock::do_reverse_connect(char const *ccb_contact,bool nonblocking)
{
	ASSERT( !m_ccb_client.get() ); // only one reverse connect at a time!
	m_ccb_client =
		new CCBClient( ccb_contact, (ReliSock *)this );

	if( !m_ccb_client->ReverseConnect(NULL,nonblocking) ) {
		dprintf(D_ALWAYS,"Failed to reverse connect to %s via CCB.\n",
				peer_description());
		return 0;
	}
	if( nonblocking ) {
		return CEDAR_EWOULDBLOCK;
	}

	m_ccb_client = NULL; // in blocking case, we are done with ccb client
	return 1;
}

void
ReliSock::cancel_reverse_connect() {
	ASSERT( m_ccb_client.get() );
	m_ccb_client->CancelReverseConnect();
}

char const *
Sock::get_sinful_public()
{
		// In case TCP_FORWARDING_HOST changes, do not cache it.
	MyString tcp_forwarding_host;
	param(tcp_forwarding_host,"TCP_FORWARDING_HOST");
	if (!tcp_forwarding_host.IsEmpty()) {
		struct sockaddr_in sin;
		if (!is_ipaddr(tcp_forwarding_host.Value(), &sin.sin_addr)) {
			struct hostent *he = condor_gethostbyname(tcp_forwarding_host.Value());
			if (he == NULL) {
				dprintf(D_ALWAYS,
					"failed to resolve address of TCP_FORWARDING_HOST=%s\n",
					tcp_forwarding_host.Value());
				return NULL;
			}
			sin.sin_addr = *(in_addr*)(he->h_addr_list[0]);;
		}
		sin.sin_port = htons(get_port());
		char const *addr = sin_to_string(&sin);
		if( !addr ) {
			return NULL;
		}
		strncpy(_sinful_public_buf,addr,SINFUL_STRING_BUF_SIZE);
		_sinful_public_buf[SINFUL_STRING_BUF_SIZE-1] = '\0';
		return _sinful_public_buf;
	}

	return get_sinful();
}
