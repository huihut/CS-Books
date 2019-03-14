#include "splay.h"
#include <stdio.h>
#define NumItems 500

main( )
{
    SplayTree T;
    SplayTree P;
    int i;
    int j = 0;

    T = Initialize( );
    T = MakeEmpty( T );
    for( i = 0; i < NumItems; i++, j = ( j + 7 ) % NumItems )
        T = Insert( j, T );
  
    for( j = 0; j < 2; j++ )
        for( i = 0; i < NumItems; i++ )
        {
            T = Find( i, T );
            if( Retrieve( T ) != i )
                printf( "Error1 at %d\n", i );
        }

    printf( "Entering remove\n" );

    for( i = 0; i < NumItems; i += 2 )
        T = Remove( i, T );

    for( i = 1; i < NumItems; i += 2 )
    {
        T = Find( i, T );
        if( Retrieve( T ) != i )
            printf( "Error2 at %d\n", i );
    }

    for( i = 0; i < NumItems; i += 2 )
    {
        T = Find( i, T );
        if( Retrieve( T ) == i )
            printf( "Error3 at %d\n", i );
    }

    printf( "Min is %d\n", Retrieve( T = FindMin( T ) ) );
    printf( "Max is %d\n", Retrieve( T = FindMax( T ) ) );

    return 0;
}
