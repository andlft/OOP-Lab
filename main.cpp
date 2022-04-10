#include<iostream>

class Punct{
private:
    float x;
    float y;
public:
    Punct() = default;

    Punct(float x_, float y_){    // constructor de initializare parametrizat
        x = x_;
        y = y_;
    }

    Punct(const Punct &pct){     // constructor de copiere
        x = pct.x;
        y = pct.y;
    }
    virtual ~Punct() = default;

    Punct& operator= (const Punct &pct) = default;

    friend std::ostream& operator<< (std::ostream& o, const Punct &pct){
        o<<pct.x<<" "<<pct.y;
        return o;
    }

    friend std::istream& operator>> (std::istream& i, Punct &pct){
        i>>pct.x >>pct.y;
        return i;
    }

    void actualizare(const float& x_, const float& y_){
        x = x_;
        y = y_;
    }

    float getX() const {
        return x;
    }

//    void setX(float x_) {
//        x = x_;
//    }

    float getY() const {
        return y;
    }

//    void setY(float y_) {
//        y = y_;
//    }

    bool operator==(const Punct &rhs) const {
        return x == rhs.x && y == rhs.y;
    }

    bool operator!=(const Punct &rhs) const {
        return !(rhs == *this);
    }
};

class Patrat{
protected:
    Punct pct_st_jos;
    float latura;
public:
    Patrat() = default;

    Patrat(const float& x, const float& y,const float& latura_){  //constructor cu parametrii
        pct_st_jos.actualizare(x,y);
        latura = latura_;
    }

    Patrat(const Patrat &patrat): pct_st_jos(patrat.pct_st_jos), latura(patrat.latura){} //constructor de copiere
    virtual ~Patrat() = default;

    Patrat& operator= (const Patrat& patrat_){
        pct_st_jos = patrat_.pct_st_jos;
        latura = patrat_.latura;
        return *this;
    }

    friend std::ostream& operator<< (std::ostream& o, const Patrat &patrat_){
        o<<patrat_.pct_st_jos<<" "<<patrat_.latura;
        return o;
    }

    friend std::istream& operator>> (std::istream& i, Patrat &patrat_){
        i>>patrat_.pct_st_jos >>patrat_.latura;
        return i;
    }

//    Punct getPctStJos() const {
//        return pct_st_jos;
//    }
//
//    void setPctStJos(Punct pctStJos) {
//        pct_st_jos = pctStJos;
//    }

//    float getLatura() const {
//        return latura;
//    }
//
//    void setLatura(float latura_) {
//        Patrat::latura = latura_;
//    }

    bool operator==(const Patrat &rhs) const {
        return pct_st_jos == rhs.pct_st_jos &&
               latura == rhs.latura;
    }

    bool operator!=(const Patrat &rhs) const {
        return !(rhs == *this);
    }
};

class Dreptunghi : virtual public Patrat{
protected:
    float latura2;
public:
    Dreptunghi() = default;

    Dreptunghi(const float &x, const float &y, const float &latura,const float latura2_) :
    Patrat(x, y, latura) {
        latura2 = latura2_;
    }
         //constructor de initializare cu parametrii


    Dreptunghi(const Dreptunghi & dreptunghi_):Patrat(dreptunghi_.pct_st_jos.getX(),
                                                      dreptunghi_.pct_st_jos.getY(),
                                                      dreptunghi_.latura)
                                                      { //constructor de copiere
        latura2 = dreptunghi_.latura2;
    }

//    float getLatura2() const {  //getter
//        return latura2;
//    }
//
//    void setLatura2(float latura2_) { //setter
//        Dreptunghi::latura2 = latura2_;
//    }

    virtual ~Dreptunghi() = default;

    Dreptunghi& operator= (const Dreptunghi &drptg){
        pct_st_jos = drptg.pct_st_jos;
        latura = drptg.latura;
        latura2 = drptg.latura2;
        return *this;
    }

    bool operator==(const Dreptunghi &rhs) const {   //operator ==
        return static_cast<const Patrat &>(*this) == static_cast<const Patrat &>(rhs) &&
               latura2 == rhs.latura2;
    }

    bool operator!=(const Dreptunghi &rhs) const {  //operator !=
        return !(rhs == *this);
    }

    friend std::ostream &operator<<(std::ostream &os, const Dreptunghi &dreptunghi) {
        os << static_cast<const Patrat &>(dreptunghi) <<  dreptunghi.latura2;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Dreptunghi &dreptunghi){
        is >> dreptunghi.pct_st_jos>>dreptunghi.latura >> dreptunghi.latura2;
        return is;
    }
};

class Romb : virtual public Patrat{
protected:
    Punct pct_colt_op;
public:
    Romb(){}//consturctor fara parametrii

    Romb(const float &x, const float &y, const float &latura, const float &z, const float&w) :
    Patrat(x, y, latura)  {
        pct_colt_op.actualizare(z,w);
    }
    //constructor cu parametrii

    Romb(const Romb &romb):Patrat(romb.pct_st_jos.getX(),
                                  romb.pct_st_jos.getY(),
                                  romb.latura),
                                  pct_colt_op(romb.pct_colt_op){}


    Punct getPctColtOp() const {
        return pct_colt_op;
    }

//    void setPctColtOp(float x, float y) {
//        pct_colt_op.setX(x);
//        pct_colt_op.setY(y);
//
//    }

    virtual ~Romb() = default;

    bool operator==(const Romb &rhs) const {
        return static_cast<const Patrat &>(*this) == static_cast<const Patrat &>(rhs) &&
               pct_colt_op == rhs.pct_colt_op;
    }

    bool operator!=(const Romb &rhs) const {
        return !(rhs == *this);
    }

