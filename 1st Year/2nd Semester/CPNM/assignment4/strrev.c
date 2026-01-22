#include <stdio.h>

int main()  {
	 char s[100000];
	printf("Enter a string :: ");
	fgets(s, sizeof(s), stdin);
	int i=0, j;
	while (s[i]!='\0'&&s[i]!='\n') i++;
	for (j=i-1; j>=0; j--) {
		printf("%c", s[j]);
	}
	printf("\n");
	return 0;
}		
