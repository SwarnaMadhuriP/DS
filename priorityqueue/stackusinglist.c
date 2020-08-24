#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define size 4
struct node{
	int data;
	struct node * next;
};
int flag=1,max=0;
void push();
int pop();
void display();
struct node * top=NULL,*newptr,*temp;
int main(){
	int ch,x;
	printf("enter 1-create,2-insert,3-display and 4-exit\n");
	do{
		printf("enter choice\n");
		scanf("%d",&ch);
		switch(ch){
		case 1:push();
			   break;
		case 2: x=pop();
		        if(flag)
		        printf("\n popped element is %d",x);
			    break;
		case 3: display();
			    break;
					   
				   }
			   }while(ch!=4);
			   return 0;
		   }
void push(){
	newptr=(struct node *)malloc(sizeof(struct node));
	if((newptr==NULL)||max>3)
	printf("stack overflow\n");
	else{
		flag=1;
		max++;
		printf("enter the element to be pushed\n");
		scanf("%d",&newptr->data);
		newptr->next=top;
		top=newptr;
	}
	return ;
}
int pop(){
	int x;
	if(top==NULL){
	 printf("stack underflow\n");
	 flag=0;
	 return(-1);
 }
    x=top->data;
    --max;
    temp=top;
     top=top->next;
     free(temp);
     return x;
 }
 void display(){
	 if(top==NULL){
		 printf("the stack is empty\n");}
		 else{
			 temp=top;
			 printf("the stack contents are\n");
			 while(temp!=NULL){
				 printf("the elements of the list are %d\n",temp->data);
				 temp=temp->next;
			 }}
		 }
 
		

		
