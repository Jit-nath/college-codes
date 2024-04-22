#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // If key is present at mid, return mid
        if (arr[mid] == key)
        {
            return mid;
        }

        // If key is greater, ignore left half
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }

        // If key is smaller, ignore right half
        else
        {
            high = mid - 1;
        }
    }

    // If key is not present in array
    return -1;
}

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int index = binarySearch(arr, 0, n - 1, key);

    if (index != -1)
    {
        printf("Element %d found at index %d.\n", key, index);
    }
    else
    {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}
