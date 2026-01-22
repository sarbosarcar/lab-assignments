#include <stdio.h>

int main() {

	char s[100000];
	printf("Enter a string ;: ");
	fgets(s, sizeof(s), stdin);
	int i=0;
	while (s[i]!='\n' && s[i]!='\0') i++;
	int j, count=0, flag = 1;
	for (j=1; j<i; j++) {
 		if (s[j]==' ' && s[j-1]!=' ') flag = 1;
		else flag = 0;
		if (flag) count++;
	}
	printf("Number of words is %d", count+1);
	return 0;
}
