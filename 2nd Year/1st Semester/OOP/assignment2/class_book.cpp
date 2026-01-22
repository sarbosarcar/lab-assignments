#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

class Book {
	// isbn, title, list of authors, price
	string isbn, title;
	string *authors;
	double price;
	int num_of_auth;
	public:
		Book(string i, string t, string *a, int n,  double p) {
			isbn = i; title = t;
			authors = new string[n];
			for(int i=0; i<n; i++) {
				authors[i] = a[i];
			}
			price = p;
			num_of_auth = n;
		}
		Book (Book &b) {
			isbn = b.get_isbn();
			title = b.get_title();
			price=b.get_price();
			int n = b.get_num();
			authors = new string[n];
			for (int i=0; i<n; i++) {
				authors[i] = (b.get_list())[i];
			}
			num_of_auth = b.get_num();
		}
		Book () {
			isbn=""; title=""; price=0;
		}
		string get_isbn() {return isbn;}
		string get_title() {return title;}
		double get_price() {return price;}
		string* get_list() {return authors;}
		int get_num() {return num_of_auth;}
		
};

class BookStore {
	Book *b;
	int  num;
	public: 
		BookStore (Book *bks, int n) {
			b = new Book[n];
			for (int i=0; i<n; i++) {
				b[i] = bks[i];
			}
			num = n;
		}
		void books() {
			string uniq[1000];
			int ct=0;
			int k=0;
			for (int i=0; i<num; i++) {
				string curr = b[i].get_isbn();
				bool flag = 0;
				for (int j=0; j<i; j++) {
					if (b[j].get_isbn()==curr) {flag=1; break;}
				}
				if (!flag) {uniq[k] = curr; k++;}
			}	
				for (int i=0; i<k; i++) {
					cout << uniq[i] << endl;
					cout << "Count: " << this->noOfCopies(uniq[i]) << endl;
				}
		}
		int un_ct() {
			int ct=0;
			for (int i=0; i<num; i++) {
				string curr = b[i].get_isbn();
				bool flag = 0;
				for (int j=0; j<i; j++) {
					if (b[j].get_isbn()==curr) {flag=1; break;}
				}
				if (!flag) {ct++;}
			}
			return ct;
		}
		int noOfCopies(string i) {
			int c=0;
			for (int j=0; j<num; j++) {
				if (b[j].get_isbn()==i) c++;
			}
			return c;	
		}
		double totalPrice() {
			double sum=0;
			for (int i=0; i<num; i++) {
				sum+= (b[i].get_price());
			}
			return sum;
		}
				
								
};

int main() {
	int n=100;
	Book b[n];
	for (int i=0; i<n; i++) {
		//isbn, title, authors, num, price
		string isbn = to_string(rand()%10);
		char buff[100];
		sprintf(buff, "Book %d", i+1);
		string title = buff;
		string auth[2] = {"Author 1", "Author 2"};
		double price = rand()%500;
		b[i] = Book(isbn, title, auth, 2, price);
	}
	BookStore bs(b, n);
	bs.books();
	cout << "Total price: " << bs.totalPrice();
}
	
