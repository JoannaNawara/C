#pragma once

typedef struct  // typ dla info
{
	char* sName;
	int   nKey;
} QInfo;

#define QINFO QInfo

void freeMem( const void* );

