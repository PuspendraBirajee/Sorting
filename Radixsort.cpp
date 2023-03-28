#include<stdio.h>
  /*void TakeInput(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}*/

void radixsort(int a[], int n);
int main()
{
    //TakeInput();
    int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
	radixsort(a,n);
}
int Get_Max(int a[],int n){
	int maxi=0;
	for(int i=0;i<n;i++)
	{
		if(maxi<a[i])
		{
			maxi=a[i];
		}
	}
	return maxi;
}
void radixsort(int a[], int n)
{
	int max_val=Get_Max(a,n);
	int place=1;
	while(max_val)
	{
		int matrix[10][n];
		int cnt[10]={0};
		for(int i=0;i<n;i++)
		{
			int digit=(a[i]/place)%10;
			matrix[digit][cnt[digit]]=a[i];
			cnt[digit]++;
		}
		int x=0;
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<cnt[i];j++)
			{
				a[x]=matrix[i][j];
				
				x++;
			}
		}
		max_val=max_val/10;
		place=place*10;
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}