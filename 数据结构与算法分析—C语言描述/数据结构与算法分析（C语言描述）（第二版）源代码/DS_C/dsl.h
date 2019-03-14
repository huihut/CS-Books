        #include <stdlib.h>
        #include "fatal.h"

        typedef int ElementType;
        #define Infinity (10000)

        #ifndef _SkipList_H
        #define _SkipList_H

        struct SkipNode;
        typedef struct SkipNode *Position;
        typedef struct SkipNode *SkipList;

        SkipList MakeEmpty( SkipList L );
        Position Find( ElementType X, SkipList L );
        Position FindMin( SkipList L );
        Position FindMax( SkipList L );
        SkipList Initialize( void );
        SkipList Insert( ElementType X, SkipList L );
        SkipList Remove( ElementType X, SkipList L );
        ElementType Retrieve( Position P );

        #endif  /* _SkipList_H */

/* END */
