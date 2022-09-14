#pragma once
#include "Vector.h"

class Matrix
{
private:
	int m_nRow; //ilosc wierszy m_nRow
	Vector* m_pVect; //tablica wektorow
public:
	Matrix( int Row = 2, int Col = 2, int Elem = 0 );
	Matrix( const Matrix& m ); // konstr kopiujacy
	virtual ~Matrix(); // destr

public:
	//---rozmiar macierzy - ilosc wierszy i kolumn//
	int GetRowNo() const;
	int GetColNo() const;

	friend istream& operator >> ( istream& in, Matrix& m );
	friend ostream& operator << ( ostream& out, const Matrix& m );
	
	Vector& operator [] ( int ); 				  
	const Vector& operator [] ( int ) const; 
	
	operator Vector* () const; //opera rzutowania na Vector* ( const )
	Matrix& operator = ( const Matrix& m ); //operator podstawienia =
	friend bool operator == ( const Matrix& m1, const Matrix& m2 ); //operator porównania == !=
	friend bool operator != ( const Matrix& m1, const Matrix& m2 ); 

	//mno¿enie macierzy
	friend const Matrix operator * ( const Matrix& m1, const Matrix& m2 );
	//mno¿enie macierzy przez wektor - mo¿na uzyc tych od wektorow
	friend const Vector operator * ( const Matrix& m, const Vector& v );
};

