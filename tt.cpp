#include <stdio.h>

int main()
{
	int a,b,n;
	scanf("%d%ld",&a,&b);
	n=a;
	while(1)
	{
		if(a%n==0&&b%n==0)
		{
			printf("%d\n",n);break;
		}
		else
			n--;
	}
	return 0;
}
