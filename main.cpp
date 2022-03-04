#include <iostream>

using namespace std;


class Matrice{
private:
    int nr_linii, nr_coloane;
    double** matrix;

public:

    Matrice(double elem, int linii, int coloane) // constructor de initializare cu o valoare
    {
        nr_linii = linii;
        nr_coloane = coloane;

        matrix = new double*[nr_linii];

        for(int i = 0; i < nr_linii; i++)
            {
                matrix[i]= new double[nr_coloane];

            }
        for(int i = 0; i < nr_linii; i++)
            for(int j = 0; j < nr_coloane; j++)
            {
                matrix[i][j] = elem;
            }
    }




        Matrice(int linii, int coloane) // constructor de initializare
    {
        nr_linii = linii;
        nr_coloane = coloane;

        matrix = new double*[nr_linii];

        for(int i = 0; i < nr_linii; i++)
            {
                matrix[i]= new double[nr_coloane];

            }

    }


    Matrice(const Matrice &matrice) // constructor de copiere
    {

        nr_linii = matrice.nr_linii;
        nr_coloane = matrice.nr_coloane;

        matrix = new double*[nr_linii];

        for(int i = 0; i < nr_linii; i++)

                matrix[i]= new double[nr_coloane];


        for (int i = 0; i < nr_linii; i++)
            for(int j = 0; j < nr_coloane; j++)
                matrix[i][j] = matrice.matrix[i][j];
    }


    ~Matrice()//destructor
    {
        for(int i = 0; i < nr_linii; i++)
            delete [] matrix[i];

        delete [] matrix;
    }


    void citire_matrice()//metoda publica de citire
    {

        cout<< "Elementul de pus pe componentele matricii: ";
        int aux;
        cin >> aux;

        for(int i = 0; i < nr_linii; i++)
            for(int j = 0; j < nr_coloane; j++)
                matrix[i][j] = aux;

    }

    void afisare_matrice()//metoda publica de afisare
    {
        for (int i = 0; i < nr_linii; i++) {
            for (int j = 0; j < nr_coloane; j++)
                cout << matrix[i][j]<<" ";
            cout<<endl;
        }
        cout<<"----------------------------------"<<endl;
    }

    void operator=(Matrice matrix_)//operator public de atribuire
            {

        for(int i = 0; i < nr_linii; i++)
            delete [] matrix[i];

        delete [] matrix;


        nr_linii = matrix_.nr_linii;
        nr_coloane = matrix_.nr_coloane;

        matrix = new double*[nr_linii];

        for(int i = 0; i < nr_linii; i++)

                matrix[i]= new double[nr_coloane];


        for (int i = 0; i < nr_linii; i++)
            for(int j = 0; j < nr_coloane; j++)
                matrix[i][j] = matrix_.matrix[i][j];

    }


    friend istream& operator>>(istream& i, Matrice& matrix_)//supraincarcarea operatorului >>
    {
        double elem;
    i>>elem;
        for(int k = 0; k < matrix_.nr_linii; k++)
            for(int j = 0; j < matrix_.nr_coloane; j++)
                matrix_.matrix[k][j] = elem;
        return i;
    }

    friend ostream& operator<<(ostream& o, Matrice& matrix_)//supraincarcarea operatorului <<
    {
        for(int i = 0; i < matrix_.nr_linii; i++)
            {
            for(int j = 0; j < matrix_.nr_coloane; j++)
                o<<matrix_.matrix[i][j]<<" ";
            cout<<endl;
            }
        return o;
    }

    void actualizare(double elem, int nrlinii, int nrcoloane)//metoda pentru reactualizarea nr linii si nr coloane + initializare cu nr dat
    {
        for(int i = 0; i < nr_linii; i++)
            delete [] matrix[i];

        delete [] matrix;


        nr_linii = nrlinii;
        nr_coloane = nrcoloane;

        matrix = new double*[nr_linii];

        for(int i = 0; i < nr_linii; i++)

                matrix[i]= new double[nr_coloane];


        for (int i = 0; i < nr_linii; i++)
            for(int j = 0; j < nr_coloane; j++)
                matrix[i][j] = elem;



    }

    friend Matrice operator+ (Matrice mat1, Matrice mat2)//operator friend +
    {
        if ((mat1.nr_linii == mat2.nr_linii)&&(mat1.nr_coloane == mat2.nr_coloane))
        {   Matrice mat_ret(mat2.nr_linii, mat2.nr_coloane);

            for (int i = 0; i < mat2.nr_linii; i++)
                for (int j = 0; j < mat2.nr_coloane; j++)
                    mat_ret.matrix[i][j] = mat1.matrix[i][j] + mat2.matrix[i][j];

            return mat_ret;
        }
        else
        {
            cout<<"Adunarea nu se poate face, matricele nu au acelasi nr de linii sau/si coloane!!!"<<endl;
                Matrice mat_ret(0,0,0);
                return mat_ret;
        }

    }

