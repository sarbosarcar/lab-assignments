#include <stdio.h>

struct Emp {
	char name[50], desig[50], add[100];
	struct Salary {
		double bs, da, hra;
	} salary;
};

int main() {
	int i; struct Emp emp[3];
	double gross[3];
	for (i=0; i<3; i++) {
		printf("Enter name of employee %d: ", i+1);
		fgets(emp[i].name, 50, stdin);
		printf("Enter designation: ");
		fgets(emp[i].desig, 50, stdin);
		printf("Enter address: ");
		fgets(emp[i].add, 100, stdin);
		printf("Enter basic salary, da, hra: ");
		scanf("%lf %lf %lf", &emp[i].salary.bs, &emp[i].salary.da, &emp[i].salary.hra);
		gross[i] = emp[i].salary.bs+emp[i].salary.da+emp[i].salary.hra;
		getchar();
	}
	for (i=0; i<3; i++) {
		printf("Gross salary of employee %d is %g", i+1, gross[i]);
	}
	return 0;
}
