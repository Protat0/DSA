#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}*STACK;

void initStack(STACK *S)
{
    *S = NULL;
}

int isEmpty(STACK S)
{
    return S == NULL;
}

void pop(STACK *S)
{
    if(!isEmpty(*S))
    {
        STACK temp;
        temp = *S;
        *S = temp->link;

        free(temp);
    }
}

void push(STACK *S, int elem)
{
    STACK temp = (STACK)malloc(sizeof(struct node));

    if(temp != NULL)
    {
        temp->data = elem;
        temp->link = *S;
        *S = temp;
    }
}

void display(STACK S)
{
    for(; S != NULL; S = S->link)
    {
        printf("%d \n", S->data);
    }
}

void insertBottom(STACK *S, int elem)
{
    if(isEmpty(*S))
    {
        push(S, elem);
    }else{
        STACK temp;
        initStack(&temp);

            while(!isEmpty(*S))
            {
                push(&temp, (*S)->data);
                pop(S);
            }

            push(S, elem);

            while (!isEmpty(temp))
            {
                push(S, temp->data);
                pop(&temp);
            }
            
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
