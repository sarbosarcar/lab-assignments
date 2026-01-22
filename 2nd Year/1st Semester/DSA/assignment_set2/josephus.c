#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node *next;
} node;

void create(node *head) {
	printf("Enter number of elements apart from the header node: ");
	int n, i;
	node *tmp = head;
	scanf("%d", &n);
	for (i=0; i<n; i++) {
		node *temp = (node*) malloc(sizeof(node*));
		printf("Enter element: ");
		int m;
		scanf("%d", &m);

		temp->val = m;
		temp->next=NULL;
		head->next = temp;
		head = head->next;
	}
	head->next = tmp;
}

void print(node *head) {
	node *temp = head;
	node *temp2 = head;
	while (temp->next!=temp2) {
		printf("%d\t", temp->val);
		temp = temp->next;
	}
	printf("%d", temp->val);
	printf("\n");
}

int count(node *head) {
	int c=0;
	node *temp, *temp2;
	temp = temp2 = head;
	while (temp->next!=temp2) {
		c++;
		temp=temp->next;
	}
	return c+1;
}

void survive(node *head, int z) {
	int i=z,j,k;
	node *tmp = head;
	while (count(tmp)!=1) {
		i=z;
		node *init = tmp;
		while (i-1) {
			tmp=tmp->next;
			i--;
		}
		node *del = tmp->next;
		tmp->next = tmp->next->next;
		printf("Deleting node %d!\n", del->val);
		free(del);
	}
	printf("Surviving node is:\n%d\n", tmp->val);
}

int main() {
	node *head = (node*) malloc(sizeof(node*));
	int n, m;
	printf("Enter value of header node: ");
	scanf("%d", &n);
	head->val = n;
	head->next = NULL;
	create(head);
	print(head);
	printf("Enter number of nodes to skip before deletion: ");
	scanf("%d", &m);
	survive(head, m);
	return 0;
}
