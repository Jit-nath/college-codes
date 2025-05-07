#include <stdio.h>
#include <string.h>

char *removeBlanks(char *str) {
    if (str == NULL)
        return NULL;

    char *dest = str;
    char *src = str;

    while (*src) {
        if (*src != ' ' && *src != '\t') {
            *dest = *src;
            dest++;
        }
        src++;
    }
    *dest = '\0';

    return str;
}

int main() {
    // Create modifiable string buffer
    char str[] = "I am Jit";

    char *newstr = removeBlanks(str);

    printf("Text before removing blanks: %s", "I am Jit");
    printf("\nText after removing blanks: %s", newstr);
    return 0;
}