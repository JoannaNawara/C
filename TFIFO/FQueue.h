#pragma once
#include "global.h"

typedef struct
{
	QINFO** pFQItems; // dynamiczna tablica wskaznikow do informacji
	int nHead; // indeks pierwszego elementu w kolejce
	int nTail; // indeks pierwszego wolnego miejsca w kolejce(po ostatnim zajetym)
	int	nNoElem; //ilosc elementow kolejki
	int nMaxElem; //rozmiar kolejki(rozmiar tablicy pFQItems)
}QFIFO;

// kreowanie dynamiczne kolejki (struktury i tablicy)                                
QFIFO* QFCreate( int nSize );  // nSize  - rozmiar tablicy

// zwraca 1 gdy kolejka pusta, w przeciwnym wypadku 0
int QFEmpty( QFIFO* q );

// wstawienie elementu do kolejki
int QFEnqueue( QFIFO* q, QINFO* pItem );

// usuniecie elementu z kolejki i zwrocenie wskaznika do tego elementu
QINFO* QFDequeue( QFIFO* q );

// czyszczenie kolejki, kolejke mozna uzywac
void QFClear( QFIFO* q, void( __cdecl* freeItem )( const void* ) );

// czyszczenie kolejki i usuniecie wszystkich struktur danych, wyzerowanie wskaznika
void QFRemove( QFIFO** q, void( __cdecl* freeItem )( const void* ) );
