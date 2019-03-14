
        typedef long ElementType;
        #define Infinity (30000L)

        #ifndef _BinHeap_H
        #define _BinHeap_H

        #define MaxTrees (14)   /* Stores 2^14 -1 items */
        #define Capacity (16383)

        struct BinNode;
        typedef struct BinNode *BinTree;
        struct Collection;
        typedef struct Collection *BinQueue;

        BinQueue Initialize( void );
        void Destroy( BinQueue H );
        BinQueue MakeEmpty( BinQueue H );
        BinQueue Insert( ElementType Item, BinQueue H );
        ElementType DeleteMin( BinQueue H );
        BinQueue Merge( BinQueue H1, BinQueue H2 );
        ElementType FindMin( BinQueue H );
        int IsEmpty( BinQueue H );
        int IsFull( BinQueue H );
        #endif
/* END */
