#include <stdio.h>
#include <math.h>


void isArmstrong(int);
void isPerfect(int);

void isArmstrong(int n) {
	int len = 0, temp=n, sum=0, temp2=n;
	while (temp>0) {
		len++;
		temp /= 10;
	}
	while (temp2>0) {
		sum += pow(temp2%10, len);
		temp2 /= 10;
	}
	
	if (sum==n) printf("%d is an Armstrong number", n);
	else printf("%d is not an Armstrong number", n);
}

void isPerfect(int n) {
	int sum=1, i;
	for (i=2; i<=pow(n, 0.5); ++i) {
		if (n%i==0){
			 if (n/i != i)  sum += (i) + (n/i);
			else sum += i;
	}
}
	
	if (n==sum) printf("%d is a Perfect Number!", n);
	else printf("%d is not a Perfect Number!", n);
}

int main() {
	int a,b;
	printf("Enter a number to check for Armstrong numbers: ");
	scanf("%d", &a);
	printf("Enter a number to check for Perfect numbers: ");
	scanf("%d", &b);
	isArmstrong(a);
	isPerfect(b);
	




	return 0;
}

	
