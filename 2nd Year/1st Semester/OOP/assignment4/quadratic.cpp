#include <iostream>
#include <cmath>

using namespace std;

class Complex {
	double x,y;
	public: 
		Complex(double a=0, double b=0) {
			x=a, y=b;
		}
		friend ostream& operator<<(ostream &os, const Complex ob) {
			if (ob.y) os << "(" <<  ob.x << ") + (" << ob.y << ") j" << endl;
			else os << "(" << ob.x << ")" << endl;
			return os;
		}
};

class Quadratic {
	double a,b,c;
	public:
		Quadratic(double x=0, double y=0, double z=0) {
			a=x;
			b=y;
			c=z;
		}	
		Quadratic operator+(Quadratic &q) {
			return Quadratic(q.a+a,q.b+b,q.c+c);
		}
		double evaluate(double x) {
			return a*x*x + b*x + c;
		}
		void root() {
			double disc = b*b - 4*a*c;
			if (disc<0) {
				Complex root1(-b,sqrt(disc)/(2*a));
				Complex root2(-b, - sqrt(disc)/(2*a));
				cout << "Root 1:" << root1;
				cout << "Root 2:" << root2;
			}
			else if (disc==0) {
				Complex root(-b/(2*a));
				cout << "Root is:" << root;
			}
			else {
				Complex root1((-b+sqrt(disc))/(2*a));	
				Complex root2((-b+sqrt(disc))/(2*a));
				cout << "Root 1:" << root1;
				cout << "Root 2:" << root2;
			}

		}			
friend ostream& operator<<(ostream &os, const Quadratic ob) {
	os << "(" << ob.a << ") x^2 + (" << ob.b << ") x + (" << ob.c << ")" << endl;
	return os;
}

friend istream& operator>>(istream& is, Quadratic &ob) {
	cout << "Enter a: ";
	is >> ob.a;
	cout << "Enter b: ";
	is >> ob.b;
	cout << "Enter c: ";
	is >> ob.c;
	return is;
}
};


int main() {
	Quadratic q1, q2;
	cin >> q1 >> q2;
	cout << q1+q2;
	cout << q1.evaluate(10);
	q1.root();
	q2.root();
	return 0;
}
	
