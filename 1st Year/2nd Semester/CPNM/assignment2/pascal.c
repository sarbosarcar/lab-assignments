#include <stdio.h>

int main() {
	int n, i, j, k=1;
	printf("Enter the value of n: ");
	scanf("%d", &n);
	for (i=0; i<n; i++) {
		k=1;
		for (j=n-i; j>0; j--) {
			printf(" ");
	}
	
		for (j=0; j<=i; j++) {
		if (j==0 || j==i) {printf("1 ");}
		else { k = k*(i-j+1)/j; printf("%d ", k);}
		
		
}
 printf("\n");}
return 0;
}
			









/*
     1       
    1 1
   1 2 1
  1 3 3 1
 1 3 4 3 1
1 4 7 7 4 1






 */	
