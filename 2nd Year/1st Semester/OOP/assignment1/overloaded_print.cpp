#include <iostream>
using namespace std;

void print(int v[], int n) {
	for (int i=0; i<n; i++) cout<<v[i]<<"  ";
	cout<<endl;
}
void print(int m[][4], int n) {
	for (int i=0; i<n; i++) {//assuming nxn matrix
		for (int j=0; j<n; j++) {
			cout <<m[i][j]<<"  ";
		}
		cout<<endl;
	}
}
int main() {
	int m[][4] = {{1, 3, 5, 7}, {2, 4, 6, 8}, {2, 3, 5, 7}, {1, 4, 9, 16}};
	cout<<"Printing matrix\n";
	print(m, 4);
	int v[] = {2, -4, 90, -5, 103};
	cout<<"Printing vector\n";
	print(v, 5);

}
