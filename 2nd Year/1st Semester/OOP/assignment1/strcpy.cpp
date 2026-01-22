#include <iostream>

using namespace std;
	
void swap(char* x, const char* y) {
	*x = *y;
}
int main() {
	cout <<"Enter a string: ";
	char x[100], y[100];
	cin >> x;
	swap(y, x);
	cout << "After copying\ndestination: "<<y<<endl;
}
