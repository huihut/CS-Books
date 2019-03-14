        /* Bad random number generator */

        #include <stdio.h>

/* START: fig10_54.txt */
        static unsigned long Seed = 1;

        #define A 48271L
        #define M 2147483647L

        double
        Random( void )
        {
            Seed = ( A * Seed ) % M;
            return ( double ) Seed / M;
        }

        void
        Initialize( unsigned long InitVal )
        {
            Seed = InitVal;
        }
/* END */

main( )
{
    int i;

    for( i = 0; i < 20; i++ )
        printf( "%6f\n", Random( ) );
    return 0;
}