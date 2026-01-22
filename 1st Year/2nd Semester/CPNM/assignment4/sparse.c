#include <stdio.h>

int main() {
	int m, n, i, j;
	printf("Enter number of rows and columns :: ");
	scanf("%d %d", &m, &n);
	int arr[m][n], e=0, z=0;
	for (i=0; i<m; ++i) {
		for (j=0; j<n; ++j) {
			printf("Enter element %d, %d: ", i, j);
			scanf("%d", &arr[i][j]);
			if (arr[i][j]==0) z+=1;
			e+=1;
		}
	}
	(z>e/2) ? printf("Sparse!\n") : printf("Not Sparse!\n");
	return 0;
}
