#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}*nodetype;

typedef struct{
    nodetype front;
    nodetype rear;
}QUEUE;

void initQ(QUEUE *Q)
{
    Q->front = NULL;
    Q->rear = NULL;
}

int isEmpty(QUEUE Q)
{
    return Q.front == NULL;
}

void enqueue(QUEUE *Q, int elem)
{

    nodetype temp = (nodetype)malloc(sizeof(struct node));

    if(temp != NULL)
    {

            temp->data = elem;
            temp->link = NULL;

            if(Q->rear == NULL)
            {
                Q->front = temp;
            }else{
                Q->rear->link = temp;
            }
        Q->rear = temp;
    }
}

void dequeue(QUEUE *Q)
{

    nodetype temp = (nodetype)malloc(sizeof(struct node));
    temp = Q->front;

    if(temp != NULL)
    {
        Q->front = temp->link;
        free(temp);

        if(Q->front == NULL)
        {
            Q->rear = NULL;
        }
    }
}

void display(QUEUE Q)
{
    while (!isEmpty(Q))
    {
        printf("%d ", Q.front->data);
        dequeue(&Q);
    }
}

int main()
{

    QUEUE A;
    initQ(&A);

    //task 1
    printf("Task 1: Enqueue 4 elements\n");
    enqueue(&A, 1);
    enqueue(&A, 2);
    enqueue(&A, 3);
    enqueue(&A, 4);
    display(A);
    printf("\n\n");

    printf("\n==============================================\n");

    //task 2
    printf("\n\n");
    printf("Task 2: Dequeue 1 elem\n");
    dequeue(&A);
    display(A);
    printf("\n\n");

    printf("\n==============================================\n");


    //task 3
    printf("\n\n");
    printf("Task 2: Enqueue until more than full \n");
    enqueue(&A, 5);
    enqueue(&A, 6);
    enqueue(&A, 7);
    enqueue(&A, 8);
    enqueue(&A, 9);
    display(A);
    printf("\n\n");


    return 0;
}