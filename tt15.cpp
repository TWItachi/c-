#include <stdio.h>

main()
{
	int a,i,sum=1,cnt=0;
	scanf("%d",&a);
	for(a;a>0;a--)
	{
		i=a;
		sum=1;
		while(i)
		{
			sum*=i;
			i--;	
		}
		cnt+=sum;
	}
	printf("%d",cnt);
}
