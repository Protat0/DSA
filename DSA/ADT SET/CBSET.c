#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int elem;
    int link;
}stype, HeapSpace[MAX];

typedef struct{
    HeapSpace H;
    int Avail;
}VHeap;

typedef int SET;

SET UNION(SET A, SET B, VHeap *VH){
    SET C, *trav;
    C = -1;
    trav = &C;

    while(A != -1 && B != -1){
        *trav = VH->Avail;
        
        if(*trav != -1){
            VH->Avail = VH->H[*trav].link;

            if(VH->H[A].elem < VH->H[B].elem){
                VH->H[*trav].elem = VH->H[A].elem;
                A = VH->H[A].link;
            } else {
                if(VH->H[A].elem == VH->H[B].elem){
                    A = VH->H[A].link;
                }
                VH->H[*trav].elem = VH->H[B].elem;
                B = VH->H[B].link;
            }
            trav = &VH->H[*trav].link;
        }
    }

    if(A == -1 && B != -1){
        A = B;
    }

    while(A != -1){
        *trav = VH->Avail;

        if(*trav != -1){
            VH->Avail = VH->H[*trav].link;
            VH->H[*trav].elem = VH->H[A].elem;
            trav = &VH->H[*trav].link;
            A = VH->H[A].link;
        }
    }

    *trav = -1;
    return C;
}

SET INTERSECTION(SET A, SET B, VHeap *VH){
    SET C, travB, *travA;
    C = -1;
    travA = &C;

    for(; A != -1; A = VH->H[A].link){
        for(travB = B; travB != -1 && VH->H[A].elem > VH->H[travB].elem; travB = VH->H[travB].link){}

        if(travB != -1 && VH->H[A].elem == VH->H[travB].elem){
            *travA = VH->Avail;

            if(*travA != -1){
                VH->Avail = VH->H[*travA].link;
                VH->H[*travA].elem = VH->H[A].elem;
                travA = &VH->H[*travA].link;
            }
        }
    }

    *travA = -1;
    return C;
}
