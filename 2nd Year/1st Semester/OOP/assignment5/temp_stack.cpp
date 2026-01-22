#include <iostream>
#include <cmath>
using namespace std;

class Complex {
    int re, im;
    public:
        Complex(double x=0, double y=0):re(x),im(y) {}
        friend ostream& operator<<(ostream &os, Complex o) {
            os<< o.re <<" + " << o.im << " i";
            return os;
        }
};

template <class T=int>
class Stack {
    T *a;
    int top, size;
    public:
        Stack(int p=0) {
            size=p;
            a = new T[size];
            top=-1;
        }
        void push(T x) {
            if (top==size-1) {cout << "Overflow!\n"; return;}
            top++;
            a[top]=x;
        }
        T pop() {
            if (top==-1) {cout << "Underflow!\n"; return -1;}
            T tmp = a[top--];
            return tmp;
        }
        int get_top() {
            return top;
        }
        void print() {
            for (int i=0; i<=top; i++ ) cout << a[i] << "\t";
            cout << "\n";
        }
};

int main() {
    Stack<int> s1(3); Stack<Complex> s2(3);
    int arr[3][2] = {{1,2}, {2,4}, {5,9}};
    for (int i=0; i<3; i++) {
        s1.push(arr[i][0] + arr[i][1]);
        s2.push(Complex(arr[i][0], arr[i][1]));
    }
    cout << "Popped from s1: " << s1.pop();
    cout << "\nPopped from s2: " << s2.pop();
    cout << "\ns1: "; s1.print();
    cout << "s2: "; s2.print();
}

