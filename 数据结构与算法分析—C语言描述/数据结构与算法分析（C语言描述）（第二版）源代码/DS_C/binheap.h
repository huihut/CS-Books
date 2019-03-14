
        typedef int ElementType;

/* START: fig6_4.txt */
        #ifndef _BinHeap_H
        #define _BinHeap_H

        struct HeapStruct;
        typedef struct HeapStruct *PriorityQueue;

        PriorityQueue Initialize( int MaxElements );
        void Destroy( PriorityQueue H );
        void MakeEmpty( PriorityQueue H );
        void Insert( ElementType X, PriorityQueue H );
        ElementType DeleteMin( PriorityQueue H );
        ElementType FindMin( PriorityQueue H );
        int IsEmpty( PriorityQueue H );
        int IsFull( PriorityQueue H );

        #endif

/* END */
