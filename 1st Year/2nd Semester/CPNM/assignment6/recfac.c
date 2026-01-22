#include <stdio.h>

long int fact(int);

long int fact(int n) {
	if (n==1) return 1;
	else return n * fact(n-1);
}
int main () {
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	printf("%d! = %ld", n, fact(n));
	return 0;
}
