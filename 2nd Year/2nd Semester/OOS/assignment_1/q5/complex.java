class Complex {
	int a,b;
	Complex() {
		a = 0;
		b = 0;
	}
	Complex(int t) {
		a=t;
		b=0;
	}
	Complex(int x, int y) {
		a=x;
		b=y;
	}
	Complex add(Complex c) {
		Complex tmp = new Complex(a+c.a, b+c.b);
		return tmp;
	}
	Complex multiply(Complex c) {
		Complex tmp = new Complex(a*c.a-b*c.b, b*c.a+a*c.b);
		return tmp;
	}
	/* 3+2i, 4-2i */
	void disp() {
		System.out.println(a+" + "+b+"i");
	}
	public static void main(String args[]) {
		Complex o1 = new Complex(3,2);
		Complex o2 = new Complex(4,-2);
		Complex o3 = o1.add(o2);
		Complex o4 = o1.multiply(o2);
		System.out.println("Num 1 is \n3+2i");
		System.out.println("Num 2 is \n4-2i");
		System.out.println("Sum is");
		o3.disp();
		System.out.println("Product is");
		o4.disp();
	}
}
