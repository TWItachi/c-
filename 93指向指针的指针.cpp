#include <stdio.h>

int main()
{
	char *name[]={"fishc.com","www.fishc.com","home.fish.com","fish.com/dz"}; 
	char **p;
	int i;
	for(i=0;i<4;i++)
	{
		p = name +i;
		printf("%s\n",*p);
	}
	return 0;
 } 
