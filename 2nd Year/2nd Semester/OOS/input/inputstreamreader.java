import java.io.*;

class Input {
	public static void main(String args[]) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Enter roll no.: ");
		try {
			int roll = Integer.parseInt(br.readLine());
			System.out.print("Enter name: ");
			String name = br.readLine();
			System.out.println("Name is " + name + ", roll number is " + roll);
		}
		catch(Exception e) {
			System.out.println(e);
		}
	}
}
