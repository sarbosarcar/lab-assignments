#include <stdio.h>

int main () {
	
	int m, n;
	printf("Enter no. of rows and cols:; ");
	scanf("%d %d", &m, &n);
	int a[m][n];
	int i, j;
	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			printf("Enter element at %d, %d:: ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	int (*p)[n];
	p=a;
	for (i=0; i<m; ++i) {
		for (j=0; j<n; ++j)
			printf("Element at %d, %d :: %d\n", i, j, *(*(p+i)+j));
	}
	return 0;
}

			
