import java.util.Scanner;
	
class Next {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter roll no.: ");
		int roll = sc.nextInt();
		System.out.print("Enter name: ");
		sc.nextLine();
		String name = sc.nextLine();
		System.out.println("Name is " + name + ", and roll number is " + roll);
	}
}
