#pragma once
#include <iostream>
#include "Point.h"

#define PI 3.1415926535897932

class Sigm
{
public:
    Sigm( Point p1=0, Point p2=0);
    Sigm( double x1, double y1, double x2, double y2 );
    Sigm( const Sigm& s );

    inline Point getPt1( const Sigm& s ) const { return m_Pt1; }
    inline Point getPt2( const Sigm& s ) const { return m_Pt2; }
    inline void setPt1( const Point& P ) { m_Pt1 = P; }
    inline void setPt2( const Point& P ) { m_Pt2 = P; }
    inline void setPt1( double x, double y ) { m_Pt1.setPoint( x, y ); }
    inline void setPt2( double x, double y ) { m_Pt2.setPoint( x, y ); }
    void setSegm( double x1, double y1, double x2, double y2 );
    void setSegm( const Point& P1, const Point& P2 );
    void Translate( double vx, double vy );
    void Rotate( int Angle );
    double Length();

    friend istream& operator >> ( istream& in, const Sigm& s );
    friend ostream& operator << ( ostream& out, const Sigm& s );


private:
    Point m_Pt2;
    Point m_Pt1;

private:
    double sqr( double x );
    double deg2rad( int Angle );
    double ave( double x1, double x2 );
};

