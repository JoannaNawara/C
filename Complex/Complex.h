#pragma once
#include <iostream>
using namespace std;

class Complex
{
public:
	Complex( double re = 0, double im = 0 );
	Complex( const Complex& z );

public:
	double get_Re() const; 
	double get_Im() const;

	void setRe( double re );
	void setIm( double im );
	void setComplex( double re, double im );

	double mod( Complex& z );
	const Complex Con( const Complex& z );

	friend const Complex operator + ( const Complex& z1, const Complex& z2 );
	friend const Complex operator - ( const Complex& z1, const Complex& z2 );
	friend const Complex operator * ( const Complex& z1, const Complex& z2 );
	friend const Complex operator / ( const Complex& z1, const Complex& z2 );
	friend const Complex operator - ( const Complex& z); //minus unarny

	Complex& operator += ( const Complex& z );
	Complex& operator -= ( const Complex& z );
	Complex& operator *= ( const Complex& z );
	Complex& operator /= ( const Complex& z );

	Complex& operator = ( const Complex& z ); //operator podstawienia
	friend bool operator == ( const Complex& z1, const Complex& z2 );
	friend bool operator != ( const Complex& z1, const Complex& z2 );

	operator double();
	operator int();

	friend istream& operator >> ( istream& in, Complex& z );
	friend ostream& operator << ( ostream& out, const Complex& z );

private:
	double m_re;
	double m_im;

private:
	double sqr() const;
};

class CanonComplex : public Complex
{
public:
	CanonComplex( const Complex& z );
	friend ostream& operator << ( ostream& out, const CanonComplex& z );
};

inline double Complex::get_Re() const { return m_re; } 
inline double Complex::get_Im() const { return m_im; }
inline void Complex::setRe( double re ) { m_re = re; }
inline void Complex::setIm( double im ) { m_im = im; }
inline void Complex::setComplex( double re, double im ) { setRe( re ); setIm( im ); }

inline Complex::operator double() { return get_Re(); }
inline Complex::operator int() { return ( int )get_Re(); }

