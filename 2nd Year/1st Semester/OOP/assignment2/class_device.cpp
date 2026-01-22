#include <iostream>
#include <cmath>
#include <cstdlib>

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
class Device {
	Point loc;
	static int id;
	int uid;
	double range;
	public:
		Device() {
			Point l;
			double r = 0;
			loc=l;
			range=r;
		}
		Device(Point l, double r) {
			loc = l;
			range = r;
			
			uid = id;
			id++;
		}
		double get_range() {
			return range;
		}
		int get_id() {
			return uid;
		}
		Point get_loc() {
			return loc;
		}
		
        	bool isNeighbour(Device d2) {
			double d = loc.distance(d2.get_loc());
			if (range>=d) return true;
			else return false;
		}
		void set_loc(Point l) {
			loc = l;
		}
	                                   

};
int Device::id=1;

int main()  {
	srand(time(NULL));
	Device d[10];
	for (int i=0; i<10; i++) {
 		Point loc(rand()%100, rand()%100, rand()%100);
		Device dev(loc, rand()%100);
		d[i] = dev;
	}
	for (int i=0; i<10; i++) {
		Device d1 = d[i];
		cout << d1.get_id() << " has the following neightbours: "<<endl;
		for (int j=0; j<10 && j!=i; j++) {
			Device d2 = d[j];
			if (d1.isNeighbour(d2)) cout << d2.get_id() << "    ";
		}
		cout <<endl;
	}
	cout << "After modifying locations, the new neightbours are: " <<endl;
	for (int i=0; i<10; i++) {
		Point p(rand()%100, rand()%100, rand()%100);
		d[i].set_loc(p);
	}
	for (int i=0; i<10; i++) {	
		Device d1 = d[i];
		cout << d1.get_id() << " has the following neightbours: "<<endl;
		for (int j=0; j<10 && j!=i; j++) {
			Device d2 = d[j];
			if (d1.isNeighbour(d2)) cout << d2.get_id() << "    ";
		}
		cout <<endl;	
	}





	
}
			
		
