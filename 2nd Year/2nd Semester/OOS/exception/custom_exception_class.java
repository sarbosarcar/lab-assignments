class LowBalanceException extends Exception {
	long amount;
	LowBalanceException(long amount) {
		this.amount = amount;
	}
}
class ExcessBalanceException extends Exception {
        long amount;
        ExcessBalanceException(long amount) {
                this.amount = amount;
        }
}
class Bank {
	static long maxAmount = 10000;
	public void withdraw(long accNo, long amount) throws LowBalanceException, ExcessBalanceException {
		long balance = getBalance(accNo);
		if (balance < amount) {
			throw new LowBalanceException(amount);
		}
		if (amount > maxAmount) {
			throw new ExcessBalanceException(amount);
		}
		else {
			withdrawAmount(amount);
		}
	}
	private long getBalance(long accNo) {
		return 0;
	}
	private void withdrawAmount(long amount) {
		System.out.println("Withdrawn " + amount);
	}
}

class userException {
	public static void main(String args[]) {
		Bank ob = new Bank();
		try {
			ob.withdraw(5, 200000);
		}
		catch (LowBalanceException le) {
			le.printStackTrace();
		}
		catch (ExcessBalanceException ee) {
			ee.printStackTrace();
		}
	}
}
