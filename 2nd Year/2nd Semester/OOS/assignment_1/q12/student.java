class Student {
	String name;
	int roll;
	String[] subs;
	Student(String n, int r, String[] s) {
		name = n;
		roll = r;
		subs = new String[5];
		for (int i=0; i<5; i++) {
			subs[i] = s[i];
		}
	}
	int get_roll() {return roll;}
	String get_name() {return name;}
	String[] get_subs() {return subs;}
	
	void set_roll(int r) {roll=r;}
	void set_name(String s) {name=s;}
	void set_subs(String[] s) {
		for (int i=0; i<5; i++) {
			subs[i] = s[i];
		}
	}
}

class TabulationSheet {
	String sub;
	int[] rolls;
	double[] marks;
	int top;
	TabulationSheet(int n) {
		rolls = new int[n];
		marks = new double[n];
		top = -1;
	}
	void add(int r, double m) {
		if (top==marks.length-1) System.out.println("Overflow!");
		rolls[++top] = r;
		marks[top]  = m;
	}
}

class MarkSheet {	
	double[] marks = new double[5];
	//String[] names;
	//int top;
	Student st;
	//String[] subs;
	MarkSheet(Student ob) {
		//marks = new double[n][5];
		//names = new String[n];
		//top = -1;
		st = ob;
	}
	void add(String n, double[] m) {
		st.name = n;
		for (int i=0; i<5; i++) {
			marks[i] = m[i];
		}
	}
	/*void add(String n, double[] m) {
		//for (int i=0; i<marks.length; i++) {
		//	if (marks[i].equals(n)) {
		//		for (int j=0; j<5; j++) {
		//			marks[i][j] = m[j];
		//		}
		//		break;
		//	}
		//}
		if (top==marks.length-1) {
			System.out.println("Overflow!");
			return;
		}
		names[++top] = n;
		for (int i=0; i<5; i++) {
			marks[top][i] = m[i];
		}
	}*/
	void disp(TabulationSheet[] t) {
		System.out.println("\t\tMarkSheet for " + st.name);
		for (int i=0; i<marks.length; i++) {
			//System.out.println(names[i] + "'s Marksheet");
			System.out.println(t[i].sub + " => " + marks[i]);
		}
	}
}
	
	/*
 * Implement a class “MarkSheet”. A mark sheet contains marks of all subjects for a particular
 * student. This class should have a method to add name of a student and marks in each subject.
 * Write a main() function to create three “Student” objects, Five “Tabulationsheet” objects for Five
 * subjects and three “Marksheet” object for three students. Print the mark sheets.
 */

class Demo {
	public static void main(String args[]) {
		Student[] st = new Student[3];
		for (int i=0; i<3; i++) {
			st[i] = new Student("Student " + (i+1), 10*(i+1)+i, new String[] {"English", "CS", "Physics", "Chemistry", "Mathematics"});
		}
		TabulationSheet[] t = new TabulationSheet[5];
		for (int i=0; i<5; i++) {
			t[i] = new TabulationSheet(3);
			t[i].sub = st[0].subs[i];
			for (int j=0; j<3; j++) {
				t[i].add(st[j].roll, 90+((i+1)*(j+1))%9);
			}
		}
		MarkSheet[] m =  new MarkSheet[3];
		for (int i=0; i<3; i++) {
			m[i] = new MarkSheet(st[i]);
			double temp[] = new double[5];
			for (int j=0; j<5; j++) {
				temp[j] = (t[j]).marks[i];
			}
			m[i].add(st[i].name, temp);
		}
		for (int i=0; i<3; i++)
			m[i].disp(t);
	}
}
