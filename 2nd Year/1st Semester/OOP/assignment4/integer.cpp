#include <iostream>

using namespace std;


class Integer {
	int a;
	public:
		Integer(int x=0):a(x) {}
		Integer operator++(int) {
			return Integer(a++);
		}
		operator int() {
			return a;
		}	
		friend ostream &operator<<(ostream &os, const Integer ob) {
			os << ob.a;
			return os;
		}	
};


int main() {
	Integer a=4, b=a, c;
	c=a+b++;
	int i=a;
	cout << a << b << c;
	return 0;
}
