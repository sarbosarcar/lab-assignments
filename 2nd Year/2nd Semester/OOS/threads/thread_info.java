class ThreadInfo {
	public static void main(String args[]) {
		Thread t = Thread.currentThread();
		System.out.println("Current thread = " + t);
		System.out.println("Name = " + t.getName());
		System.out.println("Id = " + t.getId());
		System.out.println("Priority = " + t.getPriority());
		System.out.println("State = " + t.getState());
		System.out.println("Changing name & priority of thread: ");
		t.setName("Primary");
		t.setPriority(8);
		System.out.println("After name and priority changed: ");
		System.out.println("New name = " + t.getName());
		System.out.println("New priority = " + t.getPriority());
	}
}
