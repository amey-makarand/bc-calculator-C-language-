struct operand
{
	list *data;
	int topd;
	int capacity1;
};
struct operat
{
	char *oper;
	int topt;
	int capacity2;
}; 
int isEmpty1(struct operand* stack);
int isEmpty2(struct operat* stack);
list peek1(struct operand* stack);
int peek2(struct operat* stack);
struct operand* initialize(int cap);
struct operat* initialize2(int cap);
int Pre(char x);
int isFull1(struct operand* stack);
int isFull2(struct operat* stack);
void push1(struct operand*, list item);
void push2(struct operat* stack, char ch);
void pop1(struct operand* stack);
void pop2(struct operat* stack);
int isoperand(char x);
list checkstatm(char *b);


 
 




