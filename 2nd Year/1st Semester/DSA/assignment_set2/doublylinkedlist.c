#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node *prev;
	struct node *next;
} node;


void create(node *head) {
	int n,i, j;
	printf("Enter number of nodes apart from header node: ");
	scanf("%d", &n);
	for (i=0; i<n; i++) {
		printf("Enter value of node: ");
		scanf("%d", &j);
		node *tmp = (node*) malloc(sizeof(node*));
		tmp->val = j;
		tmp->next=NULL;
		tmp->prev = head;
		head->next = tmp;
		head = head->next;
	}
}

void insert(node *head, int i, int v) {
	if (i==0) {
		node *t = (node*) malloc(sizeof(node*));
		t->val = v;
		t->prev = NULL;
		head->prev = t;
		t->next = head;
		return;
	}
	int c=0;
	node *tmp = head;
	while (c<i-1) {
		tmp=tmp->next;
		c++;
	}
	node *t = (node*) malloc(sizeof(node*));
	t->val = v;
	t->prev = tmp;
	t->next = tmp->next;
	tmp->next->prev = t;
	tmp->next = t;
}

int count(node *head) {
	int p=0;
	node *tmp = head;
	while (tmp) {
		tmp = tmp->next;
		p++;
	}
	return p;
}

void reverse(node *head) {
	node *slow, *fast;
	slow=fast=head;
	while (fast->next) {
		fast = fast->next;
	}
	int c = count(head)/2;
	while (c) {
		int temp = fast->val;
		fast->val = slow->val;
		slow->val = temp;
		slow = slow->next;
		fast = fast->prev;
		c--;
	}
}

void delete(node *head, int i) {
	int x=0;
	node *tmp = head;
	while (x<i-1) {
		x++;
		tmp=tmp->next;
	}
	if (tmp->next->next) {
		tmp->next->next->prev = tmp;
		tmp->next = tmp->next->next;
	}
	else if (tmp->next) {
		free(tmp->next);
		tmp->next=NULL;
	}
	else {
		tmp->prev->next = NULL;
		free(tmp);
	}
	
}

void revprint(node *head) {
	node *tmp = head;
	while (tmp->next) {
		tmp = tmp->next;
	}
	while (tmp) {
		printf("%d\t", tmp->val);
		tmp = tmp->prev;
	}
	printf("\n");

}



int main() {
	int m,n,i,j,k;
	printf("Enter value of header node: ");
	scanf("%d", &n);
	node *head = (node*) malloc(sizeof(node*));
	head->val=n;
	head->prev=NULL;
	head->next = NULL;
	int c=0;
	create(head);
	do {
		printf("\t\tMENU:\n1. Insert\n2. Delete\n3. Reverse\n4. Count\n5. Reverse Print\n6. Exit\nEnter option number:: ");
		scanf("%d", &c);
		switch (c) {
			case 1:
				printf("Enter index and value to insert: ");
				scanf("%d %d", &i, &j);
				insert(head, i, j);
				break;
			case 2:
				printf("Enter index to delete: ");
				scanf("%d", &i);
				delete(head, i);
				break;
			case 3:
				reverse(head);
				break;
			case 4:
				k = count(head);
				printf("There are %d nodes\n", k);
				break;
			case 5:
				revprint(head);
				break;
			case 6:
				break;
			default:
				printf("Invalid choice!\n");
		}
	} while (c!=6);
	printf("Exiting...\n");
	return 0;
}

		
