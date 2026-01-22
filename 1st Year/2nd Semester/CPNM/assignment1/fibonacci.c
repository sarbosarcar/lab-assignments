#include <stdio.h>

int main() {
	unsigned int a=0, b=1, temp, flag=0, n;
	printf("Enter a number: ");
	scanf("%u", &n);
	while (b <= n) {
		if (b == n) { flag = 1; break; }
		else { 
		temp = a;
		a = b;
		b = a + temp;
		}
	}
	(flag) ? printf("Yes %u is a part of the Fibonacci series\n", n) : printf("No %u is not a part of the Fibonacci series\n", n);
	return 0;
}
