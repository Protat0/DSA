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
        printf("%d \n", S.data[S.top]);
        pop(&S);
    }
}

void insertBottom(STACK *S, int elem)
{
    if(!isFull(*S))
    {
        if(isEmpty(*S))
        {
            push(S, elem);
        }else{
            STACK temp;
            initStack(&temp);

            while(!isEmpty(*S))
            {
                push(&temp, S->data[S->top]);
                pop(S);
            }
            
                push(S, elem);

            while(!isEmpty(temp))
            {
                push(S, temp.data[temp.top]);
                pop(&temp);
            }
        }
    }else{
        printf("Stack is already Full!");
    }
}

int main()
{

    STACK A;
    initStack(&A);


    //TASK 1
    printf("TASK 1: Pushing 4 numbers into the stack: \n");
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

    //TASK 3
    printf("\nTASK 3: Inserting element at the bottom: \n");
    insertBottom(&A, 5);
    display(A);
    printf("\n===========================================\n");


    return 0;
}
