#include <stdio.h>
#define SIZE1 100
#define SIZE2 100
int main() {
    int arr1[SIZE1] = {1,2,3,4}, arr2[SIZE2]={5,6,7,8}, mergedArray[SIZE1+SIZE2];
    int length1 = 4,length2 = 4;
    int mergedSize = length1+length2;
    int index = 0;

    // Merging the arrays
    for (int i = 0; i < length1; i++) {
        mergedArray[index++] = arr1[i];
        
    }
    for (int i = 0; i < length2; i++) {
        mergedArray[index++] = arr2[i];
    }

    // Printing the merged array
    printf("Merged array: ");
    for (int i = 0; i < mergedSize; i++) {
        printf(" >%d ", mergedArray[i]);
    }
    printf("\n");

    return 0;
}
