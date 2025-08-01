#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char ch, input[100], output[100];
    int no[26] = {0}, n, c, t, x;

    printf("Enter some text\n");
    fgets(input, strlen(input), stdin);

    n = strlen(input);

    /** Storing how many times characters (a to z)
     appears in input string in an array */
    for (c = 0; c < n; c++) {
        ch = input[c] - 'a';
        no[ch]++;
    }
    t = 0;
    /** Insert characters 'a' to 'z' in output string as many times
     as they appear in the input string */
    for (ch = 'a'; ch <= 'z'; ch++) {
        x = ch - 'a';
        for (c = 0; c < no[x]; c++) {
            output[t] = ch;
            t++;
        }
    }

    output[t] = '\0';

    printf("%s\n", output);
    return 0;
}
