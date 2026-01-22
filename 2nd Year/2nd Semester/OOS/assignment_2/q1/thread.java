
class Main extends Thread {
	public static void main(String args[]) {
		Main thread = new Main();
		thread.start();
		System.out.println("In main thread");
	}
	public void run() {
		System.out.println("In child thread");
	}
}

