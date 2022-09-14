#include "Matrix.h"

Matrix::Matrix( int Row, int Col, int Elem )
{
	m_nRow = Row;
	m_pVect = new ( nothrow ) Vector[Row];
	if( !m_pVect ) throw VecException( ALLOCATION_ERROR );

	//Vector v( Col, Elem );

	for( int i = 0; i < Row; i++ ) {
		m_pVect[i] = Vector( Col, Elem );
	}
}

Matrix::Matrix( const Matrix& m ) {
	m_nRow = 0;
	m_pVect = NULL;
	*this = m;
}
Matrix::~Matrix() {
	m_nRow = 0;
	delete[] m_pVect;
}

int Matrix::GetRowNo() const {
	return m_nRow;
}
int Matrix::GetColNo() const {
	return m_pVect->getDim();
}
istream& operator >> ( istream& in, Matrix& m ) {
	for( int i = 0; i < m.m_nRow; i++ ) {
		in >> m.m_pVect[i];
	}
	return in;
}
ostream& operator << ( ostream& out, const Matrix& m ) {
	out << "\n{";
	for( int i = 0; i < m.m_nRow; i++ ) {
		out << m.m_pVect[i] << ( ( i < m.m_nRow - 1 ) ? ",\n" : "" );
	}
	out << "}\n";
	return out;
}
Vector& Matrix::operator [] ( int ix ) {
	if( ix >= 0 && ix < m_nRow )
		return m_pVect[ix];
	throw VecException( INDEX_OUT_OF_RANGE );
}

const Vector& Matrix::operator [] ( int ix ) const {
	if( ix >= 0 && ix < m_nRow )
		return m_pVect[ix];
	throw VecException( INDEX_OUT_OF_RANGE );
}

Matrix::operator Vector* ( ) const {
	return m_pVect;
}

Matrix& Matrix::operator = ( const Matrix& m ) {
	if( GetRowNo() != m.GetRowNo() || GetColNo() != m.GetColNo() ) {
		delete[] m_pVect;
		m_nRow = m.m_nRow;
		m_pVect = new ( nothrow ) Vector[m_nRow]; //tworzy tablice wektorow o nDim=2
		if( !m_pVect ) throw VecException( ALLOCATION_ERROR );
		for( int i = 0; i < GetRowNo(); i++ ) {
			m_pVect[i] = Vector( GetColNo(), 0 );
		}
	}
	for( int i = 0; i < m.GetRowNo(); i++ ) {
		m_pVect[i] = m.m_pVect[i];
	}
	return *this;
}

bool operator == ( const Matrix& m1, const Matrix& m2 ) {
	if( m1.GetRowNo() != m2.GetRowNo() || m1.GetColNo() != m2.GetColNo() )
		return false;
	for( int i = 0; i < m1.m_nRow; i++ ) {
		if( m1.m_pVect[i] != m2.m_pVect[i] ) return false;
	}
	return true;
}
bool operator != ( const Matrix& m1, const Matrix& m2 ) {
	return !( m1 == m2 );
}

const Matrix operator * ( const Matrix& m1, const Matrix& m2 ) {
	if( m1.GetColNo() != m2.GetRowNo() ) throw VecException( INCOMPATIBLE_SIZES );
	Matrix res( m1.GetRowNo(), m2.GetColNo(), 0 );

	for( int i = 0; i < m1.GetRowNo(); i++ ) {
		for( int j = 0; j < m2.GetColNo(); j++ ) {
			int temp = 0;
			for( int k = 0; k < m1.GetColNo(); k++ ) {
				 temp += m1.m_pVect[i][k] * m2.m_pVect[k][j];
			}
			res.m_pVect[i][j] = temp;
		}
	}
	return res;
}
const Vector operator * ( const Matrix& m, const Vector& v ) {
	if( m.GetColNo() != v.getDim() ) throw VecException( INCOMPATIBLE_SIZES );
	Vector res( m.GetRowNo() );
	for( int i = 0; i < m.GetRowNo(); i++ ) {
		 //for( int k = 0; k < v.getDim(); k++ ) {
			// res[i] += m[i][k] * v[k];
		// }
		 res[i] = m[i] * v; 
	}
	return res;
}
