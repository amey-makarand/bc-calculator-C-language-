#include<stdio.h>
#include<stdlib.h>
#include"oper.h"

void main()
{           
      int ch;
     do
      {
	int i = 0 , j=0; list l , l1 ; char *s,*s1 ;list g;
         
        
	s = (char *)malloc(sizeof(char)*1024);list d;
	s1 = (char *)malloc(sizeof(char)*1024);
        printf("\n 1) Addition \n ");
        printf("\n 2) Subtraction \n ");
        printf(" \n 3) Multiplication \n ");
        printf(" \n 4) Shift left \n ");
        printf(" \n 5) Exit \n");
        printf("\n In case of shift left,4 is chosen for bit shift \n"); 
        
         init(&g);init(&d);
	printf("Enter any 2 numbers:");
	init(&l);
	init(&l1);
	scanf("%s",s);
	scanf("%s",s1);
	while(s[i] != '\0')
  
	create(s[i++]-'0',&l);
  
    
	while(s1[j] != '\0')
    
        create(s1[j++]-'0',&l1);
        
        
           
           printf("\n Enter your choice: \n");
           scanf("%d",&ch);
           switch(ch)
            {
               case 1:
                        printf("Answer is: \t"); g=addm(&l,&l1);
                         break;
               case 2:
         //             printf("Answer is: \t");sub(&l,&l1);
           //           break;
               case 3:  
                       d=mult(&l,&l1);
                       printf("Answer is: \t");revdisplay(&d);
                       break;
               case 4:
                       printf("Answer is: \t ");shiftr(&l,4);
                       break;
               default:
                     exit(0);
            }

      }
      while(ch!=0);    
	 
}

 //free(s);free(s1);
    

