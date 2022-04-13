#include <iostream>
#include <vector>
#include <memory>
#include <string>
//#include <typeinfo>

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
        o<<" ";
        return o;
    }

    friend std::istream& operator>> (std::istream& i, Patrat &patrat_){
        i>>patrat_.pct_st_jos >>patrat_.latura;
        return i;
    }
/*
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
*/
    bool operator==(const Patrat &rhs) const {
        return pct_st_jos == rhs.pct_st_jos &&
               latura == rhs.latura;
    }

    bool operator!=(const Patrat &rhs) const {
        return !(rhs == *this);
    }

    virtual float arie () {
        return latura*latura;
    };
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
    virtual float arie() override{
        return latura*latura2;
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


//    Punct getPctColtOp() const {
//        return pct_colt_op;
//    }

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
    virtual float arie() override{
        return latura * (pct_colt_op.getY()-pct_st_jos.getY());
    }
};

class Paralelogram : public Dreptunghi, public Romb{
public:
    Paralelogram() = default;

            Paralelogram(

    const float &x_,
    const float &y_,
    const float &latura_,
    const float &latura2_,
    const float &x2_,
    const float &y2_
    )
    {
                pct_st_jos.actualizare(x_,y_);
                latura = latura_;
                latura2=latura2_;
                pct_colt_op.actualizare(x2_,y2_);
            }

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

    friend std::ostream &operator<<(std::ostream &os, const Paralelogram &para) {
        os << para.pct_st_jos<<" "<<para.latura<<" "<<para.latura2<<" "<<para.pct_colt_op;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Paralelogram &paralelogram){
        is >> paralelogram.pct_st_jos
        >>paralelogram.latura
        >>paralelogram.latura2
        >>paralelogram.pct_colt_op;
        return is;
    }
    virtual float arie() override{
        return latura * (pct_st_jos.getY()-pct_colt_op.getY());
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
        os << static_cast<const Paralelogram &>(trapez) << " "<< trapez.baza2;
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
    virtual float arie() override{
        return (latura+baza2)/2 * (pct_st_jos.getY()-pct_colt_op.getY());
    }
};

class Shapes {
    static std::vector<std::shared_ptr<Patrat>> shapes;
public:
    static void addShape (const std::shared_ptr<Patrat> &shp){
        shapes.push_back(shp);
    }
    static std::vector<std::shared_ptr<Patrat>> getShapes(){
        return shapes;
    }
        static void deleteShape (int i){
        shapes.erase(shapes.begin()+i);
    }
    static float showArea(int index){
        return shapes[index]->arie();
    }

