/*
 * construct
 * insert
 * delete
 * no of elements
 * overflow/underflow\
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

typedef struct node {
	int val;
	struct node *next;
} node;

typedef struct queue {
	int cap;
	node *front;
	node *rear;
} queue;

int overflow(queue*);
int underflow(queue*);
int count(queue*);

int enqueue(queue *q, int v) {
	if (!overflow(q)) {
		node *tmp = (node*) malloc(sizeof(node));
		tmp->val = v;
		tmp->next = NULL;
		if (q->front==NULL) {
			q->front = tmp;
			q->rear = tmp;
		}
		q->rear->next = tmp;
		q->rear = tmp;
		return 1;
	}
	else return 0;
}

int dequeue(queue *q) {
	if (!underflow(q)) {
		node *t = q->front;
		q->front = q->front->next;
		if (q->rear==t) q->rear = NULL;
		int d = t->val;
		free(t);
		return d;
	}
	else return -1;
}

int count(queue *q) {
	int c=0;
	if (!q->front) return 0;
	node *t = q->front;
	while (t!=q->rear) {
		c++;
		t = t->next;
	}
	return c+1;
}

int overflow(queue *q) {
	if (count(q)==q->cap) return 1;
	return 0;
}

int underflow(queue *q) {
	if (!q->rear && !q->front) return 1;
	return 0;
}

queue *create() {
	queue *q = (queue*) malloc(sizeof(queue));
	q->rear = NULL;
	q->front = NULL;
	q->cap = MAX_SIZE;
	return q;
}

int main() {
	int c=0;
	queue *q = create();
	do {
		printf("\t\tMENU\n1. Construct a queue\n2. Insert an element\n3. Delete an element\n4. Count no. of elements\n5. Check for overflow\n6. Check for undeflow\n7. Exit\n");
		printf("Enter an option: ");
		scanf("%d", &c);
			if (c==1) {
				printf("Successfully created a queue!\n");
			}
			else if (c==2) {
				int v;
				printf("Enter value to insert: ");
				scanf("%d", &v);
				int r = enqueue(q, v);
				if (r) printf("Successfully inserted element\n");
				else printf("Could not insert element\n");
			}
			else if (c==3) {
				int r = dequeue(q);
				if (r>=0) printf("Successfully deleted element: %d!\n", r);
				else printf("Could not delete any element!\n");
			}
			else if (c==4) {
				int ct = count(q);
				printf("There are %d elements\n", ct);
			}
			else if (c==5) {
				if (overflow(q)) printf("Overflow!\n");
				else printf("Not Overflow!\n");
			}
			else if (c==6) {
				if (underflow(q)) printf("Undeflow!\n");
				else printf("Not Underflow!\n");
			}
			else if (c==7) {
				printf("Exiting...\n");
			}
			else {
				printf("Invalid choice!\n");
			}

	} while (c!=7);
	return 0;
}
