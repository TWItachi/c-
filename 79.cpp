#include <stdio.h>
int a=32,j=0;


int f(int a)
{
	if(a==1)
	{
		j++;return 56;
	}
	else
	{
		j++;return f(a/2);
	}
}

main ()
{
	int o;
	o=f(a);
	printf("%d%d",j,o);	
}

