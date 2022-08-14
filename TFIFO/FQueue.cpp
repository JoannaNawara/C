#include "FQueue.h"
#include "stdlib.h"

void  QFDel( QFIFO* q );

// kreowanie dynamiczne kolejki (struktury i tablicy)                                
QFIFO* QFCreate( int nSize )  // nSize  - rozmiar tablicy
{
	if( nSize < 1 ) return NULL;
	QFIFO* TFifo = ( QFIFO* )calloc( 1, sizeof( QFIFO* ) );
	if( !TFifo ) return NULL;

	TFifo->pFQItems = ( QINFO** )calloc( nSize, sizeof( QINFO* ) );
	if( !TFifo->pFQItems ) return NULL;

	TFifo->nMaxElem = nSize;
	return TFifo;
}
// zwraca 1 gdy kolejka pusta, w przeciwnym wypadku 0
int QFEmpty( QFIFO* q )
{
	return !q || !q->nNoElem;
}

// wstawienie elementu do kolejki
int QFEnqueue( QFIFO* q, QINFO* pItem )
{
	if( !q ) return 0;
	if( q->nMaxElem <= q->nNoElem ) return 0;
	q->pFQItems[q->nTail] = pItem;
	q->nTail = ( q->nTail + 1 ) % q->nMaxElem;
	q->nNoElem++; //zmiana liczby elementow
	return 1;
}

// usuniecie elementu z kolejki i zwrocenie wskaznika do tego elementu
QINFO* QFDequeue( QFIFO* q )
{
	if( QFEmpty( q ) ) return NULL;
	QINFO* Info = q->pFQItems[q->nHead];
	QFDel( q );
	return Info;
}

// czyszczenie kolejki, kolejke mozna uzywac
void QFClear( QFIFO* q, void( __cdecl* freeItem )( const void* ) )
{
	if( !q )
	{
		perror( "\nERROR: Queue does not exist" );
		return;
	}
	while( !QFEmpty( q ) )
	{
		freeItem( QFDequeue( q ) );
	}
	q->nHead = q->nTail = 0;
}

// czyszczenie kolejki i usuniecie wszystkich struktur danych, wyzerowanie wskaznika
void QFRemove( QFIFO** q, void( __cdecl* freeItem )( const void* ) )
{
	if( !q || !*q )
	{
		perror( "\nERROR: Queue does not exist" );
		return;
	}
	QFClear( *q, freeItem );
	free( ( *q )->pFQItems );
	free( *q );
	*q = NULL;
}

void  QFDel( QFIFO* q )
{
	if( QFEmpty( q ) )
	{
		perror( "\nERROR: Queue does not exist or is empty" );
		return;
	}
	q->pFQItems[q->nHead] = NULL; //  - wstawia NULL do pozycji tablicy, skad pobierany jest element
	q->nHead = ( q->nHead + 1 ) % q->nMaxElem;
	q->nNoElem--;
}
