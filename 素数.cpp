#include <stdio.h>

int main()
{
	int a,b,t;
	for(a=2;a<=100;a++)
	{
		int t=1;
		for(b=2;b<a;b++)
		{	
			if(a%b==0)
			{
				t=0;break;	
			}
		}
		if(t==1)
			printf("%d\n",a);
	}
	return 0;
 } 
