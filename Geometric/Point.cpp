#include "Point.h"

Point::Point( double x, double y )
{
	setPoint( x, y );
}
Point::Point( const Point& pt )
{
	*this = pt;
}
void Point::setPoint( const Point& pt )
{
	m_x = pt.getX();
	m_y = pt.getY();
}
void Point::Rotate( double fangle )
{
	setPoint( this->getX() * cos( fangle ) - this->getY() * sin( fangle ), 
		this->getX() * sin( fangle ) + this->getY() * cos( fangle ) );
}
void Point::Translate( double vx, double vy )
{
	setPoint( this->getX() + vx, this->getY() + vy );
}

istream& operator >> ( istream& in, Point& pt ) 
{
	double temp;
	cin >> temp; pt.setX( temp );
	cin >> temp; pt.setY( temp );
	return in;
}
ostream& operator << ( ostream& out, const Point& pt )
{
	out << "( " << pt.getX() << ", " << pt.getY() << " )";
	return out;
}