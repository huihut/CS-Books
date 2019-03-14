
        typedef int ElementType;

        #ifndef _PairHeap_H
        #define _PairHeap_H

        struct PairNode;
        typedef struct PairNode *PairHeap;
        typedef struct PairNode *Position;

        PairHeap Initialize( void );
        void Destroy( PairHeap H );
        PairHeap MakeEmpty( PairHeap H );
        PairHeap Insert( ElementType Item, PairHeap H, Position *Loc );
        PairHeap DeleteMin( ElementType *MinItem, PairHeap H );
        ElementType FindMin( PairHeap H );
        PairHeap DecreaseKey( Position P,
                              ElementType NewVal, PairHeap H );
        int IsEmpty( PairHeap H );
        int IsFull( PairHeap H );
        #endif
