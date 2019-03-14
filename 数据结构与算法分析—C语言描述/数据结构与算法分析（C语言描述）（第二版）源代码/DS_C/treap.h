        #include <stdlib.h>
        #include "fatal.h"

        typedef int ElementType;
        #define Infinity 32767

        #ifndef _Treap_H
        #define _Treap_H

        struct TreapNode;
        typedef struct TreapNode *Position;
        typedef struct TreapNode *Treap;

        Treap MakeEmpty( Treap T );
        Position Find( ElementType X, Treap T );
        Position FindMin( Treap T );
        Position FindMax( Treap T );
        Treap Initialize( void );
        Treap Insert( ElementType X, Treap T );
        Treap Remove( ElementType X, Treap T );
        ElementType Retrieve( Position P );


        extern Position NullNode;

        #endif  /* _Treap_H */

/* END */
