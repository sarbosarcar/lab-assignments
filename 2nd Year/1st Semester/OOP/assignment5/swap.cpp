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

class Stack {
    int *a, top, size;
    public:
        Stack(int p=0) {
            size=p;
            a = new int[size];
            top=-1;
        }
        void push(int x) {
            if (top==size-1) {cout << "Overflow!\n"; return;}
            top++;
            a[top]=x;
        }
        int pop() {
            if (top==-1) {cout << "Underflow!\n"; return -1;}
            int tmp = a[top--];
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

namespace ns {
template <class T>
void swap(T &x, T &y) {
    T tmp;
    tmp = x;
    x = y;
    y = tmp;
}

template <>
void swap(Stack &s1, Stack &s2) {
    int t1 = s1.get_top(), t2 = s2.get_top();
    Stack tmp(t1+1), tmp2(t2+1);
    for (int i=0; i<=t1; i++) {
        tmp.push(s1.pop());
    }
    for (int i=0; i<=t2; i++) {
        tmp2.push(s2.pop());
    }
    for (int i=0; i<=t1; i++) {
        s2.push(tmp.pop());
    }
    for (int i=0; i<=t2; i++) {
        s1.push(tmp2.pop());
    }
}
}

int main() {
    int a=1, b=10;
    Complex c1(2,5), c2(1,4);
    Stack s1(3), s2(3);
    int arr[] = {1,3,6};
    for (int i=0; i<3; i++) {
        s1.push(arr[i]);
        s2.push(arr[i]*2);
    }
    cout << "Before Swap: " << a << " & " << b << endl;
    ns::swap(a,b);
    cout << "After Swap: " << a << " & " << b << endl;
    
    cout << "Before Swap: (" << c1 << ") & (" << c2 << ")" << ")\n";
    ns::swap(c1,c2);
    cout << "After Swap: (" << c1 << ") & (" << c2 << ")" << ")\n";
    
    cout << "Before Swap: \n";
    cout << "Stack 1: ";
    s1.print();
    cout << "Stack 2: ";
    s2.print();
    ns::swap(s1,s2);
    cout << "After Swap: \n";
    cout << "Stack 1: ";
    s1.print();
    cout << "Stack 2: ";
    s2.print();
}

