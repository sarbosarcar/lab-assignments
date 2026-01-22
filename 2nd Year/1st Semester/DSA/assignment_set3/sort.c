#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        printf("Pass %d: ", i);
        printArray(arr, n);
    }
}

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        printf("Pass %d: ", i + 1);
        printArray(arr, n);
    }
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printf("Pass %d: ", i + 1);
        printArray(arr, n);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1), j;
    for (j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        printf("Quick Sort: ");
        printArray(arr, high+1);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void quickSortPrint(int arr[], int n) {
    quickSort(arr, 0, n - 1);
    printf("Quick Sort: ");
    printArray(arr, n);
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    int i,j,k;
    for ( i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for ( j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    printf("Merge Sort: ");
    printArray(arr, r + 1);  
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void mergeSortPrint(int arr[], int n) {
    mergeSort(arr, 0, n - 1);
    printf("Merge Sort: ");
    printArray(arr, n);
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        printf("Heap Sort: ");
        printArray(arr, n);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void heapSortPrint(int arr[], int n) {
    heapSort(arr, n);
    printf("Heap Sort: ");
    printArray(arr, n);
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int arr1[] = {12, 11, 13, 5, 6, 7};
    printf("Insertion Sort:\n");
    insertionSort(arr1, n);

    int arr2[] = {12, 11, 13, 5, 6, 7};
    printf("Selection Sort:\n");
    selectionSort(arr2, n);

    int arr3[] = {12, 11, 13, 5, 6, 7};
    printf("Bubble Sort:\n");
    bubbleSort(arr3, n);

    int arr4[] = {12, 11, 13, 5, 6, 7};
    quickSortPrint(arr4, n);

    int arr5[] = {12, 11, 13, 5, 6, 7};
    mergeSortPrint(arr5, n);

    int arr6[] = {12, 11, 13, 5, 6, 7};
    heapSortPrint(arr6, n);

    return 0;
}

