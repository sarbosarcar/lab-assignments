#include <stdio.h>
#include <string.h>
struct Student {
	char name[50];
	int age;
	int total;
};

int main() {
	struct Student stud[5];
	int i;
	for (i=0; i<5; i++) {
		 int age; int total;
		printf("Enter name of student %d:: ", i+1);
		fgets(stud[i].name, 50, stdin);
		printf("Enter age and total marks for student %d:: ", i+1);
		scanf("%d %d", &age, &total);
		stud[i].age = age; stud[i].total=total;
		getchar();
	} int sum=0;
	for (i=0; i<5; i++) {
		printf("Name of student %d is %s.", i+1, stud[i].name);
		printf("Age is %d and total marks is %d\n", stud[i].age, stud[i].total);
		sum+=stud[i].total;
	}	
	printf("Average total marks is %g", (float) sum/5);
	return 0;
}
