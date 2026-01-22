class Account {
	int accountNumber;
	String holderName;
	int balance;
	/*Account (int a, String h, int b) {
		accountNumber = a;
		holderName = h;
		balance = b;
	}*/
	void set_acc(int v) {
		accountNumber = v;
	}
	void set_holder(String h) {
		holderName = h;
	}
	void set_balance(int b) {
		balance = b;
	}
	String get_holder() {
		return holderName;
	}
	int get_acc() {
		return accountNumber;
	}
	int get_balance() {
		return balance;
	}
	void disp() {
		System.out.println("Account Number " + accountNumber + " held by " + holderName + " has balance " + balance);
	}
	double calculateYearlyInterest() {
		return 0.00;	
	}
}

class SavingsAccount extends Account {
	double interestRate;
	double calculateYearlyInterest() {
		return (balance*interestRate/100);
	}
	SavingsAccount(double ir)  {
		interestRate = ir;
	}
	void disp() {
		System.out.println("Details for Savings Account: ");
		super.disp();
	}
}

class CurrentAccount extends Account {
	void disp() {
		System.out.println("Details for Current Account: ");
		super.disp();
	}
}

class Manager {
	Account[] acc;
	Manager(int n) {
		acc = new Account[n];
	}
	
	public static void main(String args[]) {
		Manager m = new Manager(5);
		for (int i=0 ;i<2; i++) {
			m.acc[i] = new SavingsAccount((i+1)*0.23);
			m.acc[i].set_acc(1000*(i+1)+i+1);
			m.acc[i].set_holder("SA Holder " + i);
			m.acc[i].set_balance(10000*(i+2)*(i+1));
		}
		for (int i=2; i<5; i++) {
			m.acc[i] = new CurrentAccount();
			m.acc[i].set_acc(1000*(i+1)+i+1);
			m.acc[i].set_holder("CA Holder " + i);
			m.acc[i].set_balance(10000*(i+2)*(i+1));
		}
		for (int i=0; i<2; i++) {
			System.out.println("Interest of Savings Account " + m.acc[i].get_acc() + " is " + m.acc[i].calculateYearlyInterest());
		}
		System.out.println("The details of all accounts are: ");
		for (int i=0; i<5; i++) {
			m.acc[i].disp();
		}
	}
}
