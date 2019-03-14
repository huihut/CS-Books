        typedef int ElementType;
        #define SpaceSize 100

/* START: fig3_28.txt */
        #ifndef _Cursor_H
        #define _Cursor_H

        typedef int PtrToNode;
        typedef PtrToNode List;
        typedef PtrToNode Position;

        void InitializeCursorSpace( void );

        List MakeEmpty( List L );
        int IsEmpty( const List L );
        int IsLast( const Position P, const List L );
        Position Find( ElementType X, const List L );
        void Delete( ElementType X, List L );
        Position FindPrevious( ElementType X, const List L );
        void Insert( ElementType X, List L, Position P );
        void DeleteList( List L );
        Position Header( const List L );
        Position First( const List L );
        Position Advance( const Position P );
        ElementType Retrieve( const Position P );

        #endif    /* _Cursor_H */

/* END */
