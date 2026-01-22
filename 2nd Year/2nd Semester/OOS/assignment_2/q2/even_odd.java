class EvenOdd {
	int num = 1;
	static int MAX = 8;
	public synchronized void printEven() {
		if (num%2==0) {
			System.out.print(num + " ");
			num++;
			notify();
		}
		else {
			try {	
				wait();
			}
			catch(Exception e) {
			}
		}
	}
	public synchronized void printOdd() {
		if (num%2==1) {
			System.out.print(num + " ");
			num++;
			notify();
		}
		else {
			try {
				wait();
			}
			catch(Exception e) {
			}
		}
	}	
}

class MainThread {
	public static void main(String args[]) throws Exception {	
		EvenOdd eo = new EvenOdd();
		Thread EvenThread = new Thread(new Runnable() {
			public void run() {
				while (eo.num<=eo.MAX) {
				eo.printEven();}
			}});
		Thread OddThread = new Thread(new Runnable() {
			public void run() {
				while (eo.num<=eo.MAX) {
				eo.printOdd();}
			}});
		EvenThread.start();
		OddThread.start();
	Thread.sleep(1000);
	System.out.println(" ");
	}
}	
