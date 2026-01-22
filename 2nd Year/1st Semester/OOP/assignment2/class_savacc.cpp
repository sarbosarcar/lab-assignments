#include <iostream>
#include <cstdlib>
#include <cstdio>
#define r 0.04

using namespace std;


class SavingsAccount{
	string name;
	const int uid;
	double balance;
	static int id;
	public: 
		SavingsAccount():uid(id) {
			id++;
			name = "";
			balance=0;
		}
		SavingsAccount(string n, double b):uid(id) {
			id++;
			name = n;
			balance = b;
		}
		double interest() {
			return r*balance;
		}
		void deposit(double amt) {
			if ((balance+amt)<=100000) balance+=amt;
			else cout << "Exceeded limit while adding balance" << endl;
		}	
		void withdraw(double amt) {
			if ((balance-amt)>=1000) balance-=amt;
			else cout << "Insufficient balance while withdrawing" << endl;
		}
		void set_name(string s) {
			name = s;
		}
		void set_balance(double b) {
			balance = b;
		}
		

};

int SavingsAccount::id = 1;


int main() {
	srand(time(NULL));
	SavingsAccount s[100];
	for (int i=0; i<100; i++) {
		char buffer[100];
		sprintf(buffer, "Person %d", i+1); 
		s[i].set_name(buffer);
		s[i].set_balance(rand()%(100000-1000+1));
	}
	double sum=0;
	for (int i=0; i<100; i++) {
		double b = s[i].interest();
		sum+=b;
		s[i].deposit(b);
		
	}
	cout << "The total interest to be paid is : " << sum <<endl;






}

