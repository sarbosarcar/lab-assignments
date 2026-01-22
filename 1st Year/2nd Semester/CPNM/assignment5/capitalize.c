#include <stdio.h>
#include <string.h>

int main() {

	char s[100000];
	printf("Enter a string:: ");
	fgets(s, sizeof(s), stdin);
	int flag = 1;
	int n=strlen(s), i=0;
	while (i<n) { if (s[i]!='\n') {
		if (flag) {
			s[i] = toupper(s[i]);
			flag = 0;
		}
		if (s[i]==' ') flag = 1;
	}	i++;
	
}
	printf("\nThe modified string is :: ");
	printf("%s", s);
	return 0;
}
	
