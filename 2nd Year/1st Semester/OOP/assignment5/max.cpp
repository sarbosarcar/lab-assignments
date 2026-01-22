#include <iostream>
#include <cmath>
using namespace std;

class Complex {
    int re, im;
    public:
        Complex(double x=0, double y=0):re(x),im(y) {}
        operator int() {
            return sqrt(re*re + im*im);
        }
        friend ostream& operator<<(ostream &os, Complex o) {
            os<< o.re <<" + " << o.im << " i";
            return os;
        }
};

namespace ns {
template <class T>
T max(T x, T y) {
    return (x>y) ? x : y;
}

template <>
char *max(char *x, char *y) {
    int i=0;
    while (x[i] && y[i]) {
        if (x[i]>y[i]) 
            return x;
        i++;
    }
    return y;
}
}

int main() {
    int a=1, b=10;
    Complex c1(2,5), c2(1,4);
    cout << "Max of " << a << " & " << b << " is " << ns::max(a,b) << endl;
    cout << "Max of (" << c1 << ") & (" << c2 << ") is (" << ns::max(c1,c2) << ")\n";
    char p1[] = "A string", p2[] = "A spring";
    cout << "Max of [" << p1 << "] & [" << p2 << "] is [" << ns::max(p1,p2) << "]\n";
    
}

