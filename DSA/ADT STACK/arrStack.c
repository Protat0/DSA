#include <stdio.h>

#define MAX 10

typedef struct{
    int top;
    int data[MAX];
}STACK;

void initStack(STACK *S)
{
    S->top = -1;
}

int isEmpty(STACK S)
{
   return S.top == -1; 
}

int isFull(STACK S)
{
   return S.top == MAX-1; 
}

void pop(STACK *S)
{
    if(!isEmpty(*S))
    {
        S->top--;
    }
}

void push(STACK *S, int elem)
{
    if(!isFull(*S))
    {
        S->data[++S->top] = elem;
    }
}

void display(STACK S)
{
    while(!isEmpty(S))
    {
        printf("%d ", S.data[S.top]);
        pop(&S);
    }
}

int main()
{

    STACK A;
    initStack(&A);


    //TASK 1
    printf("TASK 1: Pushing 4 number into the stack: \n");
    push(&A, 1);
    push(&A, 2);
    push(&A, 3);
    push(&A, 4);    
    display(A);
    printf("\n===========================================\n");

    //TASK 2
    printf("\nTASK 2: Poping a number out of the stack: \n");
    pop(&A);
    display(A);
    printf("\n===========================================\n");


    return 0;
}
