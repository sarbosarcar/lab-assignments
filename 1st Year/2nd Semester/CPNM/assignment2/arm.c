#include <stdio.h>
#include <math.h>

int main() {
	int l, u;
	printf("Enter limits: ");
	scanf("%d %d", &l, &u);
	int i;
	for (i=l; i<=u; i++) {
		int n=0, temp=i, z=0, j=i;
		while (temp>0) {
				n++;
				temp /= 10;	
		}	
		while (j>0) {
		z = z+ pow(j%10, n);
		j /= 10;
		}
		if (i==z) {
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}
