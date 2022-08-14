
#include "TimeDate.h"


TimeDate::TimeDate() : Time2(), Date()
{
}
TimeDate::TimeDate( int h, int m, int s, int D, int M, int Y ) : Time2( h, m, s ), Date( D, M, Y )
{
}
TimeDate::TimeDate( const TimeDate& td ) : Time2( ( const Time2& ) td ), Date( ( const Date& ) td )
{	
}

TimeDate::TimeDate( const Time2& t, const Date& d )
{
	setTimeDate( t.getHour(), t.getMin(), t.getSec(), d.getDay(), d.getMonth(), d.getYear() );
}

TimeDate& TimeDate::operator = ( const TimeDate& td )
{
	( Time2& )*this = ( const Time2& )td; //dwie mozliwosci 
	( Date& )*this = ( const Date& )td;
	return *this;
}
void TimeDate::setTimeDate( int h, int m, int s, int D, int M, int Y )
{
	setTime( h, m, s );
	setDate( D, M, Y );
}
istream& operator >> ( istream& in, TimeDate& td )
{
	in >> ( Time2& ) td;
	in >> ( Date& ) td;
	return in;
}
ostream& operator << ( ostream& out, TimeDate& td )
{
	cout << ( Time2& ) td;
	cout << "  ";
	cout << ( Date& ) td;
	return out;
}

