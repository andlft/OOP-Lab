#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Produs{

protected:
    float pret;
    int cantitate;
    static int id;

public:
    Produs(float pret, int cantitate) : pret(pret), cantitate(cantitate) {
        id++;
    };
    Produs(const Produs & prod){
        this->pret = prod.pret;
        this->cantitate = prod.cantitate;
    }

    virtual ~Produs() {
        id--;
    }

    float getPret() const {
        return pret;
    }

    void setPret(float pret_) {
        Produs::pret = pret_;
    }

    int getCantitate() const {
        return cantitate;
    }

    void setCantitate(int cantitate_) {
        Produs::cantitate = cantitate_;
    }

    static int getId() {
        return id;
    }

    static void setId(int id_) {
        Produs::id = id_;
    }

    bool operator==(const Produs &rhs) const {
        return pret == rhs.pret &&
               cantitate == rhs.cantitate;
    }

    bool operator!=(const Produs &rhs) const {
        return !(rhs == *this);
    }

    friend ostream &operator<<(ostream &os, const Produs &produs) {
        os << "pret: " << produs.pret << " cantitate: " << produs.cantitate << " id_produs: ";
        return os;
    }

    friend istream &operator>>(istream &is, Produs &produs){
        is >> produs.pret >> produs.cantitate;
        return is;
    }



};

class Carte : public Produs {

protected:
    string titlul;
    vector<string> autori;

public:
    Carte(float pret, int cantitate, const string &titlul, const vector<string> &autori) : Produs(pret, cantitate),
                                                                                           titlul(titlul),
                                                                                           autori(autori) {}

    Carte(const Carte &carte) : Produs(carte.getPret(), carte.getCantitate()) {
        this->titlul = carte.titlul;
        this->autori = carte.autori;
    }

    virtual ~Carte() {}

    const string &getTitlul() const {
        return titlul;
    }

    void setTitlul(const string &titlul_) {
        Carte::titlul = titlul_;
    }

    const vector<string> &getAutori() const {
        return autori;
    }

    void setAutori(const vector<string> &autori_) {
        Carte::autori = autori_;
    }

    bool operator==(const Carte &rhs) const {
        return static_cast<const Produs &>(*this) == static_cast<const Produs &>(rhs) &&
               titlul == rhs.titlul &&
               autori == rhs.autori;
    }

    bool operator!=(const Carte &rhs) const {
        return !(rhs == *this);
    }

    friend ostream &operator<<(ostream &os, const Carte &carte) {
        os << static_cast<const Produs &>(carte) << " titlul: " << carte.titlul << " autori: " << carte.autori[0];
        return os;
    };

    friend istream &operator>>(istream &is, Carte carte) {
        is >> carte.pret >> carte.cantitate >> carte.titlul >> carte.autori[0];
        return is;
        return is;
    };

};
class DVD : public Produs{

protected:
    int nr_minute;

public:
    DVD(float pret, int cantitate, int nrMinute) : Produs(pret, cantitate), nr_minute(nrMinute) {};
    DVD(const DVD &dvd): Produs(dvd.pret, dvd.cantitate){
    this->nr_minute = dvd.nr_minute;
    }

    virtual ~DVD() {}

    int getNrMinute() const {
        return nr_minute;
    }

    void setNrMinute(int nrMinute) {
        nr_minute = nrMinute;
    }

    bool operator==(const DVD &rhs) const {
        return static_cast<const Produs &>(*this) == static_cast<const Produs &>(rhs) &&
               nr_minute == rhs.nr_minute;
    }

    bool operator!=(const DVD &rhs) const {
        return !(rhs == *this);
    }

    friend ostream &operator<<(ostream &os, const DVD &dvd) {
        os << static_cast<const Produs &>(dvd) << " nr_minute: " << dvd.nr_minute;
        return os;
    }
    friend istream &operator>>(istream &is, DVD &dvd){
        is >> dvd.pret >>dvd.cantitate>>dvd.nr_minute;
        return is;
    }

};

