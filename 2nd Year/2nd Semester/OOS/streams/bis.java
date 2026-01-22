import java.io.*;

class BISDemo {
	public static void main(String args[]) {
		BufferedInputStream bis = null;
		int nextByte;
		try {
			bis = new BufferedInputStream(new FileInputStream("a.txt"));
			while ((nextByte = bis.read()) != -1) {
				System.out.print((char)nextByte);
			}
		}
		catch (IOException ie) {
			System.out.println(ie);
		}
		finally {
			try {
				bis.close();
			}
			catch(IOException i) {
				System.out.println(i);
			}
		}
	}
}
