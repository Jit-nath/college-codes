#include <stdio.h>
#include <string.h>

char[50][50];
int top = -1;

void clear_()
{
    top = -1;
}

void push(char *s)
{
    strcpy([++top], s);
}

char *pop()
{
    return [top--];
}

int is_operator(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// function to Convert prefix to Postfix
void convert(char *exp)
{
    clear_();

    int i, l;
    char op1[50], op2[50];

    l = strlen(exp);

    // scanning from right to left
    for (i = l - 1; i >= 0; i--)
    {
        // checking if the symbol is an operator
        if (is_operator(exp[i]))
        {
            // popping two operands from
            strcpy(op1, pop());
            strcpy(op2, pop());
            ;
            // concating the operands and operator
            strcat(op1, strcat(op2, (char[2]){(char)exp[i], '\0'}));
            // Pushing the temporary string to
            push(op1);
        }
        // if it is an operand
        else
        {
            // push the operand to the
            push((char[2]){(char)exp[i], '\0'});
        }
    }
    // printf("The postfix expression is: %s",[top].c_str());
    printf("%s\n", [top]);
}

// main function
int main()
{
    convert("*-A/BC-/AKL");
    convert("+ab");
    convert("*+abc");
    convert("*a+bc");
    convert("+/ab/cd");
    convert("*+ab+cd");
    convert("-*+abcd");
    return 0;
}