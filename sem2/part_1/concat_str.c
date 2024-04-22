#include <stdio.h>

void concatStrings(char *str1, char *str2, char *result) {
    int i = 0, j = 0;

    // Copy str1 to result
    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }

    // Concatenate str2 to result
    while (str2[j] != '\0') {
        result[i + j] = str2[j];
        j++;
    }

    // Null-terminate the result string
    result[i + j] = '\0';
}

int main() {
    char str1[100], str2[100], result[200];

    printf("Enter the first string: ");
    fgets(str1,sizeof(str1),stdin);

    printf("Enter the second string: ");
    fgets(str2,sizeof(str2),stdin);

    concatStrings(str1, str2, result);

    printf("Concatenated string: %s\n", result);

    return 0;
}
