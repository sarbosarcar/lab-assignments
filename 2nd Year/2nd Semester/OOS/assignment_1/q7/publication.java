abstract class Publication {
	int noOfPages, price;
	String publisherName;
	/*Publication(int n, int p, String pn) {
		noOfPages = n;
		price = p;
		publisherName = pn;
	}*/
	void set_page(int n)  {
		noOfPages = n;
	}
	void set_price(int p) {
		price = p;
	}
	void set_name(String n) {
		publisherName = n;
	}
	int get_page() {
		return noOfPages;
	}
	int get_price() {
		return price;
	}
	String get_name() {
		return publisherName;
	}
	void disp() {
		System.out.println("Publisher's name is " + publisherName + " with " + noOfPages +  " pages and price " + price);
	}

}

class Book extends Publication {
	void disp() {
		System.out.println("Details for Book:");
		super.disp();
	}
}

class Journal extends Publication {
	void disp() {
                System.out.println("Details for Journal:");
                super.disp();
	}
}

class Library {
	Publication[] pub;
	Library(int s) {
		pub = new Publication[s];
	}
	public static void main(String args[]) {
		Library l = new Library(5);
		for (int i=0; i<3; i++) {
			l.pub[i] = new Book();
			l.pub[i].set_name("Book Publisher " + i);
			l.pub[i].set_price(100*(i+1)+i*i);
			l.pub[i].set_page((i+1)*50+i);
		}
		for (int i=3; i<5; i++) {
			l.pub[i] = new Journal();
			
			l.pub[i].set_name("Journal Publisher " + i);
			l.pub[i].set_price(100*i+i*i);
			l.pub[i].set_page(i*50+i);
		}
		for (int i=0; i<5; i++) {
			l.pub[i].disp();
		}
	}
}
