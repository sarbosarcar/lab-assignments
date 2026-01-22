#include <stdio.h>

int main() {
	long long n, i, fac=1, S=0;
	printf("Enter value of n: ");
	scanf("%lld", &n);
	for (i=1; i<=n; i++) {
		S = S + fac*i;
		fac *= i;
	}
	printf("\n Sum is %lld\n", S);
	return 0;
}
