#include <stdio.h>

#define IsEven( N ) ( ( N ) % 2 == 0 )

/* START: fig2_11.txt */
        long int
        Pow( long int X, unsigned int N )
        {
/* 1*/      if( N == 0 )
/* 2*/          return 1;
/* 3*/      if( N == 1 )
/* 4*/          return X;
/* 5*/      if( IsEven( N ) )
/* 6*/          return Pow( X * X, N / 2 );
            else
/* 7*/          return Pow( X * X, N / 2 ) * X;
        }
/* END */

main( )
{
    printf( "2^21 = %ld\n", Pow( 2, 21 ) );
    return 0;
}
