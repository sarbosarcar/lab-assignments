#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node *next;
} node;

void insert(node *n, int v, int v2) {	
	node *temp = (node*) malloc(sizeof(node));
	temp = n;
	while (temp!=NULL) {
		if (temp->val==v) {
			node *t = (node*) malloc(sizeof(node));
			t->val = v2;
			t->next = temp->next;
			temp->next = t;
		}
		temp = temp->next;
	}
}

void delete(node *n, int v) {
	node *slow = (node*) malloc(sizeof(node));
	slow = n;
	if (slow->val==v) {
		n = n->next;
		return;
	}
	node *fast = (node*) malloc(sizeof(node));
	fast = n;
	while (fast->val!=v) {
		fast = fast->next;
	}
	while (slow->next!=fast) {
		slow = slow->next;
	}
	slow->next = fast->next;
}

int count(node *n) {
	node *temp = n;
	int c=0;
	while (temp!=NULL) {
		temp = temp->next;
		c++;
	}
	return c;
}


void revprint(node *n) {
	node *slow = (node*) malloc(sizeof(node));
	node *fast = (node*) malloc(sizeof(node));
	slow = n;
	fast = n;
	while (fast!=NULL) fast = fast->next;
	while (fast!=n) {
		while (slow->next!=fast) {
			slow = slow->next;
		}
		printf("%d\t", slow->val);
		fast = slow;
		slow = n;
	}
	printf("\n");
}

void rev(node *n) {
	node *slow = (node*) malloc(sizeof(node));
	node *curr = (node*) malloc(sizeof(node));
	node *fast = (node*) malloc(sizeof(node));
	int c = count(n);
	if (c==1) {printf("Only 1 node!\n"); return;}
	slow = n;
	curr = n;
	fast = n;
	while (fast!=NULL) {
		fast = fast->next;
	}
	while (c>1) {
		while (curr->next!=fast) {
			curr = curr->next;
		}

		int temp = curr->val;
		curr->val = slow->val;
		slow->val = temp;
		c-=2;
		fast = curr;
		slow = slow->next;		
	}
}

int main() {
	int v, v2;
	printf("Enter value of header: ");
	scanf("%d", &v);
	node *header = (node*) malloc(sizeof(node));
	header->val = v;
	header->next = NULL;
	printf("\t\tMENU\n1. Insert\n2. Delete\n3. Count\n4. Reverse Print\n5. Reverse\n6. Exit");
	printf("\nEnter your choice: ");
	int c;
	scanf("%d", &c);
	while (c!=6) {
		switch (c) {
			case 1:
				printf("Enter value after which value is to be inserted and value to be inserted: ");
				scanf("%d %d", &v, &v2);
				insert(header, v, v2);
				break;
			case 2:
				printf("Enter node to delete: ");
				scanf("%d", &v);
				delete(header, v);
				break;
			case 3:
				printf("There are %d nodes\n", count(header));
				break;
			case 4:
				revprint(header);
				break;
			case 5:
				rev(header);
				break;
			case 6:
				break;
			default:
				printf("Invalid input!");
		}
		printf("Enter next choice: ");
		scanf("%d", &c);
	}
	return 0;
}

