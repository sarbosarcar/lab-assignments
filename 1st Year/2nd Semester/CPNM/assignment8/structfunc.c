#include <stdio.h>

struct Student {
	char name[50];
	int age, marks;
};

void print(struct Student stud[]) {
	int i;
	for (i=0; i<3; i++) {
		printf("Details of student %d:: \n", i+1);
		printf("Name: %s", stud[i].name);
		printf("Age: %d", stud[i].age);
		printf("Marks: %d", stud[i].marks);
	}
}

int main() {
	int i;
	struct Student stud[3];
	for (i=0; i<3; i++) {
		printf("Enter name of student %d: ", i+1); 
		fgets(stud[i].name, 50, stdin);
		printf("Enter age and marks: ");
		scanf("%d %d", &stud[i].age, &stud[i].marks);
		getchar();
	}
	print(stud);
	return 0;
}
