#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class HatchBack {
    string model;

public:
    HatchBack(string x):model(x) {};
    void setModel (const string &model_){
        this->model  = model_;
    }
    string getModel (){
        return this->model;
    }
};
class Cabrio{
    string model;
public:
    Cabrio(string x):model(x) {};
    void setModel (const string &model_){
        this->model  = model_;
    }
    string getModel (){
        return this->model;
    }

};
class Supersport{

    string model;
    int pret;
public:
    Supersport(string x, int p):model(x), pret(p) {};
    void setModel (const string &model_){
        this->model  = model_;
    }
    string getModel (){
        return this->model;
    }
    void setPret (const int &pret_){
        this->pret  = pret_;
    }
    int getPret (){
        return this->pret;
    }
};

template<typename T>
class Expozitie{
    vector<T> masini;
    static int nr_masini;
public:
    Expozitie(){};
    Expozitie(const Expozitie &e){ this->masini = e.masini;}
    ~Expozitie(){};

    void addCar(const T &car){
        masini.push_back(car);
    }
    T getCar(const int &x){
        return masini[x];
    }

    void showAllCars(){
        for(int i = 0; i < static_cast<int>(masini.size());i++)
        {
                cout<<masini[i].getModel()<<endl;
        }
    }
};
template<typename T> int Expozitie<T>::nr_masini = 0;

template<>
class Expozitie<Supersport>{
    vector<Supersport> masini;
public:
    Expozitie(){};
    Expozitie(const Expozitie &e){ this->masini = e.masini;}
    ~Expozitie(){};

    void addCar(const Supersport &car){
        masini.push_back(car);
    }
    Supersport getCar(const int &x){
        return masini[x];
    }
    void setPret(const int &p, const int &index){
        this->masini[index].Supersport::setPret(p);
    }
    int getPret(const int &index){
        return this->masini[index].Supersport::getPret();
    }
    void showAllCars(){
        for(int i = 0; i < static_cast<int>(masini.size());i++)
        {
            cout<<masini[i].getModel()<<" --- "<<masini[i].getPret()<<endl;
        }
    }
    
};

class Meniu{
    Meniu(){}
    static Meniu * instance;
    int optiune = -1;
    string model;
    int pret;
    int index;

public:
    Meniu(const Meniu &s) =delete;
    void operator= (const Meniu &s) = delete;
    static Meniu* get();

    void runMenu(){

        Expozitie<HatchBack> hatchback;
        Expozitie<Cabrio> cabrio;
        Expozitie<Supersport> supersport;

        while(true) {
            cout << "Alege operatia pe care vrei sa o faci:\n"
                 << "1.adauga masina hatchback\n"
                 << "2.adauga masina cabrio\n"
                 << "3.adauga masina supersport\n"
                 << "4.vanzare masina supersport\n"
                 << "5.afiseaza masinile hatchback\n"
                 << "6.afiseaza masinile cabrio\n"
                 << "7.afiseaza masinile supersport\n";
            cin >> optiune;
            cin.ignore();

            if(optiune == 0)
            {
                break;
            }
            if (optiune == 1) {
                getline(cin, model);
                hatchback.addCar(HatchBack(model));
            }
            if (optiune == 2){
                getline(cin, model);
                cabrio.addCar(Cabrio(model));
            }
            if (optiune ==3){
                getline( cin, model);
                supersport.addCar(Supersport(model, pret= -1));
            }
            if (optiune == 4){
                cin>>pret;
                cin>>index;
                supersport.setPret(index, pret);
            }
            if(optiune == 5){
                hatchback.showAllCars();
            }
            if(optiune == 6){
                cabrio.showAllCars();
            }
            if(optiune == 7){
                supersport.showAllCars();
            }

        }

    }

};
Meniu* Meniu::instance = nullptr;

Meniu* Meniu::get() {
    if(instance == nullptr)
        instance = new Meniu;
    return instance;
}



int main(){
    auto m = Meniu::get();
    m->runMenu();

}


