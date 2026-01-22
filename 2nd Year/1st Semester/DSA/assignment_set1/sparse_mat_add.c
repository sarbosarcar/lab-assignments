#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	int row, col, val;
} element;

typedef struct sparse {
	int non_zero, row_num, col_num;
	element e[1000];
} sparse;

void add(sparse *m1, sparse *m2, sparse *m3) {
	int i, j, k=0, l;
	for (i=0, j=0; i<m1->non_zero && j<m2->non_zero; k++) {
		if ((m1->e[i].row == m2->e[j].row) && (m1->e[i].col == m2->e[j].col)) {
			m3->e[k].row = m1->e[i].row;
			m3->e[k].col = m1->e[i].col;
			m3->e[k].val = m1->e[i].val + m2->e[j].val;
			i++; j++;
		}
		else if (m1->e[i].col<m2->e[j].col) {
			m3->e[k].row = m1->e[i].row;
			m3->e[k].col = m1->e[i].col;
			m3->e[k].val = m1->e[i].val;
			i++;
		}
		else {
			m3->e[k].row = m2->e[j].row;
			m3->e[k].col = m2->e[j].col;
			m3->e[k].val = m2->e[j].val;
			j++;
		}
	}
	while (i<m1->non_zero) {
			m3->e[k].row = m1->e[i].row;
			m3->e[k].col = m1->e[i].col;
			m3->e[k].val = m1->e[i].val;
			i++; k++;
	}
	while (j<m2->non_zero) {
			m3->e[k].row = m2->e[j].row;
			m3->e[k].col = m2->e[j].col;
			m3->e[k].val = m2->e[j].val;
			j++; k++;
	}
	m3->non_zero = k;
	m3->row_num = m1->row_num;
	m3->col_num = m1->col_num;
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
	printf("Enter number of non-zero elements in matrices 1 and 2: ");
	scanf("%d %d", &n1, &n2);
	sparse *m1 = (sparse*) malloc(sizeof(sparse));
	sparse *m2 = (sparse*) malloc(sizeof(sparse));
	sparse *m3 = (sparse*) malloc(sizeof(sparse));
	m1->non_zero = n1;
	m2->non_zero = n2;
	m1->row_num = r; m2->row_num = r; m1->col_num = c; m2->col_num = c;
	printf("Enter elements of matrix 1 in (row col val) format: \n");
	for (i=0; i<n1; i++) {	
		printf(" > ");
		scanf("%d %d %d", &r, &c, &v);
		element tmp = {r, c, v};
		m1->e[i] = tmp;
	}
	printf("Enter elements of matrix 2 in (row col val) format: \n");
	for (i=0; i<n2; i++) {	
		printf(" > ");
		scanf("%d %d %d", &r, &c, &v);
		element tmp = {r, c, v};
		m2->e[i] = tmp;
	}
	add(m1, m2, m3);
	printf("Matrix 1:\n");
	print(m1);
	printf("Matrix 2:\n");
	print(m2);
	printf("Sum:\n");
	print(m3);
	free(m1); free(m2); free(m3);
	return 0;
}
