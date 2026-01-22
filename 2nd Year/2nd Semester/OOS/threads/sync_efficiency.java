class X extends Thread {
	int i1, i2;
	Object o1 = new Object();
	Object o2 = new Object();
	void inc1() {
		synchronized(o1) {
			i1++;
		}
	}
	void inc2() {
		synchronized(o2) {
			i2++;
		}
	}
	public void run() {
		for (int i=0; i<10000; i++) {
			inc2();
		}
	}
	public static void main(String args[]) throws InterruptedException {	
		X o = new X();
		for (int i=0; i<10000; i++) {
			o.inc1();
		}
		o.join();
		System.out.println("Final values\ni1 = " + o.i1);
		System.out.println("i2 = " + o.i2);
	}		
}

