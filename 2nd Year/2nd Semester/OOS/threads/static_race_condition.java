class Counter {
	static int val = 0;
	void inc() {	
		synchronized(Counter.class) {
			val++;
		}
	}
	static void dec() {
		synchronized(Counter.class) {
			val--;
		}
	}
}

class StaticRaceConditionDemo extends Thread {
	Counter c;
	StaticRaceConditionDemo(Counter c) {
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
		StaticRaceConditionDemo rc = new StaticRaceConditionDemo(c);
		for (int i=0; i<10000; i++) {
			c.inc();
		}
		rc.join();
		System.out.println("Final value = "  + c.val);
	}
}
	
