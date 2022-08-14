#pragma once
#include <iostream>
using namespace std;

class Point
{
public:
    Point( double x = 0, double y = 0 );
    Point( const Point& pt );

    inline void setX( double x );
    inline void setY( double y );
    inline void setPoint( double x, double y );
    void setPoint( const Point& pt );
    inline double getX() const;
    inline double getY() const;

    void Rotate( double fangle ); //kat w radianach
    void Translate( double vx, double vy ); //przesuniecie o wektor[vx, vy]

    friend istream& operator >> ( istream& in, Point& pt );
    friend ostream& operator << ( ostream& out, const Point& pt );

private:
    double m_x;
    double m_y;
};

void Point::setX( double x ) { m_x = x; }
void Point::setY( double y ) { m_y = y; }
void Point::setPoint( double x, double y ) { setX( x ); setY( y ); }
double Point::getX() const { return m_x; }
double Point::getY() const { return m_y; }

