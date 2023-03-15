#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef int SET[MAX];

SET* UNION(SET A, SET B)
{
    SET *retval = (SET*)malloc(sizeof(SET));
    int i;

    for(i = 0; i < MAX; i++)
    {
        (*retval)[i] = A[i] || B[i];
    }

    return retval;
}

SET* INTERSECTION(SET A, SET B)
{
    SET *retval = (SET*)malloc(sizeof(SET));
    int i;

    for(i = 0; i < MAX; i++)
    {
        (*retval)[i] = A[i] && B[i];
    }

    return retval;
}

SET* DIFFERENCE(SET A, SET B)
{
    SET *retval = (SET*)malloc(sizeof(SET));
    int i;

    for(i = 0; i < MAX; i++)
    {
        (*retval)[i] = A[i] &~ B[i];
    }

    return retval;
}

void insert(SET A, int elem)
{
    if(elem < MAX && elem > -1)
    {
        A[elem] |= 1;
    }
}

void delete(SET A, int elem)
{
    if(elem < MAX && elem > -1)
    {
        A[elem] &= 0;
    }
}

void display(SET S)
{
    int i;

    printf("{ ");
    for(i = 0; i < MAX; i++)
    {
        if(S[i] == 1)
        {
            printf("%d ", i);
        }
    }
    printf("}");
    printf("\n");
}


int main()
{
    //DECLARATION AND INITIALIZATION

    //SET A {0, 2, 3, 5}
    SET A = {1, 0, 1, 1, 0, 1};
    printf("SET A: ");
    display(A);

    //SET B {1, 3, 4, 5, 6}
    SET B = {0, 1, 0, 1, 1, 1, 1};
    printf("SET B: ");
    display(B);



    //TASK 1 
    printf("\ntask 1: Get the UNION of both sets A and B and put them into set C");
    SET *C = UNION(A, B);
    printf("\nSET C: ");
    display(*C);

    //TASK 2 
    printf("\ntask 2: Get the INTSERSECTION of both sets A and B and put them into set C");
    C = INTERSECTION(A, B);
    printf("\nSET C: ");
    display(*C);

    //TASK 3 
    printf("\ntask 3: Find the DIFFERENCE of set A and B and put them into set C");
    C = DIFFERENCE(A, B);
    printf("\nSET C: ");
    display(*C);

    //TASK 4 
    printf("\ntask 4: Find the DIFFERENCE of set B and A and put them into set C");
    C = DIFFERENCE(B, A);
    printf("\nSET C: ");
    display(*C);


    return 0;
}