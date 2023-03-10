#include <stdio.h>

#define SIZE 8

typedef struct{
    int front, rear;
    int data[SIZE];
}QUEUE;

void initQ(QUEUE *Q)
{
    Q->front = 0;
    Q->rear = -1;
}

int isEmpty(QUEUE Q)
{
    return (Q.rear + 1) % SIZE == Q.front;
}

int isFull(QUEUE Q)
{
    return (Q.rear + 2) % SIZE == Q.front;
}

void enqueue(QUEUE *Q, int elem)
{
    if(!isFull(*Q))
    {
        Q->rear = (Q->rear + 1) % SIZE;
        Q->data[Q->rear] = elem;
    }else{
        printf("Cant Dsiplay %d, because queue is full\n", elem);
    }
}

void dequeue(QUEUE *Q)
{
    if(!isEmpty(*Q))
    {
        Q->front = (Q->front + 1) % SIZE;
    }
}

void display(QUEUE Q)
{
    while(!isEmpty(Q))
    {
        printf("%d ",Q.data[Q.front]);
        dequeue(&Q);
    }
}

void FRStatus(QUEUE Q)
{
    printf("elemF   elemR    Front    Rear\n");
    printf("%-7d %-8d %-8d %-9d",Q.data[Q.front], Q.data[Q.rear],  Q.front, Q.rear);
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
    FRStatus(A);
    printf("\n==============================================\n");

    //task 2
    printf("\n\n");
    printf("Task 2: Dequeue 1 elem\n");
    dequeue(&A);
    display(A);
    printf("\n\n");
    FRStatus(A);
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
    FRStatus(A);

    return 0;
}
