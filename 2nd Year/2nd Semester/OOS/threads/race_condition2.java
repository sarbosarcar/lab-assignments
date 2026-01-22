class Counter {
	int val = 0;
	synchronized void inc() {	
		val++;
	}
	synchronized void dec() {
		val--;
	}
}

class RaceConditionDemo2 extends Thread {
	Counter c;
	RaceConditionDemo2(Counter c) {
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
		RaceConditionDemo2 rc = new RaceConditionDemo2(c);
		for (int i=0; i<10000; i++) {
			c.inc();
		}
		rc.join();
		System.out.println("Final value = "  + c.val);
	}
}
	