class ObCol :public  Produs{

protected:
    string denumire;

public:
    ObCol(float pret, int cantitate, const string &denumire) : Produs(pret, cantitate), denumire(denumire) {};
    ObCol(const ObCol &obiect): Produs(obiect.pret, obiect.cantitate){
        this->denumire = obiect.denumire;
    }

    virtual ~ObCol() {}

    const string &getDenumire() const {
        return denumire;
    }

    void setDenumire(const string &denumire_) {
        ObCol::denumire = denumire_;
    }

    bool operator==(const ObCol &rhs) const {
        return static_cast<const Produs &>(*this) == static_cast<const Produs &>(rhs) &&
               denumire == rhs.denumire;
    }

    bool operator!=(const ObCol &rhs) const {
        return !(rhs == *this);
    }

    friend ostream &operator<<(ostream &os, const ObCol &col) {
        os << static_cast<const Produs &>(col) << " denumire: " << col.denumire;
        return os;
    }
    friend istream &operator>>(istream &is, ObCol obiect){
        is >> obiect.pret >> obiect.cantitate >> obiect.denumire;
        return is;
    }
};

class DVDMuzica: public DVD{
private:
    string nume_album;
    string interpreti;
public:
    DVDMuzica(float pret, int cantitate, int nrMinute, const string &numeAlbum, const string &interpreti) : DVD(pret,
                                                                                                                cantitate,
                                                                                                                nrMinute),
                                                                                                            nume_album(
                                                                                                                    numeAlbum),
                                                                                                            interpreti(
                                                                                                                    interpreti) {};
    DVDMuzica(const DVDMuzica & dvd): DVD(dvd.pret, dvd.cantitate, dvd.nr_minute){
        this->nume_album = dvd.nume_album;
        this->interpreti = dvd.interpreti;

    }



    virtual ~DVDMuzica() {}

    const string &getNumeAlbum() const {
        return nume_album;
    }

    void setNumeAlbum(const string &numeAlbum) {
        nume_album = numeAlbum;
    }

    const string &getInterpreti() const {
        return interpreti;
    }

    void setInterpreti(const string &interpreti_) {
        DVDMuzica::interpreti = interpreti_;
    }

    bool operator==(const DVDMuzica &rhs) const {
        return static_cast<const DVD &>(*this) == static_cast<const DVD &>(rhs) &&
               nume_album == rhs.nume_album &&
               interpreti == rhs.interpreti;
    }

    bool operator!=(const DVDMuzica &rhs) const {
        return !(rhs == *this);
    }

    friend ostream &operator<<(ostream &os, const DVDMuzica &muzica) {
        os << static_cast<const DVD &>(muzica) << " nume_album: " << muzica.nume_album << " interpreti: "
           << muzica.interpreti;
        return os;
    };

};

class DVDFilm : public DVD{

private:
    string nume_film;
    string gen_film;
public:
    DVDFilm(float pret, int cantitate, int nrMinute, const string &numeFilm, const string &genFilm) : DVD(pret,
                                                                                                          cantitate,
                                                                                                          nrMinute),
                                                                                                      nume_film(
                                                                                                              numeFilm),
                                                                                                      gen_film(
                                                                                                              genFilm) {};


    DVDFilm(const DVDFilm &dvd):DVD(dvd.pret,dvd.cantitate,dvd.nr_minute){
        this->nume_film = dvd.nume_film;
        this->gen_film = dvd.gen_film;
    }

    virtual ~DVDFilm() {

    }

    const string &getNumeFilm() const {
        return nume_film;
    }

    void setNumeFilm(const string &numeFilm) {
        nume_film = numeFilm;
    }

    const string &getGenFilm() const {
        return gen_film;
    }

    void setGenFilm(const string &genFilm) {
        gen_film = genFilm;
    }

