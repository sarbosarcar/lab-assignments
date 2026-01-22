import java.util.Scanner;

class Average {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int sum = 0, count = 0;
		try {
			do {
				System.out.print("Enter number : ");
				int num = sc.nextInt();
				sum += num;
				count++;
			} while (sc.hasNextInt());
		}
		catch(Exception e) {
			e.printStackTrace();
		}
		finally {
			double avg = (double) sum/count;
			System.out.println("Average is "  + avg);
		}
	}
}
			
