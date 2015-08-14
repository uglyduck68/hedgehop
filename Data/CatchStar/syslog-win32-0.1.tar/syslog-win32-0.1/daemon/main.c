/*
 * main.c - syslogd implementation for windows, main function
 *
 * Created by Alexander Yaworsky
 *
 * THIS SOFTWARE IS NOT COPYRIGHTED
 *
 * This source code is offered for use in the public domain. You may
 * use, modify or distribute it freely.
 *
 * This code is distributed in the hope that it will be useful but
 * WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 * DISCLAIMED. This includes but is not limited to warranties of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#include <glib.h>

#include <syslog.h>
#include <syslogd.h>

HANDLE service_stop_event;

char local_hostname[ MAX_COMPUTERNAME_LENGTH + 1 ];

int verbosity_level = 0;

static char *service_name = "syslogd";
static char *service_display_name = "syslogd";
static char *service_stop_event_name = "syslogd-stop";

static OSVERSIONINFO vi;

static SERVICE_STATUS_HANDLE hss;
static SERVICE_STATUS        sstatus;

/******************************************************************************
 * display message
 */
void display_message( FILE* fd, char* file, int line, const char* func, char* fmt, ... )
{
    va_list args;
    char formatstr[512];

    snprintf( formatstr, sizeof(formatstr), "%08lX:%s:%d:%s: %s",
              GetCurrentThreadId(), file, line, func, fmt );
    va_start( args, fmt );
    vfprintf( fd, formatstr, args );
    va_end( args );
    fflush( fd );
}

/******************************************************************************
 * shutdown_service
 *
 * set service stop event
 * wait until event exists
 */
static void shutdown_service( gboolean quiet )
{
    HANDLE he;
    BOOL ret;

    for(;;)
    {
        he = OpenEvent( EVENT_MODIFY_STATE, FALSE, service_stop_event_name );
        if( !he )
        {
            if( !quiet )
                ERR( "cannot open event; error %lu\n", GetLastError() );
            return;
        }
        TRACE( "setting stop event\n" );
        ret = SetEvent( he );
        CloseHandle( he );
        if( !ret )
        {
            if( !quiet )
            {
                ERR( "cannot set event; error %lu\n", GetLastError() );
                return;
            }
        }
        quiet = TRUE;
        Sleep(0);
    }
}

/******************************************************************************
 * service control handler
 */
static void WINAPI ServiceControlHandler( DWORD Control )
{
    switch( Control )
    {
    case SERVICE_CONTROL_STOP:
        sstatus.dwCurrentState = SERVICE_STOP_PENDING;
        sstatus.dwCheckPoint = 0;
        SetEvent( service_stop_event );
        break;
    case SERVICE_CONTROL_INTERROGATE:  /* return status immediately */
        break;
    }
    SetServiceStatus( hss, &sstatus );
}

/******************************************************************************
 * service main
 */
static void WINAPI winnt_ServiceMain( DWORD Argc, LPTSTR* Argv )
{
    hss = RegisterServiceCtrlHandler( PACKAGE_NAME,
                                      (LPHANDLER_FUNCTION)ServiceControlHandler );
    if( !hss )
        return;

    service_stop_event = CreateEvent( NULL, TRUE, FALSE, NULL );
    if( !service_stop_event )
        return;

    sstatus.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
    sstatus.dwCurrentState = SERVICE_RUNNING;
    sstatus.dwControlsAccepted = SERVICE_ACCEPT_STOP;
    sstatus.dwWin32ExitCode = NO_ERROR;
    sstatus.dwCheckPoint = 0;
    sstatus.dwWaitHint = 1000;
    SetServiceStatus( hss, &sstatus );

    syslogd_main();

    sstatus.dwWin32ExitCode = 0;
    sstatus.dwServiceSpecificExitCode = 0;
    sstatus.dwCurrentState = SERVICE_STOPPED;
    sstatus.dwCheckPoint = 0;
    SetServiceStatus( hss, &sstatus );

    CloseHandle( service_stop_event );
}

