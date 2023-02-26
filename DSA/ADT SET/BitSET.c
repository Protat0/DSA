#include <stdio.h>

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


int main()
{


    return 0;
}