
#include "Date.h"


Date::Date()
{
	setDate( 1, 1, 1970 );
}

Date::Date( int nDay, int nMonth, int nYear )
{
	setDate( nDay, nMonth, nYear );
}

Date::Date( const Date& d )
{
	*this = d;
}



ostream& operator << ( ostream& out, const Date& d )
{
	cout << d.getDay() << '/';
	cout << d.getDay() << '/';
	cout << d.getYear();
	return out;
}

istream& operator >> ( istream& in, Date& d )
{
	char c;
	int temp;
	in >> temp >> c; // c separator daty
	d.setDay( temp );

	in >> temp >> c; // c separator daty
	d.setMonth( temp );

	in >> temp >> c; // c separator daty
	d.setMonth( temp );

	return in;
}

Date& Date::operator = ( const Date& d )
{
	setDate( d.getDay(), d.getMonth(), d.getYear() );
	return *this;
}
