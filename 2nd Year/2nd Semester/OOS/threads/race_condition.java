class Counter {
	int val = 0;
	void inc() {	
		val++;
	}
	void dec() {
		val--;
	}
}

class RaceConditionDemo extends Thread {
	Counter c;
	RaceConditionDemo(Counter c) {
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
		RaceConditionDemo rc = new RaceConditionDemo(c);
		for (int i=0; i<10000; i++) {
			c.inc();
		}
		rc.join();
		System.out.println("Final value = "  + c.val);
	}
}
	
