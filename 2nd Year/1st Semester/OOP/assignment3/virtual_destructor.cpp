#include <iostream>
using namespace std;

class B {
	public:
		B() {
			cout << "B constr" << endl;
		}
		virtual ~B() {
			cout << "B destr" << endl;
		}
};
class C : public B {
	public:
		C() {
			cout << "C constr" << endl;
		}
		~C() {	
			cout << "C destr" << endl;
		}
};

int main() {
	B *ptr = new C();
	delete ptr;
}
		
