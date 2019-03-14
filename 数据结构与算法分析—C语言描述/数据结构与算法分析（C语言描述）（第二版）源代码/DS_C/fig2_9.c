#include <stdio.h>

typedef int ElementType;
#define NotFound (-1)

/* START: fig2_9.txt */
        int
        BinarySearch( const ElementType A[ ], ElementType X, int N )
        {
            int Low, Mid, High;

/* 1*/      Low = 0; High = N - 1;
/* 2*/      while( Low <= High )
            {
/* 3*/          Mid = ( Low + High ) / 2;
/* 4*/          if( A[ Mid ] < X )
/* 5*/              Low = Mid + 1;
                else
/* 6*/          if( A[ Mid ] > X )
/* 7*/              High = Mid - 1;
                else
/* 8*/              return Mid;  /* Found */
            }
/* 9*/      return NotFound;     /* NotFound is defined as -1 */
        }
/* END */

main( )
{
    static int A[ ] = { 1, 3, 5, 7, 9, 13, 15 };
    const int SizeofA = sizeof( A ) / sizeof( A[ 0 ] );
    int i;

    for( i = 0; i < 20; i++ )
        printf( "BinarySearch of %d returns %d\n",
                 i, BinarySearch( A, i, SizeofA ) );
    return 0;
}
