        #include <stdio.h>

        #define NotAVertex (-1)
        typedef int TwoDimArray[ 4 ][ 4 ];

/* START: fig10_53.txt */
        /* Compute All-Shortest Paths */
        /* A[ ] contains the adjacency matrix */
        /* with A[ i ][ i ] presumed to be zero */
        /* D[ ] contains the values of the shortest path */
        /* N is the number of vertices */
        /* A negative cycle exists iff */
        /* D[ i ][ i ] is set to a negative value */
        /* Actual path can be computed using Path[ ] */
        /* All arrays are indexed starting at 0 */
        /* NotAVertex is -1 */

        void
        AllPairs( TwoDimArray A, TwoDimArray D,
                        TwoDimArray Path, int N )
        {
            int i, j, k;

            /* Initialize D and Path */
/* 1*/      for( i = 0; i < N; i++ )
/* 2*/          for( j = 0; j < N; j++ )
                {
/* 3*/              D[ i ][ j ] = A[ i ][ j ];
/* 4*/              Path[ i ][ j ] = NotAVertex;
                }

/* 5*/      for( k = 0; k < N; k++ )
                /* Conider each vertex as an intermediate */
/* 6*/          for( i = 0; i < N; i++ )
/* 7*/              for( j = 0; j < N; j++ )
/* 8*/                  if( D[ i ][ k ] + D[ k ][ j ] < D[ i ][ j ] )
                        {
                            /* Update shortest path */
/* 9*/                      D[ i ][ j ] = D[ i ][ k ] + D[ k ][ j ];
/*10*/                      Path[ i ][ j ] = k;
                        }
        }
/* END */

main( )
{
    TwoDimArray A = { { 0, 2, -2, 2 }, { 1000, 0, -3, 1000 },
                      { 4, 1000, 0, 1000 }, { 1000, -2, 3, 0 } };
    TwoDimArray D, Path;
    int i, j;

    AllPairs( A, D, Path, 4 );
    for( i = 0; i < 4; i++ )
    {
        for( j = 0; j < 4; j++ )
            printf( "%6d ", D[ i ][ j ] );
        printf( "\n" );
    }

    for( i = 0; i < 4; i++ )
    {
        for( j = 0; j < 4; j++ )
            printf( "%6d ", Path[ i ][ j ] );
        printf( "\n" );
    }


    return 0;
}
