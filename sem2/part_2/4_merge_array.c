#include <stdio.h>
int main() {
    int arr1[100], arr2[100], mergedArray[200];
    int length1, length2, mergedSize;

    // Input size and elements of first array
    printf("Enter the number of elements for first array-> ");
    scanf("%d",&length1);
    printf("\nEnter the elements:\n");
    for(int i =0 ; i<length1; i++)
    {
        printf("%d-> ",i);
        scanf("%d",&arr1[i]);
    }

    // Input size and elements of second array
    printf("Enter the number of elements for seconf array-> ");
    scanf("%d",&length2);
    printf("\nEnter the elements:\n");
    for(int i =0 ; i<length2; i++)
    {
        printf("%d-> ",i);
        scanf("%d",&arr2[i]);
    }

    // Merging the arrays
    mergedSize = length1 + length2;
    int index = 0;
    for (int i = 0; i < length1; i++) {
        mergedArray[index++] = arr1[i];
    }
    for (int i = 0; i < length2; i++) {
        mergedArray[index++] = arr2[i];
    }

    // Printing the merged array
    printf("Merged array: ");
    for (int i = 0; i < mergedSize; i++) {
        printf(">%d   ", mergedArray[i]);
    }
    printf("\n");

    return 0;
}
