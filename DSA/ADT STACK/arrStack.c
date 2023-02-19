#include <stdio.h>

#define MAX 10

typedef struct{
    int last;
    int data[MAX];
}STACK;

void initStack(STACK *S)
{
    S->last = -1;
}

