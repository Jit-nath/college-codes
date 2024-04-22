#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};
int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}
int isfull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}
void push(int value, struct stack *ptr)
{
    if (isfull(ptr))
    {
        printf("\nStack Overflow! , can not push element %d", value);
    }
    else
    {
        ptr->arr[ptr->top] = value;
        ptr->top++;
    }
}
int pop(struct stack *ptr)
{
    if (isempty(ptr))
    {
        return -1; // considering the -1 value is not in stack
    }
    else
    {
        ptr->top--;
        return ptr->arr[ptr->top + 1];
    }
}
int stacktop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}
int main()
{
    struct stack *val = (struct stack *)malloc(sizeof(struct stack));
    val->size = 5;
    val->top = -1;
    val->arr = malloc(val->size * sizeof(int));
    printf("Stack made successfully");
    int n, value, exit;

    do
    {
        printf("\n\nEnter choice to\n1. push\n2. pop\n3. Top -> ");
        scanf("%d", &n);

        switch (n)
        {

        case 1:
            printf("\nEnter a element to push-> ");
            scanf("%d", &value);
            push(value, val);
            break;

        case 2:
            value = pop(val);
            if (value == -1)
                printf("\nStack is empty");
            else
                printf("\nPopped value = %d", value);
            break;

        case 3:
            value = stacktop(val);
            if (value == -1)
                printf("\nStack is empty");
            else
                printf("\nTop value = %d", value);
            break;

        default:
            printf("\nInvalid choice!");
        }

        printf("exit?(0/1) ");
        scanf("%d", &exit);
    } while (exit);
    // preventing memory leakage
    free(val->arr);
    free(val);
    return 0;
}