static int win9x_ServiceMain()
{
    service_stop_event = CreateEvent( NULL, TRUE, FALSE, service_stop_event_name );
    if( !service_stop_event )
    {
        ERR( "Cannot create event %s; error %lu\n", service_stop_event_name, GetLastError() );
        return 1;
    }
    if( ERROR_ALREADY_EXISTS == GetLastError() )
    {
        CloseHandle( service_stop_event );
        ERR( "Service is already running\n" );
        return 1;
    }

    syslogd_main();

    CloseHandle( service_stop_event );
    return 0;
}

/******************************************************************************
 * open system Run key
 */
static BOOL open_run_key( PHKEY hk )
{
    static char runkey[] = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";

    TRACE_ENTER( "\n" );
    if( RegOpenKey( HKEY_LOCAL_MACHINE, runkey, hk ) )
    {
        ERR( "Cannot open registry key %s; error %lu\n", runkey, GetLastError() );
        return FALSE;
    }
    TRACE_LEAVE( "done\n" );
    return TRUE;
}

/******************************************************************************
 * service installer
 */
static BOOL win9x_InstallService( char* command_line )
{
    BOOL ret;
    HKEY hk;
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    TRACE_ENTER( "command_line=%s\n", command_line );
    ret = open_run_key( &hk );
    if( !ret )
    {
        TRACE_LEAVE( "done\n" );
        return FALSE;
    }

    if( RegSetValueEx( hk, service_name, 0, REG_SZ, command_line, strlen( command_line ) + 1 ) )
    {
        ERR( "Cannot set registry value; error %lu\n", GetLastError() );
        ret = FALSE;
    }
    RegCloseKey( hk );
    if( !ret )
        return FALSE;

    memset( &si, 0, sizeof(si ) );
    si.cb = sizeof(si);
    ret = CreateProcess( NULL, command_line, NULL, NULL, FALSE, DETACHED_PROCESS,
                         NULL, NULL, &si, &pi );
    if( !ret )
    {
        ERR( "Cannot create process; error %lu\n", GetLastError() );
        return FALSE;
    }

    CloseHandle( pi.hThread );
    CloseHandle( pi.hProcess );
    TRACE_LEAVE( "done\n" );
    return TRUE;
}

static BOOL winnt_InstallService( char* command_line )
{
    SC_HANDLE hscm, hsvc;
    BOOL ret;

    TRACE_ENTER( "command_line=%s\n", command_line );
    hscm = OpenSCManager( NULL, NULL, SC_MANAGER_ALL_ACCESS );
    if( !hscm )
    {
        ERR( "Cannot open service control manager; error %lu\n",  GetLastError() );
        return FALSE;
    }
    hsvc = CreateService( hscm, service_name, service_display_name,
                          SERVICE_ALL_ACCESS, SERVICE_WIN32_OWN_PROCESS,
                          SERVICE_AUTO_START, SERVICE_ERROR_IGNORE,
                          command_line, NULL, NULL, NULL, NULL, NULL );
    if( !hsvc )
    {
        ERR( "Cannot create service; error %lu\n",  GetLastError() );
        ret = FALSE;
    }
    else
    {
        ret = StartService( hsvc, 0, NULL );
        if( !ret )
            ERR( "Cannot start service; error %lu\n",  GetLastError() );
        CloseServiceHandle( hsvc );
    }
    CloseServiceHandle( hscm );
    TRACE_LEAVE( "done\n" );
    return ret;
}

static BOOL install_service( char* priority )
{
    BOOL ret;
    char command_line[ MAX_PATH + 64 ];

    TRACE_ENTER( "\n" );
    if( __argv[0][1] == ':' )
        command_line[0] = 0;
    else
    {
        TRACE( "argv[0] contains no absolute path\n" );
        GetCurrentDirectory( MAX_PATH, command_line );
        strcat( command_line, "\\" );
    }
    strcat( command_line, __argv[0] );
    strcat( command_line, " --service" );
    if( priority )
    {
        strcat( command_line, " --priority " );
        strcat( command_line, priority );
    }

    if( VER_PLATFORM_WIN32_NT == vi.dwPlatformId )
        ret = winnt_InstallService( command_line );
    else
        ret = win9x_InstallService( command_line );

    TRACE_LEAVE( "done; ret=%d\n", ret );
    return ret;
}

