class Series {
	int MAX;
	double sum = 0;
	boolean den = true;
	int i = 1;
	long buf = 0;
	Series(int in) {
		MAX = in;
	}
	public long fac(int i) {
		if (i==1) {
			return 1;
		}
		else {
			return i*fac(i-1);
		}
	}
	/*public void run() {
		while (true) {
			while (!den);
			buf = fac(i++);
			den = false;
		}
	}*/
}

class Main {
	public static void main(String args[]) throws Exception{
		Series s = new Series(10);
		Thread t1 = new Thread(new Runnable() {
			public void run() {
				while (s.i<=s.MAX) {
                        	while (!s.den);
	                        s.buf = s.fac(s.i);
				//System.out.println(s.buf);
				s.den = false;
               			}
			}
			});
		Thread t2 = new Thread(new Runnable() {
			public void run() {
				while (s.i<=s.MAX) {
				//System.out.println(s.i + " " + s.buf + " " + (s.i / (double) s.buf));
				while (s.den);
				s.sum+=(s.i / (double) s.buf);
				s.i++;
				s.den = true;
				}
			}
			});
		t1.start();	
		t2.start();
		Thread.sleep(2000);
		System.out.println("Sum is " + s.sum);
	}
}
