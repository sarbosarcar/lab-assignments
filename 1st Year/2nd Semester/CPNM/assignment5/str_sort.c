#include <stdio.h>
#include <string.h>

int main() {
char s[5][100000];
int i,j,k, flag;
for (i=0; i<5; i++) {
printf("Enter string %d:::", i+1);
fgets(s[i], sizeof(s[i]), stdin);
}




for(i=0; i<5; i++) {

for(k=0; k<5-i-1; k++) {flag=0;
if(strcmp(s[k], s[k+1])>0) {
char temp[100];
strcpy(temp, s[k]);
strcpy(s[k], s[k+1]);
strcpy(s[k+1], temp);

flag = 1;
}
}
if(flag==0) break;
}
for(i=0; i<5; i++) {
printf("%s", s[i]);
}
return 0;
}
