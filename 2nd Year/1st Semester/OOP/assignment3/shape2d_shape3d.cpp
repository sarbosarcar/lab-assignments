#include <iostream>
#include <cstdlib>

#define PI 3.14

using namespace std;

class Shape {
	public:
		Shape() {
			cout << "Shape created!" << endl;
		}
		virtual void disp()=0;
};
class TwoDShape : public Shape {
	public:
 		TwoDShape() {
			cout << "TwoDShape created!" << endl;
		}
		virtual void getArea()=0;
};
class ThreeDShape : public Shape {
	public:
 		ThreeDShape() {
			cout << "ThreeDShape created!" << endl;
		}
		virtual void getArea()=0;
		virtual void getVolume()=0;
};
class Circle : public TwoDShape {
	double r;
	public:
		Circle(double rad) {
			r=rad;	
		}
		void name() {
			cout << "This is a circle with radius " << r << endl;
		}
		void getArea() {
			cout << "Area is " << PI*r*r << endl;
		}
		void disp() {
			name();
			getArea();
		}	
};
class Triangle : public TwoDShape {
	double b,h;
	public:
		Triangle(double b, double h) {
			this->b=b;
			this->h = h;
		}
		void name() {
			cout << "This is a triangle with base " << b << "and height " << h  << endl;
		}
		void getArea() {
			cout << "Area is " << (0.5) * b * h << endl;
		}	
		void disp() {
			name();
			getArea();
		}
};
class Ellipse : public TwoDShape {
	double a,b;
	public:
		Ellipse(double d, double h) {
			a=d;
			b=h;
		}
		void name() {
			cout << "This is an ellipse with major axis " << a << "and minor axis " << b  << endl;
		}
		void getArea() {
			cout << "Area is " << PI * b * a << endl;
		}
		void disp() {
			name();
			getArea();
		}
};
class Cube : public ThreeDShape { 
	double a;
	public: 
		Cube(double a) {
			this->a=a;
		}
		void name() {
			cout << "This is a cube with side " <<a<<endl;
		}
		void getArea() {
			cout << "Area is " << a*a*6 <<endl;
		}
		void getVolume() {
			cout << "Area is " << a*a*a << endl;
		}
		void disp() {
			name();
			getArea();
			getVolume();
		}
};		
class Sphere : public ThreeDShape { 
	double a;
	public: 
		Sphere(double a) {
			this->a=a;
		}
		void name() {
			cout << "This is a sphere with radius " <<a<<endl;
		}
		void getArea() {
			cout << "Area is " << a*a*4*PI <<endl;
		}
		void getVolume() {
			cout << "Area is " << a*a*a*(4/3)*PI << endl;
		}
		void disp() {
			name();
			getArea();
			getVolume();
		}
};

int main() {
	Shape *p[5];
	p[0] = new Circle(10);
	p[1] = new Triangle(3.5, 5);
	p[2] = new Ellipse(4, 9);
	p[3] = new Sphere(15);
	p[4] = new Cube(14.6);
	for (int i=0; i<5; i++ ){	
		p[i]->disp();
	}
}	

			
