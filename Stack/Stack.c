/*
 * Stack.c
 *
 *  Created on: Aug 10, 2017
 *      Author: baekhg
 */


#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

typedef struct Stack
{
    int buf[STACK_SIZE];
    int top;
}Stack;

void InitStack(Stack *stack);
int IsFull(Stack *stack);
int IsEmpty(Stack *stack);
void Push(Stack *stack, int data);
int Pop(Stack *stack);

int main()
{
    int i;
    Stack stack;

    InitStack(&stack);
    for(i = 1; i <= 5; i++)
    {
        Push(&stack, i);
    }

    while(!IsEmpty(&stack))
    {
        printf("%d", Pop(&stack));
    }
    printf("\n");
    return 0;
}

void InitStack(Stack *stack)
{
    stack->top = -1;
}

int IsFull(Stack *stack)
{
    return (stack->top+1) == STACK_SIZE;
}

int IsEmpty(Stack *stack)
{
    return stack->top == -1;
}

void Push(Stack *stack, int data)
{
    if(IsFull(stack))
    {
        printf("Stack is full! \n");
        return ;
    }
    stack->top++;
    stack->buf[stack->top] = data;
}

int Pop(Stack *stack)
{
    int data = 0;
    if(IsEmpty(stack))
    {
        printf("Stack is empty! \n");
        return data;
    }
    data = stack->buf[stack->top];
    stack->top--;

    return data;
}

