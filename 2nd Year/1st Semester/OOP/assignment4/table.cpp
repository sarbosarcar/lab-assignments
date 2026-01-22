#include <iostream>

using namespace std;
	

class Table {
	int a,b;
	int **arr;
	public:
		Table(int x=0, int y=0):a(x),b(y){
			arr=new int*[a];
			for (int i=0; i<b; i++) arr[i] = new int[b];
		}
		friend istream &operator>>(istream &is, Table t) {
			for (int i=0; i<t.a; i++) {
				for (int j=0; j<t.b; j++) {
					cout << "Enter element " << i << ", " << j << ": ";
					is >> t[i][j];
				}
			}
			
			return is;
		}
		int *operator[](int i) {
			return arr[i];
		}
		friend ostream &operator<<(ostream &os, Table t) {
			for (int i=0; i<t.a; i++) {
				for (int j=0; j<t.b; j++) {
					os << t[i][j] << "     ";
				}
				os << endl;
			}	
			return os;
		}
};

int main() {
	Table t(4,5), t1(4,5);
	cin >> t;
	t[0][0] = 5;
	int x = t[2][3];
	t1 = t;
	cout << t << endl << t1;
}
