#include <stdio.h>

int main() {
	int n;
	printf("Enter the value of n: ");
	scanf("%d", &n);
	int i, j, k;
	for (i=1; i<=n; i++) {
		for (j=n-i; j>0; j--) {
			printf(" ");
		}
		for (k=1; k<=i; k++) {
			printf("* ");
		}
	printf("\n");
	}
	for (i=n-1; i>0; i--) {
		for (j=1; j<=(n-i); j++) {
			printf(" ");
		}
		for (k=i; k>0; k--) {
			printf("* ");
		}
	printf("\n");
	}



	for (i=n; i>0; i--) {
		for (j=i; j>0; j--) {
			printf("*");
		}
		for (k=(n-i)*2; k>0; k--) {
			printf(" ");
		}
		for (j=i; j>0; j--) {printf("*");}
		(i!=1) ? printf("\n") : printf("");
	}

	for (i=0; i<=n; i++) {
		for (j=0; j<i; j++) {
			printf("*");
		}
		for (k=0; k<(n-i)*2; k++) {
			printf(" ");
		}
		for (j=0; j<i; j++) {printf("*");}
		printf("\n");
	}
	


	for (i=1; i<=n; i++) {
		for (j=n-i; j>0; j--) { printf(" "); }
		if (i%2==1) {
			int a;
			for (a=1; a<=(i+1)/2; a++){
				printf("%d ", a);
			}
			for (a=(i+1)/2; a>0; a--){ printf("%d ", a);}
                      }
else {

int b;
for (b=1; b<=i; b++){printf("%d ", b);}
for (b=i-1; b>0; b--){printf("%d ", b);}}
printf("\n");}
			









return 0;
}
