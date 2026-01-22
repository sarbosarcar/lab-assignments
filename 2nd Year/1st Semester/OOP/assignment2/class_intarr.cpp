#include <iostream>
using namespace std;
#define n 3
class IntArray {
	int a[n];
	public:
		IntArray(int arr[]) {
			
			for (int i=0; i<n; i++) a[i] = arr[i];
		}
		IntArray(IntArray &v) {
			for (int i=0; i<n; i++) {
				a[i] = (v.get_a())[i];
			}
			
		}

	
		int* get_a() {
			return a;
		}
		void add(IntArray v) {
			int *arr  = v.get_a();
			for (int i=0; i<n; i++) {
			
				 a[i] += arr[i];
			}
		}
		void reverse() {
			for (int i=0; i<n/2; i++) {
				int tmp = a[i];
				a[i] = a[n-i-1];
				a[n-i-1]  = tmp;
			}
		}
		void sort() {
			for (int i=0; i<n; i++) {
				bool flag = false;
				for (int j=0; j<n-i-1; j++) {
					if (a[j]>a[j+1]) {
						int t = a[j];
						a[j] = a[j+1];
						a[j+1] = t;
						flag  = true;
					}
				} 
				if (!flag) break;
			}
		}		
			
		void print() {
			cout <<endl;
			for (int i=0; i<n; i++) cout <<a[i] << "    ";	
			cout <<endl;
		}
		
};

int main() {
	int a[] = {1, 2, 3};
	IntArray arr(a);
	cout << "obj 1: ";
	arr.print();
	IntArray arr2 = arr;
	cout << "obj 2: ";
	arr2.print();
	arr2.reverse();
	cout << "obj 1: ";
	arr.print();
        cout << "obj 2: ";
	arr2.print();
}

