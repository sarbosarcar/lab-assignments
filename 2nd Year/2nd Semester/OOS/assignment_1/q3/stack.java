class Stack {
	/*
 * push, pop, print
 * const to create an array of integers, size supplied by user
 * create stack to hold maximum of 30
 * push 10,20,30,15,9
 * print
 * pop thrice
 * print
 *
 */
	int[] s;
	int n;
	int top=-1;
	Stack(int t) {
		n = t;
		s = new int[t];
	}
	void push(int v) {
		if (top==n-1) {
			System.out.println("Overflow!");
		}
		s[++top] = v;
	}
	int pop() {
		if (top<0) {
			System.out.println("Underflow!");
		}
		top--;
		return s[top];
	}
	void print() {
		System.out.println("The elements are:");
		for (int i = 0; i<=top; i++) {
			System.out.println(s[i]);
		}
	}
}

class Demo {
	public static void main(String args[]) {
		Stack s = new Stack(30);
		s.push(10); s.push(20); s.push(30); s.push(15); s.push(9);
		s.print();
		s.pop();
		s.pop();
		s.pop();
		System.out.println("Popped thrice!");
		s.print();
	}
}

