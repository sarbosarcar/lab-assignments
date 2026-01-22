#include <iostream>
using namespace std;

class Vehicle {
    int dir;
    string state;
    public:
        Vehicle(int d=1, string st="running") {
            dir=d;
            state=st;
        }
        int get_dir() {return dir;}
        string get_state() {return state;}
};

class Lane {
    Vehicle *a;
    int size;
    int top;
    public:
        Lane(int s=0) {
            size=s;
            a=new Vehicle[size];
            top=-1;
        }
        void add(Vehicle v) {
            for (int i=0; i<=top; i++) {
                if (v.get_dir()!=a[i].get_dir() && v.get_state()=="running" && a[i].get_state()=="running")
                    throw "Collision may occur!";
            }
            a[++top]=v;
            cout << "Added a car!\n";
        }
};

int main() {
    Vehicle v1(1, "running");
    Vehicle v2(-1, "running");
    Lane l1(3);
    try {
        l1.add(v1);
        l1.add(v2);
    }
    catch (const char *ex) {
        cout << ex << endl;
    }
}
