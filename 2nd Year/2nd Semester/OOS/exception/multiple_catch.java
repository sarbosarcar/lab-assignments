class Main {
	public static void main(String args[]) {
		try {
			String s = args[0];
			int r = 100/0;
		}
		catch (ArrayIndexOutOfBoundsException ae) {
			System.out.println(ae);
		}
		catch (ArithmeticException a) {
			System.out.println(a);
		}
	}
}
