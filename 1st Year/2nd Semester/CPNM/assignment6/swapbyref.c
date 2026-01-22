#include <stdio.h>

void swap(int*, int*);

void swap(int* m, int* n) {
	//printf("called");
	int temp = *m;
//	*temp = *m;
	*m = *n;
	*n = temp;
	printf("After swapping numbers are %d and %d", *m, *n);
}

int main() {
	printf("Enter two numbers: ");
	int m, n;
	scanf("%d %d", &m, &n);
printf("Before swapping numbers are %d and %d\n", m, n);
//int *p=&m, *q=&n;
swap(&m, &n);
	return 0;
}
