#include <stdio.h>

/* Define one of CubicAlgorithm, QuadraticAlgorithm, NlogNAlgorithm,
 * or LinearAlgorithm to get one algorithm compiled */

#define NlogNAlgorithm

#ifdef CubicAlgorithm

/* START: fig2_5.txt */
        int
        MaxSubsequenceSum( const int A[ ], int N )
        {
            int ThisSum, MaxSum, i, j, k;

/* 1*/      MaxSum = 0;
/* 2*/      for( i = 0; i < N; i++ )
/* 3*/          for( j = i; j < N; j++ )
                {
/* 4*/              ThisSum = 0;
/* 5*/              for( k = i; k <= j; k++ )
/* 6*/                  ThisSum += A[ k ];

/* 7*/              if( ThisSum > MaxSum )
/* 8*/                  MaxSum = ThisSum;
                }
/* 9*/      return MaxSum;
        }
/* END */

#endif


#ifdef QuadraticAlgorithm

/* START: fig2_6.txt */
        int
        MaxSubsequenceSum( const int A[ ], int N )
        {
            int ThisSum, MaxSum, i, j;

/* 1*/      MaxSum = 0;
/* 2*/      for( i = 0; i < N; i++ )
            {
/* 3*/          ThisSum = 0;
/* 4*/          for( j = i; j < N; j++ )
                {
/* 5*/              ThisSum += A[ j ];

/* 6*/              if( ThisSum > MaxSum )
/* 7*/                  MaxSum = ThisSum;
                }
            }
/* 8*/      return MaxSum;
        }
/* END */



#endif



#ifdef NlogNAlgorithm

        static int
        Max3( int A, int B, int C )
        {
            return A > B ? A > C ? A : C : B > C ? B : C;
        }

/* START: fig2_7.txt */
        static int
        MaxSubSum( const int A[ ], int Left, int Right )
        {
            int MaxLeftSum, MaxRightSum;
            int MaxLeftBorderSum, MaxRightBorderSum;
            int LeftBorderSum, RightBorderSum;
            int Center, i;

/* 1*/      if( Left == Right )  /* Base case */
/* 2*/          if( A[ Left ] > 0 )
/* 3*/              return A[ Left ];
                else
/* 4*/              return 0;

/* 5*/      Center = ( Left + Right ) / 2;
/* 6*/      MaxLeftSum = MaxSubSum( A, Left, Center );
/* 7*/      MaxRightSum = MaxSubSum( A, Center + 1, Right );

/* 8*/      MaxLeftBorderSum = 0; LeftBorderSum = 0;
/* 9*/      for( i = Center; i >= Left; i-- )
            {
/*10*/          LeftBorderSum += A[ i ];
/*11*/          if( LeftBorderSum > MaxLeftBorderSum )
/*12*/              MaxLeftBorderSum = LeftBorderSum;
            }

/*13*/      MaxRightBorderSum = 0; RightBorderSum = 0;
/*14*/      for( i = Center + 1; i <= Right; i++ )
            {
/*15*/          RightBorderSum += A[ i ];
/*16*/          if( RightBorderSum > MaxRightBorderSum )
/*17*/              MaxRightBorderSum = RightBorderSum;
            }

/*18*/      return Max3( MaxLeftSum, MaxRightSum,
/*19*/                          MaxLeftBorderSum + MaxRightBorderSum );
        }

        int
        MaxSubsequenceSum( const int A[ ], int N )
        {
            return MaxSubSum( A, 0, N - 1 );
        }
/* END */


#endif


#ifdef LinearAlgorithm
/* START: fig2_8.txt */
        int
        MaxSubsequenceSum( const int A[ ], int N )
        {
            int ThisSum, MaxSum, j;

/* 1*/      ThisSum = MaxSum = 0;
/* 2*/      for( j = 0; j < N; j++ )
            {
/* 3*/          ThisSum += A[ j ];

/* 4*/          if( ThisSum > MaxSum )
/* 5*/              MaxSum = ThisSum;
/* 6*/          else if( ThisSum < 0 )
/* 7*/              ThisSum = 0;
            }
/* 8*/      return MaxSum;
        }
/* END */


#endif

main( )
{
    static int A[ ] = { 4, -3, 5, -2, -1, 2, 6, -2 };

    printf( "Maxsum = %d\n",
            MaxSubsequenceSum( A, sizeof( A ) / sizeof( A[ 0 ] ) ) );
    return 0;
}
