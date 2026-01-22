#include <iostream>

using namespace std;

class Stack {
	int *buffer, top, max_length;
	public: 
		Stack(int l) {
			buffer = new int[l];
			max_length = l;
			top = -1;
		}
		void push(int x) {
			if (top+1<max_length) 
			buffer[++top] = x;
			else cout << "Overflow!";
		}
		int pop() {
			if (top>=0) {
				return buffer[top--];
			}
			else cout <<"Underflow!";
		}		
		void disp() {
			if (top>=0) {
			cout << "Contents of the stack are: " << endl;
			for (int i=0; i<=top; i++) {
				cout << buffer[i] << endl;
			}
			}
			else cout << "Stack is empty" << endl;
		}
		~Stack() {
			delete buffer;
			cout << "Stack deleted!" << endl;
		}
};


int main() {
	Stack s(10);
	s.push(2);
	s.push(3);	
	s.push(4);	
	s.push(5);
	int popped = s.pop();
	s.disp();
}
	
