#include "FQueue.h"
#include <stdlib.h>
#include <stdio.h>

void QFDel( QFIFO* q );
QFIFO* QFCreate()
{
	QFIFO* pFifo = ( QFIFO* )calloc( 1, sizeof( QFIFO* ) );
	if( !pFifo ) return 0;

	FQItem* pNew = ( FQItem* )calloc( 1, sizeof( FQItem* ) );
	if( !pNew ) return 0;

	pFifo->pHead = pFifo->pTail = pNew;

	return pFifo;
}

int QFEmpty( QFIFO* q )
{
	return !q || !( q->pHead->pNext );
}

int QFEnqueue( QFIFO* q, QINFO* pItem ) //wstawianie elementu do kolejki
{
	if( !q ) return 0; // kolejka nie istnieje
	FQItem* pNew = ( FQItem* )calloc( 1, sizeof( FQItem* ) );
	if( !pNew ) return 0;

	pNew->pInfo = pItem;

	q->pTail->pNext = pNew;
	q->pTail = pNew;

	return 1;
}

// usuniecie elementu z kolejki i zwrocenie wskaznika do tego elementu (NULL - kolejka pusta)
QINFO* QFDequeue( QFIFO* q )  // ma wywolac QFDel() 
{
	if( QFEmpty( q ) ) return NULL;
	QINFO* ptr = q->pHead->pNext->pInfo;
	QFDel( q );
	return ptr;
}

// czyszczenie kolejki, kolejke mozna uzywac dalej
void  QFClear( QFIFO* q, void( __cdecl* freeMem )( const void* ) )
{
	if( !q )
	{
		printf( "\nERROR: Queue doesn't exist" );
		return;
	}

	while( !QFEmpty( q ) )
		freeMem( QFDequeue( q ) );
}

// czyszczenie kolejki i usuniecie wszystkich struktur danych, wyzerowanie kolejki
void QFRemove( QFIFO** q, void( __cdecl* freeMem )( const void* ) )
{
	if( !q || !*q )
	{
		perror( "\nERROR: Queue does not exist" );
		return;
	}
	QFClear( *q, freeMem ); //czyszczenie kolejki
	free( ( *q )->pHead );
	free( *q );
	*q = NULL;
}

// funkcja prywatna modulu  - tylko usuniecie elemenu z listy (nie info) 
void QFDel( QFIFO* q )
{
	if( QFEmpty( q ) )
	{
		perror( "\nError: no elements to delete or queue does not exist" );
		return;
	}
	FQItem* ptr = q->pHead->pNext; // wskaznik na element do usuniecia
	q->pHead->pNext = ptr->pNext; //przesuniecie na nastepny element
	free( ptr );
	if( QFEmpty( q ) ) q->pTail = q->pHead;
}