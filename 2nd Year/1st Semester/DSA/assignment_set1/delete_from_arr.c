#include <stdio.h>

int main()
{
    int arr[10], i;
    for (i=0; i<10; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("The entered array is:\n");
    for (i=0; i<10; i++) printf("%d\t", arr[i]);
    for (i=2; i<9; i++) arr[i] = arr[i+1]; //deleting 3rd element
    for (i=4; i<8; i++) arr[i] = arr[i+1]; //deleting 6th element
    printf("\nAfter deletion array is:\n");
    for (i=0; i<8; i++) printf("%d\t", arr[i]);
    printf("\n5th element is: %d", arr[4]);
    
    return 0;
}
