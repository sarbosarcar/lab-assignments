#include <iostream>

using namespace std;

class Index;
class Integer {
	int a;
	public:
		Integer(int x=0):a(x) {}
		operator int() {return a;}
};

class Index {
	int a;
	public:
		Index(int x=0):a(x){}
		Index operator+(Index &ob) {
			return Index(a+ob.a);
		}
		operator int() {
			return a;
		}
		operator Integer() {
			return Integer(a);
		}
};


int main() {
	Index in(4), out(10);
	int x = in;
	int y = in + out;
	in = 2;
	Integer i;
	i = in;
	cout << i << endl;
}