    static void showShapes(const std::string &type){
        for (int i = 0; i < static_cast<int>(getShapes().size()); i++){

            auto d1 = std::dynamic_pointer_cast<Trapez>(shapes[i]);
            if(d1!= nullptr){
                if(type == typeid(Trapez).name())
                {
                    std::cout<<"Trapez: "<< *d1<<"\n";
                    continue;
                }
                else continue;
            }
            auto d2 = std::dynamic_pointer_cast<Paralelogram>(shapes[i]);
            if(d2!= nullptr){
                if(type == typeid(Paralelogram).name())
                {
                    std::cout<<"Paralelogram: "<< *d2<<"\n";
                    continue;
                }
                else continue;
            }
            auto d3 = std::dynamic_pointer_cast<Romb>(shapes[i]);
            if(d3!=nullptr){
                if(type == typeid(Romb).name())
                 {
                    std::cout<<"Romb: "<< *d3<<"\n";
                    continue;
                }
                else continue;
            }

            auto d4 = std::dynamic_pointer_cast<Dreptunghi>(shapes[i]);
            if(d4!=nullptr){
                if(type == typeid(Dreptunghi).name())
                 {
                    std::cout<<"Dreptunghi: "<< *d4<<"\n";
                    continue;
                }
                else continue;
            }

            auto d5 = std::dynamic_pointer_cast<Patrat>(shapes[i]);
            if(d5!=nullptr) {
                if(type == typeid(Patrat).name())
                {
                    std::cout<<"Patrat: "<< *d5<<"\n";
                    continue;
                }
                else continue;
            }

            }
        }
        static void showAllShapes(){
        for (int i = 0; i < static_cast <int> (shapes.size()); i++ ){
            std::cout<<i<<": ";
            auto d5 = std::dynamic_pointer_cast<Trapez>(shapes[i]);
            if(d5 != nullptr){
                std::cout << "trapez: " << *d5 << "\n";
                continue;
            }
            auto d4 = std::dynamic_pointer_cast<Paralelogram>(shapes[i]);
            if(d4 != nullptr){
                std::cout << "paralelogram: " << *d4 << "\n";
                continue;
            }
            auto d3 = std::dynamic_pointer_cast<Romb>(shapes[i]);
            if(d3!= nullptr){
                std::cout << "romb: " << *d3 << "\n";
                continue;
            }

            auto d2 = std::dynamic_pointer_cast<Dreptunghi>(shapes[i]);
            if (d2 != nullptr){
                std::cout << "dreptunghi: " << *d2 << "\n";
                continue;
            }
            auto d1 = dynamic_pointer_cast<Patrat>(shapes[i]);
            if(d1!= nullptr) {
                std::cout << "patrat: " << *d1<< "\n";
                continue;
            }

        }
    }
};

std::vector <std::shared_ptr<Patrat>> Shapes::shapes;

/*
//class Shapes{
//    static std::vector<Patrat*> shapes;
//public:
//    static void addShape (Patrat &patrat){
//        shapes.push_back(&patrat);
//    }
//    static void deleteShape (int i){
//        shapes.erase(shapes.begin()+i);
//    }
//    static void showShapes(std::string type){
//        for (int i = 0; i < static_cast <int> (shapes.size()); i++ ){
//
//            if(type == typeid(Patrat).name()){
//                Patrat *d = dynamic_cast<Patrat*>(shapes[i]);
//                if(d!= nullptr) {
//                    std::cout << "patrat: " << *d << "\n";
//                }
//            }
//            if(type == typeid(Dreptunghi).name()) {
//                Dreptunghi *d = dynamic_cast<Dreptunghi *>(shapes[i]);
//                if (d != nullptr){
//                std::cout << "dreptunghi: " << *d << "\n";
//               }
//            }
//            if(type == typeid(Romb).name()) {
//                Romb *d = dynamic_cast<Romb *>(shapes[i]);
//                if(d!= nullptr){
//                std::cout << "romb: " << *d << "\n";
//                }
//            }
//            if(type == typeid(Paralelogram).name()) {
//                Paralelogram *d = dynamic_cast<Paralelogram *>(shapes[i]);
//                if(d != nullptr){
//                std::cout << "paralelogram: " << *d << "\n";
//                }
//            }
//            if(type == typeid(Trapez).name()) {
//                Trapez *d = dynamic_cast<Trapez *>(shapes[i]);
//                if(d != nullptr){
//                std::cout << "trapez: " << *d << "\n";
//                }
//            }
//        }
//    }
//
//    static void showAllShapes(){
//        for (int i = 0; i < static_cast <int> (shapes.size()); i++ ){
//            std::cout<<i<<": ";
//            Trapez *d5 = dynamic_cast<Trapez *>(shapes[i]);
//            if(d5 != nullptr){
//                std::cout << "trapez: " << *d5 << "\n";
//                continue;
//            }
//            Paralelogram *d4 = dynamic_cast<Paralelogram *>(shapes[i]);
//            if(d4 != nullptr){
//                std::cout << "paralelogram: " << *d4 << "\n";
//                continue;
//            }
//            Romb *d3 = dynamic_cast<Romb *>(shapes[i]);
//            if(d3!= nullptr){
//                std::cout << "romb: " << *d3 << "\n";
//                continue;
//            }
//
//            Dreptunghi *d2 = dynamic_cast<Dreptunghi *>(shapes[i]);
//            if (d2 != nullptr){
//                std::cout << "dreptunghi: " << *d2 << "\n";
//                continue;
//            }
//            Patrat *d1 = dynamic_cast<Patrat*>(shapes[i]);
//            if(d1!= nullptr) {
//                std::cout << "patrat: " << *d1<< "\n";
//                continue;
//            }
//
//        }
//    }
//};
//
//std:: vector <Patrat*> Shapes::shapes;
 */

class noOption : public std::exception{
public:
    noOption()=default;
//    const char* what() const noexcept override{
//        return "Nu exista optiunea!";
//    }
};
class Menu{
    int option = -1, index = 0;
public:
    void showMenu(){
        std::cout<<"Alege optiunea pe care o doresti:\n"
        <<"1.Adauga o forma\n"
        <<"2.Sterge o forma\n"
        <<"3.Arata toate formele\n"
        <<"4.Arata formele de un anumit tip\n"
        <<"5.Calculeaza aria unei forme\n"
        <<"0.Iesire din program\n"
        <<"Numar optiune: ";
        try{std::cin>>option;
        if(option<0||option>5) throw noOption();}
        catch (...){
            std::cout<<"Introdu un numar valid\n";
        }
        std::cout<<"-----------------------------------------------\n";
    }
    void showAvailableShapes(){
        std::cout<<"Ce forma doresti?\n"
        <<"1.Patrat\n"
        <<"2.Dreptunghi\n"
        <<"3.Romb\n"
        <<"4.Paralelogram\n"
        <<"5.Trapez\n"
        <<"Numar forma:";
        std::cin>>index;
        std::cout<<"-----------------------------------------------\n";
    }
    void showIndexQuestion(){
        std::cout<<"Da indexul formei:\n";
        std::cin>>index;
    }

