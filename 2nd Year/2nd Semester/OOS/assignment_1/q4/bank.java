
class BankAccount {
	int AccountNumber;
	float balance;
	String ownerName;	
	/*
 * constructor for this class
 * methods: balance, add, subtract
 * another class acc manager: arr of bank acc, methods: create, delete, deposit, withdraw, 
 * class bank to create an AccountManager and create 5 accounts
 * print details of all accounts
 */
	BankAccount(int ba, float b, String o) {
		AccountNumber = ba;
		balance = b;
		ownerName = o;
	}
	void balance() {
		System.out.println("Account " + AccountNumber + " held by " + ownerName + " has balance " + balance);
	}
	void add(float f) {
		balance+=f;
	}
	void subtract(float f) {
		balance-=f;
	}
}
class AccountManager {
	BankAccount[] acc;
	int top = -1;
	AccountManager(int n) {
		acc = new BankAccount[n];
	}
	void create(BankAccount ob) {
		if (top==acc.length-1) {
			System.out.println("Overflow!");
		}
		acc[++top] = ob;
	}
	void delete(int v) {
		for (int i=0; i<=top; i++) {
			if (acc[i].AccountNumber==v) {
				for (int j=i+1; j<top; j++) {
					acc[j] = acc[j+1];
				}
				top--;
			break;
			}
		}
	}
	void deposit(int ba, int v) {
		for (int i=0; i<=top; i++) {
			if (acc[i].AccountNumber==ba) {
				acc[i].add(v);
				break;
			}
		}
	}
	void withdraw(int ba, int v) {
		for (int i=0; i<=top; i++ ){
			if (acc[i].AccountNumber==ba) {
				acc[i].subtract(v);
				break;
			}
		}
	}
}

class Main {
	public static void main(String args[]) {
		AccountManager manager = new AccountManager(5);
		
		for (int i=0; i<5; i++) {
			manager.acc[i] = new BankAccount(1000+i*100+(i+2)*10, i*1000+(i*2)*10, ("Owner"+i));
		}
		for (int i=0; i<5; i++) {
			manager.acc[i].balance();
		}
	}
}
