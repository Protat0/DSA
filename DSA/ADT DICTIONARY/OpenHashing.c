#include <stdio.h>


#define MAX 10
typedef struct node{
    int elem;
    struct node *link;
}*ptr;


typedef ptr DICTIONARY[MAX];

typedef int SET[MAX];

int HASH(int elem)
{
    return elem % MAX;
}

void initDict(DICTIONARY D){
    int i;

        for(i = 0; i < MAX; i++)
        {
            D[i] = NULL;
        }
}

//Populate Disctionary
void PopDict(DICTIONARY D, SET A)
{
    int i, hashVal;
    ptr *trav;

        for(i = 0; i < MAX; i++)
        {
            hashVal = HASH(A[i]);

                for(trav = &D[hashVal]; *trav != NULL && A[i] != (*trav)->elem; trav = &(*trav)->link){}

                    if (*trav == NULL)
                    {
                        *trav = (ptr)malloc(sizeof(struct node));

                            if(*trav != NULL)
                            {
                                (*trav)->elem = A[i];
                                (*trav)->link = NULL;
                            }
                    }
        }
}

