#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}
int main() {
	cout<< "Enter the value of a and b: ";
	int a, b;
	cin >> a >> b;
	cout << "a: "<<a<<", b: "<<b;
	swap(a, b);
	cout<<"\nAfter swapping, \n a: "<<a<<", b: "<<b<<endl;
}

