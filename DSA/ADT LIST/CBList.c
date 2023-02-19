#include <stdio.h>

#define MAX 6

typedef struct{
    char data;
    int link;
}nodes;

typedef struct{
	nodes node[MAX];
	int avail;
}VirtualHeap;

typedef int List;

void initVirtualHeap(VirtualHeap *VH);
int allocSpace(VirtualHeap *VH);
void deallocSpace(VirtualHeap *VH, int index);
void insertFirst(VirtualHeap *VH, List *A, char elem);
void display(VirtualHeap VH, List A);

int main()
{
	VirtualHeap VA;
	initVirtualHeap(&VA);
	
	
	List A;
	A = -1;
	
	insertFirst(&VA, &A, 'O');
	insertFirst(&VA, &A, 'L');
	insertFirst(&VA, &A, 'L');
	insertFirst(&VA, &A, 'E');
	insertFirst(&VA, &A, 'H');
	display(VA, A);
	
	
	return 0;
}

void initVirtualHeap(VirtualHeap *VH)
{
	int i;
	
	for(i = MAX-1; i > -1; i--)
	{
		(*VH).node[i].link = i-1;
	}
	
		(*VH).avail = MAX-1;
}

int allocSpace(VirtualHeap *VH)
{
	int ret;

	if((*VH).avail != -1)
	{
		ret = (*VH).avail;
		(*VH).avail = (*VH).node[ret].link;
	}else{
		printf("There is no more space in the Virtual Heap");
	}
	
	return ret;
}

void deallocSpace(VirtualHeap *VH, int index)
{
	int temp;
	
	if(index < MAX && index != -1)
	{
		(*VH).node[index].link = (*VH).avail;
		(*VH).avail = index;
	}
}


void insertFirst(VirtualHeap *VH, List *A, char elem)
{
		int temp;
		
		temp = allocSpace(VH);
		(*VH).node[temp].data = elem;
		(*VH).node[temp].link = *A;
		*A = temp;
		
}

void deleteFirst(VirtualHeap *VH, List *A)
{
	if((*A) != -1)
	{
		
	}else{
		printf("List is Empty");
	}
}

void display(VirtualHeap VH, List A)
{
	int i;
	
	for(i = A; i > -1; i = VH.node[i].link)
	{
		printf("%c ", VH.node[i].data);
	}
}








