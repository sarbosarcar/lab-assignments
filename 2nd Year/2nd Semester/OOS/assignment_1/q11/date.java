class Date {
	int day;
	int month;
	int year;
	Date() {
		day = 1;
		month = 1;
		year = 1970;
	}
	Date(int d) {
		day = d;
		month = 1;
		year = 1970;
	}
	Date(int d, int m) {
		day = d;
		month = m;
		year = 1970;
	}
	Date(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}
	Date next() {
		if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
			day++;
			if (day==32) {
				day = 1;
				month++;
				if (month==13) {
					year++;
					month=1;
				}
			}
		}
		else {
			if (month==2) {
				if (year%400==0 || (year%4==0 && year%100!=0)) {
					if (day+1==30) {
						month++;
						day = 1;
					}
					else {
						day++;
					}
				}
				else {
					if (day+1==29) {
						month++;
						day=1;
					}
					else {
						day++;
					}
				}	
			}
			else {
				if (day+1>30) {
					month++;
					day = 1;
				}
				else {
					day++;
				}
			}
		}
	return this;
	}
	Date prev() {
	if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
			day--;
			if (day==0) {
				day = 30;
				month--;
				if (month==2) {
					if (year%400==0 || (year%4==0 && year%100!=0)) {
						day = 29;
					}
					else {
						day = 28;
					}
				}
				else if (month==0) {
					day = 31;month=12; year--;
				}
			}
		}
		else {
			day--;
			if (day==0) {
				day = 31;
				month--;
			}
		}
	return this;
	}
	void disp() {
		String s = "";
		if (month==1) s = "January";
		else if (month==2) s = "February"; 
		else if (month==3) s = "March";
		else if (month==4) s = "April";
		else if (month==5) s = "May";
		else if (month==6) s = "June";
		else if (month==7) s = "July";
		else if (month==8) s = "August";
		else if (month==9) s = "September";
		else if (month==10) s = "October";
		else if (month==11) s = "November";
		else if (month==12) s = "December";
		
		System.out.println(day + " " + s + " " + year);
	}
}

class Demo {
	public static void main(String args[]) {
		Date d1 = new Date();
		Date d2 = new Date(12);
		Date d3 = new Date(10, 11);
		Date d4 = new Date(31, 12, 1999);
		System.out.println("Current: ");
		d1.disp();
		System.out.println("Next: ");
		d1.next().disp(); 
		System.out.println("Previous: ");
		d1.prev().prev().disp();
		//d4.next().disp();
	}
}
				
		
