import java.util.Scanner;
class Book {
	String author, title, publisher;
	int cost, stock;
	Book(String n, String a, String p, int c, int s) {
		author = a;
		title = n;
		publisher = p;
		cost = c;
		stock = s;
	}
}

class Bookstore {
	int n, size;
	Book[] books;
	Bookstore(int size) {
		books = new Book[size];
		n = -1;
		this.size = size;
	}
	void add(Book b) {
		if (n==size-1) {
			System.out.println("No space left!");
		}
		else {
			books[++n] = b;
		}
	}
	void search(String a, String t, int c) {
		for (int i=0; i<=n; i++) {
			if (books[i].title.equals(t) && books[i].author.equals(a)) {
				if (books[i].stock>=c) {
				System.out.println("Total cost of " + c + " copies is " + books[i].cost*c);
				}
				else {
				System.out.println("Required copies not in stock!");
				}
				return;
			}
		}
				System.out.println("Book not available!");
	}
	
}

class Demo {
	public static void main(String args[]) {
		Bookstore b = new Bookstore(10);
		b.add(new Book("Harry Potter", "JK Rowling", "Penguin", 600, 12));
		b.add(new Book("Sapiens", "YN Harari", "Vintage", 400, 6));
		b.add(new Book("Diary of a Young Girl", "Anne Frank", "Penguin", 200, 3));
		Scanner myObj = new Scanner(System.in);

    System.out.println("Enter title, author and number of copies: ");
    String name = myObj.nextLine();
    String author = myObj.nextLine();
    int copies = myObj.nextInt();
	//System.out.println(name + " " + author);
		b.search(author, name, copies);
	}
}
