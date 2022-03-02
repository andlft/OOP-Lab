#include <iostream>
using namespace std;

class Matrice{
    int nr_linii, nr_coloane;
    double matrice[1000][1000];

public:
    Matrice(double elem, int coloane, int linii){
        nr_linii = linii;
        nr_coloane = coloane;

        for(int i = 0; i < linii; i++)
            for(int j = 0; j<coloane; j++)
                matrice[i][j] = elem;
    }

    Matrice(int coloane, int linii){
        nr_linii = linii;
        nr_coloane = coloane;

    }

    Matrice(Matrice const &matrix){
        nr_linii = matrix.nr_linii;
        nr_coloane = matrix.nr_coloane;

        for (int i = 0; i < nr_linii; i++)
            for(int j = 0; j < nr_coloane; j++)
                matrice[i][j] = matrix.matrice[i][j];
    }

    friend istream& operator>>(istream& i, Matrice& matrix){
        i>>matrix.nr_linii>>matrix.nr_coloane;
        for(int k = 0; k < matrix.nr_linii; k++)
            for(int j = 0; j < matrix.nr_coloane; j++)
                i>>matrix.matrice[k][j];
        return i;
    }

    friend ostream& operator<<(ostream& o, Matrice& matrix){
        for(int i = 0; i < matrix.nr_linii; i++)
            {
            for(int j = 0; j < matrix.nr_coloane; j++)
                o<<matrix.matrice[i][j]<<" ";
            cout<<endl;
            }
        return o;
    }

    void operator=(Matrice matrix){
        nr_linii = matrix.nr_linii;
        nr_coloane = matrix.nr_coloane;

        for (int i = 0; i < nr_linii; i++)
            for(int j = 0; j < nr_coloane; j++)
                matrice[i][j] = matrix.matrice[i][j];
    }

    void actualizare (double elem, int linii, int coloane){

        for(int i = 0; i < linii; i++)
            for(int j = 0; j<coloane; j++)
                matrice[i][j] = elem;
    }

    friend Matrice operator+(Matrice matrix1, Matrice matrix2){
        Matrice obiect(0, matrix1.nr_linii, matrix1.nr_coloane) ;
        for(int i = 0; i < matrix1.nr_linii; i++)
            for(int j = 0; j < matrix1.nr_coloane; j++)
                obiect.matrice[i][j] = matrix1.matrice[i][j] + matrix2.matrice[i][j];
        return obiect;
    }

    friend Matrice operator-(Matrice matrix1, Matrice matrix2){
        Matrice obiect(0, matrix1.nr_linii, matrix1.nr_coloane) ;
        for(int i = 0; i < matrix1.nr_linii; i++)
            for(int j = 0; j < matrix1.nr_coloane; j++)
                obiect.matrice[i][j] = matrix1.matrice[i][j] - matrix2.matrice[i][j];
        return obiect;
    }
    // de continuat

    friend int nrlinii(Matrice matrix){
        return matrix.nr_linii;

    }
    // de continuat

};


