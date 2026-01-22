#include <iostream>

using namespace std;

class Complex {
	double a, b;
	public:
		Complex (double x=0, double y=0) {
			a=x;
			b=y;
		}
		Complex operator+(Complex c) {
			return Complex(a+c.a, b+c.b);
		}
		Complex operator-(Complex c) {
			return Complex(a-c.a, b-c.b);
		}
		Complex operator*(Complex c) {
			return Complex(a*c.a-b*c.b, a*c.b+b*c.a);
		}
		Complex operator/(Complex c) {
			return Complex((a*c.a + b*c.b)/(c.a*c.a+c.b*c.b), (b*c.a-a*c.b)/(c.a*c.a+c.b*c.b));
		}
		Complex& operator=(Complex c) {
			a=c.a;
			b=c.b;
		}
		void disp() {
			cout<< a << " + " << b << " i" << endl;
		}
};
int main() 
{
Complex c1(2,3), c2(3,5), c3;
c3=c1+c2;
cout << "c1 + c2 = ";
c3.disp();
c3=c1-c2;
cout << "c1 - c2 = ";
c3.disp();
c3=c1*c2;
cout << "c1 * c2 = ";
c3.disp();
c3=c1/c2;
cout << "c1 / c2 = ";
c3.disp();
}

