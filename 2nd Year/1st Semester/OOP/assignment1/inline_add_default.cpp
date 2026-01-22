#include <iostream>
using namespace std;

inline void add(int x, int y=0, int z=0) {
	cout <<"Sum is "<< x+y+z<<endl;
}

int main() {
	int x,y,z;
	cout<<"Enter three numbers: ";
	cin >> x>>y>>z;
	cout<<"Calling with one argument\n";
	add(x);
	cout<<"Calling with two arguments\n";
	add(x,y);
	cout<<"Calling with three arguments\n";
	add(x,y,z);
}
