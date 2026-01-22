#include <stdio.h>

int main() {
char s[100000];
printf("Enter string:: ");
fgets(s, sizeof(s), stdin);
int i=0, n=0;
while (s[i]!='\0' && s[i]!='\n') {
n++; i++;
}
i=0;
int flag = 1;
while (i<n/2) {
if (s[i]!=s[n-i-1]) {
flag = 0;
break;
}
i++;
}
(flag) ? printf("String is palindromic!") : printf("String is not palindromic!");
return 0;
}

