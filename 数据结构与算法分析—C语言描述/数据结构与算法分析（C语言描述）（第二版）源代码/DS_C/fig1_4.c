#include <stdio.h>

#define PrintDigit( Ch )      ( putchar( ( Ch ) + '0' ) )

/* START: fig1_4.txt */
        void
        PrintOut( unsigned int N )  /* Print nonnegative N */
        {
            if( N >= 10 )
                PrintOut( N / 10 );
            PrintDigit( N % 10 );
        }
/* END */

main( )
{
    PrintOut( 1369 );
    putchar( '\n' );
    return 0;
}
