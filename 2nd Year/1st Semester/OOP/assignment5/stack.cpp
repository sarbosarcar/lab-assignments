#include <iostream>
using namespace std;

class Error {
    const char *p;
    public:
        Error(const char *s):p(s) {}
        void disp() {
            cout << p << endl;
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
            if (top==size-1) throw Error("Overflow!");
            top++;
            a[top]=x;
            cout << "Pushed element!\n";
        }
        int pop() {
            if (top==-1) throw Error("Underflow!");
            int tmp = a[top--];
            return tmp;
        }
};

int main() {
    Stack s(3);
    int el[] = {1,3,4, 5, 10};
    try {
        for (int i=0; i<5; i++) {
            s.push(el[i]);
        }
    }
    catch (Error ob) {
        ob.disp();
    }
    try {
        for (int i=0; i<5; i++) {
            cout << s.pop() << endl;
        }
    }
    catch (Error ob) {
        ob.disp();
    }
}