    bool operator==(const DVDFilm &rhs) const {
        return static_cast<const DVD &>(*this) == static_cast<const DVD &>(rhs) &&
               nume_film == rhs.nume_film &&
               gen_film == rhs.gen_film;
    }

    bool operator!=(const DVDFilm &rhs) const {
        return !(rhs == *this);
    }

    friend ostream &operator<<(ostream &os, const DVDFilm &film) {
        os << static_cast<const DVD &>(film) << " nume_film: " << film.nume_film << " gen_film: " << film.gen_film;
        return os;
    }

};


class ObColFig : public ObCol{

private:
    string categorie;
    string brand;
    string material;
public:
    ObColFig(float pret, int cantitate, const string &denumire, const string &categorie, const string &brand,
             const string &material) : ObCol(pret, cantitate, denumire), categorie(categorie), brand(brand),
                                       material(material) {};
    ObColFig(const ObColFig &obiect): ObCol(obiect.pret, obiect.cantitate, obiect.denumire){
        this->categorie = obiect.categorie;
        this->brand = obiect.brand;
        this->material = obiect.material;

    }

    virtual ~ObColFig() {

    }

    const string &getCategorie() const {
        return categorie;
    }

    void setCategorie(const string &categorie_) {
        ObColFig::categorie = categorie_;
    }

    const string &getBrand() const {
        return brand;
    }

    void setBrand(const string &brand_) {
        ObColFig::brand = brand_;
    }

    const string &getMaterial() const {
        return material;
    }

    void setMaterial(const string &material_) {
        ObColFig::material = material_;
    }

    bool operator==(const ObColFig &rhs) const {
        return static_cast<const ObCol &>(*this) == static_cast<const ObCol &>(rhs) &&
               categorie == rhs.categorie &&
               brand == rhs.brand &&
               material == rhs.material;
    }

    bool operator!=(const ObColFig &rhs) const {
        return !(rhs == *this);
    }

    friend ostream &operator<<(ostream &os, const ObColFig &fig) {
        os << static_cast<const ObCol &>(fig) << " categorie: " << fig.categorie << " brand: " << fig.brand
           << " material: " << fig.material;
        return os;
    }
    friend istream &operator>>(istream &is, ObColFig fig) {
        is >> fig.pret>>fig.cantitate>>fig.denumire>>fig.categorie>>fig.material>>fig.brand;
        return is;
    }

};

class ObColPos : public ObCol{
private:
    string format;
public:
    ObColPos(float pret, int cantitate, const string &denumire, const string &format) : ObCol(pret, cantitate,
                                                                                              denumire),
                                                                                        format(format) {};
    ObColPos(const ObColPos &obiect):ObCol(obiect.pret, obiect.cantitate, obiect.denumire){
        this->format = obiect.format;
    }

    virtual ~ObColPos() {

    }

    const string &getFormat() const {
        return format;
    }

    void setFormat(const string &format_) {
        ObColPos::format = format_;
    }

    bool operator==(const ObColPos &rhs) const {
        return static_cast<const ObCol &>(*this) == static_cast<const ObCol &>(rhs) &&
               format == rhs.format;
    }

    bool operator!=(const ObColPos &rhs) const {
        return !(rhs == *this);
    }

    friend ostream &operator<<(ostream &os, const ObColPos &pos) {
        os << static_cast<const ObCol &>(pos) << " format: " << pos.format;
        return os;
    }
    friend istream &operator>>(istream &is, ObColPos &obiect){
        is>>obiect.pret>>obiect.cantitate>>obiect.denumire>>obiect.format;
        return is;
    }

};

class Meniu{
    static vector<shared_ptr<Produs>> produse;
public:
    static void add_produs(const shared_ptr<Produs> produs) {
        produse.push_back(produs);
    }
};


int main()
{
    //Produs prd(5, 10);
    //Meniu::add_produs(make_shared<Produs>(prd));
    return 0;
}