#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    int *arr;
} stack;

stack *make_stack(int size)
{
    stack *val = malloc(sizeof(stack));
    val->size = size;
    val->top = -1;
    val->arr = malloc(val->size * sizeof(int));
    return val;
}
int isempty(stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}
int isfull(stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}
void push(int value, stack *ptr)
{
    if (isfull(ptr))
    {
        printf("\nStack Overflow! , can not push element %d", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
int pop(stack *ptr)
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
int stacktop(stack *ptr)
{
    return ptr->arr[ptr->top];
}

void print_stack(stack *ptr)
{
    if (ptr->top == -1)
        printf("\nStack is empty");
    else
        for (int i = 0; i <= ptr->top; i++)
            printf("\n%d", ptr->arr[i]);
}

int main()
{
    printf("Stack made successfully");
    stack *val = make_stack(5);
    push(10, val);
    push(12, val);
    push(13, val);
    print_stack(val);
    free(val->arr);
    free(val);

    return 0;
}