/******************************************************************************
 * service uninstaller
 */
static void win9x_RemoveService()
{
    HKEY hk;

    TRACE_ENTER( "\n" );
    if( !open_run_key( &hk ) )
        return;
    RegDeleteValue( hk, service_name );
    RegCloseKey( hk );
    TRACE_LEAVE( "done\n" );
}

static void winnt_RemoveService()
{
    SC_HANDLE hscm, hsvc;
    int  i;

    TRACE_ENTER( "\n" );
    hscm = OpenSCManager( NULL, NULL, SC_MANAGER_ALL_ACCESS );
    if( !hscm )
    {
        ERR( "Cannot open service control manager; error %lu\n", GetLastError() );
        return;
    }

    hsvc = OpenService( hscm, service_name, SERVICE_ALL_ACCESS );
    if( !hsvc )
    {
        ERR( "Cannot open service %s; error %lu\n", service_name, GetLastError() );
        CloseServiceHandle( hscm );
        return;
    }

    ControlService( hsvc, SERVICE_CONTROL_STOP, &sstatus );

    for( i = 0; i < 10; i++ )
    {
        Sleep( 100 );
        if( !QueryServiceStatus( hsvc, &sstatus ) )
        {
            TRACE( "Cannot query service status; error %lu\n", GetLastError() );
            break;
        }
        if( SERVICE_STOPPED == sstatus.dwCurrentState )
            break;
    }
    if( !DeleteService( hsvc ) )
        TRACE( "Cannot delete service; error %lu\n", GetLastError() );

    CloseServiceHandle( hsvc );
    CloseServiceHandle( hscm );
    TRACE_LEAVE( "done\n" );
}

static void remove_service()
{
    TRACE_ENTER( "\n" );
    if( VER_PLATFORM_WIN32_NT == vi.dwPlatformId )
        winnt_RemoveService();
    else
        win9x_RemoveService();

    /* always try to shutdown because it's possible that daemon
       is running not as service under winNT */
    shutdown_service( TRUE );
    TRACE_LEAVE( "done\n" );
}

/******************************************************************************
 * exception_handler
 */
