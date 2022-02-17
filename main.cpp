#include <iostream>
#include <vector>

using namespace std;
int main() {
    vector<int> gem;
    vector<int> frisca;
    int raza, latura, lungime, inaltime, arie, volum;
    gem.push_back(0);
    frisca.push_back(0);
    char comanda[21];
    char forma[21];
    forma[0] = 'a';
    comanda[0]='a';

    while(comanda[0]!='S')
    {
        cin.getline(comanda, 20);

        if(comanda[0=='A'])
        {//operatia de ADD
            cin.getline(forma, 20);
            if(forma[0]=='c')
            {//cerc
                cout<<"raza cercului:"<<endl;
                cin>>raza;
                cout<<"inaltime:"<<endl;
                cin>>inaltime;
                arie = raza*raza*3;
                volum = arie*inaltime;
                gem.push_back(volum*2);
                frisca.push_back(2*3*raza*inaltime);

            }
            if(forma[0]=='d')
            {   cout<<"lungimea dreptunghiului este:"<<endl;
                cin>>lungime;
                cout<<"latimea dreptunghiului este:"<<endl;
                cin>>latura;
                cout<<"inaltime:"<<endl;
                cin>>inaltime;

                //dreptunghi
            }
            if(forma[0]=='p')
            {
                //patrat
            }
            if(forma[0]=='t')
            {
                //triunghi
            }
        }

        if(comanda[0]=='R')
        {//operatia de REMOVE

        }

        if(comanda[0]=='T')
        {//operatia de TOTAL

        }

    }

    return 0;
}
