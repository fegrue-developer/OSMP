#include "../OSMPLib/osmplib.h"

int main(int argc, char *argv[])
{
    int rv, size, rank;
    char buffer[message_max_size];
    rv = OSMP_Init( &argc, &argv );
    rv = OSMP_Size( &size );
    rv = OSMP_Rank( &rank );



    if( size < 2 ) {
/* Fehlerbehandlung */ }
    if( rank == 1 )
    {
        char src[message_max_size];
        src[0] = 20;
        memcpy(buffer, src , sizeof(src));
        rv = OSMP_Bcast( buffer, sizeof(src), OSMP_BYTE, true, &rank, NULL );
    }
    else
    {
        int source, len;
        rv = OSMP_Bcast( buffer, sizeof(src), OSMP_BYTE, false, &source, &len);

    }

    return 0;
}