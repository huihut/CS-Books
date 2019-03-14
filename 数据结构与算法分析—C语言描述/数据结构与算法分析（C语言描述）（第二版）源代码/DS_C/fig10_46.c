        #include <stdio.h>
        #include <limits.h>

        typedef long int TwoDimArray[ 5 ][ 5 ];
        #define Infinity INT_MAX

/* START: fig10_46.txt */
        /* Compute optimal ordering of matrix multiplication */
        /* C contains number of columns for each of the N matrices */
        /* C[ 0 ] is the number of rows in matrix 1 */
        /* Minimum number of multiplications is left in M[ 1 ][ N ] */
        /* Actual ordering is computed via */
        /* another procedure using LastChange */
        /* M and LastChange are indexed starting at 1, instead of 0 */
        /* Note: Entries below main diagonals of M and LastChange */
        /* are meaningless and uninitialized */

        void
        OptMatrix( const long C[ ], int N,
                   TwoDimArray M, TwoDimArray LastChange )
        {
            int i, k, Left, Right;
            long ThisM;

            for( Left = 1; Left <= N; Left++ )
                M[ Left ][ Left ] = 0;
            for( k = 1; k < N; k++ )   /* k is Right - Left */
                for( Left = 1; Left <= N - k; Left++ )
                {
                    /* For each position */
                    Right = Left + k;
                    M[ Left ][ Right ] = Infinity;
                    for( i = Left; i < Right; i++ )
                    {
                        ThisM = M[ Left ][ i ] + M[ i + 1 ][ Right ]
                                + C[ Left - 1 ] * C[ i ] * C[ Right ];
                        if( ThisM < M[ Left ][ Right ] ) /* Update min */
                        {
                            M[ Left ][ Right ] = ThisM;
                            LastChange[ Left ][ Right ] = i;
                        }
                    }
                }
        }
/* END */

main( )
{
    long C[ ] = { 50, 10, 40, 30, 5 };
    long M[ 5 ][ 5 ], LastChange[ 5 ][ 5 ];
    int i, j;

    OptMatrix( C, 4, M, LastChange );
    for( i = 1; i <= 4; i++ )
    {
        for( j = 1; j <= 4; j++ )
            printf( "%14d", M[ i ][ j ] );
        printf( "\n" );
    }
    for( i = 1; i <= 4; i++ )
    {
        for( j = 1; j <= 4; j++ )
            printf( "%14d", LastChange[ i ][ j ] );
        printf( "\n" );
    }
    return 0;
}

