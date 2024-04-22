#include <stdio.h>

void reverseArray(int *p, int length);

int main() {
    int arr[100],length;
    int *p = arr;
    printf("Enter the number of elements-> ");
    scanf("%d",&length);
    printf("\nEnter the elements \n");
    for(int i =0 ; i<length; i++)
    {
        printf("%d-> ",i);
        scanf("%d",&arr[i]);
    }

    reverseArray(arr, length);

    printf("\nReversed Array: ");
    for (int i = 0; i < length; i++) {
        printf("\n%d -> %d",i, arr[i]);
    }
    printf("\n");

    return 0;
}

void reverseArray(int *p, int length) {
    int start_index = 0;
    int end_index = length - 1;
    int temp;

    while (start_index < end_index) {
        temp = p[start_index];
        p[start_index] = p[end_index];
        p[end_index] = temp;
        start_index++;
        end_index--;
    }
}