LONG WINAPI exception_handler( PEXCEPTION_POINTERS ei )
{
    DWORD i;
    BYTE *addr;

    fprintf( stderr,
             "*********************************\n"
             "thread id:\t\t%lX\n"
             "ExceptionCode:\t\t%lX\n"
             "ExceptionFlags:\t\t%lX\n"
             "ExceptionRecord:\t%p\n"
             "ExceptionAddress:\t%p\n"
             "NumberParameters:\t%lx\n"
             "ExceptionInformation:\n",
             GetCurrentThreadId(),
             ei->ExceptionRecord->ExceptionCode,
             ei->ExceptionRecord->ExceptionFlags,
             ei->ExceptionRecord->ExceptionRecord,
             ei->ExceptionRecord->ExceptionAddress,
             ei->ExceptionRecord->NumberParameters );

    for( i = 0; i < ei->ExceptionRecord->NumberParameters; i++ )
        fprintf( stderr, "\t%lX\n", ei->ExceptionRecord->ExceptionInformation[i] );

#if defined(_X86_)

    fprintf( stderr,
             "ContextFlags=%lX\n"
             "CS=%lX  DS=%lX  ES=%lX  SS=%lX  FS=%lX  GS=%lX\n"
             "EAX=%lX EBX=%lX ECX=%lX EDX=%lX ESI=%lX EDI=%lX\n"
             "EBP=%lX ESP=%lX EIP=%lX EFLAGS=%lX\n"
             "Stack Dump:\n",
	     ei->ContextRecord->ContextFlags,
             ei->ContextRecord->SegCs,
             ei->ContextRecord->SegDs,
             ei->ContextRecord->SegEs,
             ei->ContextRecord->SegSs,
             ei->ContextRecord->SegFs,
             ei->ContextRecord->SegGs,
             ei->ContextRecord->Eax,
             ei->ContextRecord->Ebx,
             ei->ContextRecord->Ecx,
             ei->ContextRecord->Edx,
             ei->ContextRecord->Esi,
             ei->ContextRecord->Edi,
             ei->ContextRecord->Ebp,
             ei->ContextRecord->Esp,
             ei->ContextRecord->Eip,
             ei->ContextRecord->EFlags );

    addr = (LPBYTE) (ei->ContextRecord->Esp);

#else
    fprintf( stderr, "FIXME: add more machines\n" );
#endif

    while( !IsBadReadPtr( addr, 16 ) )
    {
        int skip = ((DWORD) addr) & 15;
        BYTE *keep_addr = addr;

        fprintf( stderr, "%08lX", ((DWORD) addr) & ~15 );
        for( i = 0; i < skip; i++ )
            fprintf( stderr, "   " );
        for( ; i < 8; i++ )
            fprintf( stderr, " %02X", *addr++ );
        if( i == 8 )
            fputc( '-', stderr );
        for( ; i < 16; i++ )
            fprintf( stderr, "%02X ", *addr++ );
        fputc( ' ', stderr );
        addr = keep_addr;
        for( i = 0; i < skip; i++ )
            fputc( ' ', stderr );
        for( ; i < 16; i++ )
        {
            BYTE b = *addr++;

            if( b < 32 ) b = ' ';
            fputc( b, stderr );
        }
        fputc( '\n', stderr );
    }
    fprintf( stderr, "*********************************\n" );
    fflush( stderr );
    ExitProcess(2);
}

/******************************************************************************
 * main
 *
 * Parse command line
 */