    friend Matrice operator- (Matrice mat1, Matrice mat2)//operator friend -
    {
        if ((mat2.nr_linii == mat1.nr_linii)&&(mat2.nr_coloane == mat1.nr_coloane))
        {   Matrice mat_ret(mat1.nr_linii, mat1.nr_coloane);

            for (int i = 0; i < mat1.nr_linii; i++)
                for (int j = 0; j < mat1.nr_coloane; j++)
                    mat_ret.matrix[i][j] = mat1.matrix[i][j] - mat2.matrix[i][j];

            return mat_ret;
        }
        else
        {
            cout<<"Scaderea nu se poate face, matricele nu au acelasi nr de linii si/sau coloane!!!"<<endl;
                Matrice mat_ret(0,0,0);
                return mat_ret;
        }

    }

    friend Matrice operator* (Matrice mat1, Matrice mat2)//operator friend * pt inmultiri de matrice
    {
        if (mat1.nr_coloane == mat2.nr_linii)
        {   Matrice mat_ret (mat2.nr_coloane, mat1.nr_linii);

            for(int i = 0; i < mat2.nr_coloane; i++)
                for(int j = 0; j < mat1.nr_linii; j++ )
                    {mat_ret.matrix[i][j] = 0;
                        for(int k = 0; k < mat1.nr_coloane; k++)
                        {
                            mat_ret.matrix[i][j] += mat1.matrix[j][k]*mat2.matrix[k][i];
                        }
                    }
            return mat_ret;
        }

        else
            cout<<"Produsul nu se poate face!!!"<<endl;
                Matrice mat_ret(0,0,0);
                return mat_ret;
    }

    friend Matrice operator* (Matrice mat1, int x)//operator friend * pt inmultirea unei matrici cu o const
    {
        for(int i = 0; i < mat1.nr_linii; i++)
            for(int j = 0; j < mat1.nr_coloane; j++)
            mat1.matrix[i][j] *= x;
                return mat1;
    }

    friend Matrice operator* (int x, Matrice mat1)//operator friend * pt inmultirea unei matrici cu o const
    {       for(int i = 0; i < mat1.nr_linii; i++)
            for(int j = 0; j < mat1.nr_coloane; j++)
            mat1.matrix[i][j] *= x;
            return mat1;
    }

    friend int afis_linii (Matrice mat)//functie friend pt afisarea numarului de linii
    {
        return mat.nr_linii;
    }

    friend int afis_coloane (Matrice mat)//functie friend pt afisarea numarului de coloane
    {
        return mat.nr_coloane;
    }
    friend int afis_elemente (Matrice mat)//functie friend pt afisarea numarului de elemente
    {
        return mat.nr_coloane*mat.nr_linii;
    }

    friend Matrice rez_ecuatie(Matrice mat1, Matrice mat2)//functie pt rezolvarea tipului de ecuatie propus
    {
        if(mat1.nr_linii == mat2.nr_coloane){
            double elem;
            elem = mat2.matrix[0][0] / mat1.nr_coloane / mat1. matrix[0][0];
            Matrice mat_ret(elem,mat1.nr_coloane, mat2.nr_linii);
            return mat_ret;
        }
        else{
            cout<<"Nu se poate rezolva ecuatia!"<<endl;
                    Matrice mat_ret(0,0,0);
                    return mat_ret;
        }


    }
};


int main(){
/*
Matrice matrix(5.2, 3, 10);
Matrice matrix2 = matrix;
matrix.~Matrice();
Matrice matrix3(5, 2);
matrix3.afisare_matrice();
matrix3.citire_matrice();
matrix3.afisare_matrice();
*/
Matrice matrix3(5, 10, 20);
Matrice matrix2(10, 4, 3);
cin >> matrix3;
matrix2.afisare_matrice();
matrix3.afisare_matrice();
//cout << matrix3;
matrix2 = matrix3;
matrix2.afisare_matrice();
matrix3.afisare_matrice();
//matrix3.actualizare(3.5, 2, 3);
//matrix3.afisare_matrice();
Matrice matrix4(0,0);
matrix4 = matrix2+matrix3;
matrix4.afisare_matrice();
matrix4 = matrix4-matrix2;
matrix4.afisare_matrice();
matrix2.actualizare(2,3,3);
matrix3.actualizare(5,3,10);
matrix4 = matrix2*matrix3;
matrix4.afisare_matrice();
cout<<afis_linii(matrix4)<<endl;
cout<<afis_coloane(matrix4)<<endl;
cout<<afis_elemente(matrix4)<<endl;
matrix4 = matrix4 * 4 * 10;
matrix4.afisare_matrice();
Matrice matrix5(2,2,3);
Matrice matrix6(30,1,2);
Matrice matrix7(0, 0, 0);
matrix7 = rez_ecuatie(matrix5, matrix6);
matrix7.afisare_matrice();



}
