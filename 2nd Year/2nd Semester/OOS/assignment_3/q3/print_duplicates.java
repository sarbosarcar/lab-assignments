class Main<T>
{
    T[] arr;
    void printDuplicates() {
        Integer[] tmp = new Integer[arr.length];
        for (int i=0; i<arr.length; i++) tmp[i]=0;
        System.out.println("The duplicate elements are:");
        for (int i=0; i<arr.length; i++) {
            if (tmp[i]==0) {
                tmp[i]=1;
                boolean flag = false;
                for (int j=i+1; j<arr.length; j++) {
                    if (arr[j].equals(arr[i])) {
                        flag = true;
                        tmp[j]=1;
                        break;
                    }
                }
                if (flag)
                    System.out.println(arr[i]);
            }
        }
    }
    void print() {
        for (int i=0; i<arr.length; i++) {
            System.out.print(arr[i] + "\t");
        }
        System.out.println();
    }
	public static void main(String[] args) {
	    Main<Double> m = new Main<Double>();
	    m.arr = new Double[]{65.43, -34.32, 23.54, 23.54, -0.01, 65.43, 23.54, 65.43, -0.01};
		System.out.println("Array: ");
		m.print();
		m.printDuplicates();
	}
}
