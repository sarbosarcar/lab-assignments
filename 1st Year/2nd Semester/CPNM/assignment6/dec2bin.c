#include <stdio.h>
#include <math.h>

void dec2bin(int);

void dec2bin(int n) {
	
	int len = log2(n), temp = n;
	char s[100000]={'\0'};
	int bin=1, i=len;
	while (n>0) {
		int z = n%2;
		if (z) s[i] = '1';
		else s[i] = '0';
		i--;
		n/=2;
	}
	printf("\n=>%s\n", s);

}

int main() {
	int n;
	printf("Enter a decimal number: ");
	scanf("%d", &n);
//	printf("%d in binary is %lld", n, dec2bin(n));
	dec2bin(n);	
return 0;
}
