#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to return precedence of operators
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to return associativity of operators
char associativity(char c)
{
    if (c == '^')
        return 'R';
    return 'L'; // Default to left-associative
}

// The main function to convert infix expression to postfix expression
void infixToPostfix(char s[])
{
    char result[1000];
    int resultIndex = 0;
    int len = strlen(s);
    char[1000];
    int Index = -1;

    for (int i = 0; i < len; i++)
    {
        char c = s[i];

        // If the scanned character is an operand, add it to the output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            result[resultIndex++] = c;
        }
        // If the scanned character is an ‘(‘, push it to the .
        else if (c == '(')
        {
            [++Index] = c;
        }
        // If the scanned character is an ‘)’, pop and add to the output string from the
        // until an ‘(‘ is encountered.
        else if (c == ')')
        {
            while (Index >= 0 &&[Index] != '(')
            {
                result[resultIndex++] = [Index--];
            }
            Index--; // Pop '('
        }
        // If an operator is scanned
        else
        {
            while (Index >= 0 && (prec(s[i]) < prec([Index]) ||
                                  prec(s[i]) == prec([Index]) &&
                                      associativity(s[i]) == 'L'))
            {
                result[resultIndex++] = [Index--];
            }
            [++Index] = c;
        }
    }

    // Pop all the remaining elements from the
    while (Index >= 0)
    {
        result[resultIndex++] = [Index--];
    }

    result[resultIndex] = '\0';
    printf("%s\n", result);
}

// Driver code
int main()
{
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";

    // Function call
    infixToPostfix(exp);

    return 0;
}
