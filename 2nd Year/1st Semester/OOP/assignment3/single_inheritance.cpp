#include <iostream>
using namespace std;

class A {
	int a;
	public: 
		void set_a(int x) {
			a=x;
		}
		void disp() {
			cout << a << endl;
		}
};

class B : public A {
	int b;
	public: 
		void set_b(int y) { b=y; }
		void disp() { cout <<b << endl;}
};

int main() {
	B ob;
	ob.set_b(10);
	ob.disp();
}

