#include <iostream>
using namespace std;

class Sample {
    class Exc {
        const char *p;
        public:
        Exc(const char *x):p(x) {}
        void disp() {
            cout << p << endl;
        }
    };
    public:
    void fun1() {
        int a=10, b=0, c;
        try {
            if (b==0) throw Exc("Div by 0!");
            c=a/b;
            cout << c << endl;
        }
        catch(Exc ob) {
            ob.disp();
        }
    }
};
int main()
{
    Sample ob;
    ob.fun1();
}
