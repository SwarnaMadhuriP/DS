#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
# define max 4
struct node{
	int data;
	struct node * next;
};//In queue element is inserted at the end but is deleted at the begining.
int size=0;
struct node* delete(struct node * head)
{
	struct node * temp;
	if(head==NULL){
	printf("queue is empty\n");
	return head;}
	else if (head->next==NULL){
		head=NULL;
		return(head);
	}
	temp=head->next;
	free(head);
	return(temp);
}
struct node* createnode(){
	struct node * temp;
	temp=(struct node *)malloc(sizeof(struct node));
	if((temp==NULL)||(size>3)){
		printf("queue overflow\n");
	}
	temp->next=NULL;
	printf("enter the data for this node\n");
	scanf("%d",&temp->data);
	size++;
	return temp;
}
struct node* insert(struct node * head)
{
	struct node *temp,*newnode;
	if(head==NULL){
	head=(struct node *)malloc(sizeof(struct node));
	printf("enter data for head node\n");
	scanf("%d",&head->data);
	head->next=NULL;
	size++;}
	temp=head;
	newnode = createnode();
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->next=NULL;
	return(head);
}
struct node * display(struct node * head){
	struct node * temp;
	temp=head;
	if(temp==NULL)
	printf("queue is empty\n");
	while(temp!=NULL){
		printf("the elements of the queue are %d\n",temp->data);
		temp=temp->next;
	}
	return head;
}

int main(){
	int ch;
	struct node * head=NULL;
	printf("enter 1-create,2-insert,3-display and 4-exit\n");
	do{
		printf("enter choice\n");
		scanf("%d",&ch);
		switch(ch){
		case 1:head=insert(head);
			   break;
		case 2: head=delete(head);
			    break;
		case 3: head=display(head);
			    break;
					   
				   }
			   }while(ch!=4);
			   return 0;
		   }

