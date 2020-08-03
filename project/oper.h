typedef struct node
{
     
     long long int data;
     struct node *next,*prev;
}node;


typedef struct list
{
     node *head,*tail;
}list;




void init(list *l);
void dislpay(list *l);
void create(long long int d,list *l);
list add(list *l,list *m);
void revdisplay(list *l);
list sub(list *l,list *m);
list mult(list *l,list *m);
list shiftr(list *l,list *m);
list evdisplay(list *l);
list addm(list *l,list *m);
int checkzero(list *l);
list divi(list *l,list *m);
list expo(list *l,list *m);
int compare(list *m,list *n);
list divi3(list *l,list *m);
int  bigcheck(list *l,list *m);
int comparator(list *l,list *m);
list shiftr2(list *l,list *m);
list modulo(list *l,list *m);
