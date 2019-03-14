#include <stdio.h>

/* START: fig10_43.txt */
        double
        Eval( int N )
        {
            int i;
            double Sum;

            if( N == 0 )
                return 1.0;
            else
            {
                Sum = 0.0;
                for( i = 0; i < N; i++ )
                    Sum += Eval( i );
                return 2.0 * Sum / N + N;
            }
        }
/* END */

main( )
{
    printf( "%f\n", Eval( 10 ) );
    return 0;
}
