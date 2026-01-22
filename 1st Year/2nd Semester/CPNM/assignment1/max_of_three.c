#include <stdio.h>
int main() {
	int a, b, c, max;
	printf("Enter 3 numbers: ");
	scanf("%d %d %d", &a, &b, &c);
	if (a > b) {
		if (a > c) {
			max = a;
		}
		else {
			max = c;
		}		
	}
	else if (b > c) {
		if (b > a) {
			max = b;
		}
		else {
			max = a;
		}
	}
	else if (c > a) {
		if (c > b) {
			max = c;
		}
		else {
			max = b;
		}
	}

	printf("%d is the maximum", max);
	return 0;
}
