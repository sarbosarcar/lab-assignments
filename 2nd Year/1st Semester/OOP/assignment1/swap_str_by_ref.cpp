#include <iostream>
using namespace std;

void swap(char** &x, char** &y) {
	char** z = x;
	x=y;
	y=z;
}
int main() {
	cout<<"Enter two strings: ";
	char x[100], y[100];
	cin >> x >> y;
	swap(x, y);
	cout <<"After swapping\nstring 1: "<<x<<" and string 2: "<<y<<endl;
}
