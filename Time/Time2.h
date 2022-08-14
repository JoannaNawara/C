#pragma once
#include <iostream>

using namespace std;

class Time2
{
public:
	Time2();
	Time2( int H, int M, int S );
	Time2( const Time2& t );
	Time2& operator = ( const Time2& t );

public:
	void setHour( int H );
	void setMin( int M );
	void setSec( int S );
	void setTime( int H, int M, int S );

	int getHour() const;
	int getMin() const;
	int getSec() const;

	friend ostream& operator << ( ostream& out, const Time2& t ); //ostream to jest klasa
	friend istream& operator >> ( istream& in, const Time2& t );

private:
	int m_nHour;
	int m_nMin;
	int m_nSec;

};

void Time2::setHour( int H )
{
	m_nHour = H;
}

void Time2::setMin( int M )
{
	m_nMin = M;
}

void Time2::setSec( int S )
{
	m_nSec = S;
}

void Time2::setTime( int H, int M, int S )
{
	setHour( H );
	setMin( M );
	setSec( S );
}

inline int Time2::getHour() const
{
	return m_nHour;
}

inline int Time2::getMin() const
{
	return m_nMin;
}

inline int Time2::getSec() const
{
	return m_nSec;
}