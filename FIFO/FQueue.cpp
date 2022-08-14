#include "FQueue.h"
#include <stdlib.h>

void QFDel( QFIFO* q );
QFIFO* QFCreate()
{
	return ( QFIFO* )calloc( 1, sizeof( QFIFO* ) );
}

int QFEmpty( QFIFO* q )
{
	return !q || !( q->pHead );
}

int QFEnqueue( QFIFO* q, QINFO* pItem ) //wstawianie elementu do kolejki
{
	if( !q ) return 0;
	FQItem* pNew = ( FQItem* )calloc( 1, sizeof( FQItem* ) );
	if( !pNew ) return 0;

	pNew->pInfo = pItem;

	if( QFEmpty( q ) ) q->pHead = pNew;
	else
		q->pTail->pNext = pNew;

	q->pTail = pNew;

	return 1;
}

// usuniecie elementu z kolejki i zwrocenie wskaznika do tego elementu (NULL - kolejka pusta)
QINFO* QFDequeue( QFIFO* q )  // ma wywolac QFDel() 
{
	if( QFEmpty( q ) ) return NULL;
	QINFO* Info = q->pHead->pInfo; // dostep do info
	QFDel( q );
	return Info;
}

// czyszczenie kolejki, kolejke mozna uzywac dalej
void  QFClear( QFIFO* q, void( __cdecl* freeMem )( const void* ) )
{
	if( !q )
	{
		perror( "\nERROR: Queue does not exist" );
		return;
	}
	while( !QFEmpty( q ) )
		freeMem( QFDequeue( q ) );
}

// czyszczenie kolejki i usuniecie wszystkich struktur danych, wyzerowanie kolejki
void  QFRemove( QFIFO** q, void( __cdecl* freeMem )( const void* ) )
{
	if( !q || !*q )
	{
		perror( "\nERROR_2: Queue does not exist" );
		return;
	}

	QFClear( *q, freeMem ); //czyszczenie kolejki
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

	FQItem* ptr = q->pHead;
	q->pHead = ptr->pNext;
	free( ptr );
	if( QFEmpty( q ) ) free( q->pTail );
}