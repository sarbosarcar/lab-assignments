import java.util.Scanner;
import java.util.Random;
import java.util.Arrays;

class BinarySearch {
	int[] a;
	int n;
	
	BinarySearch(int[] a, int n) {
		this.a = a;
		this.n = n;
	}
}

class BinThread extends Thread {
	int a[];
	int e;
	int low;
	int high;
	BinThread(int arr[], int l, int h, int el) {
		low = l;
		high = h;
		a = arr;
		e = el;
	}
	int binSearch(int a[], int low, int high, int e) {
		while (low<high) {
			int mid = (low+high)/2;
			if (a[mid]==e) {
				return mid;
			}
			else if (a[mid]>e) {
				binSearch(a, low, mid, e);
			}
			else {
				binSearch(a, mid, high, e);
			}
		}
		return -1;
	}
	public void run() {
		int ret = binSearch(a, low, high, e);
		if (ret>=0)
 			System.out.println("Element found at " + ret);
		else
			System.out.println("Element not found");
	}
}
	
class Main {	
	static void print(int[] a) {
		for (int n : a) {
			System.out.print(n + "\t");
		}
		System.out.println();
	}
	
	public static void main(String args[]) {
		int n = 1;
		while (n%10!=0) {
			System.out.print("Enter number of elements: ");		
			Scanner sc = new Scanner(System.in);
			n = sc.nextInt();
		}
        	Random rand = new Random();
		int[] a = new int[n];
	        for (int i = 0; i < n; i++) {
        	    int randomNumber = rand.nextInt(100);
	            a[i] = randomNumber;
	        }
		BinarySearch bs = new BinarySearch(a, n);
		System.out.println("Original array:");
		print(a);
		System.out.println("Sorted array:");
		print(a);
		int e;
		System.out.print("Enter element to search: ");
		Scanner sc = new Scanner(System.in);
		e = sc.nextInt();
		for (int i=0; i<n/10; i++) {
			BinThread bt = new BinThread(a, i*10, i*10+10, e);
			bt.start();
		}
	}
}
