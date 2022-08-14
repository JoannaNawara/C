#include <stdio.h>
#include "global.h"
#include "FQueue.h"
#include <stdlib.h>
#include <cstring>

QINFO* CreateInfo( char* Name, int nKey );
void PrintQueue( QFIFO* q );

int main()
{
    QFIFO* TFifo = QFCreate( 4 );
    if( !TFifo )
    {
        perror( "\nERROR_1: Memory allocation error" );
        return 1;
    }
    char a[32] = { 0 };

    for( int i = 0; i < 4; i++ ) // dodaje 4 elementy 
    {
        QINFO* NewInfo = CreateInfo( _itoa( i + 1, a, 10 ), i + 1 );
        if( NewInfo == NULL )
        {
            perror( "\nERROR_2: Cannot create a new item" );
            return 2;
        }
        if( !QFEnqueue( TFifo, NewInfo ) )
        {
            perror( "\nERROR_3: Cannot insert a new item" );
            return 3;
        }
    }

    PrintQueue( TFifo );

    QINFO* NewInfo = CreateInfo( _itoa( 5, a, 10 ), 5 ); //element wyzwalajacy blad
    if( NewInfo == NULL )
    {
        perror( "\nERROR_4: Cannot create a new item" );
        return 4;
    }
    if( !QFEnqueue( TFifo, NewInfo ) )
    {
        perror( "\nERROR_5: Cannot insert a new item" );
        freeItem( NewInfo );
    }

    for( int i = 0; i < 3; i++ ) //usuwam trzy elementy
    {
        QINFO* Info = QFDequeue( TFifo );
        if( Info == NULL )
            break;
        printf( "\nInfo%d: %d \n", i + 1, Info->nKey );
    }

    PrintQueue( TFifo );

    for( int i = 0; i < 2; i++ ) // dodaje dwa elementy
    {
        QINFO* NewInfo = CreateInfo( _itoa( i + 1, a, 10 ), i + 1 );
        if( NewInfo == NULL )
        {
            perror( "\nERROR_6" );
            return 6;
        }
        if( !QFEnqueue( TFifo, NewInfo ) )
        {
            perror( "\nERROR_7" );
            return 7;
        }
    }

    PrintQueue( TFifo );

    QFClear( TFifo, freeItem ); // czyszczenie listy

    for( int i = 0; i < 3; i++ ) // wstawiam 3 elementy
    {
        QINFO* NewInfo = CreateInfo( _itoa( i + 1, a, 2 ), i + 2 );
        if( NewInfo == NULL )
        {
            perror( "\nERROR_8" );
            return 8;
        }
        if( !QFEnqueue( TFifo, NewInfo ) )
        {
            perror( "\nERROR_9" );
            return 9;
        }
    }

    QINFO* Info = QFDequeue( TFifo ); //usuwam element
    printf( "\nInfo%d: %d \n", 1, Info->nKey );

    QFRemove( &TFifo, freeItem ); // usuwam kolejke
}

void freeItem( const void* pItem )
{
    free( ( QINFO* )pItem );
    ( ( QINFO* )pItem )->nKey = NULL;
    ( ( QINFO* )pItem )->sName = NULL;
}

QINFO* CreateInfo( char* Name, int nKey )
{
    QINFO* ptr = ( QINFO* )calloc( 1, sizeof( QINFO ) );
    if( !ptr ) return NULL;

    ptr->sName = ( char* )calloc( strlen( Name ) + 1, sizeof( char ) );
    if( !ptr->sName ) return NULL;

    strcpy( ptr->sName, Name );
    ptr->nKey = nKey;
    return ptr;
}

void PrintQueue( QFIFO* q )
{
    int index = q->nHead;
    for( int i = 0; i < q->nNoElem; i++ )
    {
        printf( "%d ", q->pFQItems[index]->nKey );
        if( index < q->nMaxElem - 1 )
            index += 1;
        else
            index = 0;
    }
    printf( "\n\n" );
}