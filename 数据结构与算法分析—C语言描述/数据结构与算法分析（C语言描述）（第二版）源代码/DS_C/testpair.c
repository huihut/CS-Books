#include "pairheap.h"
#include <stdio.h>

void
sleep( int x )
{
    int i, j, k, m;

    for( i = 0; i < 10000; i++ )
        for( j = 0; j < 1000; j++ )
            for( k = 0; k < x; k++ )
                m++;
    printf( "Done sleeping!! %d", m );
}

#define MaxSize 500

main( )
{
    PairHeap H;
    Position P[ MaxSize ];
    int i, j;
    int AnItem;

    H = Initialize( );
    for( i=0, j=MaxSize/2; i<MaxSize; i++, j=( j+71)%MaxSize )
        H = Insert( j + MaxSize, H, &P[ j ] );

    printf( "Done inserting\n" );

    for( i = 0, j = MaxSize / 2; i <MaxSize; i++, j=(j+51)%MaxSize )
        H = DecreaseKey( P[ j ], MaxSize, H );

    j = 0;
    while( !IsEmpty( H ) )
    {
        if( ( ( H = DeleteMin( &AnItem, H ) ), AnItem ) != j++ )
            printf( "Error in DeleteMin, %d\n", j );
    }
    printf( "Done...\n" );

    return 0;
}
