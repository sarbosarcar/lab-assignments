
/*
 * . Implement the classes for the following inheritance hierarchies.
 * Create an interface “Shape” that contains methods ‘area’, ‘draw’, ‘rotate’, ‘move’ etc. Now create
 * two classes “Circle” and “Rectangle” that implement this ‘Shape’ interface and implement the
 * methods ‘area’, ‘move’, etc. Write a main() function to create two “Circle” and three “Rectangle”,
 * then move them. Print the details of circles and rectangles before after moving them.
 * 15. Imagine a toll booth and a bridge. Cars passing by the booth are expected to pay
 */

interface Shape {/*
	double rotation=0;
	double position=0;*/
	double area();
	void draw(double d1, double d2);
	void rotate(double r);
	void move(double m);
}

class Circle implements Shape {
	double rotation=0, position=0, radius=0;
	Circle(double r, double x, double ro) {
		radius = r;
		position = x;
		rotation = ro;
	}
	public double area() {
		return (3.14*radius*radius);
	}
	public void draw(double d) {
		radius = d;
	}
	public void draw(double d1, double d2) {
		radius = d1;
	}
	public void move(double x) {
		System.out.println("Moved Circle to " + x + " from " + position);
		position = x;
	}
	public void rotate(double r) {
		System.out.println("Rotated Circle to " + r + " degrees from " + rotation + " degrees");
		rotation = r;
	}	
}

class Rectangle implements Shape {
	double length, breadth, position, rotation;
	public double area() {
		return (length*breadth);
	}
	Rectangle(double l, double b, double m, double r) {
		length = l;
		breadth = b;
		position = m;
		rotation = r;
	}
	public void draw(double d) {
		length = d;
		breadth = d;
	}
	public void draw(double d1, double d2) {
		length = d1;
		breadth = d2;
	}
	public void move(double x) {
		System.out.println("Moved Rectangle to " + x + " from " + position);
		position = x;
	}
	public void rotate(double r) {
		System.out.println("Rotated Rectangle to " + r + " degrees from " + rotation + " degrees");
		rotation = r;
	}	
}

class Main {
	public static void main(String args[]) {
		Shape c1 = new Circle(10.5, 20, 45);
		Shape c2 = new Circle(21, 15, 90);
		Shape r1 = new Rectangle(5, 10, 34.5, 60);
		Shape r2 = new Rectangle(10, 5, 23.45, 75);
		Shape r3 = new Rectangle(1, 2, 23.12, 180);
		System.out.println("Circle 1 of area " + c1.area());
		c1.move(100);
		c1.rotate(90.5);
		System.out.println("Circle 2 of area " + c2.area());
		c2.move(40);
		c2.rotate(15);
		System.out.println("Rectangle 1 of area " + r1.area());
		r1.move(100); r1.rotate(90);
		System.out.println("Rectangle 2 of area " + r2.area());
		r2.move(400); r2.rotate(10);
		System.out.println("Rectangle 3 of area " + r3.area());
		r3.move(10); r3.rotate(90);
	}
}
