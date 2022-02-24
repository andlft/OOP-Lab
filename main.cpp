#include <iostream>
#include <string.h>
#include <cmath>



class numar_complex{
private:
    double parte_reala;
    double parte_imaginara;

public:
    double get_parte_reala() const {
        return parte_reala;
    }

    void set_parte_reala(double parte_reala_) {
        numar_complex::parte_reala = parte_reala_;
    }

    double get_parte_imaginara() const {
        return parte_imaginara;
    }

    void set_parte_imaginara(double parte_imaginara_) {
        numar_complex::parte_imaginara = parte_imaginara_ ;
    }


public:
    numar_complex(int parte_reala_, int parte_imaginara_){
        parte_reala = parte_reala_;
        parte_imaginara = parte_imaginara_;
    }
    ~numar_complex(){}

    void afisare(numar_complex nr){
        std::cout<<nr.parte_reala<<"+*"<<nr.parte_imaginara<<std::endl;

    }
    void afisare_modul (numar_complex nr){
        std::cout<<sqrt(nr.parte_reala*nr.parte_reala+nr.parte_imaginara*nr.parte_imaginara)<<std::endl;

    }
    numar_complex operator+ (numar_complex nr1, numar_complex nr2){

    }

};
