#include <stdio.h>
#define M 1000

int main()
{
	int n,i,n1,t=0;
	long long int s[M]; 
	int b[M],a1[M],a2[M];
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%lld",&s[i]);
		scanf("%d %d",&a1[i],&a2[i]);
	} 
	
	scanf("%d",&n1);
	
	for(int j=0;j<n1;j++)
	{
		scanf("%d",&b[j]);
	}
		
		for(i=0;i<n;i++)
		{
			for(t=0;t<n;t++)
			{
				if(b[i]==a1[t])
				{
					printf("%lld ",s[t]);
					printf("%d\n",a2[t]);
				
				}
			}
		}
	return 0;
}
