public class Sample {
	int num = 1;
	static int MAX;
	public void printOdd() {
		synchronized (this) {
			while (num<MAX) {
				while (num%2==0) {
					try {
						wait();
					}
					catch (Exception e) {
						System.out.println(e);	
					}
				}
				System.out.print(num + " ");
				num++;
				notify();
			}
		}
	}
	public void printEven() {
		synchronized (this) {
			while (num<MAX) {
				while (num%2==1) {	
					try {
						wait();
					}
					catch(Exception e) {
						System.out.println(e)	;
					}
				}
				System.out.print(num + " ");
				num++;
				notify();
			}
		}
	}
	public static void main (String args[]) {
		MAX = 8;	
		Sample obj = new Sample();
		Thread EvenThread = new Thread(new Runnable() {
			public void run() {
				obj.printEven();
			}
		});
		Thread OddThread = new Thread(new Runnable() {
			public void run() {
				obj.printOdd();
			}
		});
		EvenThread.start();
		OddThread.start();
	}
}
