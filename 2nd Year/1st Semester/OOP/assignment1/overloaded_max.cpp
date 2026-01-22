#include <iostream>

using namespace std;


void max(int a, int b, int c) {
	int max = ((a>b) ? ((a>c) ? a : c)  : ((b>c) ? b : c));
	cout << "Max of "<<a<<", "<<b<<", "<<c<<" is " <<max<<endl;
}
void max (int a[], int n) {
	int max = a[0];
	cout<<"Array is\n";
	for (int i=0; i<n; i++) {if (a[i]>max) max = a[i]; cout<<a[i]<<"\t";}
	
	cout << "\nMax is " <<max<<endl;
}
int main() {
	int arr[] = {1,2,3,100,-8,10};
	int a=0, b=-4, c=2;
	cout << "Max among integers\n";
	max(a,b,c);
	cout<<"Max of the array\n";
	max(arr, 6);
}

	
