import java.io.*;

class BRDemo {
	public static void main(String args[]) {
		BufferedReader br = null;
		int nextByte;
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			String str = br.readLine();
			System.out.println("The string is >>> " + str);
		}
		catch (IOException ie) {
			System.out.println(ie);
		}
		finally {
			try {
				br.close();
			}
			catch(IOException i) {
				System.out.println(i);
			}
		}
	}
}
