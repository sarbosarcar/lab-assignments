#include <iostream>

using namespace std;

class A {
	public:
		void disp1() {
			cout <<"from base A" << endl;
		}
};

class B {
	public:
		void disp2() {
			cout << "from base B" << endl;
		}

};
class C {
	public:
		void disp3() {
			cout <<"from base C" << endl;
		}
};

class D : virtual public A, virtual public B {
	public:
		void disp4() {
			disp1();
			disp2();
			cout << "from D" << endl;
		}

};


class E  : virtual public B, virtual public C {
	public:
 		void disp5() {
			disp2();
			disp3();
			cout << "from E" << endl;
		}
};

class F : public D, public E {
	public:
		void disp6() {
			disp4();
			disp5();
			cout << "from F" <<endl; 
		}
};

int main() {
	F ob;
	ob.disp6();
}
