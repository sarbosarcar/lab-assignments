#include <iostream>

using namespace std;

void swap(char** x, char** y) {
	char **z = x;
	x = y;
	y = z;
}

int main() {
	char x[100], y[100];
	cout<<"Enter string 1: ";
	cin >> x;
	cout<<"Enter string 2: ";
	cin >> y;
	swap(x, y);
	cout<<"After swapping,\nstring 1: "<<x<<" and string 2: "<<y<<endl;
}
