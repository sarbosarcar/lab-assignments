import java.net.Socket;
import java.io.*;
class ResourceTesting {
	public static void main(String args[]) {
		try (FileInputStream fis = new FileInputStream("a.txt");
		     FileOutputStream fos = new FileOutputStream("b.txt");
		     Socket s = new Socket("localhost", 6789)) {
			System.out.println("Inside a try-with-resources block");
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
}
