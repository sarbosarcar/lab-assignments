import java.io.*;

class FOSDemo {
	public static void main(String args[]) {
		FileInputStream fis = null;
		FileOutputStream fos = null;
		int nextByte;
		try {
			fis = new FileInputStream("a.txt");
			fos = new FileOutputStream("b.txt");
			while ((nextByte=fis.read())!=-1) {
				fos.write((char)nextByte);
			}
		}
		catch(IOException e) {
			System.out.println(e);
		}
		finally {
			try {
				fis.close();
				fos.close();
			}	
			catch(IOException ie) {
				System.out.println(ie);	
			}
		}
	}
}
