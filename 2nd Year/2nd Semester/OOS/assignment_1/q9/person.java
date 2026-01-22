class Person {
	int age;
	double height, weight;
	String dateOfBirth, address;
	void set_age(int v) {
		age = v;
	}
	void set_weight(double w) {
		weight = w;
	}
	void set_height(double h) {
		height = h;
	}
	void set_add(String a) {
		address = a;
	}
	void set_dob(String d) {
		dateOfBirth = d;
	}
	int get_age() {
		return age;
	}
	double get_weight() {
		return weight;
	}
	double get_height() {
		return height;
	}
	String get_dob() {
		return dateOfBirth;
	}
	String get_add() {
		return address;
	}
	void disp() {
		System.out.println("Age is " + age + ", height is " + height + ", weight is " + weight + ", dob is "  + dateOfBirth + ", address is " + address);
	}
}

class Employee extends Person {
	int salary, experience;
	String dateOfJoining;
	/*
 * 	technician , professor(courses, listOfAdvisee, their methods) under employee
 */
}

class Student extends Person {
	int roll;
	String[] listOfSubjects;
	int[] marks;
	Student(int n) {
		listOfSubjects = new String[n];
		marks = new int[n];
	}
	String calculateGrade(String sub) {
		int i=-1;
		for (i=0; i<marks.length; i++) {
			if (listOfSubjects[i]==sub)  {
				break;
			}
		}
		if (marks[i]>=90) {
			return "A";
		}
		else if (marks[i]>=80) {
			return "B";
		}
		else if (marks[i]>=70) {
			return "C";	
		}
		else if (marks[i]>=60) {
			return "D";
		}
		else {
			return "E";
		}
	}
	int get_roll() {
		return roll;
	}
	String[] get_sub() {
		return listOfSubjects;
	}
	int[] get_marks() {
		return marks;
	}
	void set_roll(int v) {
		roll = v;
	}
	void set_sub(String[] s) {
		for (int i=0; i<s.length; i++) {
			listOfSubjects[i]=s[i];
		}
	}
	void set_marks(int[] i) {
		for (int j=0; j<i.length; j++) {
			marks[j] = i[j];
		}
	}
	void disp() {
		System.out.println("Marks obtained by Student Roll no. : " + roll);
		for (int i=0; i<marks.length; i++) {
			System.out.println("Subject: " + listOfSubjects[i] + ": " + marks[i]);
			System.out.println("Grade: " + calculateGrade(listOfSubjects[i]));
		}
	}
}

class Technician extends Employee {
	void disp() {
		System.out.println("Details for Technician: ");
		super.disp();
	}
}

class Professor extends Employee {
	String[] courses;
	String[] listOfAdvisee;
	Professor(int n) {
		courses = new String[n];
		listOfAdvisee = new String[n];
	}
	void set_courses(String[] c) {
		for (int i=0; i<c.length; i++) {
			courses[i] = c[i];
		}
	}
	void set_loa(String[] l) {
		for (int i=0; i<l.length; i++) {
			listOfAdvisee[i] = l[i];
		}
	}
	String[] get_courses() {
		return courses;
	}
	String[] get_loa() {
		return listOfAdvisee;
	}
	void disp() {
		System.out.println("Courses are:");
		for (int i=0; i<courses.length; i++) {
			System.out.println(courses[i]);
		}
		System.out.println("List of advisees: ");
		for (int i=0; i<listOfAdvisee.length; i++) {
			System.out.println(listOfAdvisee[i]);
		}
	}
}

class Demo {
	public static void main(String args[]) {
		System.out.println("For Technician: ");
		Technician t1 = new Technician();
		t1.set_age(30);
		t1.set_dob("10-11-1995");
		t1.set_height(180);
		t1.set_weight(65);
		t1.set_add("10 Orange Street");
		t1.disp();
		
		System.out.println("For Professor: ");
		Professor p1 = new Professor(3);
		p1.set_courses(new String[] {"A", "B", "C"});
		p1.set_loa(new String[] {"A1", "A2", "A3"});
		p1.disp();	
		
		System.out.println("For Student: ");
		Student s1 = new Student(3);
		s1.set_roll(3);
		s1.set_sub(new String[] {"S1", "S2", "S3"});
		s1.set_marks(new int[] {98, 99, 100});
		s1.disp();
	}
}
		
