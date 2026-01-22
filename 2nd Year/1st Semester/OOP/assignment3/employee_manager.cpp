#include <iostream>
#include <cstdio>

using namespace std;

class Employee {
	string name; double salary;
	public: 
		Employee(string s="", double sal=0) {name=s; salary=sal;}
		void set_name(string s) {name=s;}
		void set_salary(double h) {salary = h;}
		string get_name() {return name;}
		double get_salary() {return salary;}
		virtual void printDetails() {
			cout << "Name is " << name << endl;
			cout << "Salary is " << salary << endl;
		}
};

class Manager : public Employee {
	string type;
	public:
		Manager (string n="", double sal=0, string t="") : Employee (n, sal) {
			type=t;
		}
		void set_type(string t="") { type=t; }
		string get_type() {return type;}
		void printDetails() {
			Employee::printDetails();
			cout << "Type is " << type << endl;
		}
};

class Clerk : public Employee {
	double all;
	public:
		Clerk (string n="", double sal=0, double a=0) : Employee(n, sal) {
			all=a;
		}
		void set_all(double a=0) { all=a; }
		double get_all() {return all;}
		void printDetails() {
			Employee::printDetails();
			cout << "Allowance is " << all << endl;
		}
};
int main() {
	Manager m1;
	m1.set_name("P1");
	m1.set_salary(20000);
	m1.set_type("Type 1");
	m1.printDetails();
	Clerk s;
	s.set_name("C1");
	s.set_salary(15000);
	s.set_all(5000);
	s.printDetails();
	Employee* a[6];
	for (int i=0; i<2; i++) {
		//a[i] = new Employee();
		char buffer[100];
		sprintf(buffer, "Employee %d", i+1);
		/*(a[i])->set_name(buffer);
		(a[i])->set_salary(10000+i);*/
		a[i] = new Employee(buffer, 10000+i);
	}
	for (int i=2; i<4; i++) {
		//a[i] = new Manager();
		char buffer[100];
		sprintf(buffer, "Manager %d", i+1);
		/*(a[i])->set_name(buffer);	
		(a[i])->set_salary(20000);
		(a[i])->set_type("Type 3");*/
		a[i] = new Manager(buffer, 20000, "Type 3");
	}
	for (int i=4; i<6; i++) {
		//a[i] = new Clerk();
		char buffer[100];
		sprintf(buffer, "Clerk %d", i+1);
		/*(a[i])->set_name(buffer);
		(a[i])->set_salary(10000+i);
		(a[i])->set_all(1000+i);*/
		a[i] = new Clerk(buffer, 10000+i, 1000+i);
	}
	for (int i=0; i<4; i++) {
		(a[i])->printDetails();
	}
	double tot=0;
	for (int i=0; i<6; i++) tot += (a[i])->get_salary();
	cout << "Total salary: " << tot << endl;
}
