#include<stdio.h>

void bubblesort(int a[],int n){
	
int i,j,temp;
	
for(i=0;i<n-1;i++){
		
		
  for(j=0;j<n-i-1;j++){
			
      if(a[j]>a[j+1]){
				
				
          temp=a[j];
				
          a[j]=a[j+1];
				
          a[j+1]=temp;
				
				
        }
			
			
} 
			 
}
		 
}
		 
 

int main(){
	
int a[10],n,i;
	
printf("enter the maximum size of the array\n");
	
scanf("%d",&n);
	printf("enter the elements of the array\n");
	
for(i=0;i<n;i++)
	
scanf("%d",&a[i]);
	
bubblesort(a,n);
	
printf("the sorted array is \n");
	
for(i=0;i<n;i++)
	
printf("%d \t",a[i]);
	
return 0;
}

