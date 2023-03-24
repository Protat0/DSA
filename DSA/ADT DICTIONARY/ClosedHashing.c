#include <stdio.h>

#define MAX 10
#define EMPTY -1
#define DELETED -2

typedef struct{
    int data[MAX];
    int last;
}DICTIONARY;

void initDict(DICTIONARY *D)
{
    int i;

    for(i = 0; i < MAX; i++)
    {
        D->data[i] = EMPTY;
    }

    D->last = -1;
}

int HASH(char elem)
{
    return elem % MAX;
}

void insert(DICTIONARY *D, char elem)
{
    int hashv = HASH(elem);
    int i;

    for(i = hashv;  != EMPTY && i != DELETED)

}