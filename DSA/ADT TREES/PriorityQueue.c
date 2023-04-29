#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct{
    int data[MAX];
    int count;
}HEAP;

void init(HEAP *H)
{
    H->count = 0;
}

int parent(int x)
{
    return (x - 1) / 2;
}

int leftChild(int x)
{
    return ((2 * x) + 1);
}
 
int rightChild(int x)
{
    return ((2 * x) + 2);
}

void swap(HEAP *H, int x, int y)
{
    int temp;

    H->data[temp] = H->data[x];
    H->data[x] = H->data[y];
    H->data[y] = H->data[temp];
}

void shiftUp(HEAP *H, int index)
{
    while(index > 0 && H->data[index] > H->data[parent(index)])
    {
        swap(H, index, parent(index));
        index = parent(index);
    }
}

void insert(HEAP *H, int data)
{
    if(H->count < MAX)
    {
        H->data[H->count] = data;
        shiftUp(H, H->count);
        H->count++;
    }else{
        printf("\n Heap is already full!");
    }


}

void display(HEAP H)
{
    int i;

    printf("\n");
    for(i = 0; i < H.count; i++)
    {
        printf("%d ", H.data[i]);
    }
}

int main()
{

    HEAP A;
    init(&A);

    insert(&A, 20);
    insert(&A, 19);
    insert(&A, 10);
    insert(&A, 30);
    insert(&A, 23);
    insert(&A, 58);
    insert(&A, 48); 

    display(A);


    return 0;
}