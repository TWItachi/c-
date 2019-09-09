#include <stdio.h>

main()
{
	int a,b,c;
	scanf("%d:%d",&a,&b);
	if(a>=12)
	{
		if(b>0)
		{
			a++;
		} 
	}
	if(a>=0&&a<=12)
	{
		if(a<10&&b<10)
			printf("Only 0%d:0%d.  Too early to Dang.",a,b);
		if(a<10&&b>=10)
			printf("Only 0%d:%d.  Too early to Dang.",a,b);
		if(a>=10&&b<10)
			printf("Only %d:0%d.  Too early to Dang.",a,b);
		if(a>=10&&b>=10)
			printf("Only %d:%d.  Too early to Dang.",a,b);
	}
	if(a>12&&a<25) 
		for(a;a>12;a--)
		{
			printf("Dang");
		}
}
