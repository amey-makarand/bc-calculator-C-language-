#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include<string.h>
#include"oper.h"
#include"begin.h"
 
int isEmpty1(struct operand* stack) 
{ 
    return stack->topd == -1; 
} 
int isEmpty2(struct operat* stack) 
{ 
    return stack->topt == -1; 
} 
list peek1(struct operand* stack) 
{ 
    if (isEmpty1(stack)) 
          return;
    return stack->data[stack->topd]; 
} 
int peek2(struct operat* stack) 
{ 
    if (isEmpty2(stack)) 
          return INT_MIN; 
    return stack->oper[stack->topt]; 
} 
  
  
struct operand* initialize(int cap)
{
	struct operand *k=(struct operand *)malloc(sizeof(struct operand));
	k->topd=-1;
	k->capacity1=cap;
	k->data=(list*)malloc((k->capacity1) * sizeof(list));
	return k;
}
struct operat* initialize2(int cap)
{
	struct operat *m=(struct operat*)malloc(sizeof(struct operat));
	m->topt=-1;
	m->capacity2=cap;
	m->oper=(char*)malloc((m->capacity2)*sizeof(char));
	return m; 

}
int Pre(char x)
{
	if(x == '+' || x == '-')
		return 1;
	if(x == '*' || x == '/' || x== '%')
		return 3;
	if(x == '^')
		return 4;
	if(x == '<' || x== '>')
		return 5;
	
	return 0;
}
int isFull1(struct operand* stack) 
{ 
    return stack->topd == stack->capacity1 - 1; 
} 
int isFull2(struct operat* stack) 
{ 
    return stack->topt == stack->capacity2 - 1; 
} 
   
void push1(struct operand* stack, list item) 
{ 
    if (isFull1(stack)) 
        return; 
    stack->data[++(stack->topd)] = item; 
    stack->data= (list *)realloc(stack->data, sizeof(list)*(4096)); 

} 
void push2(struct operat* stack, char ch) 
{ 
    if (isFull2(stack)) 
        return; 
    stack->oper[++(stack->topt)] = ch; 
    stack->oper= (char *)realloc(stack->oper, sizeof(char)*(4096)); 
  
} 
void pop1(struct operand* stack) 
{ 
    if (isEmpty1(stack)) 
         return; 
     stack->data[stack->topd--]; 
} 
 void pop2(struct operat* stack) 
{ 
    if (isEmpty2(stack)) 
         return ;  
    stack->oper[stack->topt--]; 
} 
   
int isoperand(char x)
{


	if(x == '+' || x=='-'|| x=='*' || x=='/' || x==')' || x=='(' || x =='<'||x == '^' || x=='>'|| x=='%')
		return 0;
	   return 1;
}

list checkstatm(char b[])
{
     list final;
     init(&final);
     struct operand* s=initialize(4096);
     struct operat* t=initialize2(4096);
     int i = 0,operand;list x,z;char y;list g;init(&g);init(&x);init(&z);
	init(&x);
	int c = 0;
     while(b[i]!='\0')
     {
     	if(b[i]==' '|| b[i] == ',')
     	{
     		i++;
		
	}
	else
	if (isoperand(b[i])){	
		while(i < strlen(b) && isoperand(b[i])){
			create(b[i]-'0', &g);
			i++;
	        }
		
		
		
		push1(s,g);
		init(&g);
		
	}
	
	else 	
	if(!isoperand(b[i]) && isEmpty2(t)){
		push2(t,b[i]);
		i++;	
	}
	
	else
	if(!isoperand(b[i]) && !isEmpty2(t)) {
		if(b[i]=='(')
			push2(t,b[i++]);	
		else 
		if(Pre(b[i]) > Pre(peek2(t)) && b[i]!=')')
			push2(t,b[i++]);
		else if(b[i]==')' && peek2(t) == '('){
			pop2(t);
		        i++;
		}
		else {
			x = peek1(s);
			pop1(s);
			y = peek2(t);
			pop2(t);
			z = peek1(s);
			pop1(s);
			if(y == '+')
			 	push1(s,addm(&x,&z));
			 else
		         if(y == '-')
				push1(s,sub(&z,&x));
			else 
			if(y == '*')
		 		push1(s,mult(&x,&z));
			else 
			if(y == '<')
				push1(s, shiftr(&x,&z));
			else 
                         if(y == '/')
			push1(s,divi3(&z,&x));
                        else
                         if(y=='^')
                        push1(s,expo(&x,&z));
                       else
                         if(y=='>')
                        push1(s,shiftr(&x,&z));
                       else
                         if(y=='%')
                         push1(s,modulo(&z,&x));

	     	}
		       
	}
   
  } // while is over
  
   while(!isEmpty2(t)) {
	x = peek1(s);
	pop1(s);
	y = peek2(t);
	pop2(t);
	z = peek1(s);
	pop1(s);
	if(y == '+'){
		final = addm(&z,&x);
		push1(s, final);
	}
	else if(y == '-')
		push1(s,sub(&z,&x));
	else if(y == '*')
		push1(s,mult(&x,&z));
	else if(y == '<')
		push1(s,shiftr(&x,&z));
	else if(y == '/')
		push1(s,divi3(&z,&x));
        else if(y=='^')
                push1(s,expo(&x,&z));
        else if(y=='>')
               push1(s,shiftr2(&x,&z));
        else if(y=='%')
           push1(s,modulo(&z,&x));
	}

	return peek1(s);
	
 
}


/*int main()
{
   char statm[225];
  printf("Enter the infix statement:");
  gets(statm) ;	
  int c=checkstatm(statm);
  printf("%d",c);
  return 0;
	
}
*/
