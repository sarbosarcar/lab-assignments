class Student {
	/*
 * 	name
 * 	marks in 3 subjects
 * 	function to assign initial values
 * 	compute total average
 * 	display name, total marks
 */
	String name;
	int m1, m2, m3;
	void insertMarks(int a, int b, int c) {
		m1 = a;
		m2 = b;
		m3 = c;
	}
	void insertName(String s) {
		name = s;
	}
	double average() {
		return (m1+m2+m3)/3;
	}
	void disp() {
		System.out.println("Name is " + name + " and marks in received in Subjects 1, 2, & 3 are " + m1 + ", " + m2 + ", & " + m3);
	}
}

class Demo {
	public static void main(String args[]) {
		Student s = new Student();
		s.insertName("Sarbo Sarcar");
		s.insertMarks(100, 98, 99);
		s.disp();
		System.out.println("Average marks received is " + s.average());
	}
}
