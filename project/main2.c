#include<stdio.h>
#include<stdlib.h>
#include"oper.h"
#include"begin.h"
void main()
{           
        int ch;FILE *fp;
        fp=fopen("history.txt","a+");
	int i = 0 , j=0; list l , l1 ; char *s;
        list h;init(&h);
        
	s = (char *)malloc(sizeof(char)*4096);
        printf("Enter the statement:");
        gets(s);	
        //fprintf(fp,"\n");
        fprintf(fp,"%s",s);
         fprintf(fp,"\n");  
        
        h = checkstatm(s);
        printf("\n   Answer:   ");
        display(&h);
        printf("\n \n");
        fclose(fp);
}

 //free(s);free(s1);
    

