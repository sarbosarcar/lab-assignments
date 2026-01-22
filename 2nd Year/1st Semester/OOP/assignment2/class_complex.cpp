#include <iostream>
using namespace std;

class Complex {
	double real, imag;
	public: 
		Complex(double r=0, double i=0) {
			real =r;
			imag=i;
		}
		Complex(Complex &c) {
			real = c.getReal();
			imag = c.getImg();
		}
		void setReal(double r) {
			real = r;
		}
		void setImg(double i) {
			imag = i;
		}
		double getReal() {
			return real;
		}
		double getImg() {
			return imag;
		}
		void disp() {
			cout << real << " + " << imag << " i" << endl;
		}	
		Complex sum(Complex c) {
			Complex c2;
			c2.setReal(c.getReal()+real);
			c2.setImg(c.getImg() + imag);
			return c2;
		}
		
};
int main() {
	Complex c1(3, 5), c2(7, 9), c3;
	c3 = c1.sum(c2);
	c1.disp();
	c2.disp();
	cout << "Sum is: ";
	c3.disp();
}
