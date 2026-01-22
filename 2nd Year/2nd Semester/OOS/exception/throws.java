import java.io.*;
class ThrowsDemo {
	static void f() throws java.io.IOException {
		throw new IOException("test");
	}
	public static void main(String args[] ) {
		try {
			f();
		}
		catch (IOException i) {
			System.out.println(i);
		}
	}
}
