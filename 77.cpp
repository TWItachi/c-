#include <stdio.h>
#define M 1000
int i=0,n,j;
int max(int a[]);

main()
{
	int a[M],sum;
	scanf("%d",&n);
	for(;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sum=max(a);
	printf("%d",sum);
} 

int max(int a[])
{
	if(i<0)
		return -1;
	if(i==1)
		return 1;
	if(i>1)
		{
			i--;
			if(a[i]>a[i-1])
			{
				a[i-1]=a[i];
				j=a[i-1];
			}
		}
}
