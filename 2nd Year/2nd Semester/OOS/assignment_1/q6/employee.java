class Employee {
	String name;
	int id;
	String address;
	double salary;
	Employee(String n, int i, String a, double s) {
		name = n;
		id = i;
		address = a;
		salary = s;
	}
	void disp() {
		System.out.println("Employee " + name + " with id " + id + " living at " + address + " has salary " + salary);
	}
	double get_sal() {
		return salary;
	}
	int get_id() {
		return id;
	}
	String get_name() {
		return name;
	}
	String get_add() {
		return address;
	}
	void set_sal(int s) {
		salary = s;
	}
	void set_name(String n) {
		name = n;
	}
	void set_add(String a) {
		address = a;
	}
	void set_id(int v) {
		id = v;
	}
}

class Dept {
	String name, location;
	Employee[] emp;
	int top = -1;
	Dept(String n, String loc, int s) {
		name = n;
		location = loc;
		emp = new Employee[s];
	}
	void add(Employee e) {
		if (top==emp.length-1) {
			System.out.println("Overflow!");
		}
		emp[++top] = e;
	}
	void delete(int id) {
		if (top<0) {
			System.out.println("Underflow!");
		}
		for (int i=0; i<=top; i++) {
			if (emp[i].id==id) {
				for (int j=i; j<top; j++) {
					emp[j] = emp[j+1];
				}
				top--;
				break;
			}
		}
	}
}

class Main {
	public static void main(String args[]) {
		Dept d = new Dept("Information Technology", "JUSL", 5);
		for (int i=0; i<5; i++) {
			Employee tmp = new Employee("Emp "+i, 100+i*10+i*2, "Street " + (i*i+3), 50000 + (1000*i) + (100*i));
			d.add(tmp);
		}
		int s=0;
		for (int i=0; i<=d.top; i++) {
			s+=d.emp[i].get_sal();
			d.emp[i].disp();
		}
		System.out.println("Total expenditure on all employees of the department is " + s);
	}
}
