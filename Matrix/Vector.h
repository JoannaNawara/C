#pragma once
#include <iostream>
#include <memory.h>

using namespace std;

//doda klase do obslugi wyjatkow
#define VERROR 0x00
#define INDEX_OUT_OF_RANGE 0x01
#define ALLOCATION_ERROR 0x02
#define INCOMPATIBLE_SIZES 0x04

typedef unsigned short int USSHORT;

class VecException {
public:
	VecException( USSHORT errCode );
	const char* getReason();

private:
	int m_ErrCode;
};

class Vector
{
public:
	Vector( int nDim = 2, int nElem = 0 );
	Vector( const Vector& v );
	virtual ~Vector();
	
	int getDim() const;
	operator int* ( ) const; //operator rzutowania

	//operators
public:
	Vector& operator = ( const Vector& v );//v1 = v2

	//unary minus
	friend const Vector& operator - ( const Vector& v );

	//addiction
	friend const Vector operator + ( const Vector& v1, const Vector& v2 );
	friend const Vector operator + ( const Vector& v, int x );
	friend const Vector operator + ( int x , const Vector& v );
	Vector& operator += ( const Vector& v );
	Vector& operator += ( int x );

	//substraction
	friend const Vector operator - ( const Vector& v1, const Vector& v2 ); //v1 - v2
	friend const Vector operator - ( const Vector& v, int x ); //v - 3
	Vector& operator -= ( const Vector& v );
	Vector& operator -= ( int x );


	//multiplication
	friend const Vector operator * ( const Vector& v, int x );
	friend const Vector operator * ( int x, const Vector& v );
	Vector& operator *= ( int x );

	//scalar multiplication
	friend const int operator * ( const Vector& v1, const Vector& v2 ); // int res = v1*v2

	//comparison
	friend bool operator == ( const Vector& v1, const Vector& v2 ); // v1==v2
	friend bool operator != ( const Vector& v1, const Vector& v2 ); // v1 != v2

	//indexation
	int& operator [] ( int ); // v[1]=3
	const int operator [] ( int ) const; //int x = v[3]

	//input output

	friend istream& operator >> ( istream& in, Vector& v );
	friend ostream& operator << ( ostream& out, const Vector& v );

private:
	int* m_pCoord; //tablica dynamiczna
	int m_nDim; //rozmiar wektora = wielkosc tablicy
	void CreateVect( int nDim );
	void copyVec( const Vector& v );

};

//=============INLINE================

inline int Vector::getDim() const
{
	return m_nDim;
}
inline Vector::operator int* ( ) const
{
	return m_pCoord;
}

inline void Vector::CreateVect( int nDim )
{
	if( nDim < 2 ) nDim = 2;
	m_nDim = nDim;
	m_pCoord = new( nothrow ) int[nDim];
	if( !m_pCoord ) throw VecException( ALLOCATION_ERROR ); //rzucic wyjatkiem
}

inline int& Vector::operator [] ( int ix )
{
	if( ix >= 0 && ix < getDim() ) 
		return m_pCoord[ix];
	throw VecException( INDEX_OUT_OF_RANGE );//rzycic wyjatek
}
inline const int Vector::operator [] ( int ix ) const
{
	if( ix >= 0 && ix < getDim() )
		return m_pCoord[ix];
	throw  VecException( INDEX_OUT_OF_RANGE );//rzucic wyjatekiem
}

inline void Vector::copyVec( const Vector& v )
{
	memcpy( m_pCoord, ( int* )v, v.getDim() * sizeof( int ) );
}

inline VecException::VecException( USSHORT errCode )
{
	m_ErrCode = errCode;
}
inline const char* VecException::getReason()
{
	switch( m_ErrCode ) {
	case INDEX_OUT_OF_RANGE:  return "ERROR: Index out of range!";
	case ALLOCATION_ERROR:    return "ERROR: Allocation error";
	case INCOMPATIBLE_SIZES:  return "ERROR: Incompatible sizes!";
	default:                  return "Other error";
	}
}
