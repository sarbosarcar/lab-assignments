class Counter {
	int val = 0;
	Object o = new Object();
	void inc() {	
		synchronized(o) {
			val++;
		}
	}
	void dec() {
		synchronized(o) {
			val--;
		}
	}
}

class RaceConditionDemo3 extends Thread {
	Counter c;
	RaceConditionDemo3(Counter c) {
		this.c = c;
		start();
	}
	public void run() {
		for (int i=0; i<10000; i++) {
			c.dec();
		}
	}
	public static void main(String args[]) throws Exception{
		Counter c = new Counter();
		RaceConditionDemo3 rc = new RaceConditionDemo3(c);
		for (int i=0; i<10000; i++) {
			c.inc();
		}
		rc.join();
		System.out.println("Final value = "  + c.val);
	}
}
	
