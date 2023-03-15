#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct{
    int data[MAX];
    int count;
}SET;

void initSet(SET *S)
{
    S->count = 0;
}

void insertSorted(SET *S, int elem)
{
    int j, i = 0;

        for(; i < S->count && elem > S->data[i]; i++){}
            if(elem != S->data[i])
            {
                for(j = i; j < S->count; j++)
                {
                    S->data[j+1] = S->data[j];
                    S->data[i] = elem;
                }
            }
}

SET UNION(SET A, SET B)
{
    SET C;
    int a, b;

    a = b = 0;
    C.count = 0;

        while(a < A.count && b < B.count)
        {
            if(A.data[a] < B.data[b])
            {
                C.data[C.count] = A.data[a];
                a++;
            }else
            {
                if(A.data[a] == B.data[b])
                {
                    a++;
                }
                C.data[C.count] = B.data[b];
                b++;
            }

            C.count++;
        }

        if(b < B.count)
        {
            A = B;
            a = b;
        }

        while(a < A.count)
        {
            C.data[C.count] = A.data[a];
            a++;
            C.count++;
        }

    return C;
}

int main()
{

    //DECLARATION AND INITIALIZATION



    return 0;
}