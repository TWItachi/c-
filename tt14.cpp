#include <stdio.h>

main()
{
	int n,a=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		a*=2;
	}
	printf("2^%d = %d",n,a);
}
