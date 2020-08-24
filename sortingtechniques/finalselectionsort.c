#include<stdio.h>

int smallest(int arr[],int k,int n)
{
	int pos=k,small=arr[pos],i;

	for(i=k+1;i<n;i++)

	{

           if(arr[i]<small){
	
		pos=i;

	        small=arr[i];
}
	
        }
	        
 return pos;

}

void selectionsort(int arr[],int n){

int k,pos,temp;

for(k=0;k<n-1;k++)//It finally depends on the input because some may require only n-2 passes which may not work for other inputs.

{
		
    pos=smallest(arr,k,n);
		
    temp=arr[k];
		
    arr[k]=arr[pos];
		
    arr[pos]=temp;
	
}

}
		

int main(){
	
int a[10],n,i;
	
printf("enter the maximum size of the array\n");

scanf("%d",&n);

printf("enter the elements of the array\n");
	
for(i=0;i<n;i++)
	
scanf("%d",&a[i]);
	
selectionsort(a,n);
	
printf("the sorted array is \n");
	
for(i=0;i<n;i++)
	
printf("%d \t",a[i]);
	
return 0;
}
