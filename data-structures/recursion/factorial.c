#include <stdio.h>
#include <stdlib.h>
long long int factorial(int number) {
    if (number < 0) {
        printf("ERROR!..only positive numbers have factorial.");
        exit(1);
    }
    if (number <= 1)
        return 1;
    else
        return number * factorial(number - 1);
}

int main() {
    long long int result;
    int input;
    printf("Enter the nth term for factorial: ");
    scanf_s("%d", &input);
    result = factorial(input);
    printf("THe factorial of %d is %lld\n\n\n", input, result);
    system("pause");
    return 0;
}