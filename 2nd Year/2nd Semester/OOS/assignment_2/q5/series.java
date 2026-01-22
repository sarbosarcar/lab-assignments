class Series {
	int i = 0;
	int sum = 0;

}

class Odd extends Thread {
	Series s;
	int i = 1;
	int sum = 0;
	Odd(Series s) {	
		this.s = s;
	}
	public void run() {
			while (i<=99) {
				sum += i;
				i+=2;
			}
			synchronized(s) {
				s.sum+=sum;
			}
	}
}
							
			
class Even extends Thread{
	Series s;
	int i = 2;
	int sum = 0;
	Even(Series s) {
		this.s = s;
	}
	public void run() {
		while (i<=100) {
			sum += i;
			i+=2;
		}
		synchronized(s) {
			s.sum += sum;
		}
	}
}

class Main {
	public static void main(String args[]) throws Exception{
		Series s = new Series();
		Odd o = new Odd(s);
		Even e = new Even(s);
		o.start();
		e.start();
		Thread.sleep(500);
		System.out.println("(1+3+...+99) = " + o.sum + "\n(2+4+...+100) = " + e.sum + "\n(1+2+3+...+100) = " + s.sum);
	}
}
