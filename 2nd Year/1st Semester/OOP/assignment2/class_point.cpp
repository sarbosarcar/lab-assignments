#include <iostream>
#include <cmath>

using namespace std;

class Point {
	double x, y, z;
	public:
		Point(int x=0, int y=0, int z=0) {
			this->x = x;
			this->y = y;
			this->z = z;
		}
		double get_x() {
			return x;
		}
		double get_y() {
			return y;
		}
		double get_z() {
			return z;
		}	
		
		double distance(Point p) {
			double dist = pow(pow(x-p.get_x(), 2)+pow(y-p.get_y(),2)+pow(z-p.get_z(), 2), 0.5);
			return dist;
		}
};
int main()  {
	Point a(1,2,3), b(2,3,4);
	cout << "Distance is " << a.distance(b) << " units" << endl;
}
			
		
