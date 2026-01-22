#include <stdio.h>
#include <string.h>

int main () {

	char s[100000];
	printf("Enter a string:: ");
	fgets(s, sizeof(s), stdin);
	char temp[100][100]={'\0'};
	int i, n=strlen(s), j=0, flag=1,k=0,x=1;
	for (i=0; i<n-1; i++) {
		if (s[i]==' ') {
			//flag = 0;
			j++;
			k=0;
			x++;
		}
		else {
			if (flag) {
				temp[j][k] = s[i];
				k++;
				
			}
		}
	}
	for (i=0; i<x; i++) {
		printf("%s\n", temp[i]);
	}

	for (i=0; i<x; i++) {
		flag=1;
		k=0;
		for (j=0; j<x; j++) {
			if (strcmp(temp[i], temp[j])==0) {
						
				k++;
				if (k>1){flag=1; temp[j][0]='\0';}
			}
		}
		
		if (flag) printf("%s ", temp[i]);

	}
	
	return 0;
}



/*
 *
 *
 *
 *Hello world hello ! 
 *
 *
 * */	
				

