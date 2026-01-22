#include <stdio.h>
#include <math.h>


int isPrime(int);
int isSumOfPrime(int);


int isPrime(int n) {
	int i=2, flag=1;
	if (n==2) return 1;
	for (i; i<=pow(n, 0.5); i++) {
		if (n%i==0) {flag=0; break;}
	}
	return flag;
}

int isSumOfPrime(int n) {
	int i;
	for (i=2; i<pow(n,0.5); i++) {
		if (isPrime(i) && isPrime(n-i)) return 1;
	}
	return 0;
}

int main() {
	printf("===>> ");
	int n;
	scanf("%d", &n);	
	printf("%d", isSumOfPrime(n));
	return 0;
}
