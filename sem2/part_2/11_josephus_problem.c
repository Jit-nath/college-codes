#include <stdio.h>

// Function to find the survivor position in Josephus problem
int josephus(int n, int k)
{
    if (n == 1)
    {
        return 0;
    }
    else
    {
        return (josephus(n - 1, k) + k) % n;
    }
}

int main()
{
    int n, k;

    // Input the number of people and the counting number
    printf("Enter the number of people: ");
    scanf("%d", &n);
    printf("Enter the counting number: ");
    scanf("%d", &k);

    // Find the survivor position
    int survivor = josephus(n, k) + 1;

    // Output the survivor position
    printf("The person at position %d survives.\n", survivor);

    return 0;
}
