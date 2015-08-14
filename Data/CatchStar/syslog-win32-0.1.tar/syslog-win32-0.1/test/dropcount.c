#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char* argv[] )
{
    FILE *fd;
    char buffer[ 256 ];
    int msg_index = 1, drop_count = 0;

    if( argc < 2 )
    {
        puts( "required filename" );
        return 1;
    }

    fd = fopen( argv[1], "r" );
    if( !fd )
    {
        perror( "fopen" );
        return 1;
    }
    while( fgets( buffer, sizeof(buffer), fd ) )
    {
        char *p;
        int i;

        p = buffer + strlen( buffer );
        while( *p != ' ' ) p--;
        i = strtoul( p, NULL, 10 );
        while( msg_index < i )
        {
            msg_index++;
            drop_count++;
        }
        msg_index++;
    }
    printf( "dropped %d message(s)\n", drop_count );
    fclose( fd );
    return 0;
}
