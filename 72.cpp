#include <stdio.h> 
#include <math.h>

main()
{
	int max_4(int a,int b,int c,int d);
	int a,b,c,d,max;
	printf("ÇëÊäÈë4¸öÊı:");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	max=max_4(a,b,c,d);
	printf("max is %d",max); 
}

int max_4(int a,int b,int c,int d)
{	
	int m;
	int max_2(int,int);
	m=max_2(a,b);
	m=max_2(m,c);
	m=max_2(m,d);
	return (m);
 } 
 int max_2(int a,int b)
	{
		if(a>b)
			return (a);
		else
			return (b); 
	}
