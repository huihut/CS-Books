        #include <stdio.h>
        #include <stdlib.h>

        typedef long HugeInt;

        HugeInt
        RandInt( HugeInt Low, HugeInt High )
        {
            return rand( ) % ( High - Low + 1 ) + Low;
        }


/* START: fig10_62.txt */
        /* If Witness does not return 1, N is definitely composite */
        /* Do this by computing ( A ^ i ) mod N and looking for */
        /* non-trivial square roots of 1 along the way */
        /* We are assuming very large numbers, so this is pseudocode */

        HugeInt
        Witness( HugeInt A, HugeInt i, HugeInt N )
        {
            HugeInt X, Y;

            if( i == 0 )
                return 1;

            X = Witness( A, i / 2, N );
            if( X == 0 )  /* If N is recursively composite, stop */
                return 0;

            /* N is not prime if we find a non-trivial root of 1 */
            Y = ( X * X ) % N;
            if( Y == 1 && X != 1 && X != N - 1 )
                return 0;

            if( i % 2 != 0 )
                Y = ( A * Y ) % N;

            return Y;
        }

        /* IsPrime: Test if N >= 3 is prime using one value of A */
        /* Repeat this procedure as many times as needed for */
        /* desired error rate */

        int
        IsPrime( HugeInt N )
        {
            return Witness( RandInt( 2, N - 2 ), N - 1, N ) == 1;
        }
/* END */

main( )
{   int i;

    for( i = 101; i < 200; i += 2 )
        if( IsPrime( i ) )
            printf( "%d is prime\n", i );

    return 0;
}
