#include <iostream>

using namespace std;

class IntArray {
	int a;
	int *arr;
	public:
		IntArray(int x):a(x) { arr = new int[a];}
		int &operator[] (int i) {
			//if (i>=a) return -1;
			return arr[i];
		}
		friend ostream& operator<<(ostream &os, const IntArray ob) {
			for (int i=0; i<ob.a; i++) os << ob.arr[i] << "    ";
			os << endl;
			return os;
		}
		
};

int main() {
	IntArray i(10);
	for (int k=0; k<10; k++) 
		i[k] = k;
	cout << i;
	return 0;
}

		
