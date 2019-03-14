#include <stdio.h>

/* START: fig1_2.txt */
        int
        F( int X )
        {
/* 1*/      if( X == 0 )
/* 2*/          return 0;
            else
/* 3*/          return 2 * F( X - 1 ) + X * X;
        }
/* END */

main( )
{
    printf( "F(5) = %d\n", F( 5 ) );
    return 0;
}
