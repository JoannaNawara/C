#pragma once
#include <iostream>
using namespace std;

class  Date
{
public:
	Date();
	Date( int nDay, int nMonth, int nYear );
	Date( const Date& d ); // konstruktor kopiuj¹cy ma wywo³aæ konstruktor podstawienia

	Date& operator = ( const Date& d );

public:
	void setDay( int nDay );
	void setMonth( int nMonth );
	void setYear( int nYear );
	void setDate( int nDay, int nMonth, int nYear );

	int getDay() const;
	int getMonth() const;
	int getYear() const;

	friend ostream& operator << ( ostream& out, const Date& d ); //ostream to jest klasa
	friend istream& operator >> ( istream& in, Date& d );

private:
	int m_nDay;
	int m_nMonth;
	int m_nYear;

};

inline void Date::setDay( int nDay )
{
	if( 1 <= nDay <= 31 )
		m_nDay = nDay;
}

inline void Date::setMonth( int nMonth )
{
	if( 1 <= nMonth <= 12 )
		m_nMonth = nMonth;
}

inline void Date::setYear( int nYear )
{
	m_nYear = nYear;
}

inline void Date::setDate( int nDay, int nMonth, int nYear )
{
	setDay( nDay );
	setMonth( nMonth );
	setYear( nYear );
}

inline int Date::getDay() const
{
	return m_nDay;
}

inline int Date::getMonth() const
{
	return m_nMonth;
}

inline int Date::getYear() const
{
	return m_nYear;
}
