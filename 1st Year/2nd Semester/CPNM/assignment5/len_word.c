#include <stdio.h>
#include <string.h>

int main() {
char s[100000];

printf("Enter a string:: ");

fgets(s, sizeof(s), stdin);

int n=strlen(s), i=0, flag=0, c=0;

while (i<n-1) {
if (s[i]!=' ') {
flag = 1;
c++;
}
else {

if(flag) {
printf("%d, ", c);}
flag=0;c=0;
}
i++;
}
printf("%d\n", c);
return 0;

}
