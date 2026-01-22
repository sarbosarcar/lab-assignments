import java.io.*;

class FISDemo {
	public static void main(String args[]) {
		FileInputStream fis = null;
		int nextByte;
		try {
			fis = new FileInputStream("a.txt");
			while ((nextByte=fis.read())!=-1) {
				System.out.print((char) nextByte);
			}
		}
		catch(IOException e) {
			System.out.println(e);
		}
		finally {
			try {
				fis.close();
			}	
			catch(IOException ie) {
				System.out.println(ie);	
			}
		}
	}
}
