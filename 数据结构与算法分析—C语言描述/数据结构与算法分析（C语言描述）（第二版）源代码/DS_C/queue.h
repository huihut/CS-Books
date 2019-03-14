        typedef int ElementType;
/* START: fig3_57.txt */
        #ifndef _Queue_h
        #define _Queue_h

        struct QueueRecord;
        typedef struct QueueRecord *Queue;

        int IsEmpty( Queue Q );
        int IsFull( Queue Q );
        Queue CreateQueue( int MaxElements );
        void DisposeQueue( Queue Q );
        void MakeEmpty( Queue Q );
        void Enqueue( ElementType X, Queue Q );
        ElementType Front( Queue Q );
        void Dequeue( Queue Q );
        ElementType FrontAndDequeue( Queue Q );

        #endif  /* _Queue_h */
/* END */
