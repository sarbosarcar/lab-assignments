class MyThread implements Runnable {
	public void run() {
		for (int i = 0; i<=4; i++) 
			System.out.println("In MyThread: " + i);
	}
}
class MyThreadRunnable {
	public static void main(String args[]) {
		Thread ob = new Thread(new MyThread());
		ob.start();
	}
}
