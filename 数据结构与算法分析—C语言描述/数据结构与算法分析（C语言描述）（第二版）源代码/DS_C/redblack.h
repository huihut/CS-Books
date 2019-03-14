        #include <stdlib.h>
        #include "fatal.h"

        typedef int ElementType;
        #define NegInfinity (-10000)

        #ifndef _RedBlack_H
        #define _RedBlack_H

        struct RedBlackNode;
        typedef struct RedBlackNode *Position;
        typedef struct RedBlackNode *RedBlackTree;

        RedBlackTree MakeEmpty( RedBlackTree T );
        Position Find( ElementType X, RedBlackTree T );
        Position FindMin( RedBlackTree T );
        Position FindMax( RedBlackTree T );
        RedBlackTree Initialize( void );
        RedBlackTree Insert( ElementType X, RedBlackTree T );
        RedBlackTree Remove( ElementType X, RedBlackTree T );
        ElementType Retrieve( Position P );
        void PrintTree( RedBlackTree T );

        #endif  /* _RedBlack_H */

/* END */
