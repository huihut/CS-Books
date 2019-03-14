        #include <stdio.h>

typedef double Matrix[ 2 ][ 2 ];

/* START: fig10_38.txt */
        /* Standard matrix multiplication */
        /* Arrays start at 0 */

        void
        MatrixMultiply( Matrix A, Matrix B, Matrix C, int N )
        {
            int i, j, k;

            for( i = 0; i < N; i++ )  /* Initialization */
                for( j = 0; j < N; j++ )
                    C[ i ][ j ] = 0.0;

            for( i = 0; i < N; i++ )
                for( j = 0; j < N; j++ )
                    for( k = 0; k < N; k++ )
                        C[ i ][ j ] += A[ i ][ k ] * B[ k ][ j ];
         }
/* END */

main( )
{
    Matrix A = { { 1, 2 }, { 3, 4 } };
    Matrix C;

    MatrixMultiply( A, A, C, 2 );
    printf( "%6.2f %6.2f\n%6.2f %6.2f\n", C[ 0 ][ 0 ], C[ 0 ][ 1 ],
          C[ 1 ][ 0 ], C[ 1 ][ 1 ] );
    return 0;
}
