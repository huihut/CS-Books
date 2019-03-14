#include <stdio.h>

/* START: fig2_10.txt */
        unsigned int
        Gcd( unsigned int M, unsigned int N )
        {
            unsigned int Rem;

/* 1*/      while( N > 0 )
            {
/* 2*/          Rem = M % N;
/* 3*/          M = N;
/* 4*/          N = Rem;
            }
/* 5*/      return M;
        }
/* END */

main( )
{
    printf( "Gcd( 45, 35 ) = %d\n", Gcd( 45, 35 ) );
    printf( "Gcd( 1989, 1590 ) = %d\n", Gcd( 1989, 1590 ) );
    return 0;
}
