#include <stdio.h>

int main () {
	int l, u, i;
	printf("Enter range:: ");
	scanf("%d %d", &l, &u);
	for (i=l; i<=u; i++) {
		int flag = 1, j;
		for (j=2; j<i; j++) {
			if (i%j==0) {
				flag = 0;
				break;
			}
		}
		if (i!=1) {
			(flag) ? printf("%d ", i) : printf("");
		}
	}
	printf("\n");
	return 0;
}