int main( int argc, char* argv[] )
{
    static int help_flag = 0;
    static int version_flag = 0;
    static int install_flag = 0;
    static int remove_flag = 0;
    static int service_flag = 0;
    static int shutdown_flag = 0;
    char *instance_name = NULL;
    char *priority = NULL;
    int getopt_failure = 0;
    WSADATA wsd;
    DWORD size;

    SetUnhandledExceptionFilter( exception_handler );

    if( WSAStartup( MAKEWORD( 2, 2 ), &wsd ) )
    {
        ERR( "Cannot initialize winsock; error %lu\n", WSAGetLastError() );
        return 1;
    }

    /* get local host name */
    size = sizeof(local_hostname);
    if( !GetComputerName( local_hostname, &size ) )
    {
        ERR( "Cannot get computer name; error %lu\n", GetLastError() );
        return 1;
    }
    TRACE( "local host name=%s\n", local_hostname );

    /* get windows version */
    vi.dwOSVersionInfoSize = sizeof( OSVERSIONINFO );
    if( ! GetVersionEx( &vi ) )
    {
        ERR( "Cannot get windows version; error %lu\n", GetLastError() );
        return 1;
    }

    for(;;)
    {
        static struct option long_options[] =
        {
            { "verbose",         no_argument,       NULL,         'v'},
            { "help",            no_argument,       &help_flag,    1 },
            { "version",         no_argument,       &version_flag, 1 },
            { "install",         no_argument,       &install_flag, 1 },
            { "remove",          no_argument,       &remove_flag,  1 },
            { "service",         no_argument,       &service_flag, 1 },
            { "shutdown",        no_argument,       &shutdown_flag,1 },
            { "instance",        required_argument, NULL,         'I'},
            { "priority",        required_argument, NULL,         'p'},
            { 0, 0, 0, 0 }
        };
        int option_char;
        int option_index;

        option_char = getopt_long( argc, argv, "vhirsI:p:",
                                   long_options, &option_index );
        if( -1 == option_char )
            break;

        switch( option_char )
        {
        case 0:
            break;

        case 'v':
            verbosity_level++;
            break;

        case 'h':
            help_flag = 1;
            break;

        case 'i':
            install_flag = 1;
            break;

        case 'r':
            remove_flag = 1;
            break;

        case 'I':
            instance_name = optarg;
            break;

        case 'p':
        {
            DWORD pclass;
            if( strcmpi( optarg, "normal" ) == 0 )
            {
                priority = optarg;
                pclass = NORMAL_PRIORITY_CLASS;
            }
            else if( strcmpi( optarg, "high" ) == 0 )
            {
                priority = optarg;
                pclass = ABOVE_NORMAL_PRIORITY_CLASS;
            }
            else if( strcmpi( optarg, "highest" ) == 0 )
            {
                priority = optarg;
                pclass = HIGH_PRIORITY_CLASS;
            }
            else
            {
                ERR( "Invalid priority %s; must be 'normal', 'high' or 'highest'\n", optarg );
                break;
            }
            SetPriorityClass( GetCurrentProcess(), pclass );
            break;
        }
        case '?':
            /* getopt_long already printed an error message. */
            getopt_failure++;
            break;

        default:
            abort();
        }
    }
    if( getopt_failure )
        return 1;

    /* handle flags in order of priority */
    /* at first, check instance name */
    if( instance_name )
    {
        service_name = g_strconcat( service_name, "_", instance_name, NULL );
        service_display_name = g_strconcat( service_display_name, "_", instance_name, NULL );
        service_stop_event_name = g_strconcat( service_stop_event_name, "_", instance_name, NULL );
    }
    /* check service flag */
    if( service_flag )
    {
        if( VER_PLATFORM_WIN32_NT == vi.dwPlatformId )
        {
            /* run as service under windows NT */
            static SERVICE_TABLE_ENTRY service_table[] = {
                { "", (LPSERVICE_MAIN_FUNCTION) winnt_ServiceMain },
                { NULL, NULL }
            };

            if( !StartServiceCtrlDispatcher( service_table ) )
            {
                ERR( "Cannot start service control dispatcher; error %lu\n", GetLastError() );
                return 1;
            }
            return 0;
        }
        else
        {
            /* run as service under windows 9x */
            FreeConsole();
            return win9x_ServiceMain();
        }
    }

    /* print version */
    if( version_flag )
    {
        printf( "%s %s\n", PACKAGE_NAME, PACKAGE_VERSION );
        return 0;
    }

    /* print help */
    if( help_flag )
    {
        printf( "Usage: syslogd [OPTION]\n" );
        printf( "This is syslog daemon for windows.\n" );
        printf( "\n" );
        printf( "-v, --verbose\tbe verbose; each occurence of this parameter\n"
                "\t\tincreases verbosity\n" );
        printf( "-i, --install\tinstall and start service\n" );
        printf( "-r, --remove\tstop and remove service\n" );
        printf( "-s, --shutdown\tsend shutdown signal to the daemon\n" );
        printf( "-I, --instance\tset instance name in the case of multiple daemons\n" );
        printf( "-p, --priority\tset priority class; value may be 'normal' (default),\n"
                          "\t\t\t'high', or 'highest'\n" );
        printf( "-h, --help\tdisplay this message\n" );
        printf( "--version\tdisplay version information\n" );
        return 0;
    }

    /* install/remove/shutdown */
    if( remove_flag )
    {
        if( install_flag || shutdown_flag )
            ERR( "Remove option has priority over install/shutdown\n" );
        remove_service();
        return 0;
    }
    if( install_flag )
    {
        if( shutdown_flag )
            ERR( "Install option has priority over shutdown\n" );
        install_service( priority );
        return 0;
    }
    if( shutdown_flag )
    {
        shutdown_service( FALSE );
        return 0;
    }

    /* run as ordinary console application */
    return win9x_ServiceMain();
}
