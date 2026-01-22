import java.util.Scanner;

class Demo {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter name: ");
		String name = sc.nextLine();
		System.out.print("Enter gender: ");
		char gen = sc.next().charAt(0);
		System.out.print("Enter age: ");                                                                                        int age = sc.nextInt();
		System.out.print("Enter Mobile No.: ");                                                                                 long mobno = sc.nextLong();
		System.out.print("Enter CGPA: ");                                                                                       double cgpa = sc.nextDouble();
		System.out.println("Name is " + name + ", gender is " + gen + ", age is "  + age + "\nMobile no. is "  +mobno + ", CGPA is "  + cgpa);
	}
}	
	
		
