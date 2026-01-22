#include <stdio.h>

int main() {
	unsigned int n;
	printf("Enter a number: ");
	scanf("%u", &n);
	if (n == 1) { printf("No it is not prime!\n"); }
	int i, flag = 1;
	for (i = 2; i < n; i++) {
		if (n % i == 0) {
			flag = 0;
			break;
		}
	}
	(flag) ? printf("Yes it is prime!\n") : printf("No it is not prime!\n");
	return 0;
}
