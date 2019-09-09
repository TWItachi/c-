#include <stdio.h>
#define M 1000

main()
{
	int n,a[M],i,x=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int k=0;k<n;k++)
		for(i=0;i<n-1;i++)
		{
			if(a[i]>a[i+1])
			{
				int temp;
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
	for(i=0;i<n;i++)
	{
		if(a[i]==a[i+1])
		{
			a[i]=0;x++;
		} 
	}
	for(int k=0;k<n;k++)
		for(i=0;i<n-1;i++)
		{
			if(a[i]>a[i+1])
			{
				int temp;
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
	printf("%d\n",n-x);
	for(;x<n;x++)
	{
		printf("%d ",a[x]);
	}
} 
