#include<stdio.h>
#include <string.h>

int main(void){
	char string[250][500],temp[250];
	int i,j;
	int num;
	
	scanf("%d",&num);
	
	for(i=0;i<=num;i++){
		fgets(string[i], sizeof string, stdin);
	}
	
	for(i=1;i<=num;i++){
		for(j=0;j<=num-i;j++){
		  if(strcmp(string[j],string[j+1])>0)
	        { 
            strcpy(temp,string[j]);
	        strcpy(string[j],string[j+1]);
	        strcpy(string[j+1],temp);
	        }
	  }
	  }
	      for(i=0;i<=num;i++){
		    printf("%s",string[i]); 
		}
}