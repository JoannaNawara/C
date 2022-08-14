#pragma once
#include "global.h"

typedef struct tagFQItem
{
	QINFO* pInfo; // wskaznik na informacje
	tagFQItem* pNext; // wskaznik na nastepny element
}FQItem;


typedef struct
{
	FQItem* pHead;
	FQItem* pTail;
} QFIFO;

// kreowanie dynamiczne kolejki                                  
QFIFO* QFCreate();

// zwraca 1 gdy kolejka pusta, w przeciwnym wypadku 0
int QFEmpty( QFIFO* q );

// wstawienie elementu do kolejki i zwrocenie 1 gdy OK i 0 gdy blad alokacji
int QFEnqueue( QFIFO* q, QINFO* pItem );

// usuniecie elementu z kolejki i zwrocenie wskaznika do tego elementu (NULL - kolejka pusta)
QINFO* QFDequeue( QFIFO* q );  // ma wywolac QFDel() 

// czyszczenie kolejki, kolejke mozna uzywac dalej
void  QFClear( QFIFO* q, void( __cdecl* freeMem )( const void* ) );

// czyszczenie kolejki i usuniecie wszystkich struktur danych, wyzerowanie kolejki
void  QFRemove( QFIFO** q, void( __cdecl* freeMem )( const void* ) );