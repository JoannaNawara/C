#include <iostream>
#include "Vector.h"
#include "Matrix.h"
using namespace std;

int main()
{
    try {
        Vector res( 3, 1 );
        Matrix macierz( 3, 3, 1 );
        Vector res2( 3, 3 );
        Matrix macierz2( 3, 3, 1 );
        Matrix m1( macierz2 );
        Matrix m3( 3, 3, 5 );
        Matrix m4( 3, 3, 6 );
        cout << res * res2 << endl;
        cout << "Macierz1: " << macierz << endl; 
        cout << "m1: " << m1 << endl;
        cout << "Rzutowanie macierzy na Vector*, zerowy wektor:" << ( ( Vector* ) macierz )[0] << endl;
     
        cout << "Mnozenie macierz2 przez wektor res: " << macierz2 * res << endl;
        //cout << macierz2.GetColNo() << endl;
        //cout << macierz.GetRowNo() << endl;

        cout << "Macierz 3: " << m3 << endl;
        m3 = m4;
        cout << "Macierz 3: (po podstawieniu m4 ) " << m3 << endl;

        if( m3 == m4 ) {
            cout << "macierze m3 i m4 sa rowne" << endl;
        }
        else
            cout << "macierze m3 i m4 nie sa rowne" << endl;
        
        cout << "Mnozenie macierzy macierz1 i macierz2: " << macierz2 * macierz << endl;
    }
    catch( VecException e ) {
        cout << e.getReason() << endl;
    }
}

