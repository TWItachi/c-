#include <stdio.h>
#define M 1000
#include <math.h>
 
main()
{
	int a,i,temp=0;long int b[M];
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{	
		scanf("%ld",&b[i]);
	}
	for(i=0;i<a;i++)
	{
		if(b[i]==1)
		{
			
			printf("No"); 
			continue;
		}
		for(int j=2;j<=sqrt(b[i]);j++)
		{	
			if(b[i]%j==0)
			{
				temp=1;
			}	
		}
		if(temp==0)
			printf("Yes\n");
		else
			printf("No\n");
		temp=0;
	}
}
