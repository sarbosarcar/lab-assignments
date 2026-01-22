#include <iostream>
#include <cmath>

using namespace std;

class Rect {
	double x, y;
	public:
		Rect(int x=0, int y=0) {
			this->x = x;
			this->y = y;
		}
		double get_x() {
			return x;
		}
		double get_y() {
			return y;
		}
		
		double area() {
			return x*y;
		}
};
int main()  {
	Rect r1(3,4), r2(5, 10), r3(23.5, 9), r4(10, 10);
	cout << "Area of r1 is " << r1.area() << ", r2 is " << r2.area() << ", r3 is " << r3.area() << ", and r4 is " << r4.area() << " sq. units respectively" << endl;
}
			
		
