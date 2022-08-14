#include <stdio.h>
#include "global.h"
#include "FQueue.h"
#include <stdlib.h>
#include <cstdlib>
#include <cstring>

QINFO* CreateInfo( char* sName, int nKey );
void PrintFIFO( QFIFO* pFifo );

int main()
{
    QFIFO* Fifo = QFCreate();
    if( !Fifo )
    {
        perror( "\nERROR_1" );
        return 1;
    }

    char a[32] = { 0 };

    for( int i = 0; i < 4; i++ )
    {
        QINFO* NewInfo = CreateInfo( _itoa( i + 1, a, 2 ), i + 1 );
        if( NewInfo == NULL )
        {
            perror( "\nERROR_2" );
            return 2;
        }
        if( !QFEnqueue( Fifo, NewInfo ) )
        {
            perror( "\nERROR_3" );
            return 3;
        }
    }

    for( int i = 0; i < 3; i++ )
    {
        QINFO* Info = QFDequeue( Fifo );
        if( Info == NULL )
            break;
        printf( "\nInfo%d: %d \n", i + 1, Info->nKey );
    }


    for ( int i = 0; i < 2; i++ )
    {
        QINFO* NewInfo = CreateInfo( _itoa( i + 1, a, 2 ), i + 1 );
        if( NewInfo == NULL )
        {
            perror( "\nERROR_2" );
            return 2;
        }
        if( !QFEnqueue( Fifo, NewInfo ) )
        {
            perror( "\nERROR_3" );
            return 3;
        }
    }

    QFClear( Fifo, freeMem );

    for( int i = 0; i < 3; i++ )
    {
        QINFO* NewInfo = CreateInfo( _itoa( i + 1, a, 2 ), i + 2 );
        if( NewInfo == NULL )
        {
            perror( "\nERROR_2" );
            return 2;
        }
        if( !QFEnqueue( Fifo, NewInfo ) )
        {
            perror( "\nERROR_3" );
            return 3;
        }
    }

    QINFO* Info = QFDequeue( Fifo );
    printf( "\nInfo%d: %d \n", 1, Info->nKey );

    QFRemove( &Fifo, freeMem );
}

void freeMem( const void* pFifo )
{

    free( ( ( QINFO* )pFifo )->sName );
    free( ( ( QINFO* )pFifo ) );
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

void PrintFIFO( QFIFO* pFifo )
{
    while( pFifo->pHead->pInfo )
    {
        printf( "%d ", pFifo->pHead->pInfo->nKey );
        pFifo->pHead = pFifo->pHead->pNext;
    }
    printf( "\n\n" );
}
