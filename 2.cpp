#include <stdio.h>
#include <math.h>

main() 
{	
	int j;int a;
	for(a=1000;a<9999;a++)
	{
		int t=1;
		for(j=2;j<sqrt(a);j++)
		{
			if(a%j==0)
			{
				t=0;
			}
			else
				continue;
		}
		if(t==1)
		{
			printf("%d ",a);
		}
	}
}
