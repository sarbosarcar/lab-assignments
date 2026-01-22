#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	int row, col, val;
} element;

typedef struct sparse {
	int non_zero, row_num, col_num;
	element e[1000];
} sparse;

void count(sparse *m) {
	int i, curr = m->e[0].row, c=0;
	for (i=0; i<m->non_zero; i++) {
		if (m->e[i].row == curr) c++;
		else {
			printf("Row %d has %d element(s)\n", curr, c);
			c=1;
			curr = m->e[i].row;
		}
	}
	printf("Row %d has %d element(s)\n", curr, c);
}


	

void print(sparse *m) {
	int i;
	for (i=0; i<m->non_zero; i++) {
		printf("(%d, %d, %d)\t", m->e[i].row, m->e[i].col, m->e[i].val);
	}
	printf("\n");
} 			
	
int main() {
	printf("Enter number of rows and cols: ");
	int r, c, i, j, k, n1, n2, v;
	scanf("%d %d", &r, &c);
	printf("Enter number of non-zero elements in matrix: ");
	scanf("%d", &n1);
	sparse *m1 = (sparse*) malloc(sizeof(sparse));
	m1->non_zero = n1;
	m1->row_num = r; m1->col_num = c;
	printf("Enter elements of matrix in (row col val) format: \n");
	for (i=0; i<n1; i++) {	
		printf(" > ");
		scanf("%d %d %d", &r, &c, &v);
		element tmp = {r, c, v};
		m1->e[i] = tmp;
	}
	printf("Matrix entered:\n");
	print(m1);
	count(m1);
	free(m1);
	return 0;
}
