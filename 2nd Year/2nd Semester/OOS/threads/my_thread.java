class MyThread extends Thread {
	public void run() {
		for (int i=0; i<=4; i++) {
			System.out.println("In MyThread: " + i);
		}
	}
}
class MyThreadDemo {
	public static void main(String args[]) {
		MyThread ob = new MyThread();
		ob.start();
	}
}
