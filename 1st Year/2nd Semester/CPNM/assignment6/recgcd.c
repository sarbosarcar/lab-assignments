#include <stdio.h>

int gcd(int, int);

int gcd(int m, int n) {
	if (n!=0) return gcd(n, m%n);
	else return m;
}

int main() {
	int m,n;
	printf("Enter 1st number: ");
	scanf("%d", &m);
	printf("Enter 2nd number: ");
	scanf("%d", &n);
	printf("GCD(%d, %d) = %d", m, n, gcd(m, n));
	return 0;
}
