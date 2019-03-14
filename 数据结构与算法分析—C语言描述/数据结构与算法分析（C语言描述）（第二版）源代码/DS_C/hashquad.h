/* Interface for quadratic probing hash table */
typedef int ElementType;

/* START: fig5_14.txt */
        #ifndef _HashQuad_H
        #define _HashQuad_H

        typedef unsigned int Index;
        typedef Index Position;

        struct HashTbl;
        typedef struct HashTbl *HashTable;

        HashTable InitializeTable( int TableSize );
        void DestroyTable( HashTable H );
        Position Find( ElementType Key, HashTable H );
        void Insert( ElementType Key, HashTable H );
        ElementType Retrieve( Position P, HashTable H );
        HashTable Rehash( HashTable H );
        /* Routines such as Delete are MakeEmpty are omitted */

        #endif  /* _HashQuad_H */

/* END */
