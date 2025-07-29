#include <stdio.h>
int main() 
{
    int arr[100];
    int n;
    printf("Enter the numberof elements(max-100)-> ");
    scanf("%d",&n);
    printf("\nEnter the elements \n");
    for(int i =0 ; i<n; i++)
    {
        printf("%d-> ",i);
        scanf("%d",&arr[i]);
    }

    int start_index = 0;
    int end_index = n - 1;
    int temp;

    while (start_index < end_index) 
    {
        temp = arr[start_index];
        arr[start_index] = arr[end_index];
        arr[end_index] = temp;
        start_index++;
        end_index--;
    }

    printf("\nReversed Array: ");
    for (int i = 0; i < n; i++) {
        printf("\n%d -> %d",i, arr[i]);
    }
    printf("\n");

    return 0;
}