class MyThread extends Thread {
	int[] a;
	MyThread(int[] a) {
		this.a = a;
		start();
	}
	public void run() {
		java.util.Arrays.sort(a);
		System.out.println("Child completed sorting");
	}
}
class JoinDemo {
	public static void main(String args[]) throws Exception {
		int[] a = {1,0,3,4,5,2,8,7};
		MyThread ob = new MyThread(a);	
		ob.join();
		System.out.println("The array elements are: ");
		for (int i=0; i<a.length; i++)
			System.out.println(a[i] + "\t");
	}
}
