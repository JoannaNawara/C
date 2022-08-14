
#include "Time2.h"

Time2::Time2()
{
	setTime( 0, 0, 0 );
}
Time2::Time2( int H, int M, int S )
{
	setTime( H, M, S );
}

Time2::Time2( const Time2& t )
{
	*this = t;
}

ostream& operator << ( ostream& out, const Time2& t )
{
	cout << t.getHour() << ':';
	cout << t.getMin() << ':';
	cout << t.getSec();
	return out;
}

istream& operator >> ( istream& in, Time2& t )
{
	char c;
	int temp;
	in >> temp >> c; // c separator daty
	t.setHour( temp );

	in >> temp >> c; // c separator daty
	t.setMin( temp );

	in >> temp >> c; // c separator daty
	t.setSec( temp );

	return in;
}

Time2& Time2::operator = ( const Time2& t )
{
	setTime( t.getHour(), t.getMin(), t.getSec() );
	return *this;
}