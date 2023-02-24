#include <stdio.h>
#define SIZE 10

typedef enum{ TRUE, FALSE }boolean;

typedef struct{
    char FN[24], MI, LN[16];
}Nametype;

typedef struct{
    Nametype name;
    int ID;
    int age;
    char course[8];
    int yrLevel;
}Studtype;

typedef struct{
    Studtype stud[SIZE];
    int count;
};


void main(){
    Nametype names;
    puts("Please enter your complete name: ");
    scanf("%s", &names);

    
}