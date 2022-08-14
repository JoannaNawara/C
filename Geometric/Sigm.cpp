#include "Sigm.h"

Sigm::Sigm( Point p1, Point p2 )
{
	setSegm( p1, p2 );
}
Sigm::Sigm( double x1, double y1, double x2, double y2 )
{
	setPt1( x1, y1 );
	setPt2( x2, y2 );
}
Sigm::Sigm( const Sigm& s )
{
	*this = s;
}

void Sigm::setSegm( double x1, double y1, double x2, double y2 )
{
	setPt1( x1, y1 );
	setPt2( x2, y2 );
}
void Sigm::setSegm( const Point& P1, const Point& P2 )
{
	setPt1( P1 );
	setPt2( P2 );
}
void Sigm::Translate( double vx, double vy )
{
	setPt1( getPt1( *this ).getX() + vx, getPt1( *this ).getY() + vy );
	setPt2( getPt2( *this ).getX() + vx, getPt2( *this ).getY() + vy );
}
void Sigm::Rotate( int Angle )
{
	Point vector( ave( getPt1( *this ).getX(), getPt2( *this ).getX() ), ave( getPt1( *this ).getY(), getPt2( *this ).getY() ) );
	//do punktu 0,0
	setPt1( getPt1( *this ).getX() - vector.getX(), getPt1( *this ).getY() - vector.getY() );
	setPt2( getPt2( *this ).getX() - vector.getX(), getPt2( *this ).getY() - vector.getY() );
	//rotacja
	setPt1( getPt1( *this ).getX() * cos( deg2rad( Angle ) ) - getPt1( *this ).getY() * sin( deg2rad( Angle ) ), getPt1( *this ).getX() * sin( deg2rad( Angle ) ) + getPt1( *this ).getY() * cos( deg2rad( Angle ) ) );
	setPt2( getPt2( *this ).getX() * cos( deg2rad( Angle ) ), getPt2( *this ).getY() * sin( deg2rad( Angle ) ) );
	
	setPt1( getPt1( *this ).getX() + vector.getX(), getPt1( *this ).getY() + vector.getY() );
	setPt2( getPt2( *this ).getX() + vector.getX(), getPt2( *this ).getY() + vector.getY() );
}
double Sigm::Length()
{
	return sqrt( sqr( getPt2( *this ).getX() - getPt1( *this ).getX() ) + sqr( getPt2( *this ).getY() - getPt1( *this ).getY() ) );
}

istream& operator >> ( istream& in, const Sigm& s )
{
	char c;
	int temp;
	in >> temp >> c;
	s.getPt1( s ).setX( temp );
	in >> temp >> c;
	s.getPt1( s ).setY( temp );
	in >> temp >> c;
	s.getPt2( s ).setX( temp );
	in >> temp >> c;
	s.getPt2( s ).setY( temp );
	return in;
}
ostream& operator << ( ostream& out, const Sigm& s )
{
	out << s.getPt1( s );
	out << ", " << s.getPt2(s);
	return out;
}

double Sigm::sqr( double x )
{
	return x * x;
}
double Sigm::deg2rad( int Angle )
{
	return  2 * PI * Angle  / 360;
}
double Sigm::ave( double x1, double x2 )
{
	return ( x1 + x2 ) / 2;
}