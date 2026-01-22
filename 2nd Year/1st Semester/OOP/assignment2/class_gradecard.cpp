#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

class GradeCard {
	string deptname, student, roll;
	int semester;
	string subs[5]; double marks[5];
	double cgpa;
	public: 
		GradeCard(string dn, string st, string r, int s, string* sub, double* m, double cg) {
			deptname = dn; student = st; roll = r; semester = s; 
			for (int i=0; i<5; i++) {subs[i] = sub[i]; marks[i] = m[i];}
			cgpa = cg;
		}
		GradeCard(GradeCard &gc) {
			deptname = gc.get_dept();
			student = gc.get_student();	
			roll = gc.get_roll();
			semester = gc.get_sem();
			for (int i=0; i<5; i++) {subs[i] = (gc.get_sub())[i]; marks[i] = (gc.get_mk())[i];}
			cgpa = gc.get_cg();
		}
		GradeCard() {
			deptname=""; student=""; roll=""; semester = 0; cgpa=0;
		}
		string get_dept() {return deptname;}
		string get_student() {return student;}
		string get_roll() {return roll;}
		int get_sem() {return semester;}
		double get_cg() {return cgpa;}
		string* get_sub() { return subs;}
		double* get_mk() {return marks;}


};
int main() {
	srand(time(NULL));
	GradeCard gc[60];
	for (int i=0; i<60; i++) {
		char buff[100];
		sprintf(buff, "Student %d", i+1);
		string name = buff;
		string dept = "I.T.";
		sprintf(buff, "ITE%d", rand()%100);
		string roll = buff;
		int sem=3;
		double cgpa = rand()%10;
		string sub[5] = {"oop", "dbms", "dsa", "maths", "coa"};
		double mks[5];
		for (int j=0; j<5; j++) {
			mks[j] = rand()%100;
		}
		GradeCard temp(dept, name, roll, sem, sub, mks, cgpa);
		gc[i] = temp;
	}
	double max=0;
	string maxname, maxroll;
	for (int i=0; i<60; i++) {
		if (gc[i].get_cg()>max) {
			max = gc[i].get_cg();
			maxname = gc[i].get_student();
			maxroll = gc[i].get_roll();
		}
	}
	cout << maxname << " with Roll No. " << maxroll << " has got the maximum CGPA: " << max << endl;
}
	
