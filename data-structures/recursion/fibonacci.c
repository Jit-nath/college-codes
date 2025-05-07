#include <stdio.h>
int fibonacci(int num) {
    if (num <= 1) {
        return num;
    } else
        return fibonacci(num - 1) + fibonacci(num - 2);
}
int main() {
    printf("Enter the n-th term for fibonacci: ");
    int result, num;
    scanf_s("%d", &num);
    result = fibonacci(num);
    printf("the %d-th fibonacci number is %d", num, result);
    return 0;
}