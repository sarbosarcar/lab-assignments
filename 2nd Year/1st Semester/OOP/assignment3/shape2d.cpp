#include <iostream>
#include <cstdlib>
#define PI 3.14
using namespace std;

class Shape2D {
	public:
		Shape2D() {
			cout << "Shape2D object created!" << endl;
		}
		virtual void area()=0;
		virtual void perimeter()=0;
};

class Circle : public Shape2D {
	double r;
	public:
		Circle(double rad=0) {
			r=rad;
		}
		void area() {
			cout << "Area of circle is: " << PI*r*r << endl;
		}
		void perimeter() {
			cout <<"Perimeter of the circle is: " << 2*PI*r << endl;
		}
};
class Rectangle : public Shape2D {
	double a, b;
	public:
 		Rectangle(double a=0, double b=0) {
			this->a = a;
			this->b= b;
		}
		void area() {
			cout << "Area of rectangle is:  " << a*b << endl;
		}
		void perimeter() {
			cout << "Perimeter of rectangle is: " << 2*(a+b) << endl;
		}
};
int main() {
	Shape2D *p[5];
	for (int i=0; i<3; i++) {
		p[i] = new Circle(rand()%(100));
	}
	for (int i=3; i<5; i++) {
		p[i] = new Rectangle(rand()%100, rand()%100);
	}
	for (int i=0; i<5; i++) {
		cout << "Shape " << i+1 << endl;
		p[i]->area();
		p[i]->perimeter();
	}
}
