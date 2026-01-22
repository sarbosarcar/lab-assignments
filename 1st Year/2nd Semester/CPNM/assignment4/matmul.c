#include <stdio.h>

int main () {
	int a[3][4] = {{2,3,0,1}, {1,2,3,4}, {1,-2,0,0}};
	int b[4][3] = {{1, -1, 0}, {2, -2, 0}, {2,0,-3}, {3, 2, -9}};
	int c[3][3];
	int i, j, k;
	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
			int sum=0;
			for (k=0; k<4; k++) {
				sum+= a[i][k]*b[k][j];
			}
		c[i][j] = sum;
		}
	}
	printf("The product is \n");
	for (i=0; i<3; i++) {
		printf("{ ");
		for (j=0; j<3; j++) {
			(j!=2) ? printf("%d, ", c[i][j]) : printf("%d }", c[i][j]);
		}
		printf("\n");
	}
	return 0;
}
