/******************************************************************************
* FILE: osmp_SendRecv.c
* DESCRIPTION:
* OSMP program with a simple pair of blocking OSMP_Send/OSMP_Recv calls
*
* LAST MODIFICATION: Felix Grüning, March 21, 2023
******************************************************************************/
#include <stdio.h>
#include "../OSMPLib/osmplib.h"

int main(int argc, char *argv[]) {
    int rv, source, rank, count, size;
    OSMP_Request myrequest;
    int bufin[1],bufout[1], len;
    rv = OSMP_Init(&argc, &argv);
    rv = OSMP_Size(&size);
    rv = OSMP_Rank(&rank);

    if (size != 2) {
        printf("size != 2\n");
        exit(-1);
    }
    if (rank == 0) { // OSMP process 0 
       
            bufin[0] = 1;
            rv = OSMP_Send(bufin, 1, OSMP_INT, 1);
            
            //rv = OSMP_Barrier();
    

    } else { // OSMP process 1
        printf("ISEND %ld", myrequest.thread);
        rv = OSMP_CreateRequest( &myrequest );
        rv = OSMP_Irecv( bufout, size, OSMP_INT, &source, &len, &myrequest );
        // // do something important…
        // // check if operation is completed and wait if not
        printf("Main THREAD NUMB %lu\n", (unsigned long)myrequest.thread);

        rv = OSMP_Wait(myrequest);
        printf("OSMP process %d received %d byte from %d [%d] \n", rank, len, source, bufout);
        
       // rv = OSMP_Barrier();
        rv = OSMP_RemoveRequest( &myrequest );
    }
    rv = OSMP_Finalize();
    return 0;
}