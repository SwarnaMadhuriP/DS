#include<stdio.h>

#include<malloc.h>

struct node{
 
int val;

struct node * next;

};

struct node * create_list()
{

int k, n;
struct node * p, * head;

printf("enter no.of elements\n");

scanf("%d", &n);

for(k=0;k<n;k++)
{

 if(k==0){

  head=(struct node*)malloc(sizeof(struct node));
 
  p=head;
}

 else{
 
  p->next=(struct node*)malloc(sizeof(struct node));

  p=p->next;}
  
  scanf("%d",&p->val);
 
   }

p->next=NULL;

return head;

}

int main()
{

 struct node * q;

 q=create_list();

 while(q!=NULL)
 {
 
 printf("The elements of the list are %d\n",q->val);

 q=q->next;
 
}

 return 0;

}


