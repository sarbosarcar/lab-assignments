#include <iostream>


using namespace std;

class INT {
	int i;
	public:
		INT(int a):i(a){}
		INT operator++() {
			return INT(++i);
		}
		INT operator++(int) {
			return INT(i++);
		}
		~INT() {}
		operator int() {
			return i;
		}
};
int main() {
	int x=3;
	INT y=x;
	y++ = ++y;
	x=y;
	cout << x << endl;
	return 0;
}
