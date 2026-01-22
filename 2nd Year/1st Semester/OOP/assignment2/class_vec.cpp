#include <iostream>
using namespace std;
#define n 5
class Vector {
	int a[n];
	public:
		Vector(int arr[]) {
			
			for (int i=0; i<n; i++) a[i] = arr[i];
		}
		Vector(Vector &v) {
			for (int i=0; i<n; i++) {
				a[i] = (v.get_a())[i];
			}
			
		}

	
		int* get_a() {
			return a;
		}
		void add(Vector v) {
			int *arr  = v.get_a();
			for (int i=0; i<n; i++) {
			
				 a[i] += arr[i];
			}
		}
		void sub(Vector v) {
			for (int i=0; i<n; i++) a[i] -= (v.get_a())[i];
		}	
		bool isEqual(Vector v) {
			for (int i=0; i<n; i++) if (a[i]!=(v.get_a())[i]) return false;
			return true;
		}	
		bool isGreater(Vector v) {
			for (int i=0; i<n; i++) if (a[i]<=(v.get_a())[i]) return false;
			return true;
		}	
		bool isLesser(Vector v) {
			for (int i=0; i<n; i++) if (a[i]>=(v.get_a())[i]) return false;
			return true;
		}
		void print() {
			cout <<endl;
			for (int i=0; i<n; i++) cout <<a[i] << "    ";	
			cout <<endl;
		}
		
};

int main() {
	int a[] = {1, 2, 3, 4, 5};
	int b[] = {2, 2, 3, 4, 7};
	Vector v1(a);
	Vector v2 = v1;
	v1.print();
	v2.print();
	v1.add(v2);
	cout << "After addition, v1 = ";
	v1.print();
	v1.sub(v2);
	cout << "After subtraction, v1 = ";
	v1.print();
	cout << "Checking for equality: ";
	if (v1.isEqual(v2)) cout << "Equal" << endl;
	else cout << "Not Equal" <<endl;
	if (!v1.isEqual(v2)) {
	if (v1.isGreater(v2)) cout <<"v1 is greater" << endl;	
	else cout<< "v2 is greater" << endl;
	if (v1.isLesser(v2)) cout <<" v1 is lesser " << endl;
	else cout << "v2 is lesser " << endl;
	}


}

