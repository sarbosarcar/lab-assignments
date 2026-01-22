class Rethrow {
	public static void main(String args[]) {
	try {
		try {
			throw new Exception("Thrown from try!");
		}
		catch (Exception e) {
			System.out.println(e);
			throw new Exception("Thrown from catch");
		}
	}
	catch (Exception e1) {
			System.out.println(e1);
	}
}
}	
