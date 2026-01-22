#include <iostream>
#include <cmath>

using namespace std;

class Point {
	double x,y;
	public:
		Point(double a=0, double b=0) {
			x=a;
			y=b;
		}
		double operator-(Point p) {
			double dist = sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));
			return dist;
		}
		~Point() {
			cout << "Point destroyed!" << endl;
		}
};	
int main()  {
	Point p1(0,10), p2(10,0);
	cout << "Distance between p1 and p2 is " << p1-p2 << endl;
}
