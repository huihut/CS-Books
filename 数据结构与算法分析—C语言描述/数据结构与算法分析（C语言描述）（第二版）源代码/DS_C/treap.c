#include "treap.h"
#include <stdlib.h>
#include "fatal.h"


        struct TreapNode
        {
            ElementType Element;
            Treap       Left;
            Treap       Right;
            int         Priority;
        };

        Position NullNode = NULL;  /* Needs initialization */

/* START: fig12_39.txt */
        Treap
        Initialize( void )
        {
            if( NullNode == NULL )
            {
                NullNode = malloc( sizeof( struct TreapNode ) );
                if( NullNode == NULL )
                    FatalError( "Out of space!!!" );
                NullNode->Left = NullNode->Right = NullNode;
                NullNode->Priority = Infinity;
            }
            return NullNode;
        }
/* END */

        /* Use ANSI C random number generator for simplicity */

        int
        Random( void )
        {
            return rand( ) -  1;
        }

        Treap
        MakeEmpty( Treap T )
        {
            if( T != NullNode )
            {
                MakeEmpty( T->Left );
                MakeEmpty( T->Right );
                free( T );
            }
            return NullNode;
        }

        void
        PrintTree( Treap T )
        {
            if( T != NullNode )
            {
                PrintTree( T->Left );
                printf( "%d ", T->Element );
                PrintTree( T->Right );
            }
        }

        Position
        Find( ElementType X, Treap T )
        {
            if( T == NullNode )
                return NullNode;
            if( X < T->Element )
                return Find( X, T->Left );
            else
            if( X > T->Element )
                return Find( X, T->Right );
            else
                return T;
        }

        Position
        FindMin( Treap T )
        {
            if( T == NullNode )
                return NullNode;
            else
            if( T->Left == NullNode )
                return T;
            else
                return FindMin( T->Left );
        }

        Position
        FindMax( Treap T )
        {
            if( T != NullNode )
                while( T->Right != NullNode )
                    T = T->Right;

            return T;
        }

        /* This function can be called only if K2 has a left child */
        /* Perform a rotate between a node (K2) and its left child */
        /* Update heights, then return new root */

        static Position
        SingleRotateWithLeft( Position K2 )
        {
            Position K1;

            K1 = K2->Left;
            K2->Left = K1->Right;
            K1->Right = K2;

            return K1;  /* New root */
        }

        /* This function can be called only if K1 has a right child */
        /* Perform a rotate between a node (K1) and its right child */
        /* Update heights, then return new root */

        static Position
        SingleRotateWithRight( Position K1 )
        {
            Position K2;

            K2 = K1->Right;
            K1->Right = K2->Left;
            K2->Left = K1;

            return K2;  /* New root */
        }

/* START: fig12_40.txt */
        Treap
        Insert( ElementType Item, Treap T )
        {
            if( T == NullNode )
            {
                /* Create and return a one-node tree */
                T = malloc( sizeof( struct TreapNode ) );
                if( T == NULL )
                    FatalError( "Out of space!!!" );
                else
                {
                    T->Element = Item; T->Priority = Random( );
                    T->Left = T->Right = NullNode;
                }
            }
            else
            if( Item < T->Element )
            {
                T->Left = Insert( Item, T->Left );
                if( T->Left->Priority < T->Priority )
                    T = SingleRotateWithLeft( T );
            }
            else
            if( Item > T->Element )
            {
                T->Right = Insert( Item, T->Right );
                if( T->Right->Priority < T->Priority )
                    T = SingleRotateWithRight( T );
            }

            /* Otherwise it's a duplicate; do nothing */

            return T;
        }
/* END */

/* START: fig12_41.txt */
        Treap
        Remove( ElementType Item, Treap T )
        {
            if( T != NullNode )
            {
                if( Item < T->Element )
                    T->Left = Remove( Item, T->Left );
                else
                if( Item > T->Element )
                    T->Right = Remove( Item, T->Right );
                else
                {
                    /* Match found */
                    if( T->Left->Priority < T->Right->Priority )
                        T = SingleRotateWithLeft( T );
                    else
                        T = SingleRotateWithRight( T );

                    if( T != NullNode )    /* Continue on down */
                        T = Remove( Item, T );
                    else
                    {
                        /* At a leaf */
                        free( T->Left );
                        T->Left = NullNode;
                    }
                }
            }
            return T;
        }
/* END */

        ElementType
        Retrieve( Position P )
        {
            return P->Element;
        }
