#include <iostream>

using namespace std;

class B1 {
	public:
		void disp1() {
			cout <<"from base 1" << endl;
		}
};

class B2 {
	public:
		void disp2() {
			cout << "fom base 2" << endl;
		}

};

class D : public B1, public B2 {
	public:
		void disp() {
			disp1();
			disp2();
			cout << "from derived class" <<endl; 
		}
};

int main() {
	D ob;
	ob.disp();
}
