#include <stdio.h>
#define M 1000

int main()
{
	int v,n,i,j,k=0,a[M]={0},temp,max=0,s=0;
	scanf("%d",&v);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&j);
		a[i]=j;
	}
	for(k=0;k<n;k++)
		for(i=0;i<n-1;i++)
		{
			if(a[i]>a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
	for(i=n-1;i>=0;i--)
	{	
		k=n-2;
		while(k>=-1)
		{
			if(a[i]>v)
				break;
			if(a[i]+a[k]>v)
			{
				k--;
			}
			else if(a[i]+a[k]<v)
			{	
				a[i]+=a[k];
				k--;
			}
			else
			{
				printf("0\n");s=1;goto loop;
			}
			
			if(a[i]>max)
			{
				max=a[i];
			}
		}
	}
	loop:i=1;
	if(s==0)
		printf("%d\n",v-max);
	return 0;
}
