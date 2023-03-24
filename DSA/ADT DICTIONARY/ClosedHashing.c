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

int HASH(int elem)
{
    return elem % MAX;
}

void insert(DICTIONARY *D, int elem)
{
    int hashv = HASH(elem);
    int i, x;

    for(i = hashv, x = 0;  D->data[i] > -1 && x < MAX; i = (i + 1) % MAX, x++){}

    D->last++;
    D->data[i] = elem;

}

void delete(DICTIONARY *D, int elem)
{
    int hashv = HASH(elem);
    int i, x;

    for(i = hashv, x = 0; x < MAX && D->data[i] != elem; i = (i + 1) % MAX, x++){}

    if(x < MAX)
    {
        D->last--;
        D->data[i] = DELETED;
    }
}

void display(DICTIONARY D)
{
    int i;

    printf("%-10s %-10s\n", "INDEX", "DATA");

    for(i = 0; i < MAX; i++)
    {
        printf("%-10d %-10d\n", i, D.data[i]);
    }
}

int main()
{

    DICTIONARY A;
    initDict(&A);

    insert(&A, 29);
    insert(&A, 12);
    insert(&A, 30);
    insert(&A, 58);
    // delete(&A, 30);
    insert(&A, 48);


    display(A);

    return 0;
}
