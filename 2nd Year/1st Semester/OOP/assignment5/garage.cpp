#include <iostream>
using namespace std;

class Motor {
    int m;
    public:
        Motor(int i=0) {
            if (i<0) throw "Motor Initialization Failed!\n";
            m=i;
        }
};

class Car {
    int c;
    public:
        Car(int y=0) {
            try {
                Motor m_ob(y);
            }
            catch (const char *ex) {
                throw ex;
            }
            c=y;
        }
};

class Garage {
  int g;
  public:
    Garage(int z=0) 
        try {
            Car c_ob(z);
        }
        catch (const char *ex) {
            throw "An Exception Occurred\n";
        }
};

int main() {
    try {
        Garage ob(-1);
    }
    catch (const char *ex) {
        cout << ex;
    }
    
}
