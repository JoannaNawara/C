#pragma once
#include <iostream>
using namespace std;
#include "Time2.h"
#include "Date.h"



class TimeDate : public Time2, Date
{
public:
	TimeDate();
	TimeDate( int h, int m, int s, int D, int M, int Y );
	TimeDate( const Time2& t, const Date& d );
	TimeDate& operator = ( const TimeDate& td );
	void setTimeDate( int h, int m, int s, int D, int M, int Y );
	friend istream& operator >> ( istream& in, TimeDate& td );
	friend ostream& operator << ( ostream& out, TimeDate& td );

};
