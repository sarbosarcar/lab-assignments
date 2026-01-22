#include <stdio.h>

int main() {
	int n, i;
	printf("Enter the value of n: ");
	scanf("%d", &n);
	int S;
	for (i=1; i<=n; i++) {
		S += (i*i*i+i*i);
	}
	printf("\nSum is %d\n", S);
	return 0;
}