    Romb& operator= (const Romb &rmb){
        pct_st_jos = rmb.pct_st_jos;
        pct_colt_op = rmb.pct_colt_op;
        latura = rmb.latura;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Romb &romb) {
        os << static_cast<const Patrat &>(romb) << romb.pct_colt_op;
        return os;
    }
    friend std::istream &operator>>(std::istream &is, Romb &romb) {
        is >> romb.pct_st_jos >> romb.latura >> romb.pct_colt_op;
        return is;
    }
};

class Paralelogram : public Dreptunghi, public Romb{
public:
    Paralelogram() = default;

            Paralelogram(

    const float &x,
    const float &y,
    const float &latura,
    const float &latura2,
    const float &x2,
    const float &y2
    ):
    Dreptunghi(x, y, latura, latura2
    ),
    Romb(x, y, latura, x2, y2
    ){}

    Paralelogram(const Paralelogram &prlgrm): Patrat(prlgrm.pct_st_jos.getX(),
                                                     prlgrm.pct_st_jos.getY(),
                                                     prlgrm.latura),
                                                        Dreptunghi(prlgrm.pct_st_jos.getX(),
                                                         prlgrm.pct_st_jos.getY(),
                                                         prlgrm.latura,
                                                         prlgrm.latura2),
                                                         Romb(prlgrm.pct_st_jos.getX(),
                                                              prlgrm.pct_st_jos.getY(),
                                                              prlgrm.latura,
                                                              prlgrm.pct_colt_op.getX(),
                                                              prlgrm.pct_colt_op.getY()
                                                         ){};


    virtual ~Paralelogram() = default;

    bool operator==(const Paralelogram &rhs) const {
        return static_cast<const Romb &>(*this) == static_cast<const Romb &>(rhs) &&
                static_cast<const Dreptunghi &>(*this) == static_cast<const Dreptunghi &>(rhs);
    }

    Paralelogram& operator= (const Paralelogram &prlgrm){
        pct_st_jos = prlgrm.pct_st_jos;
        latura=prlgrm.latura;
        latura2=prlgrm.latura2;
        pct_colt_op = prlgrm.pct_colt_op;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Paralelogram &paralelogram) {
        os << static_cast<const Dreptunghi &>(paralelogram) <<static_cast<const Romb &>(paralelogram);
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Paralelogram &paralelogram){
        is >> paralelogram.pct_st_jos
        >>paralelogram.latura
        >>paralelogram.latura2
        >>paralelogram.pct_colt_op;
        return is;
    }

};

class Trapez : public Paralelogram{
    float baza2;
public:
    Trapez() = default;

    Trapez(const float &x,
           const float &y,
           const float &latura,
           const float &latura2,
           const float &x2,
           const float &y2,
           const float &baza2_
           ): Paralelogram(x,y,latura,latura2, x2, y2)
    {
        baza2 = baza2_;
    }

    Trapez(const Trapez &trapez):Patrat(
            trapez.pct_st_jos.getX(),
            trapez.pct_st_jos.getY(),
            trapez.latura
            ),
                                Paralelogram(trapez.pct_st_jos.getX(),
                                              trapez.pct_st_jos.getY(),
                                              trapez.latura,
                                              trapez.latura2,
                                              trapez.pct_colt_op.getX(),
                                              trapez.pct_colt_op.getY())
    {
        baza2 = trapez.baza2;
    }

    ~Trapez() = default;

//    float getBaza2() const {
//        return baza2;
//    }
//
//    void setBaza2(float baza2_) {
//        Trapez::baza2 = baza2_;
//    }
    Trapez& operator= (const Trapez &trpz){
        pct_st_jos = trpz.pct_st_jos;
        latura = trpz.latura;
        latura2 = trpz.latura2;
        pct_colt_op = trpz.pct_colt_op;
        baza2 = trpz.baza2;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Trapez &trapez) {
        os << static_cast<const Paralelogram &>(trapez) << " baza2: " << trapez.baza2;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Trapez &trapez){
        is >> trapez.pct_st_jos >> trapez.latura >> trapez.latura2 >> trapez.pct_colt_op >> trapez.baza2;
        return is;
    }

    bool operator==(const Trapez &rhs) const {
        return static_cast<const Paralelogram &>(*this) == static_cast<const Paralelogram &>(rhs) &&
               baza2 == rhs.baza2;
    }

    bool operator!=(const Trapez &rhs) const {
        return !(rhs == *this);
    }
};


int main(){
    Punct pct1(20, 10);
    std::cout<<pct1;
    Punct pct3;

    Patrat patr(20, 10, 5);
    Patrat patrat2 = patr;
    std::cout<<patr<<std::endl<<patrat2<<std::endl;
    std::cin>>patr;
    std::cout<<patr<<std::endl<<patrat2<<std::endl;
    Romb rmb(5,3,3,10,20);
    std::cout<<rmb.getPctColtOp();


//    pct3.actualizare(3,4);
//    std::cout<<pct3;
//

//    std::cout<<*pct2.x<<" "<<*pct2.y<<std::endl;
//    std::cout<<*pct1.x<<" "<<*pct1.y<<std::endl;
//    *pct2.x = 5;
//    std::cout<<*pct2.x<<" "<<*pct2.y<<std::endl;
//    std::cout<<*pct1.x<<" "<<*pct1.y<<std::endl;
//    pct3=pct1=pct2;
//    std::cout<<*pct3.x<<" "<<*pct3.y<<std::endl;
//    std::cout<<*pct2.x<<" "<<*pct2.y<<std::endl;
//    std::cout<<*pct1.x<<" "<<*pct1.y<<std::endl;
//    std::cout<<pct2<<std::endl<<pct1<<std::endl;
//    std::cin>>pct1>>pct2;
//    std::cout<<pct1<<std::endl<<pct2<<std::endl;
}

