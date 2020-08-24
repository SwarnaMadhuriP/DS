#include<stdio.h>
int i,j,n,a[10],s[10],count[20];
void dist(int a[],int n);
int main()
{

printf("Enter the number of elements:\n");
scanf("%d",&n);

printf("Enter the elements in an array:\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("Unsorted array is:\n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
dist(a,n);
return 0;
}
void dist(int a[],int n)
{


for(j=0;j<20;j++)
count[j]=0;

for(i=0;i<n;i++)
count[a[i]]= count[a[i]] + 1;

for(j=1;j<=20;j++)
count[j]= count[j-1] + count[j];

for(i=n;i>=0;i--)
{
s[count[a[i]]-1]= a[i];
count[a[i]]= count[a[i]] - 1;
}

printf("\nSorted array is:\n");
for(i=0;i<n;i++)
printf("%d\t",s[i]);
}

