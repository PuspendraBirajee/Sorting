//4.1) Merge sort, to sort a given list of integers 
//Program: 
#include<stdio.h> 
void merge(int *arr,int l,int m,int h) 
{ 
 int i,a[100],b[100],n1=m-l+1,n2=h-m,k=l,newarr[1000],j; 
 for(i=0;i<n1;i++) 
  a[i]=arr[k++]; 
 k=m+1; 
 for(i=0;i<n2;i++) 
  b[i]=arr[k++]; 
 i=j=k=0; 
 while(i<n1&&j<n2) 
{ 
if(a[i]<=b[j]) 
newarr[k]=a[i++]; 
  else 
               newarr[k]=b[j++]; 
          k++; 
} 
     while(i<n1) 
          newarr[k++]=a[i++]; 
while(j<n2) 
          newarr[k++]=b[j++]; 
    k=l; 
    for(i=0;i<n1+n2;i++) 
     arr[k++]=newarr[i]; 
} 
void mergesort(int *arr,int l,int h) 
{ 
 int m; 
 if(l<h) 
{ 
  m=(l+h)/2; 
  mergesort(arr,l,m); 
  mergesort(arr,m+1,h); 
  merge(arr,l,m,h); 
} 
} 
int main() 
{ 
 int n; 
 scanf("%d",&n); 
 int i,arr[n]; 
 for(i=0;i<n;i++) 
  scanf("%d",&arr[i]); 
  int l=0;
  int h=n-1;
 mergesort(arr,l,h); 
 for(i=0;i<n;i++) 
  printf("%d ",arr[i]); 
} 