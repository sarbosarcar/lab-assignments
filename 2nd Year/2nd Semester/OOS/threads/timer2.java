class Timer extends Thread {
	public void run() {
		while (true) {
			System.out.println(new java.util.Date());
			try {Thread.sleep(2000);}
			catch(Exception e) {System.out.println(e);}
			if (Thread.interrupted()) {
				System.out.println("Timer was interrupted");
				return;
			}
		}
	}
}
class InterruptDemo2 {
	public static void main(String args[]) throws Exception {	
		Timer t = new Timer();
		t.start();
		Thread.sleep(5000);
		t.interrupt();
	}
}
