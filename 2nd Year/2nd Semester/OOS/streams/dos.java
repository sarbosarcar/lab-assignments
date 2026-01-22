import java.io.*;

class DOSDemo {
	public static void main(String args[]) {
		DataOutputStream dos = null;
		int nextByte;
		try {
			dos = new DataOutputStream(new BufferedOutputStream(new FileOutputStream("b.txt")));
			//dos = new DataOutputStream(new BufferedOutputStream(System.out));
			dos.writeInt(65);
			dos.writeInt(67);
			dos.flush();
		}
		catch (IOException ie) {
			System.out.println(ie);
		}
		finally {
			try {
				dos.close();
			}
			catch(IOException i) {
				System.out.println(i);
			}
		}
	}
}
