class SleepDemo {
	public static void main(String args[]) {
		for (;;) {
			System.out.println("Local date and time = " + new java.util.Date());	
			try {
				Thread.sleep(2000);
			}
			catch(InterruptedException ie) {
				System.out.println(ie);
			}
		}
	}
}
