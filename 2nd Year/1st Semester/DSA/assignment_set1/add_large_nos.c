//Take two large numbers as input and add them. (Large no means that the no’s does not
//fall within the range of integer or long int).
//
#include <stdio.h>
#include <stdlib.h>

typedef struct term {
	int coeff;
	int expo;
} term;
typedef struct num {
	int n;
	term a[1000];
} num;

void handlecarry(num*);

void add(num *n1, num *n2, num *n3) {
	int i, j, k=0, l;
	for (i=0, j=0; i<n1->n && j<n2->n; k++) {
		if (n1->a[i].expo == n2->a[j].expo) {
			n3->a[k].expo = n1->a[i].expo;
			int sum = n1->a[i].coeff + n2->a[j].coeff;
			 n3->a[k].coeff = sum;
			i++; j++;
		}
		else if (n1->a[i].expo< n2->a[j].expo) {
			n3->a[k].expo = n1->a[i].expo;
			n3->a[k].coeff = n1->a[i].coeff;
			i++;
		}
		else {
			n3->a[k].expo = n2->a[j].expo;
			n3->a[k].coeff = n2->a[j].coeff;
		}
	}
	while (i<n1->n) {
		n3->a[k].expo = n1->a[i].expo;
		n3->a[k].coeff = n1->a[i].coeff;
		i++; k++;
	}
	while (j<n2->n) {
		n3->a[k].expo = n2->a[j].expo;
		n3->a[k].coeff = n2->a[j].coeff;
	}
	handlecarry(n3);
	n3->n = k;
}

void handlecarry(num *n) {
	int i, j, k, l;
	for (l=0; l<n->n; l++) {
		if (n->a[l].coeff>9) {
			n->a[l].coeff %= 10;
			if (n->a[l+1].expo == n->a[l].expo + 1) n->a[l+1].coeff+=1;
			else {
				for (i=n->n; i>l; i--) {
					n->a[i] = n->a[i-1];
				}
				n->a[l].expo+=1;
				n->a[l].coeff = 1;
			}
		}
	}
}
				


/*void add(num *n1, num *n2, num *n3) {
	int i, j, k, l;
	for (i=0, j=0, k=0; i<n1->n && j<n2->n; k++) {
		if (n1->a[i].expo == n2->a[j].expo)  {
			n3->a[k].expo = n1->a[i].expo;
			int sum = n1->a[i].coeff + n2->a[j].coeff;
			if (sum<=9) n3->a[k].coeff = sum;
			else {
				n3->a[k].coeff = sum%10;
			}
			i++; j++;
		}
		else if (n1->a[i].expo < n2->a[j].expo) {
			n3->a[k].coeff = n1->a[i].coeff;
			n3->a[k].expo = n1->a[i].expo;
			i++;
		}
		else {
			n3->a[k].coeff = n2->a[j].coeff;
			n3->a[k].expo = n2->a[j].expo;
			j++;
		}
	}
	if (i<n1->n) {
		for (l=0; l<n1->n; l++, k++) {
			n3->a[k].coeff = n1->a[l].coeff;
			n3->a[k].expo = n1->a[l].expo;
		}
	}
	else {
		for (l=0; l<n2->n; l++, k++) {
			n3->a[k].coeff = n2->a[k].coeff;
			n3->a[k].expo = n2->a[k].coeff;
		}
	}
}*/
	
void print(num *n) {
	int m = n->n, i, j, k;
	i = m-1; j = n->a[m-1].expo;
	while (j>=0) {
		if (n->a[i].expo==j) {
			printf("%d", n->a[i].coeff);
			i--;
		}
		else {
			printf("0");
		}
		j--;
	}			
	printf("\n");
}			
				
				

int main() {
	int m1, m2, i, j, k;
	printf("Enter number of non-zero terms in nums 1 and 2: ");
	scanf("%d %d", &m1, &m2);
	num *n1 = (num*) malloc(sizeof(num));
	num *n2 = (num*) malloc(sizeof(num));
	num *n3 = (num*) malloc(sizeof(num));
	
	n1->n = m1;
	n2->n = m2;
	printf("Enter the non-zero terms and corresponding exponents for num 1:\n");
	for (i=0; i<m1; i++) {
 		printf("> ");
		int c, e;
		scanf("%d %d", &c, &e);
		term t = {c, e};
		n1->a[i] = t;
	}	
	printf("Enter the non-zero terms and corresponding exponents for num 2:\n");
	for (i=0; i<m2; i++) { 
		printf("> ");
		int c, e;
		scanf("%d %d", &c, &e);
		term t = {c, e};
		n2->a[i] = t;
	}
	add(n1, n2, n3);
	print(n1);
	print(n2);
	print(n3);



	return 0;
}

	
	
	
	
	
	








	
