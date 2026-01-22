class Main
{
    static <T extends Comparable<T>> void countFrequency(T[] arr) {
        Integer[] tmp = new Integer[arr.length];
        for (int i=0; i<arr.length; i++) tmp[i]=0;
	System.out.println("Frequency of each element is as follows:");
        for (int i=0; i<arr.length; i++) {
            if (tmp[i]==0) {
                tmp[i]=1;
                int ct = 1;
                for (int j=i+1; j<arr.length; j++) {
                    if (arr[j].compareTo(arr[i])==0) {
                        ct++;
                        tmp[j]=1;
                    }
                }
                System.out.println(arr[i] + " : " + ct);
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
		Double[] arr = {65.43, -34.32, 23.54, 23.54, -0.01, 65.43, 23.54, 65.43, -0.01};
		System.out.println("Array: ");
		print(arr);
		countFrequency(arr);
	}
}
