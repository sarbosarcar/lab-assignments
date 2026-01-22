/*. Write two interfaces “Fruit” and “Vegetable” containing methods ‘hasAPeel’ and ‘hasARoot’.
 * Now write a class “Tomato” implementing Fruit and Vegetable. Instantiate an object of Tomato.
 * Print the details of this object.*/


interface  Fruit {
	boolean hasAPeel();
	boolean hasARoot();
}

interface Vegetable {
	boolean hasAPeel();
	boolean hasARoot();
}

class Tomato implements Fruit, Vegetable {
	public boolean hasAPeel() {
		System.out.println("Tomato has a peel!");
		return true;
	}
	public boolean hasARoot() {
		System.out.println("Tomato has a root!");
		return true;
	}
	public static void main(String args[]) {
		Tomato t = new Tomato();
		t.hasAPeel();
		t.hasARoot();
	}
}

