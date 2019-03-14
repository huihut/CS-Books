#include "leftheap.h"
#include <stdio.h>

#define MaxSize 5000

main( )
{
    PriorityQueue H;
    int i, j;

    H = Initialize( );
    for( i=0, j=MaxSize/2; i<MaxSize; i++, j=( j+17)%MaxSize )
        Insert( j, H );

    j = 0;
    while( !IsEmpty( H ) )
        if( FindMin( H ) != j++ )
            printf( "Error in DeleteMin, %d\n", j );
        else
            H = DeleteMin1( H );
    printf( "Done...\n" );
    return 0;
}
