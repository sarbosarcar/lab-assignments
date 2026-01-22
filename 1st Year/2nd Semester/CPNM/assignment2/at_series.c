#include <stdio.h>

int main() {
	int n, i, S=0;
	printf("Enter the value of n: ");
	scanf("%d", &n);
	for (i=1; i<=n; i++) {
		int j;
for (j=1; j<=i; j++) {
if (i%j == 0){ S += j;
}}}printf("Sum is %d\n", S); return 0;}
