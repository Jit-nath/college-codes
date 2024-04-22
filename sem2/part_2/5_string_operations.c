// strcmp strlen strcat strcpy
#include <stdio.h>
#include <string.h>
#define SIZE 100
int main()
{
    char string1[SIZE], string2[SIZE], string3[SIZE * 2] = "\0";

    printf("Enter the first string - ");
    gets(string1);
    printf("Enter the second string - ");
    gets(string2);

    printf("The length of fist string = %d\n", strlen(string1));

    printf("The length of second string = %d\n", strlen(string2));
    int compare_value = strcmp(string1, string2);
    printf("Result of string compare =  %d\n", compare_value);

    strcat(string3, string1);
    strcat(string3, string2);
    printf("Concatinated string = %s\n", string3);

    strcpy(string3, "string copied using strcpy");
    printf("\n%s", string3);
    return 0;
}