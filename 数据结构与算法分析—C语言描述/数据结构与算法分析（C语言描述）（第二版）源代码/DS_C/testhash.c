#define SepChain    /* Define the appropriate hash algorithm */

#ifdef SepChain
    #include "hashsep.h"
#endif

#ifdef QuadProb
    #include "hashquad.h"
#endif


#include <stdio.h>

#define NumItems 400

main( )
{
    HashTable H;
    Position P;
    int i;
    int j = 0;
    int CurrentSize;

    H = InitializeTable( CurrentSize = 13 );

    for( i = 0; i < NumItems; i++, j += 71 )
    {
    #ifdef QuadProb
        if( i > CurrentSize / 2 )
        {
            H = Rehash( H );
            printf( "Rehashing...\n" );
            CurrentSize *= 2;
        }
    #endif
        Insert( j, H );
    }

    for( i = 0, j = 0; i < NumItems; i++, j += 71 )
    #ifdef SepChain
        if( ( P = Find( j, H ) ) == NULL || Retrieve( P ) != j )
    #endif
    #ifdef QuadProb
        if( Retrieve( ( P = Find( j, H ) ), H ) != j )
    #endif
            printf( "Error at %d\n", j );

    printf( "End of program.\n" );
    return 0;
}
