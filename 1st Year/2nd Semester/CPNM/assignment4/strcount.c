#include <stdio.h>

int main() {

	char s[100000];
	printf("Enter a string:: ");
	fgets(s, sizeof(s), stdin);
	int c=0, i=0;
	while (s[i]!='\0' && s[i]!='\n'){	c++;i++;}
	printf("Total number of characters is %d", c);
	

	
	return 0;
}
