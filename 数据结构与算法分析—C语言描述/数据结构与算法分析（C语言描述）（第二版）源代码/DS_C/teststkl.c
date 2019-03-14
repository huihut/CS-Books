#include <stdio.h>
#include "stackli.h"

main( )
{
    Stack S;
    int i;

    S = CreateStack( );
    for( i = 0; i < 10; i++ )
        Push( i, S );

    while( !IsEmpty( S ) )
    {
        printf( "%d\n", Top( S ) );
        Pop( S );
    }

    DisposeStack( S );
    return 0;
}
