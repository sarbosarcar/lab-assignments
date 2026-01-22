class Timer extends Thread {
	public void run() {
		while (true) {
			System.out.println(new java.util.Date());
			try {
				Thread.sleep(1000);
			}
			catch(InterruptedException ie) {
				System.out.println("Timer interrupted");
				return;
			}	
		}
	}
}
class InterruptDemo {
	public static void main(String args[]) throws Exception {	
		Timer t = new Timer();
		t.start();
		Thread.sleep(5000);
		t.interrupt();
	}
}
