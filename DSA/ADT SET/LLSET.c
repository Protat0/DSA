#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}dtype, *SET;

SET UNION(SET A, SET B){
    SET C, *trav;
    C = NULL;
    trav = &C;

    while(A != NULL && B != NULL){
        *trav = (SET)malloc(sizeof(dtype));
        if(*trav != NULL){
            if(A->data < B->data){
                (*trav)->data = A->data;
                A = A->link;
            } else {
                if(A->data == B->data){
                    A = A->link;
                }
                (*trav)->data = B->data;
                B = B->link;
            }
            trav = &(*trav)->link;
        }
    }

    if(A == NULL && B != NULL){
        A = B;
    }

    while(A != NULL){
        (*trav) = (SET)malloc(sizeof(dtype));
        if(*trav != NULL){
            (*trav)->data = A->data;
            trav = &(*trav)->link;
            A = A->link;
        }
    }

    *trav = NULL;
    return C;
}

SET INTERSECTION(SET A, SET B){
    SET *trav, C, temp;
    C = NULL;
    trav = &C;

    for (; A != NULL; A = A->link){
        for(temp = B; temp != NULL && A->data > temp->data; temp = temp->link){}

        if(temp != NULL && A->data == temp->data){
            *trav = (SET)malloc(sizeof(dtype));

            if(*trav != NULL){
                (*trav)->data = A->data;
                trav = &(*trav)->link;
            }
        }
    }

    *trav = NULL;
    return C;
}