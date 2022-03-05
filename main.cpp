#include <iostream>
#include <vector>

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

    void operator=(Matrice const &matrix_)//operator public de atribuire
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

    friend Matrice operator+ (Matrice const &mat1, Matrice const &mat2)//operator friend +
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

    friend Matrice operator- (Matrice const &mat1, Matrice const &mat2)//operator friend -
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

    friend Matrice operator* (Matrice const &mat1, Matrice const &mat2)//operator friend * pt inmultiri de matrice
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

    friend Matrice operator* (Matrice const &mat1, int x)//operator friend * pt inmultirea unei matrici cu o const
    {
        for(int i = 0; i < mat1.nr_linii; i++)
            for(int j = 0; j < mat1.nr_coloane; j++)
            mat1.matrix[i][j] *= x;
                return mat1;
    }

    friend Matrice operator* (int x, Matrice const &mat1)//operator friend * pt inmultirea unei matrici cu o const
    {       for(int i = 0; i < mat1.nr_linii; i++)
            for(int j = 0; j < mat1.nr_coloane; j++)
            mat1.matrix[i][j] *= x;
            return mat1;
    }

    friend int afis_linii (Matrice const &mat)//functie friend pt afisarea numarului de linii
    {
        return mat.nr_linii;
    }

    void set_linii(int n)
    {
        nr_linii=n;
    }

    friend int afis_coloane (Matrice const &mat)//functie friend pt afisarea numarului de coloane
    {
        return mat.nr_coloane;
    }

    void set_coloane(int n)
    {
        nr_coloane = n;
    }

    friend int afis_elemente (Matrice const &mat)//functie friend pt afisarea numarului de elemente
    {
        return mat.nr_coloane*mat.nr_linii;
    }

    friend Matrice rez_ecuatie(Matrice const &mat1, Matrice const &mat2)//functie pt rezolvarea tipului de ecuatie propus
    {
        if(mat1.nr_linii == mat2.nr_coloane){
            double elem;
            elem = -(mat2.matrix[0][0]) / mat1.nr_coloane / mat1. matrix[0][0];
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
    vector <Matrice> v_matrici;
    int optiune=0;
    do {cout<<"Scrie numarul a ceea ce doresti sa faci:\n 1. Adauga o matrice in vector\n2.Sterge o matrice din vectorul de matrici\n"
              "3.Afiseaza toate matricele din vector\n 4.Adunare intre 2 matrice din vector\n 5.Scadere intre 2 matrice din vector\n"
              "6.Inmultire intre 2 matrice\n 7.Inmultire intre o matrice si o constanta\n 8.Aflarea lui X din ecuatia cu matrici: AX + B = 0 \n"
              "9.Reactualizarea unei matrici deja existente\n"
              "0.Inchidere program\n";
        cin>>optiune;
        if(optiune == 1)
        {   int elem, linii, coloane;
            cout<<"Introdu elementul de pe componentele matricei"<<endl;
            cin>>elem;
            cout<<"Introdu numarul de linii al matricei"<<endl;
            cin>>linii;
            cout<<"Introdu numarul de coloane al matricei"<<endl;
            cin>>coloane;

            Matrice mat(elem, linii, coloane);
            v_matrici.push_back(mat);
        }

        if(optiune == 2)
        {
            int poz;
            cout<<"Introdu pozitia matricei pe care vrei sa o elimini (incepe cu 1):"<<endl;
            cin>>poz;
            v_matrici.erase(v_matrici.begin()+poz-1);
        }
        if(optiune == 3)
        {
            for (unsigned int i = 0; i < v_matrici.size(); i++)
            {
                cout<<"Matricea de pe pozitia "<<i+1<<" este:"<<endl;
                v_matrici[i].Matrice::afisare_matrice();
            }

        }

        if(optiune == 4)
        {
            int poz1, poz2;
            cout<<"Introdu pozitia primei matrice:"<<endl;
            cin>>poz1;
            cout<<"Introdu pozitia celei dea doua matrice:"<<endl;
            cin>>poz2;
            cout<<"Rezultatul este:"<<endl;
            (v_matrici[poz1-1]+v_matrici[poz2-1]).Matrice::afisare_matrice();
        }

        if(optiune == 5)
        {
            int poz1, poz2;
            cout<<"Introdu pozitia primei matrice:"<<endl;
            cin>>poz1;
            cout<<"Introdu pozitia celei dea doua matrice:"<<endl;
            cin>>poz2;
            cout<<"Rezultatul este:"<<endl;
            (v_matrici[poz1-1]-v_matrici[poz2-1]).Matrice::afisare_matrice();
        }

        if(optiune == 6)
        {
            int poz1, poz2;
            cout<<"Introdu pozitia primei matrice:"<<endl;
            cin>>poz1;
            cout<<"Introdu pozitia celei dea doua matrice:"<<endl;
            cin>>poz2;
            cout<<"Rezultatul este:"<<endl;
            (v_matrici[poz1-1]*v_matrici[poz2-1]).Matrice::afisare_matrice();
        }

        if(optiune == 7)
        {
            int poz1, poz2;
            cout<<"Introdu pozitia matricei:"<<endl;
            cin>>poz1;
            cout<<"Introdu constanta:"<<endl;
            cin>>poz2;
            cout<<"Rezultatul este:"<<endl;
            (v_matrici[poz1-1]*poz2).Matrice::afisare_matrice();
        }

        if(optiune == 8)
        {
            int poz1, poz2;
            cout<<"Introdu pozitia primei matrice:"<<endl;
            cin>>poz1;
            cout<<"Introdu pozitia celei dea doua matrice:"<<endl;
            cin>>poz2;
            cout<<"Rezultatul este:"<<endl;
            (rez_ecuatie(v_matrici[poz1-1],v_matrici[poz2-1])).Matrice::afisare_matrice();
        }

        if(optiune == 9)
        {
            int poz1, elem, linii, coloane;
            cout<<"Introdu pozitia matricei pe care vrei sa o actualizezi:"<<endl;
            cin>>poz1;
            cout<<"Introdu elementul de pe componentele matricei:"<<endl;
            cin>>elem;
            cout<<"Introdu numarul de linii al matricei:"<<endl;
            cin>>linii;
            cout<<"Introdu numarul de coloane al matricei:"<<endl;
            cin>>coloane;
            v_matrici[poz1-1].actualizare(elem,linii,coloane);
        }


    }while(optiune!=0);

}
