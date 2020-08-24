#include<stdio.h>
#define N 2
int queue[3][N];
int front[3]={0,0,0};
int rear[3]={-1,-1,-1};

void enqueue(int pr)
{
   int item;
   if(rear[pr]==N-1)
    printf("the queue is filled\n");
   else{
     printf("enter the item:");
     scanf("%d",&item);
     rear[pr]++;
     queue[pr][rear[pr]]=item;
 }
 
}
 void dequeue()
{
	int pr=0;
 
 while((rear[pr]==front[pr]-1)&&(pr<3))
 {
  printf("queue-%d is empty\n",pr+1);
  pr++;}
  if(pr<3){
  printf("the item deleted is %d of queue %d \n",queue[pr][front[pr]],pr+1);
  front[pr]++;}
 

}
 void display(){
 int i,j,fro,rea;
 for(i=0;i<3;i++)
{
 if(rear[i]==front[i]-1)
  printf("No elements in queue %d",i+1);
 else{
  fro=queue[i][front[i]];
  rea=queue[i][rear[i]];
  printf("\n queue %d",i+1);
  for(j=front[i];j<=rear[i];j++){
   printf("\n\t %d",queue[i][j]);
   }
   printf("\n\t Front of the queue is %d:",fro);
   printf("\n\t rear of queue is %d",rea);
 }}
}
int main()
{
  int  choice=0,pr;
  printf("enter the operation to be performed\n");
  printf("enter 1-enqueue , 2-dequeue   , 3-display and 4-exit \n");
  do{
	  printf("enter the choice\n");
	  scanf("%d",&choice);
	  switch(choice)
	{
      case 1:
               printf("enter the priority number\n");
               scanf("%d",&pr);
               if(pr>0&&pr<4)
                enqueue(pr-1);
               else
               printf("enter a valid priority number\n");
             
               break  ;
      case 2:
 
              dequeue();
              break  ; 

      case 3:
              display();
              break  ;
      default:
             printf("please enter a valid option\n"); 
     }
 }while(choice!=4);
return 0;
}

     
