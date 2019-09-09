#include <stdio.h> 
int a[101],n;
void quicksort(int left,int right)
{
	int i,j,temp,t;
	if(left>right)
	{
		return ;
	}
	temp=a[left];
	i=left;
	j=right;
	while(i!=j)
	{
		for(;a[j]>=temp&&i<j;j--);
		for(;a[i]<=temp&&i<j;i++);
		if(i<j)
		{
			t=a[i];
			a[i]=a[j];//¶à¿´¿´ 
			a[j]=t;
		}
	}
	a[left]=a[i];
	a[i]=temp;
	quicksort(left,i-1);
	quicksort(i+1,right);
	return ;
}
main()
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quicksort(0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
