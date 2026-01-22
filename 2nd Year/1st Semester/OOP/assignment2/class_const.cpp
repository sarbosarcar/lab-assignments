#include <iostream>
using namespace std;
	

class A {
	mutable int a;
	const int b;
	int c=20;
	public:
		A(int x=0, int y=0):b(y) {
			a = x;
			cout << "Initialised object and set the const variable to " << b << endl;
		}
		void f1() const {
			a = 1000;
			cout << "Modified mutable int fom const function" <<  endl;
		}
		void f2() {
			a=2000;
			c=5000;	
			cout << "Modified mutable and non mutable int from non const function" << endl;
		}
			
};

int main() {
	A o1(3,4);
	o1.f1();
	o1.f2();
}
