/*
 * /
 *
 *15. Imagine a toll booth and a bridge. Cars passing by the booth are expected to pay an amount of Rs.
50/- as toll tax. Mostly they do but sometimes a car goes by without paying. The toll booth keeps
track of the number of the cars that have passed without paying, total number of cars passed by,
and the total amount of money collected. Execute this with a class called “Tollbooth” and print
out the result as follows:
The total number of cars passed by without paying.
Total number of cars passed by.
Total cash collected.
*/

class TollBooth {
	int total=0;
	int cost=0;
	int noPay=0;
	void passedWithoutPaying() {
		noPay++;
		total++;
	}
	void passed() {
		cost+=50;
		total++;
	}
	void disp() {
		System.out.println("The total number of cars that passed by without paying: " + noPay + "\nTotal number of cars that passed by: " + total + "\nTotal cash collected: " + cost);
	}
	public static void main(String args[]) {
		TollBooth t = new TollBooth();
		t.passed();
		t.passed();
		t.passedWithoutPaying();
		t.passedWithoutPaying();
		t.passed();
		t.disp();
	}
}	