    void addShape(){
    showAvailableShapes();
        if (index==1){
            float x, y, z;
            std::cout<<"Da x si y punct si dimensiunea laturii:\n";
            std::cin>>x>>y>>z;
            auto p = std::make_shared<Patrat>(Patrat(x,y,z));
            Shapes::addShape(p);}

        if (index==2){
            float x, y, z, w;
            std::cout<<"Da x si y punct si dimensiunile laturilor 1 si 2\n";
            std::cin>>x>>y>>z>>w;
            auto p = std::make_shared<Dreptunghi>(Dreptunghi(x,y,z,w));
            Shapes::addShape(p);
        }
        if (index==3){
            float x, y, z, w, u;
            std::cout<<"Da x si y punct si dimensiunea laturii si x si y pentru punctul opus\n";
            std::cin>>x>>y>>z>>w>>u;
            auto p = std::make_shared<Romb>(Romb(x,y,z,w,u));
            Shapes::addShape(p);
        }
        if (index==4){
            float x, y, z, w, u, r;
            std::cout<<"Da x si y punct, dimensiunea laturii1 si laturii2 si x si y pentru punctul opus\n";
            std::cin>>x>>y>>z>>w>>u>>r;
            auto p = std::make_shared<Paralelogram>(Paralelogram(x,y,z,w,u,r));
            Shapes::addShape(p);
        }
        if(index==5){
            float x, y, z, w, u, r, t;
            std::cout<<"Da x si y punct, dimensiunea laturii1 si laturii2 si x si y pentru punctul opus si baza a 2 a\n";
            std::cin>>x>>y>>z>>w>>u>>r>>t;
            Trapez trpz(x,y,z,w,u,r,t);
            auto p = std::make_shared<Trapez>(x,y,z,w,u,r,t);
            Shapes::addShape(p);
        }
    }

    void deleteShape(){
        showIndexQuestion();
        Shapes::deleteShape(index);
    }
    void showShape(){
        showAvailableShapes();
        if(index==1){
            Shapes::showShapes(typeid(Patrat).name());
        }
        if(index==2){
            Shapes::showShapes(typeid(Dreptunghi).name());
        }
        if(index==3){
            Shapes::showShapes(typeid(Romb).name());
        }
        if(index==4){
            Shapes::showShapes(typeid(Paralelogram).name());
        }
        if(index==5){
            Shapes::showShapes(typeid(Trapez).name());
        }
        std::cout<<"-----------------------------------------------\n";
    }

    void showArea(){
        showIndexQuestion();
        std::cout<<"Aria este: "<<Shapes::showArea(index)<<"\n"
        <<"--------------------------------------------------"<<"\n";

    }

    void runMenu(){
        while(option!=0){
            showMenu();
            if(option == 1){
                addShape();
            }
            if(option == 2){
                deleteShape();
            }
            if(option == 3){
                Shapes::showAllShapes();
                std::cout<<"-----------------------------------------------\n";
            }
            if(option == 4){
                showShape();
            }
            if(option == 5){
                showArea();
            }

        }
    }
};

int main(){

//    auto patrat = std::make_shared<Patrat>(3, 5, 4);
//    auto drept = std::make_shared<Dreptunghi>(3, 5, 6, 5);
//    auto trpz = std::make_shared<Trapez>(1,2,3,4,5,6,7);
//    auto patrat = std::make_shared<Patrat>(1,2,3);
//    auto romb = std::make_shared<Romb>(1,2,3,46,6);
//    auto drpt = std::make_shared<Dreptunghi>(1,2,3,4);
//    auto prlg =std::make_shared<Paralelogram>(1,2,3,4,5,6);
//    Shapes::addShape(patrat);
//    Shapes::addShape(drpt);
//    Shapes::addShape(romb);
//    Shapes::addShape(trpz);
//    Shapes::addShape(prlg);
//    Shapes::showAllShapes();
//    Paralelogram pr(1, 2, 3, 4 ,5, 8);
//    std::cout<<pr;
////Patrat patrat (3,4,5);
////Patrat patrat2 (10, 20, 30);
////Dreptunghi drept (7, 8, 9, 10);
//    Shapes::addShape(patrat);
//    Shapes::addShape(drept);
//    Shapes::showAllShapes();
//    Shapes::deleteShape(1);

    Menu meniu;
    meniu.Menu::runMenu();




////    Shapes::showShapes(typeid(Dreptunghi).name());
//    std::cout<<"-----------------------"<<std::endl;
//    Shapes::showAllShapes();
    return 0;
//    Punct pct1(20, 10);
//    std::cout<<pct1;
//    Punct pct3;
//
//    Patrat patr(20, 10, 5);
//    Patrat patrat2 = patr;
//    std::cout<<patr<<std::endl<<patrat2<<std::endl;
//    std::cin>>patr;
//    std::cout<<patr<<std::endl<<patrat2<<std::endl;
//    Romb rmb(5,3,3,10,20);
//    std::cout<<rmb.getPctColtOp();


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

