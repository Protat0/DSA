#include <stdio.h>
#include <stdlib.h>

#define MAX 30

typedef struct node{
    int data;
    struct node *LL;
    struct node *LR;
}*BST;



// ======================================================================== BST FUNCTIONS ==================================================================================== //
void initBST(BST *B)
{
    *B = NULL;
}

void insert(BST *B, int elem) //insert 69
{
    BST *trav;

        for(trav = B; *trav != NULL;)
        {
            trav = (elem < (*trav)->data) ? &(*trav)->LL : &(*trav)->LR;
        }

    if(*trav == NULL)
    {
        BST temp = (BST)malloc(sizeof(struct node));

        if(temp != NULL)
        {
            temp->data = elem;
            temp->LR = NULL;
            temp->LL = NULL;
            *trav = temp;
        }
    }

}

void display(BST B)
{
    BST current = B;
    BST stack[50];

    int top  = -1;

    while(current != NULL || top != -1)
    {
        while(current != NULL)
        {
            stack[++top] = current;
            current = current->LL;
        }

        current = stack[top--];
        printf("%d ", current->data);
        current = current->LR;
    }
}

void isMember(BST B, int num) // assume num is 9
{
    BST trav;

    for(trav = B; trav != NULL && num != trav->data;)
    {
            if(num > trav->data)
            {
                trav = trav->LR;
            }else{
                trav = trav->LL;
            }
    }


    if(trav != NULL)
    {
        printf("\n%d is a part of the tree", num);
    }else{
        printf("\n%d is not a part of the tree", num);
    }
}

void delete(BST *B, int data)
{
    BST *trav, *trav2, temp;
    
    for(trav = B; *trav != NULL && (*trav)->data != data;)
    {
        trav = ((*trav)->data > data) ? &(*trav)->LL : &(*trav)->LR;
    }

    if(*trav != NULL)
    {
        if((*trav)->LL == NULL)
        {
            temp = *trav;
            *trav = temp->LR;
            free(temp);
        }else if((*trav)->LR == NULL)
        {
            temp = *trav;
            *trav = temp->LL;
            free(temp);
        }else{
            for(trav2 = &(*trav)->LR; (*trav2)->LL != NULL; trav2 = &(*trav2)->LL){}

            temp = *trav2;
            *trav2 = temp->LR;
            (*trav)->data = temp->data;
            free(temp);
        }
    }

}

int min(BST B)
{
    BST trav;

    for(trav = B; trav != NULL; trav->LL){}

    return trav->data;
}

int max(BST B)
{
    BST trav;

    for(trav = B; trav != NULL; trav->LR){}

    return trav->data;
}

void inorder(BST B)
{
    if(B != NULL)
    {
        inorder(B->LL);
        printf("%d", B->data);
        inorder(B->LR);
    }
}

void preorder(BST B)
{
    if(B != NULL)
    {
        printf("%d ", B->data);
        preorder(B->LL);
        preorder(B->LR);
    }
}

void postorder(BST B)
{
    if(B != NULL)
    {
        postorder(B->LL);
        postorder(B->LR);
        printf("%d", B->data);

    }
}


int main()
{
    BST A;
    initBST(&A);

    insert(&A, 10);
    insert(&A, 7);
    insert(&A, 4);
    insert(&A, 8);
    insert(&A, 12);
    insert(&A, 11);

    display(A);

    isMember(A, 20);
    isMember(A, 11);

    // delete(&A, 7);

    printf("\n");
    display(A);

    printf("\n\n\n");
    preorder(A);
    return 0;
}