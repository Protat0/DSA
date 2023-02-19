#include <stdio.h>

#define MAX 10

typedef struct{
    char Fname[24];
    char MI;
    char Lname[16];
}nametype;

typedef struct{
    nametype Name;
    char course[8];
    int ID;
    int yearLvl;
}studtype;

typedef struct{
    studtype Student;
    int link; 
}nodes;

typedef struct{
    nodes node[MAX];
    int avail;
}VirtualHeap;


void initVirtualHeap(VirtualHeap *VH)
{
    int i, LIM = MAX - 1;

    for(i = 0; i < LIM; i++)
    {
        (*VH).node[i].link = i+1;
    }
        (*VH).avail = 0;
        (*VH).node[i].link = -1;
}

int AllocSpace(VirtualHeap *VH)
{
    
}


int main()
{





    return 0;
}

