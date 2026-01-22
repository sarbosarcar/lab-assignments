/*
 * 13. Create a base class “Automobile”. An Automobile contains data members ‘make’, ‘type’,
 * ‘maxSpeed’, ‘price’, ‘mileage’, ‘registrationNumber’ etc. with their reader/writer methods. Now
 * create two sub-classes “Track” and “Car”. Track has data members ‘capacity’, ‘hoodType’,
 * ‘noOfWheels’ etc. Car has data members ‘noOfDoors’, ‘seatingCapacity’ and their reader/writer
 * methods. Create a main() function to demonstrate this.
 */

class Automobile {
	String make, type, registrationNumber;
	double maxSpeed, price, mileage;
	
	void set_make(String m) {make=m;}
	void set_type(String t) {type=t;}
	void set_registrationNumber(String r) {registrationNumber=r;}
	void set_speed(double m) {maxSpeed=m;}
	void set_price(double p) {price=p;}
	void set_mileage(double m) {mileage=m;}

	String get_make() {return make;}
	String get_type() {return type;}
	String get_registrationNumber() {return registrationNumber;}
	double get_speed() {return maxSpeed;}
	double get_price() {return price;}
	double get_mileage() {return mileage;}
	
	void disp() {
		System.out.println("Make: " + make);
		System.out.println("Type: " + type);
		System.out.println("Registration Number: " + registrationNumber);
		System.out.println("Max Speed: " + maxSpeed);
		System.out.println("Price: " + price);
		System.out.println("Mileage: " + mileage);
	}
}

class Track extends Automobile {
	int capacity, noOfWheels;
	String hoodType;
	
	void set_capacity(int c) {capacity=c;}
	void set_wheel(int w) {noOfWheels=w;}
	void set_hood(String s) {hoodType=s;}
	
	int get_capacity() {return capacity;}
	int get_wheel() {return noOfWheels;}
	String get_hood() {return hoodType;}
	
	void disp() {
		System.out.println("\t\tSpecifications for Track: ");
		super.disp();
		System.out.println("Capacity: " + capacity);
		System.out.println("No of wheels: " + noOfWheels);
		System.out.println("Hood Type: " + hoodType);
	}
}

class Car extends Automobile{
	int noOfDoors, seatingCapacity;
	
	void set_doors(int d) {noOfDoors=d;}
	void set_capacity(int c) {seatingCapacity=c;}
	
	int get_doors() {return noOfDoors;}
	int get_capacity() {return seatingCapacity;}

	void disp() {
		System.out.println("\t\tSpecifications for Car: ");
		super.disp();
		System.out.println("Seating Capacity: " + seatingCapacity);
		System.out.println("No of doors: " + noOfDoors);
	}

}

class Demo {
	public static void main(String args[]) {
		Track t = new Track();
		Car c = new Car();
		/*
 * String make, type, registrationNumber;
 *         double maxSpeed, price, mileage;*/
		t.set_make("ABC"); t.set_type("Type 2"); t.set_registrationNumber("R0N241Z");
		t.set_speed(85.5); t.set_price(12000000); t.set_mileage(12.42);
		t.set_wheel(4); t.set_capacity(10); t.set_hood("Type 1");

		c.set_make("EFG"); c.set_type("Type 1"); c.set_registrationNumber("R0M12YQ");
		c.set_speed(90.25); c.set_price(850000); c.set_mileage(9.96);
		c.set_capacity(10); c.set_doors(4);
	    	
		t.disp();
		c.disp();
	}
}	 
