        #include "pairheap.h"
        #include "fatal.h"
        #include <stdlib.h>

        struct PairNode
        {
            ElementType Element;
            Position    LeftChild;
            Position    NextSibling;
            Position    Prev;
        };

        #define MaxSiblings 1000

        Position CompareAndLink( Position First, Position Second );
        PairHeap CombineSiblings( Position FirstSibling );


        PairHeap
        Initialize( void )
        {
            return NULL;
        }

        PairHeap
        MakeEmpty( PairHeap H )
        {
            if( H != NULL )
            {
                MakeEmpty( H->LeftChild );
                MakeEmpty( H->NextSibling );
                free( H );
            }
            return NULL;
        }

/* START: fig12_54.txt */
        /* Insert Item into pairing heap H */
        /* Return resulting pairing heap */
        /* A pointer to the newly allocated node */
        /* is passed back by reference and accessed as *Loc */

        PairHeap
        Insert( ElementType Item, PairHeap H, Position *Loc )
        {
            Position NewNode;

            NewNode = malloc( sizeof( struct PairNode ) );
            if( NewNode == NULL )
                FatalError( "Out of space!!!" );
            NewNode->Element = Item;
            NewNode->LeftChild = NewNode->NextSibling = NULL;
            NewNode->Prev = NULL;

            *Loc = NewNode;
            if( H == NULL )
                return NewNode;
            else
                return CompareAndLink( H, NewNode );
        }


        /* Lower item in Position P by Delta */

        PairHeap
        DecreaseKey( Position P, ElementType Delta, PairHeap H )
        {
            if( Delta < 0 )
                Error( "DecreaseKey called with negative Delta" );

            P->Element -= Delta;
            if( P == H )
                return H;

            if( P->NextSibling != NULL )
                P->NextSibling->Prev = P->Prev;
            if( P->Prev->LeftChild == P )
                P->Prev->LeftChild = P->NextSibling;
            else
                P->Prev->NextSibling = P->NextSibling;

            P->NextSibling = NULL;
            return CompareAndLink( H, P );
        }
/* END */


/* START: fig12_55.txt */
        PairHeap
        DeleteMin( ElementType *MinItem, PairHeap H )
        {
            Position NewRoot = NULL;

            if( IsEmpty( H ) )
                Error( "Pairing heap is empty!" );
            else
            {
                *MinItem = H->Element;
                if( H->LeftChild != NULL )
                    NewRoot = CombineSiblings( H->LeftChild );
                free( H );
            }
            return NewRoot;
        }
/* END */

/* START: fig12_53.txt */
        /* This is the basic operation to maintain order */
        /* Links First and Second together to satisfy heap order */
        /* Returns the resulting tree */
        /* First is assumed NOT NULL */
        /* First->NextSibling  MUST be NULL on entry */

        Position
        CompareAndLink( Position First, Position Second )
        {
            if( Second == NULL )
                return First;
            else
            if( First->Element <= Second->Element )
            {
                /* Attach Second as the leftmost child of First */
                Second->Prev = First;
                First->NextSibling = Second->NextSibling;
                if( First->NextSibling != NULL )
                    First->NextSibling->Prev = First;
                Second->NextSibling = First->LeftChild;
                if( Second->NextSibling != NULL )
                    Second->NextSibling->Prev = Second;
                First->LeftChild = Second;
                return First;
            }
            else
            {
                /* Attach First as the leftmost child of Second */
                Second->Prev = First->Prev;
                First->Prev = Second;
                First->NextSibling = Second->LeftChild;
                if( First->NextSibling != NULL )
                    First->NextSibling->Prev = First;
                Second->LeftChild = First;
                return Second;
            }
        }
/* END */

/* START: fig12_56.txt */
        /* Assumes FirstSibling is NOT NULL */

        PairHeap
        CombineSiblings( Position FirstSibling )
        {
            static Position TreeArray[ MaxSiblings ];
            int i, j, NumSiblings;

            /* If only one tree, return it */
            if( FirstSibling->NextSibling == NULL )
                return FirstSibling;

            /* Place each subtree in TreeArray */
            for( NumSiblings = 0; FirstSibling != NULL; NumSiblings++ )
            {
                TreeArray[ NumSiblings ] = FirstSibling;
                FirstSibling->Prev->NextSibling = NULL; /* Break links */
                FirstSibling = FirstSibling->NextSibling;
            }
            TreeArray[ NumSiblings ] = NULL;

            /* Combine the subtrees two at a time, */
            /* going left to right */
            for( i = 0; i + 1 < NumSiblings; i += 2 )
                TreeArray[ i ] = CompareAndLink(
                        TreeArray[ i ], TreeArray[ i + 1 ] );

            /* j has the result of the last CompareAndLink */
            /* If an odd number of trees, get the last one */
            j = i - 2;
            if( j == NumSiblings - 3 )
                TreeArray[ j ] = CompareAndLink(
                        TreeArray[ j ], TreeArray[ j + 2 ] );

            /* Now go right to left, merging last tree with */
            /* next to last. The result becomes the new last */
            for( ; j >= 2; j -= 2 )
                TreeArray[ j - 2 ] = CompareAndLink(
                        TreeArray[ j - 2 ],  TreeArray[ j ] );

            return TreeArray[ 0 ];
        }
/* END */

        ElementType
        FindMin( PairHeap H )
        {
            if( !IsEmpty( H ) )
                return H->Element;
            Error( "Priority Queue is Empty" );
            return 0;
        }

        int
        IsEmpty( PairHeap H )
        {
            return H == NULL;
        }

        int
        IsFull( PairHeap H )
        {
            return 0;   /* Never full */
        }

        void
        Destroy( PairHeap H )
        {
            MakeEmpty( H );
        }

