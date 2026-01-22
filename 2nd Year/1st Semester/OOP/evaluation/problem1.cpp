#include <iostream>
using namespace std;

class Complex {
	float real, imag;
	public:
		void setData(float r, float i);
 		friend Complex sum(Complex,Complex);
		void subtract(Complex);
		Complex multiply(Complex);
		void show();
};

void Complex::setData(float r, float i) {
	real=r;
	imag=i;
}

Complex sum(Complex c1, Complex c2) {
	Complex tmp;
	tmp.setData(c1.real+c2.real, c1.imag+c2.imag);
	return tmp;
}

void Complex::subtract(Complex c) {
	real -= c.real;
	imag -= c.imag;
}

Complex Complex::multiply(Complex c) {
	Complex tmp;
	tmp.setData(real*c.real-imag*c.imag, real*c.imag+imag*c.real);
	return tmp;
}

void Complex::show() {
	cout << "Number is: (" << real << ") + (" << imag << ")i " <<  endl;
} 
	

int main() {
	Complex c1, c2;
	float a,b;
	cout << "Enter values for c1: ";
	cin >> a >> b;
	c1.setData(a,b);
	cout << "Enter values for c2: ";
	cin >> a >> b;
	c2.setData(a,b);
	Complex c3 = sum(c1,c2);
	cout << "c1 is ";
	c1.show();
	cout << "c2 is ";
	c2.show();
	cout << "c3 is c1+c2: ";
	c3.show();
	c3.subtract(c1);
	cout << "After subtraction, c3=c3-c1: ";
	c3.show();
	Complex c4 = c1.multiply(c2);
	cout << "c4 = c1*c2: ";
	c4.show();
	return 0;
}
