#include <stdio.h>
#include <string.h>


int main() {

char s[100000];
printf("Enter a string::"); 
fgets(s, sizeof(s), stdin);

int i, x=0;

for (i=0; i<strlen(s)-1; i++) {
int flag1=0, flag2 = 0;
switch (tolower(s[i])) {
case 'a':flag1=1;break;
case 'e': flag1=1;break;
case 'i': flag1=1;break;
case 'o': flag1=1;break;
case 'u':flag1=1;break;
default: flag1=0;break;
}
switch (tolower(s[i+1])) {
case 'a':flag2=1;break;
case 'e': flag2=1;break;
case 'i': flag2=1;break;
case 'o': flag2=1;break;
case 'u':flag2=1;break;
default: flag2=0; break;
}
if (flag1 && flag2) {
printf("%c%c, ", s[i], s[i+1]);
x++;
}
}
printf("Total occurrences: %d", x);
return 0;
}
