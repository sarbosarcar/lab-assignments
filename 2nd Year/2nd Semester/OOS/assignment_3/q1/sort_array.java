class Main
{
    static <T extends Comparable<T>> void sort(T[] arr) {
        for (int i=0; i<arr.length; i++) {
            for (int j=0; j<arr.length-i-1; j++) {
                if (arr[j].compareTo(arr[j+1])>0) {
                    T tmp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = tmp;
                }
            }
        }
    }
    static <T> void print(T[] arr) {
        for (int i=0; i<arr.length; i++) {
            System.out.print(arr[i] + "\t");
        }
        System.out.println();
    }
    
	public static void main(String[] args) {
		Double[] arr = {65.43, -34.32, 0.01, 3.45, 23.54, -24.56};
		System.out.println("Before sorting: ");
		print(arr);
		sort(arr);
		System.out.println("After sorting: ");
		print(arr);
	}
}
