#include <stdio.h>

int main() {
	
	int a[2][2][2][2], i, j, k, l;
	for (i=0; i<2; i++) {
		for (j=0; j<2; j++) {
			for (k=0; k<2; k++) {
				for (l=0; l<2; l++) {
					printf("Enter element at index (%d, %d, %d, %d):: ", i, j, k, l);
					scanf("%d", &a[i][j][k][l]);
				}
			}
		}
	}
	
	printf("The elements are as follows:: \n");

		for (i=0; i<2; i++) {
		for (j=0; j<2; j++) {
			for (k=0; k<2; k++) {
				for (l=0; l<2; l++) {
					printf("Element at index (%d, %d, %d, %d):: %d ", i, j, k, l, a[i][j][k][l]);
					printf("\n");
		
				}
			}
		}
	}
		
	return 0;
}
