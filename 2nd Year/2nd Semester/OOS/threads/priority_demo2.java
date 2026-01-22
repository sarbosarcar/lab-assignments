class PriorityDemo2 extends Thread {
	public void run() {
		System.out.println("Initial priority = " + this.getPriority());
		this.setPriority(8);
		System.out.println("After change = " + this.getPriority());
	}
	public static void main(String args[]) {
		Thread t = Thread.currentThread();
		System.out.println("Main's initial priority = " + t.getPriority());
		t.setPriority(7);
		System.out.println("After change = ");
		System.out.println("New priority = " + t.getPriority());
		new PriorityDemo2().start();	
	}
}
