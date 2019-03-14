#include "dsl.h"
#include <stdlib.h>
#include "fatal.h"


/* START: fig12_23.txt */
        struct SkipNode
        {
            ElementType Element;
            SkipList    Right;
            SkipList    Down;
        };

        static Position Bottom = NULL;  /* Needs initialization */
        static Position Tail   = NULL;  /* Needs initialization */

        /* Initialization procedure */

        SkipList
        Initialize( void )
        {
            SkipList L;

            if( Bottom == NULL )
            {
                Bottom = malloc( sizeof( struct SkipNode ) );
                if( Bottom == NULL )
                    FatalError( "Out of space!!!" );
                Bottom->Right = Bottom->Down = Bottom;

                Tail = malloc( sizeof( struct SkipNode ) );
                if( Tail == NULL )
                    FatalError( "Out of space!!!" );
                Tail->Element = Infinity;
                Tail->Right = Tail;
            }

            /* Create the header node */
            L = malloc( sizeof( struct SkipNode ) );
            if( L == NULL )
                FatalError( "Out of space!!!" );
            L->Element = Infinity;
            L->Right = Tail;
            L->Down = Bottom;

            return L;
        }
/* END */

        void
        Output( ElementType Element )
        {
            printf( "%d\n", Element );
        }

        /* Memory reclamation is left as an exercise */
        /* Hint: Delete from top level to bottom level */
        SkipList
        MakeEmpty( SkipList L )
        {
            L->Right = Tail;
            L->Down = Bottom;
            return L;
        }

/* START: fig12_24.txt */
        /* Return Position of node containing Item, */
        /* or Bottom if not found */

        Position
        Find( ElementType Item, SkipList L )
        {
            Position Current = L;

            Bottom->Element = Item;
            while( Item != Current->Element )
                if( Item < Current->Element )
                    Current = Current->Down;
                else
                    Current = Current->Right;

            return Current;
        }
/* END */

        Position
        FindMin( SkipList L )
        {
            Position Current = L;

            while( Current->Down != Bottom )
                Current = Current->Down;

            return Current;
        }

        Position
        FindMax( SkipList L )
        {
            Position Current = L;

            while( Current->Right->Right != Tail ||
                   Current->Down != Bottom )
            {
                if( Current->Right->Right != Tail )
                    Current = Current->Right;
                else
                    Current = Current->Down;
            }

            return Current;
        }

/* START: fig12_25.txt */
        SkipList
        Insert( ElementType Item, SkipList L )
        {
            Position Current = L;
            Position NewNode;

            Bottom->Element = Item;
            while( Current != Bottom )
            {
                while( Item > Current->Element )
                    Current = Current->Right;

                /* If gap size is 3 or at bottom level */
                /* and must insert, then promote middle element */
                if( Current->Element >
                          Current->Down->Right->Right->Element )
                {
                    NewNode = malloc( sizeof( struct SkipNode ) );
                    if( NewNode == NULL )
                        FatalError( "Out of space!!!" );
                    NewNode->Right = Current->Right;
                    NewNode->Down = Current->Down->Right->Right;
                    Current->Right = NewNode;
                    NewNode->Element = Current->Element;
                    Current->Element = Current->Down->Right->Element;
                }
                else
                    Current = Current->Down;
            }

            /* Raise height of DSL if necessary */
            if( L->Right != Tail )
            {
                NewNode = malloc( sizeof( struct SkipNode ) );
                if( NewNode == NULL )
                    FatalError( "Out of space!!!" );
                NewNode->Down = L;
                NewNode->Right = Tail;
                NewNode->Element = Infinity;
                L = NewNode;
            }

            return L;
        }
/* END */

        SkipList
        Remove( ElementType Item, SkipList L )
        {
            printf( "Remove is unimplemented\n" );
            if( Item )
                return L;
            return L;
        }

        ElementType
        Retrieve( Position P )
        {
            return P->Element;
        }

