#include <stdio.h>

int fibonacci(int n){ // n = 3
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(){
    int n;

    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);

    printf("Fibonacci series:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", fibonacci(i));

    printf("\n");

    return 0;
}
