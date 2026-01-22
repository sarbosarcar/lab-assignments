import java.util.Scanner;
import java.util.Random;
import java.util.Arrays;


class BinThread extends Thread {
        int a[];
        int e;
        int low;
        int high;
	int index;
	static boolean found = false;
        BinThread(int arr[], int l, int h, int el, int idx) {
                low = l;
                high = h;
                a = arr;
                e = el;
		index = idx;
        }
        int binSearch(int a[], int low, int high, int e) {
                while (low < high) {
			if (found) return -1;
                        int mid = (low + high) / 2;
                        if (a[mid] == e) {
				found = true;
                                return mid;
                        }
                        else if (a[mid] > e) {
                                high = mid - 1;
                        }
                        else {
                                low = mid + 1;
                        }
                }
                return -1;
        }
        public void run() {
                int ret = binSearch(a, low, high, e);
                if (ret >= 0) {
                        System.out.println("Element found at index " + ret + "!");
			System.out.println("Thread " + index + " discovered the element");
		}
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
                Scanner sc = new Scanner(System.in);
                while (n % 10 != 0) {
                        System.out.print("Enter number of elements: ");
                        n = sc.nextInt();
                }
                Random rand = new Random();
                int[] a = new int[n];
                for (int i = 0; i < n; i++) {
                    int randomNumber = rand.nextInt(100);
                    a[i] = randomNumber;
                }
                Arrays.sort(a);
                System.out.println("Sorted array:");
                print(a);
                int e;
                System.out.print("Enter element to search: ");
                e = sc.nextInt();
                for (int i = 0; i < n / 10; i++) {
                        BinThread bt = new BinThread(a, i * 10, i * 10 + 10, e, i);
                        bt.start();
			try {
				bt.join();
			}
			catch(Exception ex) {
				System.out.println(ex);
			}
                }
		if (!BinThread.found) System.out.println("Element not found!");
        }
}

