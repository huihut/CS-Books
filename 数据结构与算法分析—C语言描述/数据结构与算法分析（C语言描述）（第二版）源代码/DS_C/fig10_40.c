#include <stdio.h>

/* START: fig10_40.txt */
        /* Compute Fibonacci numbers as described in Chapter 1 */

        int
        Fib( int N )
        {
            if( N <= 1 )
                return 1;
            else
                return Fib( N - 1 ) + Fib( N - 2 );
        }
/* END */

/* START: fig10_41.txt */
        int
        Fibonacci( int N )
        {
            int i, Last, NextToLast, Answer;

            if( N <= 1 )
                return 1;

            Last = NextToLast = 1;
            for( i = 2; i <= N; i++ )
            {
                Answer = Last + NextToLast;
                NextToLast = Last;
                Last = Answer;
            }

            return Answer;
        }
/* END */

main( )
{
    printf( "%d\n%d\n", Fib( 7 ), Fibonacci( 7 ) );
    return 0;
}
