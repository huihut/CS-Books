#include <stdio.h>
#include <stdlib.h>
#include "fatal.h"


/* START: fig10_45.txt */
        double
        Eval( int N )
        {
            int i, j;
            double Sum, Answer;
            double *C;

            C = malloc( sizeof( double ) * ( N + 1 ) );
            if( C == NULL )
                FatalError( "Out of space!!!" );

            C[ 0 ] = 1.0;
            for( i = 1; i <= N; i++ )
            {
                Sum = 0.0;
                for( j = 0; j < i; j++ )
                    Sum += C[ j ];
                C[ i ] = 2.0 * Sum / i + i;
            }

            Answer = C[ N ];
            free( C );

            return Answer;
        }
/* END */

main( )
{
    printf( "%f\n", Eval( 10 ) );
    return 0;
}
