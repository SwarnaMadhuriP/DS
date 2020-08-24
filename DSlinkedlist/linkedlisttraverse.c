#include<stdio.h>
#include<malloc.h>
struct node{
 int roll;
 char name[20];
 int age;
 struct node * next;
};
struct node*  create_list()
{
int k,n;
struct node *p,*head;
printf("enter how many numbers to be entered?\n");
scanf("%d",&n);
for(k=0;k<n;k++){

if(k==0){
  head=(struct node *)malloc(sizeof(struct node));
  p=head;
}
else{
  p->next=(struct node *)malloc(sizeof(struct node));
  p=p->next;
}
printf("enter the details of the student\n");
scanf("%d%s%d",&p->roll,p->name,&p->age);
}

p->next=NULL;
return  head;
}
int main()
{
 struct node * q;
 q=create_list();
 while(q!=NULL)
 {
  printf("the values of the list are name= %s and roll=%d and age=%d \n",q->name,q->roll,q->age);
  q=q->next;
 }
 return 0;
}

