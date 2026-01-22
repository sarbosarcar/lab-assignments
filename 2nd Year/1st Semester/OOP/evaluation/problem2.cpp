#include <iostream>
using namespace std;

int sum(int x, int y) {
	cout << "int sum called\n";
	return x+y;
}

double sum(double x, double y) {
	cout << "double sum called\n";
	return x+y;
}

class B {
	public:
		virtual void show() {
			cout << "B Show!" << endl;
		}
};

class C:public B {
	public:
		void show() {
			cout << "C Show!" << endl;
		}
};

int main() {
	cout << "\t\tEARLY BINDING: Compile Time Polymorphism\n\n";
	cout << "calling sum(2,5)\n";
	int a=2, b=5;
	int s1=sum(a,b);
	cout << "\nSum is: " << s1;
	cout << "\ncalling sum(4.5,6.34)\n";
	double x=4.5, y=6.34;
	double s2=sum(x,y);
	cout << "Sum is: " << s2;
	
	cout << "\n\t\tLATE BINDING: Run Time Polymorphism\n\n";
	
B *p = new C();
cout << "Instantiated a C class object with B class pointer and C inherits from B. Then show() is called\n";
	p->show();	
	
	return 0;
}
