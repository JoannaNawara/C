#include "Complex.h"


Complex::Complex( double re, double im )
{
	setComplex( re, im );
}
Complex::Complex( const Complex& z )
{
	*this = z;
}

double Complex::mod( Complex& z )
{
	return sqrt( sqr() );
}

const Complex Complex::Con( const Complex& z )
{
	return Complex( z.get_Re(), -z.get_Im() );
}

const Complex operator + ( const Complex& z1, const Complex& z2 )
{
	Complex res( z1 );
	return res += z2;
	//return res;
}
const Complex operator - ( const Complex& z1, const Complex& z2 )
{
	return z1 + ( -z2 );
	//Complex res( z1 );
	//return res -= z2;
	//return res;  //return z1 + (-z2);
}
const Complex operator * ( const Complex& z1, const Complex& z2 )
{
	Complex res( z1 );
	return res *= z2;
	//return res;
}
const Complex operator / ( const Complex& z1, const Complex& z2 )
{
	Complex res( z1 );
	return res /= z2;
	//return res;
}

const Complex operator - ( const Complex& z ) //minus unarny
{
	Complex res( z );
	res.setComplex( -z.get_Re(), -z.get_Im() );
	return res;
}

Complex& Complex::operator += ( const Complex& z )
{
	setComplex( this->get_Re() + z.get_Re(), this->get_Im() + z.get_Im() );
	return *this;
}
Complex& Complex::operator -= ( const Complex& z )
{
	setComplex( this->get_Re() - z.get_Re(), this->get_Im() - z.get_Im() );
	return *this;
}
Complex& Complex::operator *= ( const Complex& z )
{
	setComplex( ( this->get_Re() * z.get_Re() - this->get_Im() * z.get_Im() ), ( this->get_Re() * z.get_Im() + this->get_Im() * z.get_Re() ) );
	return *this;
}
Complex& Complex::operator /= ( const Complex& z )
{
	double temp = z.sqr();
	if( temp < 1e-12 )
	{
		cout << "ERROR: not allowed to divide by 0\n";
		temp = 1;
	}
	double licz = ( this->get_Re() * z.get_Re() + this->get_Im() * z.get_Im() ) / temp ;
	double mian = ( this->get_Im() * z.get_Re() - this->get_Re() * z.get_Im() ) / temp ;
	
	setComplex( licz, mian );
	return *this;
}

Complex& Complex::operator = ( const Complex& z )
{
	setComplex( z.get_Re(), z.get_Im() );
	return *this;
}
bool operator == ( const Complex& z1, const Complex& z2 )
{
	return ( z1.get_Re() == z2.get_Re() && z1.get_Im() == z2.get_Im() );
}
bool operator != ( const Complex& z1, const Complex& z2)
{
	return !(z1 == z2);
}
istream& operator >> ( istream& in, Complex& z )
{
	double temp;
	in >> temp;
	z.setRe( temp );
	in >> temp;
	z.setIm( temp );
	return in;
}
ostream& operator << ( ostream& out, const Complex& z )
{
	out << "( " << z.get_Re() << ", " << z.get_Im() << " )";
	return out;
}

double Complex::sqr() const
{
	return get_Re()* get_Re() + get_Im() * get_Im();
}

CanonComplex::CanonComplex( const Complex& z ) : Complex( z ) {}

ostream& operator << ( ostream& out, const CanonComplex& z )
{
	out << z.get_Re() << " + " << z.get_Im() << "i";
	return out;
}