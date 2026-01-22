#include <iostream>
using namespace std;

class Queue {
	int *data;
	int front, rear, len;
	public:
		Queue(int l) {
			data = new int[l];
			front = rear = -1;
			len = l;
		}
		void add(int x) {

			if ((front==0 && rear == len-1) || ((rear+1)%len==front)) cout << "Ovberflow!";
			else {
			if (front==-1) {front=rear=0; data[rear]=x;}
			else if (rear==len-1 && front!=0) { rear=0; data[rear] = x;}  			
			else {
				rear++;
				data[rear] = x;
			}
		}
		}
		int remove() {
			if (front==-1) {cout <<"Underflow!";}
			int x = data[front];
			data[front] = -1;
			
			if (front==rear) front= rear = -1;

			else if (front==len-1) front=0;
			else front++;
			return x;
		}
				
				
		void disp() {
			cout << "Contents of the stack are: " << endl;
			for (int i=front; i<=rear; i++) {
				cout << data[i] << endl;
			}
		}
};
int main() {
	Queue q(10);
	q.add(2);
	q.add(3);
	q.add(4);
	q.add(5);
	q.remove();
	q.remove();
	q.disp();
}
		
