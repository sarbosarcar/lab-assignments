#include <iostream>

using namespace std;

int fac(const int n) {
	if (n==1) return 1;
	else return n*fac(n-1);
}
int main() {
	int m;
	
	cout << "Enter the value of n: ";
	cin >> m;
	const int n = m;
	int f = fac(n);
	cout << n << "! = " << f <<endl;
}
