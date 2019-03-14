#include "binomial.h"
#include <stdio.h>

#define MaxSize (12000)

main( )
{
    BinQueue H;
    int i, j;
    ElementType AnItem;

    H = Initialize( );
    for( i=0, j=MaxSize/2; i<MaxSize; i++, j=( j+71)%MaxSize )
    {
 /*     printf( "Inserting %d\n", j );
 */     H = Insert( j, H );
    }
 #if 1
    j = 0;
    while( !IsEmpty( H ) )
    {
 /*     printf( "DeleteMin\n" );
        H = DeleteMin( &AnItem, H );
  */    if( DeleteMin( H ) != j++ )
            printf( "Error in DeleteMin, %d\n", j );
    }
    if( j != MaxSize )
        printf( "Error in counting\n" );
    #endif
    printf( "Done...\n" );
    return 0;
}
