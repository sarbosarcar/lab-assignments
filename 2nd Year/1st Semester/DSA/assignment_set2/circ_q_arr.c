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

typedef struct queue {
	int a[MAX_SIZE];
	int front, rear;
} queue;

int overflow(queue*);
int underflow(queue*);

int enqueue(queue *q, int v) {
	if (overflow(q)) return 0;
	else {
		q->rear = (q->rear+1)%MAX_SIZE;
		q->a[q->rear] = v;
		return 1;
	}
}

int dequeue(queue *q) {
	if (underflow(q)) {
		return -1;
	}
	else {
		q->front = (q->front+1)%MAX_SIZE;
		int v = q->a[q->front];
		return v;
	}
}

int count(queue *q) {
	int c=0;
	int i = q->front;
	while (i!=q->rear) {
		i = (i+1)%MAX_SIZE;
		c++;
	}
	return c;
}

int overflow(queue *q) {
	if (count(q)==MAX_SIZE) return 1;
	return 0;
}

int underflow(queue *q) {
	if (q->front==q->rear) return 1;
	return 0;
}

queue *create() {
	queue *q = (queue*) malloc(sizeof(queue));
	q->rear = -1;
	q->front = -1;
	return q;
}

int main() {
	int c=0;
	queue *q = create();
	do {
		printf("\t\tMENU\n1. Construct a queue\n2. Insert an element\n3. Delete an element\n4. Count no. of elements\n5. Check for overflow\n6. Check for undeflow\n7. Exit\n");
		printf("Enter an option: ");
		scanf("%d", &c);
//		switch (c) {
			if (c==1) {
				//queue *q = create();
				printf("Successfully created a queue!\n");
			}//break;
			else if (c==2) {
				int v;
				printf("Enter value to insert: ");
				scanf("%d", &v);
				int r = enqueue(q, v);
				if (r) printf("Successfully inserted element\n");
				else printf("Could not insert element\n");
			}//break;
			else if (c==3) {
				int r = dequeue(q);
				if (r>=0) printf("Successfully deleted element: %d!\n", r);
				else printf("Could not delete any element!\n");
			}//	break;
			else if (c==4) {
				int ct = count(q);
				printf("There are %d elements\n", ct);
			} //break;
			else if (c==5) {
				if (overflow(q)) printf("Overflow!\n");
				else printf("Not Overflow!\n");
			}//	break;
			else if (c==6) {
				if (underflow(q)) printf("Undeflow!\n");
				else printf("Not Underflow!\n");
			}//	break;
			else if (c==7) {
				printf("Exiting...\n");
			}//	break;
			else {
				printf("Invalid choice!\n");
			}

	} while (c!=7);
	return 0;
}
