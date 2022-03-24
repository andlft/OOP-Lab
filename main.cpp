
#include <iostream>
using namespace std;

class Car{
    int speed;
public:
    Car(int speed_){
        speed = speed_;
    }

    int getSpeed() const{
        cout<<speed<<endl;
        return speed ;
    }
};

class Dacia : public Car{
public:
    Dacia(int speed_):Car(speed_){}
};

class Toyota : public Car{
public:
    Toyota(int speed_):Car(speed_){}
};

class Renault : public Car{
public:
    Renault(int speed_):Car(speed_){}
};

class Circuit{
    Car ** masina;



};

int main()
{
    Dacia masina(50);
    Toyota masina2(40);
    Renault masina3 (60);
    masina.getSpeed();
    masina2.getSpeed();
    masina3.getSpeed();

    return 0;

};


