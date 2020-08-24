#include<stdio.h>
void insertionsort(int arr[], int n)
{
int i, key, j;
for (i = 1; i < n; i++)
{
key = arr[i];
j = i-1;
/* Move elements of arr[0..i-1], that are
greater than key, to one position ahead
of their current position */
while (j >= 0 && arr[j] > key)
{
arr[j+1] = arr[j];
j = j-1;
}
arr[j+1] = key;
}
}
int main(){
	int a[10],n,i;
	printf("enter the maximum size of the array\n");
	scanf("%d",&n);
	printf("enter the elements of the array\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	insertionsort(a,n);
	printf("the sorted array is \n");
	for(i=0;i<n;i++)
	printf("%d \t",a[i]);
	return 0;
}


