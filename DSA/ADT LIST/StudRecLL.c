#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

typedef struct node{
    studtype Student;
    struct node *link; 
}*LIST;


void initList(LIST *L)
{
    *L = NULL;
}

void insertFirst(LIST *L, studtype student)
{
    LIST temp = (LIST)malloc(sizeof(struct node));

    if(temp != NULL)
    {
        temp->Student = student;
        temp->link = *L;
        *L = temp;
    }
}

void insertLast(LIST *L, studtype student)
{
    LIST temp = (LIST)malloc(sizeof(struct node));
    LIST *trav;

    if(temp != NULL)
    {
        for(trav = L; *trav != NULL; trav = &(*trav)->link){}

        temp->Student = student;
        temp->link = *trav;
        *trav = temp;
    }
}

void populate(LIST *L)
{
    studtype student1 = {{"James Winston", 'D', "Ng"}, "BSIT", 1, 2};
    insertFirst(L, student1);
    studtype student2 = {{"Pfizer JVI", 'P', "Lapeciros"}, "BSCE", 2, 3};
    insertFirst(L, student2);
    studtype student3 = {{"Nathan Eldridge Mitnick", 'C', "Pernites"}, "BSIT", 3, 2};
    insertFirst(L, student3);
    studtype student5 = {{"John Doe", 'D', "Ng"}, "BSIE", 5, 5};
    insertFirst(L, student5);
    studtype student6 = {{"Cheyanne Marie", 'D', "Ng"}, "BSA", 6, 5};
    insertFirst(L, student6);
    studtype student8 = {{"Not Romeo", 'D', "NotNg"}, "BSII", 8, 5};
    insertFirst(L, student8);
    studtype student9 = {{"Smith", 'D', "Ng"}, "BSA", 9, 5};
    insertFirst(L, student9);
    studtype student7 = {{"Romeo", 'D', "Ng"}, "BSII", 7, 5};
    insertFirst(L, student7);
    studtype student10 = {{"Romeo again", 'D', "Ng"}, "BSII", 10, 5};
    insertFirst(L, student10);

}

void deleteElem(LIST *L, int ID)
{
    LIST temp = (LIST)malloc(sizeof(struct node));
    LIST *trav;

    if(temp != NULL)
    {
        for(trav = L; *trav != NULL && (*trav)->Student.ID != ID; trav = &(*trav)->link){}

            if(*trav != NULL)
            {
                temp = *trav;
                *trav = temp->link;
                free(temp);
            }
    }
}

void deleteAllOccur(LIST *L, char Lname[])
{
    LIST *trav;

        for(trav = L; *trav != NULL;)
        {
            if(strcmp((*trav)->Student.Name.Lname, Lname) == 0)
            {
                LIST temp = (LIST)malloc(sizeof(struct node));

                if(temp != NULL)
                {
                    temp = *trav;
                    *trav = temp->link;
                    free(temp);
                }
            }else{
                trav = &(*trav)->link;
            }
        }
}

void sortAcsending(LIST *L)
{
    LIST *trav1, *trav2;

        for(trav1 = L; *trav1 != NULL; trav1 = &(*trav1)->link)
        {
            for(trav2 = &(*trav1)->link; *trav2 != NULL; trav2 = &(*trav2)->link) 
            {
                if((*trav2)->Student.ID < (*trav1)->Student.ID)
                {
                    studtype temp;

                        temp = (*trav1)->Student;
                        (*trav1)->Student = (*trav2)->Student;
                        (*trav2)->Student = temp;

                }
            }
        }
}

void display(LIST L)
{
    LIST trav;


    for(trav = L; trav != NULL; trav = trav->link)
    {
        printf("%-24s %-5c %-15s %-10s %-.8d      %d year\n",
                trav->Student.Name.Fname,
                trav->Student.Name.MI,
                trav->Student.Name.Lname,
                trav->Student.course,
                trav->Student.ID,
                trav->Student.yearLvl
        );
    }
}

int main()
{
    LIST A;
    initList(&A);
    populate(&A);

    studtype student4 = {{"Romeo John", 'C', "Magallanes"}, "BSCE", 4, 3};
    insertLast(&A, student4);

    sortAcsending(&A);
    // deleteElem(&A, 1);
    // deleteAllOccur(&A, "Ng");


    display(A);




    return 0;
}
