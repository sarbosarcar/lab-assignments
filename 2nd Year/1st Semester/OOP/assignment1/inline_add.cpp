#include <iostream>
using namespace std;

inline void add(int x, int y, int z) {
	cout <<"Sum is "<< x+y+z<<endl;
}

int main() {
	int x,y,z;
	cout<<"Enter three numbers: ";
	cin >> x>>y>>z;
	add(x,y,z);
}
