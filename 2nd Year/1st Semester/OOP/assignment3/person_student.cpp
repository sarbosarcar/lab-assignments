#include <iostream>
#include <cstdio>

using namespace std;

class Person {
	string name; int age; double height;
	public: 
		Person(string s="", int a=0, double h=0) {name=s; age=a; height=h;}
		void set_name(string s) {name=s;}
		void set_age(int x) {age=x;}
		void set_height(double h) {height = h;}
		string get_name() {return name;}
		int get_age() {return age;}
		double get_height() {return height;}
		virtual void printDetails() {
			cout << "Name is " << name << endl;
			cout << "Age is " << age << endl;
			cout << "Height is " << height<< endl;
		}
};

class Student : public Person {
	int roll, yoa;
	public:
		Student (string name="", int age=0, double height=0, int r=0, int y=0) : Person(name, age, height) {
			roll = r;
			yoa= y;
		}
		void set_roll(int x) { roll=x; }
		void set_yoa(int y) { yoa = y;}
		int get_roll() {return roll;}
		int get_yoa() {return yoa;}
		void printDetails() {
			Person::printDetails();
			cout << "Roll No. is " << roll << endl;
			cout << "Year of admission is " << yoa << endl;
		}
};

int main() {
	Person ob1;
	ob1.set_name("P1");
	ob1.set_age(20);
	ob1.set_height(170);
	ob1.printDetails();
	Student s;
	s.set_name("S1");
	s.set_age(15);
	s.set_height(160);
	s.set_roll(10);
	s.set_yoa(2020);
	s.printDetails();
	Person* a[4];
	for (int i=0; i<2; i++) {
		a[i] = new Person();
		char buffer[100];
		sprintf(buffer, "Person %d", i+1);
		/*(a[i])->set_name(buffer);
		(a[i])->set_age(20+i);
		(a[i])->set_height(165+i);*/
		a[i] = new Person(buffer, 20+i, 165+i);
	}
	for (int i=2; i<4; i++) {
		a[i] = new Student();
		char buffer[100];
		sprintf(buffer, "Student %d", i+1);
		/*(a[i])->set_name(buffer);	
		(a[i])->set_age(14+i);
		(a[i])->set_height(170+i);
		(a[i])->set_roll(10+i);
		(a[i])->set_yoa(2020+i);*/
		a[i] = new Student(buffer, 14+i, 170+i, 10+i, 2020+i);
	}
	for (int i=0; i<4; i++) {
		(a[i])->printDetails();
	}
}
